#include "cmd_crear_edificio.h"

CrearEdificio::CrearEdificio(uint16_t id, uint8_t id_jugador, Coordenadas& coords, uint8_t tipo):
id(id), id_jugador(id_jugador), coords(coords), tipo(tipo) {}

bool CrearEdificio::ejecutar(WorldView& world_view) const {
    world_view.crearEdificio(id, id_jugador, coords, tipo);
    return true;
}
