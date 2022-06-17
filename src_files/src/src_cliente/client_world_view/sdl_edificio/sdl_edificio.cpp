#include "sdl_edificio.h"

EdificioSDL::EdificioSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                SDL2pp::Texture& textura, const Coordenadas& coords,
                uint16_t alto, uint16_t ancho, uint8_t casa) :
                id(id), id_jugador(id_jugador), renderer(renderer), textura(textura),
                coords(coords), alto(alto), ancho(ancho) {}

Coordenadas EdificioSDL::obtenerDimensiones() const {
    return Coordenadas(ancho, alto);
}

void EdificioSDL::renderUI() {
    if (seleccionado) {
        renderer.SetDrawColor(255, 255, 255);
        renderer.DrawRect(
            pos_actual_x,
            pos_actual_y,
            pos_actual_x + tam_actual_x,
            pos_actual_y + tam_actual_y
        );
        renderer.SetDrawColor(90, 146, 22);
        renderer.FillRect(
            pos_actual_x + (tam_actual_x - ANCHO_HP) / 2,
            pos_actual_y + OFFSET_HP_Y,
            pos_actual_x + (tam_actual_x + ANCHO_HP) / 2,
            pos_actual_y + OFFSET_HP_Y + ALTO_HP
        );
        renderer.SetDrawColor(0, 0, 0);
        renderer.DrawRect(
            pos_actual_x + (tam_actual_x - ANCHO_HP) / 2,
            pos_actual_y + OFFSET_HP_Y,
            pos_actual_x + (tam_actual_x + ANCHO_HP) / 2,
            pos_actual_y + OFFSET_HP_Y + ALTO_HP
        );
    }
}

void EdificioSDL::seleccionar() {
    seleccionado = true;
}

void EdificioSDL::deseleccionar() {
    seleccionado = false;
}
