#include "sdl_silo.h"

SiloSDL::SiloSDL(uint8_t id, uint8_t id_jugador, uint16_t vida, SDL2pp::Renderer& renderer,
            TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
            uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color):
            EdificioSDL(id, id_jugador, vida,renderer, texturas.obtenerFramesSilo(casa)[0],
                    texturas.obtenerEdificio(6, casa, true), coords, alto, ancho, casa,
                    constantes, color, texturas.obtenerSlab()),
            silos(texturas.obtenerFramesSilo(casa)),
            limite_hp_debilitar(constantes["WorldView"]["Edificios"]["Silo"]["LimiteHPDebilitar"].as<uint32_t>()) {}

bool SiloSDL::cambiarHP(uint16_t hp_edificio) {
    vida_restante = hp_edificio;
    if (hp_edificio < limite_hp_debilitar) {
        debilitado = true;
        return true;
    }
    return false;
}

void SiloSDL::cambiarCantidadEspecia(uint8_t estado_especia) {
    this->estado_especia = estado_especia;
}

void SiloSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_transcurridos, float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * ancho_tile * zoom - origen_movil_x);
    destino.SetY(coords.y * largo_tile * zoom - origen_movil_y);
    destino.SetW(ancho_tile * ancho * zoom);
    destino.SetH(largo_tile * alto * zoom);
    setearPosicionUI(origen_movil_x, origen_movil_y);
}

void SiloSDL::render() {
    renderCimientos();
    if (debilitado)
        renderer.Copy(textura_debilitado, SDL2pp::NullOpt, destino);
    else
        renderer.Copy(silos[estado_especia], SDL2pp::NullOpt, destino);   
}
