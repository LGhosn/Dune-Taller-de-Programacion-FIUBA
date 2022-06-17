#include "cmd_crear_edificio.h"

ComandoCrearEdificio::ComandoCrearEdificio(ComandoCrearEdificioDTO &dto):
                            id_edificio(dto.id_edificio),
                            id_jugador(dto.id_jugador),
                            coords(dto.coords),
                            tipo(dto.tipo),
                            casa(dto.casa) {}

bool ComandoCrearEdificio::ejecutar(WorldView& world_view) const {
    world_view.crearEdificio(id_edificio, id_jugador, coords, tipo, casa);
    return true;
}
