#ifndef ENTIDADES_H
#define ENTIDADES_H

#include <cstdint>

class Entidades {
protected:
    char tipo;
    
public:
    Entidades() = default;
    virtual char obtenerIdentificador() = 0;
    virtual char obtenerTipoDeEntidad() = 0;
    virtual uint16_t obtenerIdJugador() = 0;
    virtual ~Entidades() = default;
};

#endif // ENTIDADES_H
