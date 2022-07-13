#include "sdl_edificio.h"
#include <iostream>

void EdificioSDL::setearPosicionUI(uint32_t origen_movil_x, uint32_t origen_movil_y) {
    destino_ui.SetX(coords.x * ancho_tile * zoom - origen_movil_x);
    destino_ui.SetY(coords.y * largo_tile * zoom - origen_movil_y);
    destino_ui.SetW(ancho_tile * ancho * zoom);
    destino_ui.SetH(largo_tile * alto * zoom);
}

void EdificioSDL::renderCimientos() {
    for (uint8_t i = 0; i < ancho; i++) {
        for (uint8_t j = 0; j < alto; j++) {
            renderer.Copy(
                textura_slab,
                SDL2pp::NullOpt,
                SDL2pp::Rect(
                    destino_ui.GetX() + i * ancho_tile * zoom,
                    destino_ui.GetY() + j * largo_tile * zoom,
                    ancho_tile * zoom,
                    largo_tile * zoom
                )
            );
        }
    }
}

void EdificioSDL::renderRectanguloSeleccion() {
    renderer.SetDrawColor(255, 255, 255);
        int largo_lineas_seleccionado = destino_ui.GetW() * relacion_lineas_largo;

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
        destino.GetX() + padding_x_hp * zoom,
        destino.GetY() + (offset_y_hp - alto_hp) * zoom,
        destino.GetX() + destino.GetW() - padding_x_hp * zoom,
        destino.GetY() + offset_y_hp * zoom
    );

    float porcentaje_restante = (float) vida_restante / (float) vida_total;
    renderer.SetDrawColor(color.obtenerPrimario());
    renderer.FillRect(
        destino.GetX() + (padding_x_hp + padding_rect_hp) * zoom,
        destino.GetY() + (offset_y_hp - alto_hp + padding_rect_hp) * zoom,
        destino.GetX() + destino.GetW() * porcentaje_restante - (padding_x_hp + padding_rect_hp) * zoom,
        destino.GetY() + (offset_y_hp - padding_rect_hp) * zoom
    );

    renderer.SetDrawColor(0, 0, 0);
    renderer.DrawRect(
        destino.GetX() + padding_x_hp * zoom,
        destino.GetY() + (offset_y_hp - alto_hp)  * zoom,
        destino.GetX() + destino.GetW() - padding_x_hp * zoom,
        destino.GetY() + offset_y_hp * zoom
    );
}

EdificioSDL::EdificioSDL(uint8_t id, uint8_t id_jugador, uint16_t vida,
                        SDL2pp::Renderer& renderer, SDL2pp::Texture& textura,
                        SDL2pp::Texture& textura_debilitado,
                        const Coordenadas& coords, uint16_t alto, uint16_t ancho,
                        uint8_t casa, YAML::Node& constantes, ColorSDL& color,
                        SDL2pp::Texture& textura_slab) :
        id(id), id_jugador(id_jugador), vida_restante(vida), vida_total(vida), renderer(renderer),
        textura(textura),textura_debilitado(textura_debilitado), textura_slab(textura_slab),
        color(color), coords(coords), alto(alto), ancho(ancho),
        alto_hp(constantes["WorldView"]["Edificios"]["UI"]["HP"]["Alto"].as<int>()),
        ancho_hp(constantes["WorldView"]["Edificios"]["UI"]["HP"]["Ancho"].as<int>()),
        offset_x_hp(constantes["WorldView"]["Edificios"]["UI"]["HP"]["OffsetX"].as<int>()),
        offset_y_hp(constantes["WorldView"]["Edificios"]["UI"]["HP"]["OffsetY"].as<int>()),
        padding_x_hp(constantes["WorldView"]["Edificios"]["UI"]["HP"]["PaddingX"].as<int>()),
        padding_rect_hp(constantes["WorldView"]["Edificios"]["UI"]["HP"]["PaddingRect"].as<int>()),
        relacion_lineas_largo(constantes["WorldView"]["Edificios"]["UI"]["RelacionLineasLargo"].as<float>()),
        ancho_tile(constantes["WorldView"]["Mapa"]["Tiles"]["Largo"].as<int>()),
        largo_tile(constantes["WorldView"]["Mapa"]["Tiles"]["Largo"].as<int>()),
        codigo_atreides(constantes["Casas"]["Atreides"].as<uint8_t>()),
        codigo_harkonnen(constantes["Casas"]["Harkonnen"].as<uint8_t>()),
        codigo_ordos(constantes["Casas"]["Ordos"].as<uint8_t>()) {}

Coordenadas EdificioSDL::obtenerDimensiones() const {
    return Coordenadas(ancho, alto);
}

void EdificioSDL::renderUI() {
    if (seleccionado) {
        renderRectanguloSeleccion();
    }
    renderHP();
}

void EdificioSDL::seleccionar() {
    seleccionado = true;
}

void EdificioSDL::deseleccionar() {
    seleccionado = false;
}

bool EdificioSDL::contiene(uint32_t pos_x, uint32_t pos_y) const {
    return destino_ui.Contains(pos_x, pos_y);
}

uint8_t EdificioSDL::obtenerId() const {
    return id;
}

uint8_t EdificioSDL::obtenerIdJugador() const {
    return id_jugador;
}
