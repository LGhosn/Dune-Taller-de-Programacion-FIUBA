#ifndef CMD_CREAR_EDIFICIO_H
#define CMD_CREAR_EDIFICIO_H

#include <stdint.h>
#include "../client_world_view/world_view.h"
#include "../../src_common/common_coords.h"
#include "client_comando.h"

class CrearEdificio : public ComandoCliente {
    uint16_t id;
    Coordenadas coords;
    uint8_t tipo;
    uint8_t id_jugador;
public:
    CrearEdificio(uint16_t id, uint8_t id_jugador, Coordenadas& coords, uint8_t tipo);
    bool ejecutar(WorldView& worldView) const override;

    ~CrearEdificio() = default;
};


#endif
