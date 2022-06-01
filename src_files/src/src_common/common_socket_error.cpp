#include <cerrno>
#include <cstdarg>
#include <cstring>
#include <cstdio>
#include "common_socket_error.h"

SocketError::SocketError() noexcept {
    /*
     * Debo copiar cuanto antes errno, cualquier llamada a una función de la STL
     * es capaz de cambiar el valor de la variable errno y modificar el tipo de mensaje.
     */
    int _errno = errno;
    strncpy(msg_error, strerror(_errno), BUFF_LEN);
    msg_error[BUFF_LEN - 1] = 0;
}

SocketError::SocketError(const char *fmt, ...) noexcept {
    int _errno = errno;
    /*
     * Argumentos variadicos. C/C++ tiene el feature de poder pasarle una cantidad arbitraria de parámetros
     * a una función, por medio de las elípsis (...). Para recuperar esta lista de variables tenemos que hacer
     * uso de la función vsnprintf, pasandolé la lista de argumentos variadicos.
     *
     * Este el mecanismo que usan funciones como printf para imprimir por salida estandar.
     */
    va_list args;
    // Inicializamos la lista de argumentos pasandolé como argumento
    // el ultimo argumento que nosotros recibimos fuera de la lista
    // variadica (de forma obligatoria debe existir al menos 1 argumento
    // fijo, que es el formato del mensaje)
    va_start(args, fmt);
    int s = vsnprintf(msg_error, BUFF_LEN, fmt, args);
    // liberamos los recursos
    va_end(args);

    // Appendeamos un separador para imprimir el errno
    // strncpy(msg_error+s, ": ", 2);
    // s+=2;

    strncpy(msg_error+s, strerror(_errno), BUFF_LEN-s);
    msg_error[BUFF_LEN - 1] = 0;
}

const char *SocketError::what() const noexcept {
    return this->msg_error;
}
