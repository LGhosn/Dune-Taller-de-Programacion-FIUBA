#include "sdl_fabrica_ligera.h"

FabricaLigeraSDL::FabricaLigeraSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                       TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
                       uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color) :
                    EdificioSDL(id, id_jugador, renderer, texturas.obtenerEdificio(2, casa, false),
                    texturas.obtenerEdificio(2, casa, true), coords, alto, ancho, casa,
                    constantes, color, texturas.obtenerSlab()),
                textura_paredes(texturas.obtenerParedesFabricaLigera(casa)),
                padding_edificio_y(constantes["WorldView"]["Edificios"]["FabricaLigera"]["PaddingY"].as<uint32_t>()),
                limite_hp_debilitar(constantes["WorldView"]["Edificios"]["FabricaLigera"]["LimiteHPDebilitar"].as<uint32_t>()) {}

void FabricaLigeraSDL::cambiarHP(uint16_t hp_edificio) {
    if (hp_edificio < limite_hp_debilitar)
        debilitado = true;
}

void FabricaLigeraSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_actual,
                                float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * ancho_tile * zoom - origen_movil_x);
    destino.SetY((coords.y * largo_tile + padding_edificio_y) * zoom - origen_movil_y);
    destino.SetW(ancho_tile * ancho * zoom);
    destino.SetH((largo_tile * alto - 2 * padding_edificio_y) * zoom);
    setearPosicionUI(origen_movil_x, origen_movil_y);
}

void FabricaLigeraSDL::render() {
    renderCimientos();
    renderer.Copy(textura_paredes, SDL2pp::NullOpt, destino);
    if (debilitado)
        renderer.Copy(textura_debilitado, SDL2pp::NullOpt, destino);
    else
        renderer.Copy(textura, SDL2pp::NullOpt, destino);    
}
