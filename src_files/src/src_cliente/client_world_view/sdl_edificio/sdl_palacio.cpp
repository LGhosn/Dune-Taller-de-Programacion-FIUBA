#include "sdl_palacio.h"

PalacioSDL::PalacioSDL(uint8_t id, uint8_t id_jugador, uint16_t vida, SDL2pp::Renderer& renderer,
                        TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
                        uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color):
                        EdificioSDL(id, id_jugador, vida, renderer, texturas.obtenerEdificio(4, casa, false),
                        texturas.obtenerEdificio(4, casa, true), coords, alto, ancho, casa, constantes,
                        color, texturas.obtenerSlab()),
                        limite_hp_debilitar(constantes["WorldView"]["Edificios"]["Palacio"]["LimiteHPDebilitar"].as<uint32_t>()),
                        offset_y(constantes["WorldView"]["Edificios"]["Palacio"]["OffsetY"].as<int32_t>()) {}

bool PalacioSDL::cambiarHP(uint16_t hp_edificio) {
    vida_restante = hp_edificio;
    if (hp_edificio < limite_hp_debilitar) {
        debilitado = true;
        return true;
    }
    return false;
}

void PalacioSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_transcurridos, float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * ancho_tile * zoom - origen_movil_x);
    destino.SetY((coords.y * largo_tile + offset_y) * zoom - origen_movil_y);
    destino.SetW(ancho * ancho_tile * zoom);
    destino.SetH(destino.GetW() * textura.GetWidth() / textura.GetHeight());
    setearPosicionUI(origen_movil_x, origen_movil_y);
}

void PalacioSDL::render() {
    renderCimientos();
    if (debilitado)
        renderer.Copy(textura_debilitado, SDL2pp::NullOpt, destino);
    else
        renderer.Copy(textura, SDL2pp::NullOpt, destino);
}
