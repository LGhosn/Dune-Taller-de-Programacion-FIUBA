#include "sdl_edificio.h"

void EdificioSDL::renderRectanguloSeleccion() {
    renderer.SetDrawColor(255, 255, 255);
        int largo_lineas_seleccionado = destino.GetW() * RATIO_LINEAS_LARGO;

        renderer.DrawLine(
            destino.GetX(), destino.GetY(),
            destino.GetX() + largo_lineas_seleccionado, destino.GetY()
        );
        renderer.DrawLine(
            destino.GetX(), destino.GetY(),
            destino.GetX(), destino.GetY() + largo_lineas_seleccionado
        );
        renderer.DrawLine(
            destino.GetX() + destino.GetW(), destino.GetY(),
            destino.GetX() + destino.GetW() - largo_lineas_seleccionado, destino.GetY()
        );
        renderer.DrawLine(
            destino.GetX() + destino.GetW(), destino.GetY(),
            destino.GetX() + destino.GetW(), destino.GetY() + largo_lineas_seleccionado
        );
        renderer.DrawLine(
            destino.GetX(), destino.GetY() + destino.GetH(),
            destino.GetX(), destino.GetY() + destino.GetH() - largo_lineas_seleccionado
        );
        renderer.DrawLine(
            destino.GetX(), destino.GetY() + destino.GetH(),
            destino.GetX() + largo_lineas_seleccionado, destino.GetY() + destino.GetH()
        );
        renderer.DrawLine(
            destino.GetX() + destino.GetW(), destino.GetY() + destino.GetH(),
            destino.GetX() + destino.GetW(), destino.GetY() + destino.GetH() - largo_lineas_seleccionado
        );
        renderer.DrawLine(
            destino.GetX() + destino.GetW(), destino.GetY() + destino.GetH(),
            destino.GetX() + destino.GetW() - largo_lineas_seleccionado, destino.GetY() + destino.GetH()
        );
}

void EdificioSDL::renderHP() {
    renderer.SetDrawColor(0, 0, 0, 150);
    renderer.FillRect(
        destino.GetX() + PADDING_HP_X * zoom,
        destino.GetY() + (OFFSET_HP_Y - ALTO_HP) * zoom,
        destino.GetX() + destino.GetW() - PADDING_HP_X * zoom,
        destino.GetY() + OFFSET_HP_Y * zoom
    );

    renderer.SetDrawColor(90, 146, 22);
    renderer.FillRect(
        destino.GetX() + (PADDING_HP_X + PADDING_HP_RECT) * zoom,
        destino.GetY() + (OFFSET_HP_Y - ALTO_HP + PADDING_HP_RECT) * zoom,
        destino.GetX() + destino.GetW() - (PADDING_HP_X + PADDING_HP_RECT) * zoom,
        destino.GetY() + (OFFSET_HP_Y - PADDING_HP_RECT) * zoom
    );

    renderer.SetDrawColor(0, 0, 0);
    renderer.DrawRect(
        destino.GetX() + PADDING_HP_X * zoom,
        destino.GetY() + (OFFSET_HP_Y - ALTO_HP)  * zoom,
        destino.GetX() + destino.GetW() - PADDING_HP_X * zoom,
        destino.GetY() + OFFSET_HP_Y * zoom
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
