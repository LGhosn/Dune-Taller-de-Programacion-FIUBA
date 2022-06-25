#include "sdl_cuartel.h"

CuartelSDL::CuartelSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                       TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
                       uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color) :
                    EdificioSDL(id, id_jugador, renderer, texturas.obtenerEdificio(1, casa, false),
                    texturas.obtenerEdificio(1, casa, true), coords, alto, ancho, casa,
                    constantes, color, texturas.obtenerSlab()),
                    padding_y(constantes["WorldView"]["Edificios"]["Cuartel"]["PaddingY"].as<uint32_t>()),
                    limite_hp_debilitar(constantes["WorldView"]["Edificios"]["Cuartel"]["LimiteHPDebilitar"].as<uint32_t>()) {}

void CuartelSDL::cambiarHP(uint16_t hp_edificio) {
    if (hp_edificio < limite_hp_debilitar)
        debilitado = true;
}

void CuartelSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_actual, float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * ancho_tile * zoom - origen_movil_x);
    destino.SetY((coords.y * largo_tile + padding_y) * zoom - origen_movil_y);
    destino.SetW(ancho_tile * ancho * zoom);
    destino.SetH((largo_tile * alto - 2 * padding_y) * zoom);
    setearPosicionUI(origen_movil_x, origen_movil_y);
}

void CuartelSDL::render() {
    renderCimientos();
    if (debilitado)
        renderer.Copy(textura_debilitado, SDL2pp::NullOpt, destino);
    else
        renderer.Copy(textura, SDL2pp::NullOpt, destino);
}
