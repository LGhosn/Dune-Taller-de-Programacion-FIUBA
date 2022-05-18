#ifndef RESOLVER_ERROR_H
#define RESOLVER_ERROR_H

#include <exception>

/*
 * Clase que encapsula un "gai" error. Vease getaddrinfo()
 * */
class ResolverError : public std::exception {
    int gai_errno;

    public:
    ResolverError(int gai_errno);

    virtual const char* what() const noexcept;

    bool is_temporal_failure() const noexcept;

    // Por que estamos heredando y usando polimorfismo
    // es importantisimo definir un destructor virtual
    // Estrictamente hablando basta con poner virtual al
    // destructor de la clase padre (std::exception) pero
    // GCC requiere de la definicion de los destructores
    // de las clases hijas para que pueda colocar la VTable.
    virtual ~ResolverError();
};
#endif
