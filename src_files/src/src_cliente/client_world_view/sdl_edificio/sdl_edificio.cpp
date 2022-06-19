#include "sdl_edificio.h"

void EdificioSDL::setearPosicionUI(uint32_t origen_movil_x, uint32_t origen_movil_y) {
    destino_ui.SetX(coords.x * LARGO_TILE * zoom - origen_movil_x);
    destino_ui.SetY(coords.y * LARGO_TILE * zoom - origen_movil_y);
    destino_ui.SetW(LARGO_TILE * ancho * zoom);
    destino_ui.SetH(LARGO_TILE * alto * zoom);
}

void EdificioSDL::renderRectanguloSeleccion() {
    renderer.SetDrawColor(255, 255, 255);
        int largo_lineas_seleccionado = destino_ui.GetW() * RATIO_LINEAS_LARGO;

        renderer.DrawLine(
            destino_ui.GetX(), destino_ui.GetY(),
            destino_ui.GetX() + largo_lineas_seleccionado, destino_ui.GetY()
        );
        renderer.DrawLine(
            destino_ui.GetX(), destino_ui.GetY(),
            destino_ui.GetX(), destino_ui.GetY() + largo_lineas_seleccionado
        );
        renderer.DrawLine(
            destino_ui.GetX() + destino_ui.GetW(), destino_ui.GetY(),
            destino_ui.GetX() + destino_ui.GetW() - largo_lineas_seleccionado, destino_ui.GetY()
        );
        renderer.DrawLine(
            destino_ui.GetX() + destino_ui.GetW(), destino_ui.GetY(),
            destino_ui.GetX() + destino_ui.GetW(), destino_ui.GetY() + largo_lineas_seleccionado
        );
        renderer.DrawLine(
            destino_ui.GetX(), destino_ui.GetY() + destino_ui.GetH(),
            destino_ui.GetX(), destino_ui.GetY() + destino_ui.GetH() - largo_lineas_seleccionado
        );
        renderer.DrawLine(
            destino_ui.GetX(), destino_ui.GetY() + destino_ui.GetH(),
            destino_ui.GetX() + largo_lineas_seleccionado, destino_ui.GetY() + destino_ui.GetH()
        );
        renderer.DrawLine(
            destino_ui.GetX() + destino_ui.GetW(), destino_ui.GetY() + destino_ui.GetH(),
            destino_ui.GetX() + destino_ui.GetW(), destino_ui.GetY() + destino_ui.GetH() - largo_lineas_seleccionado
        );
        renderer.DrawLine(
            destino_ui.GetX() + destino_ui.GetW(), destino_ui.GetY() + destino_ui.GetH(),
            destino_ui.GetX() + destino_ui.GetW() - largo_lineas_seleccionado, destino_ui.GetY() + destino_ui.GetH()
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
