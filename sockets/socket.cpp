#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#include <stdexcept>

#include "socket.h"
#include "resolver.h"
#include "liberror.h"

Socket::Socket(const char *hostname, const char *servicename) : skt(-1), closed(true) {
    Resolver resolver(hostname, servicename, false);

    int s;
    int skt = -1;
    while (resolver.has_next()) {
        struct addrinfo *addr = resolver.next();

        /* Cerramos el socket si nos quedo abierto de la iteracion
         * anterior
         * */
        if (skt != -1)
            ::close(skt);

        /* Creamos el socket definiendo la familia (deberia ser AF_INET IPv4),
           el tipo de socket (deberia ser SOCK_STREAM TCP) y el protocolo (0) */
        skt = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        if (skt == -1) {
            continue;
        }

        /* Intentamos conectarnos al servidor cuya direccion
         * fue dada por getaddrinfo()
         * */
        s = connect(skt, addr->ai_addr, addr->ai_addrlen);
        if (s == -1) {
            continue;
        }

        // Conexion exitosa!
        this->skt = skt;
        this->closed = false;
        return;
    }

    // El errno es una (psuedo) variable global con el ultimo error generado.
    // Es importante no llamar nada antes ya que cualquier llamada
    // a la libc puede cambiar el errno y hacernos perder el mensaje
    // El manejo de errores en C es muy sensible!
    int errno_saved = errno;

    // No hay q olvidarse de cerrar el socket en caso de
    // que lo hayamos abierto
    if (skt != -1)
        ::close(skt);

    // Lanzamos una excepcion con el errno que guardamos (preservamos)
    // excepcion
    // Dado que probamos multiples direcciones y llamamos a socket() y
    // a connect() multiples veces podriamos estar ante el caso de varios
    // errores *distintos*.
    // Sin embargo vamos a notificar del ultimo error y nada mas.
    //
    // Notese que lanzar una excepcion en el constructor es la unica manera
    // de poder comunicar que un objeto no se construyo
    throw LibError(errno_saved, "Socket for connection to '%s:%s' failed: ", hostname, servicename);
}

Socket::Socket(const char *servicename) : skt(-1), closed(true) {
    Resolver resolver(nullptr, servicename, true);

    int s;
    int skt = -1;
    while (resolver.has_next()) {
        struct addrinfo *addr = resolver.next();

        /* Cerramos el socket si nos quedo abierto de la iteracion
         * anterior
         * */
        if (skt != -1)
            ::close(skt);

        /* Creamos el socket definiendo la misma familia, tipo y protocolo
         * que tiene la direccion que estamos por probar.
         * Por ejemplo deberia ser la familia AF_INET IPv4,
         * el tipo de socket SOCK_STREAM TCP  y el protocolo 0.
         *
         * Ya que usamos getaddrinfo() no conviene hardcodear esos valores
         * sino usar los mismos que ya estan cargados en la direccion
         * que estamos probando.
         * */
        skt = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        if (skt == -1) {
            continue;
        }

        /*
         * Como el sistema operativo puede mantener ocupado (en TIME_WAIT)
         * un puerto que fue usado recientemente, no queremos que nuesta
         * aplicacion falle a la hora de hacer un bind() por algo que sabemos
         * que es temporal.
         *
         * Un puerto en TIME_WAIT esta "ocupado" solo temporalmente por
         * el sistema operativo.
         *
         * Entonces queremos decirle que "queremos reutilizar la direccion"
         * aun si esta en TIME_WAIT (de otro modo obtendriamos un error al
         * llamar a bind() con un "Address already in use")
         * */
        int val = 1;
        s = setsockopt(skt, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
        if (s == -1) {
            continue;
        }

        // Hacemos le bind: enlazamos el socket a una direccion local
        // para escuchar
        s = bind(skt, addr->ai_addr, addr->ai_addrlen);
        if (s == -1) {
            continue;
        }

        // Ponemos el socket a escuchar. Ese 20 (podria ser otro valor)
        // indica cuantas conexiones a la espera de ser aceptadas se toleraran
        // No tiene nada q ver con cuantas conexiones totales el server tendra
        s = listen(skt, 20);
        if (s == -1) {
            continue;
        }

        // setupeamos el socket! Ahora esta escuchando
        // en una de las direcciones obtenidas por getaddrinfo()
        // y esta listo para aceptar conexiones.
        this->skt = skt;
        this->closed = false;
        return;
    }

    int errno_saved = errno;

    // No hay q olvidarse de cerrar el socket en caso de
    // que lo hayamos abierto
    if (skt != -1)
        ::close(skt);

    throw LibError(errno_saved, "Socket for service '%s' failed: ", servicename);
}

/*
 * Constructor que inicializa el socket pasandole directamente el file descriptor.
 *
 * No queremos que el codigo del usuario este manipulando el file descriptor,
 * queremos q interactue con él *solo* a traves de Socket.
 *
 * Por ello ponemos este constructor privado (vease socket.h).
 * */
Socket::Socket(int skt) : skt(skt), closed(false) {
}

Socket::Socket() : skt(-1), closed(true) {}

int Socket::recvsome(void *data, unsigned int sz, bool *was_closed) {
    *was_closed = false;
    int s = recv(this->skt, (char*)data, sz, 0);
    if (s == 0) {
        // Puede ser o no un error, dependera del protocolo.
        // Alguno protocolo podria decir "se reciben datos hasta
        // que la conexion se cierra" en cuyo caso el cierre del socket
        // no es un error sino algo esperado.
        *was_closed = true;
        return 0;
    } else if (s < 0) {
        // 99% casi seguro que es un error real
        throw LibError(errno, "Socket recvsome failed (len %d): ", sz);
    } else {
        return s;
    }
}

int Socket::sendsome(const void *data, unsigned int sz, bool *was_closed) {
    *was_closed = false;
    int s = send(this->skt, (char*)data, sz, MSG_NOSIGNAL);
    if (s == 0) {
        // Puede o no ser un error (vease el comentario en recvsome())
        *was_closed = true;
        return 0;
    } else if (s < 0) {
        // Este es un caso especial: cuando enviamos algo pero en el medio
        // se detecta un cierre del socket no se sabe bien cuanto se logro
        // enviar (y fue recibido por el peer) y cuanto se perdio.
        //
        // Se dice que la "tuberia esta rota" o en ingles, "broken pipe"
        //
        // En Linux el sistema operativo envia una signal (SIGPIPE) que
        // mata al proceso. El flag MSG_NOSIGNAL evita eso y nos permite
        // checkear y manejar la condicion mas elegantemente
        if (errno == EPIPE) {
            // Puede o no ser un error (vease el comentario en recvsome())
            *was_closed = true;
            return 0;
        }

        // 99% casi seguro que es un error
        throw LibError(errno, "Socket sendsome failed (len %d): ", sz);
    } else {
        return s;
    }
}

int Socket::recvall(void *data, unsigned int sz, bool *was_closed) {
    unsigned int received = 0;
    *was_closed = false;

    while (received < sz) try {
        int s = this->recvsome((char*)data + received, sz - received, was_closed);
        if (s == 0) {
            // Si el socket fue cerrado (s == 0) pero es claro que no logramos
            // recibir todo lo que queriamos recibir por lo que supondremos
            // que es un error y lanzamos una excepcion.
            //
            // Podriamos crear nuestra propia clase UnexpectedClosed pero
            // por simplicidad voy a lanzar std::runtime_error que es una excepcion
            // estandar que me permite pasarle un mensaje simple
            // a su constructor
            throw std::runtime_error("Unexpected closed");
        }
        else {
            // Ok, recibimos algo pero no necesariamente todo lo que
            // esperamos. La condicion del while checkea eso justamente
            received += s;
        }
    } catch (const LibError& err) {
        throw LibError(err.error_code, "Socket recvall failed (len %d/%d): ", received, sz);
    }

    return sz;
}


int Socket::sendall(const void *data, unsigned int sz, bool *was_closed) {
    unsigned int sent = 0;
    *was_closed = false;

    while (sent < sz) try {
        int s = this->sendsome((char*)data + sent, sz - sent, was_closed);
        if (s == 0) {
            // Si el socket fue cerrado (s == 0) pero es claro que no logramos
            // enviar todo lo que queriamos enviar por lo que supondremos
            // que es un error y lanzamos una excepcion.
            //
            // Podriamos crear nuestra propia clase UnexpectedClosed pero
            // por simplicidad voy a lanzar std::runtime_error que es una excepcion
            // estandar que me permite pasarle un mensaje simple
            // a su constructor
            throw std::runtime_error("Unexpected closed");
        } else {
            sent += s;
        }
    } catch (const LibError& err) {
        throw LibError(err.error_code, "Socket sendall failed (len %d/%d): ", sent, sz);
    }

    return sz;
}

Socket Socket::accept() {
    int skt = ::accept(this->skt, nullptr, nullptr);
    if (skt == -1)
        throw LibError(errno, "Socket accept failed: ");

    /*
     * Creamos un Socket en el scope de Socket::accept() y lo retornamos.
     * Por default C y C++ harian una copia pero copiar un Socket no tiene
     * sentido y ya tenemos al constructor por copia deshabilitado
     * asi que no funcionara.
     *
     * Lo que queremos es que este Socket siga vivo y se mueva al scope
     * superior (a quien llamo a Socket::accept().
     *
     * Este es el corazon de Move Semantics.
     * */
    return Socket(skt);
}

void Socket::shutdown(int how) {
    if (::shutdown(this->skt, how) == -1) {
        throw LibError(errno, "Socket shutdown failed: ");
    }
}

int Socket::close() {
    // Aunque estrictamente uno deberia chequear el codigo de error
    // de close(), el hecho es que no hay mucho que se pueda hacer
    // al respecto.
    this->closed = true;
    return ::close(this->skt);
}

Socket::~Socket() {
    if (not this->closed) {
        // Aunque estrictamente uno deberia chequear el codigo de error
        // de shutdown() y close(), el hecho es que no hay mucho que se pueda hacer
        // al respecto.
        // Es mas, intentar lanzar una excepcion desde un destructor lleva
        // al programa abortar asi que lo mejor es dejarlo asi.
        ::shutdown(this->skt, 2);
        ::close(this->skt);
    }
}

Socket::Socket(Socket&& other) {
    this->skt = other.skt;
    this->closed = other.closed;

    // Le robamos al otro socket su file descriptor.
    // A partir de aqui somos nosotros (this) los dueños
    // del recurso.
    //
    // Hubo una transferencia de ownership y por lo tanto
    // debemos hacer que el destructor del otro socket no
    // libere los recursos.
    //
    // Para Socket con esto alcanza (mirate Resolver)
    other.skt = -1;
    other.closed = true;
}

Socket& Socket::operator=(Socket&& other) {
    // Este es un caso borde donde alguien codeo
    //  skt = skt;
    //
    // Si alguien quiere "moverse a si mismo" no hacemos nada.
    if (this == &other)
        return *this;

    // A diferencia del constructor por movimiento, nosotros
    // somos un objeto ya construido.
    // Antes de tomar el ownership del otro socket debemos
    // liberar nuestro propio recurso.
    // Al igual que en ~Socket() no chequeamos errores.
    if (not this->closed) {
        ::shutdown(this->skt, 2);
        ::close(this->skt);
    }

    // A partir de aqui hacemos lo mismo que en el constructor
    // por movimiento.
    //
    // Le robamos el recurso al otro, transferimos el ownership
    // del recurso del otro socket hacia el nuestro.
    this->skt = other.skt;
    this->closed = other.closed;

    other.skt = -1;
    other.closed = true;

    return *this;
}
