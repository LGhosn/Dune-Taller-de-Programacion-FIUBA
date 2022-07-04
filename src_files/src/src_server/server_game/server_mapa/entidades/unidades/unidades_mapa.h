#ifndef UNIDADES_H
#define UNIDADES_H

#include <cstdint>

#include "../entidades_mapa.h"

class UnidadesMapa : public Entidades {
private:
    char parada_sobre;
    uint8_t id_jugador;
    uint8_t id_unidad;
    uint8_t tipo_unidad;
    char tipo_entidad;

public:
    UnidadesMapa(char parada_sobre, uint8_t id_jugador, uint8_t tipo_unidad, uint8_t id_unidad);
    virtual char obtenerIdentificador();
    virtual char obtenerTerrenoQueEstaParada();
    virtual char obtenerTipoDeEntidad();
    virtual uint8_t obtenerIdJugador();
    virtual uint8_t obtenerTipoDeUnidad();
    virtual uint8_t obtenerIdUnidad();
    virtual ~UnidadesMapa() = default;
};

#endif // UNIDADES_H
