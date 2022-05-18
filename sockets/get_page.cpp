#include <iostream>
#include "socket.h"
#include "resolvererror.h"
#include "liberror.h"

#include <chrono>
#include <thread>
#include <exception>

/*
 * Este mini ejemplo se conecta via TCP a www.google.com.ar y se descarga una
 * pagina web.
 *
 * Esta codeado "a la C" por lo que veras muchas cosas hechas "a mano".
 * En particular veras como se manejan los errores en C con el uso de goto.
 *
 * El patron es el siguiente:
 *
 *  - reservo recurso A
 *  - si fallo, goto "after-A"
 *      - reservo recurso B
 *      - si fallo, goto "after-B"
 *          - reservo recurso C
 *          - si fallo, goto "after-C"
 *              ....
 *          - destruyo C
 *      - destruyo B                    ["after-C"]
 *  - destruyo A                        ["after-B"]
 *  - fin                               ["after-A"]
 *
 * Este patron de inicializacion y destruccion con goto evita:
 *  - tener que destruir el recurso en mas de un lugar (nos podriamos olvidar
 *    y tener un leak)
 *  - el riesgo de destruir algo que no fue inicializado (que nos daria
 *    un "use uninitialized variable"
 *
 * Ahora es claro que este esquema de goto es *muy manual*.
 *
 * En Golang podras usar los "defer" para mitigar el problema. En C++ y en Rust
 * tendras RAII para resolverlo completamente (RAII = Resource Acquisition is Initialization)
 * */
int main() try {
    int ret = -1;
    bool was_closed = false;

    const char req[] = "GET / HTTP/1.1\r\nAccept: */*\r\nConnection: close\r\nHost: www.google.com.ar\r\n\r\n";

    /*
     * Inicializamos el socket para que se conecte a google.com
     * contra el servicio http.
     *
     * Si la conexion falla, se lanzara una excepcion y cerramos el programa.
     * Al ser Socket RAII y estar instanciado en el stack su destructor
     * no se llamara si se lanza una excepcion dentro del destructor
     * (asi no liberaremos los recursos que no fueron reservados)
     *
     * En el caso de un error de resolucion temporal hacemos un pequeño retry.
     * Es una excusa para practicar try/catch y move semantics.
     * */
    int retries = 3;
    Socket skt;
    while (true) try {
        Socket tmp("www.google.com.ar", "http");

        // Move semantics: movemos el socket del scope del try/catch (tmp)
        // afuera, al scope del main (skt).
        skt = std::move(tmp);
        break;
    } catch (const ResolverError& err) {
        --retries;
        // Si el error no es temporal o se agotaron los intentos, continuamos
        // propagando al excepcion.
        // La instruccion throw sin argumentos hace que la excepcion actual (err)
        // continue (no estamos lanzando otra excepcion)
        if (not err.is_temporal_failure() or retries < 0)
            throw;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    /*
     * Enviamos el HTTP Request, el pedido de pagina web. Como sabemos
     * que no queremos enviar nada mas podemos usar socket_sendall()
     * para que envie todo.
     * En caso que el send() no pueda enviar todo de un solo golpe,
     * socket_sendall() fue codeada para hacer "el loop" por nosotros.
     * */
    skt.sendall(req, sizeof(req) - 1, &was_closed);

    /*
     * Iteramos leyendo/recibiendo de a cachos la pagina web.
     * No podemos usar socket_recvall() ya que no sabemos a priori
     * el tamaño de la respuesta.
     * Notese ademas que con socket_recvsome() no se exige q la respuesta
     * tenga exactamente el size del buffer: sera nuestro trabajo hacer
     * el loop aqui.
     * */
    char buf[512];
    while (not was_closed) {
        int r = skt.recvsome(buf, sizeof(buf) - 1, &was_closed);
        if (was_closed)
            break;

        /*
         * Recorda que con sockets se envian/reciben *bytes*, no texto.
         * La respuesta de google seran bytes y no necesariamente terminaran
         * en un \0 asi que es necesario poner ese "fin de string" nosotros.
         * */
        buf[r] = 0;
        std::cout << buf;
    }

    ret = 0;

    // Por que instanciamos el Socket en el stack, cuando la funcion main()
    // termine se llamara al destructor de Socket automaticamente
    // lo que significa que no tenemos que acordarnos de liberar
    // las cosas.
    // Esto sucede incluso si se lanzo una excepcion.
    // Este es el poder de RAII (Resource Acquisition is Initialization)
    return ret;
} catch (const std::exception& err) {
    // Si una excepcion se escapa por fuera de main() o por fuera del main de un
    // thread, el programa aborta lo cual no es bonito.
    // Lo mas prolijo es logguear que excepcion sucedio y finalizar
    // con un codigo de error.
    // En este caso estoy usando stderr pero tal vez algo mas profesional
    // seria usar algun sistema de logging como syslog.
    std::cerr << "Something went wrong and an exception was caught: " << err.what() << "\n";
    return -1;
} catch (...) {
    // En C++ no hay restriccion en que es una excepcion: uno puede lanzar
    // cualquier cosa incluso primitivos como ints.
    // Lanzar algo que herede de std::exception es opcional pero altamente
    // recomendable ya que uno puede atrapar la excepcion e invocar what()
    // para obtener un mensaje descriptivo.
    //
    // Aun asi es importante considerar el caso en que la excepcion sea de un
    // tipo que no sabemos, incluyendo uno primitivo.
    //
    // Para atrapar dichas excepciones se usa elipsis (...).
    //
    // Dado que no sabemes de que excepcion se trata loggueamos un mensaje
    // generico.
    std::cerr << "Something went wrong and an unknown exception was caught.\n";
    return -1;
}
