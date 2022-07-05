#include "sdl_refineria.h"

RefineriaSDL::RefineriaSDL(uint8_t id, uint8_t id_jugador, uint16_t vida, SDL2pp::Renderer& renderer,
                       TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
                       uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color) :
                    EdificioSDL(id, id_jugador, vida, renderer, texturas.obtenerEdificio(5, casa, false),
                    texturas.obtenerEdificio(5, casa, true), coords, alto, ancho, casa,
                    constantes, color, texturas.obtenerSlab()),
                textura_paredes(texturas.obtenerParedesRefineria(casa)),
                padding_edificio_y(constantes["WorldView"]["Edificios"]["Refineria"]["PaddingY"].as<uint32_t>()),
                limite_hp_debilitar(constantes["WorldView"]["Edificios"]["Refineria"]["LimiteHPDebilitar"].as<uint32_t>()) {}

bool RefineriaSDL::cambiarHP(uint16_t hp_edificio) {
    vida_restante = hp_edificio;
    if (hp_edificio < limite_hp_debilitar) {
        debilitado = true;
        return true;
    }
    return false;
}

void RefineriaSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_transcurridos,
                            float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * ancho_tile * zoom - origen_movil_x);
    destino.SetY((coords.y * largo_tile + padding_edificio_y) * zoom - origen_movil_y);
    destino.SetW(ancho_tile * ancho * zoom);
    destino.SetH((largo_tile * alto - 2 * padding_edificio_y) * zoom);
    setearPosicionUI(origen_movil_x, origen_movil_y);
}

void RefineriaSDL::render() {
    renderCimientos();
    renderer.Copy(textura_paredes, SDL2pp::NullOpt, destino);
    if (debilitado)
        renderer.Copy(textura_debilitado, SDL2pp::NullOpt, destino);
    else
        renderer.Copy(textura, SDL2pp::NullOpt, destino);    
}
