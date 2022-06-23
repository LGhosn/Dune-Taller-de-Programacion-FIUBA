#include "sdl_colores.h"

#define RUTA_COLORES RESOURCE_PATH "/constantes/client_colores.yaml"

#define CANT_COLORES 10

uint8_t ColoresSDL::obtenerIdColor(uint8_t id_jugador) {
    return id_jugador % CANT_COLORES;
}

ColoresSDL::ColoresSDL() {
    YAML::Node archivo_colores = YAML::LoadFile(RUTA_COLORES);
    for (uint8_t i = 0; i < CANT_COLORES; i++) {
        colores.emplace_back(archivo_colores, i);
    }
}

ColorSDL& ColoresSDL::obtenerColor(uint8_t id_jugador) {
    uint8_t id_color = obtenerIdColor(id_jugador);
    return colores[id_color];
}
