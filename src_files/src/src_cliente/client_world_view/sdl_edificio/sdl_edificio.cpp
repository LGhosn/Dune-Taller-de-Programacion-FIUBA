#include "sdl_edificio.h"

void EdificioSDL::renderRectanguloSeleccion() {
    renderer.SetDrawColor(255, 255, 255);
        int largo_lineas_seleccionado = tam_actual_x * RATIO_LINEAS_LARGO;

        renderer.DrawLine(
            pos_actual_x, pos_actual_y,
            pos_actual_x + largo_lineas_seleccionado, pos_actual_y
        );
        renderer.DrawLine(
            pos_actual_x, pos_actual_y,
            pos_actual_x, pos_actual_y + largo_lineas_seleccionado
        );
        renderer.DrawLine(
            pos_actual_x + tam_actual_x, pos_actual_y,
            pos_actual_x + tam_actual_x - largo_lineas_seleccionado, pos_actual_y
        );
        renderer.DrawLine(
            pos_actual_x + tam_actual_x, pos_actual_y,
            pos_actual_x + tam_actual_x, pos_actual_y + largo_lineas_seleccionado
        );
        renderer.DrawLine(
            pos_actual_x, pos_actual_y + tam_actual_y,
            pos_actual_x, pos_actual_y + tam_actual_y - largo_lineas_seleccionado
        );
        renderer.DrawLine(
            pos_actual_x, pos_actual_y + tam_actual_y,
            pos_actual_x + largo_lineas_seleccionado, pos_actual_y + tam_actual_y
        );
        renderer.DrawLine(
            pos_actual_x + tam_actual_x, pos_actual_y + tam_actual_y,
            pos_actual_x + tam_actual_x, pos_actual_y + tam_actual_y - largo_lineas_seleccionado
        );
        renderer.DrawLine(
            pos_actual_x + tam_actual_x, pos_actual_y + tam_actual_y,
            pos_actual_x + tam_actual_x - largo_lineas_seleccionado, pos_actual_y + tam_actual_y
        );
}

void EdificioSDL::renderHP() {
    renderer.SetDrawColor(0, 0, 0, 150);
    renderer.FillRect(
        pos_actual_x + PADDING_HP_X,
        pos_actual_y + OFFSET_HP_Y - ALTO_HP,
        pos_actual_x + tam_actual_x - PADDING_HP_X,
        pos_actual_y + OFFSET_HP_Y
    );

    renderer.SetDrawColor(90, 146, 22);
    renderer.FillRect(
        pos_actual_x + PADDING_HP_X + PADDING_HP_RECT,
        pos_actual_y + OFFSET_HP_Y - ALTO_HP + PADDING_HP_RECT,
        pos_actual_x + tam_actual_x - PADDING_HP_X - PADDING_HP_RECT,
        pos_actual_y + OFFSET_HP_Y - PADDING_HP_RECT
    );

    renderer.SetDrawColor(0, 0, 0);
    renderer.DrawRect(
        pos_actual_x + PADDING_HP_X,
        pos_actual_y + OFFSET_HP_Y - ALTO_HP,
        pos_actual_x + tam_actual_x - PADDING_HP_X,
        pos_actual_y + OFFSET_HP_Y
    );
}

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
        renderRectanguloSeleccion();
        renderHP();
    }
}

void EdificioSDL::seleccionar() {
    seleccionado = true;
}

void EdificioSDL::deseleccionar() {
    seleccionado = false;
}
