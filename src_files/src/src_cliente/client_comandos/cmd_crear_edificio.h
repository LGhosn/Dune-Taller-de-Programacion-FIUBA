#ifndef CMD_CREAR_EDIFICIO_H
#define CMD_CREAR_EDIFICIO_H

#include <stdint.h>
#include "../client_world_view/world_view.h"
#include "../client_DTO/dto_cmd_crear_edificio.h"
#include "../../src_common/common_coords.h"
#include "client_comando.h"

class ComandoCrearEdificio : public ComandoCliente {
    uint8_t id_edificio;
    uint8_t id_jugador;
    Coordenadas coords;
    uint8_t tipo;
    uint8_t casa;
    uint16_t vida;
public:
    ComandoCrearEdificio(ComandoCrearEdificioDTO& dto);
    virtual bool ejecutar(WorldView& worldView) const override;

    virtual ~ComandoCrearEdificio() = default;
};


#endif
