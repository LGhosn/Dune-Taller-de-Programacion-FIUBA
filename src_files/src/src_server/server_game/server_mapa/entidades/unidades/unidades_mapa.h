#ifndef UNIDADES_H
#define UNIDADES_H

#include <cstdint>

#include "../entidades_mapa.h"

class UnidadesMapa : public Entidades {
protected:
    char parada_sobre;
    uint16_t id_jugador;
    char tipo_entidad;

public:
    UnidadesMapa(char parada_sobre);
    virtual char obtenerIdentificador();
    virtual char obtenerTerrenoQueEstaParada();
    virtual char obtenerTipoDeEntidad();
    virtual uint16_t obtenerIdJugador();
    virtual ~UnidadesMapa() = default;
};

#endif // UNIDADES_H
