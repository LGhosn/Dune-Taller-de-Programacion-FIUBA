#include "sdl_fabrica_pesada.h"

FabricaPesadaSDL::FabricaPesadaSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                       TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
                       uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color) :
                    EdificioSDL(id, id_jugador, renderer, texturas.obtenerEdificio(3, casa, false),
                    texturas.obtenerEdificio(3, casa, true), coords, alto, ancho, casa,
                    constantes, color, texturas.obtenerSlab()),
                    textura_paredes(texturas.obtenerParedesFabricaPesada(casa)),
                    padding_edificio_y(constantes["WorldView"]["Edificios"]["FabricaPesada"]["PaddingY"].as<uint32_t>()),
                    limite_hp_debilitar(constantes["WorldView"]["Edificios"]["FabricaPesada"]["LimiteHPDebilitar"].as<uint32_t>()),
                    offset_paredes_x(constantes["WorldView"]["Edificios"]["FabricaPesada"]["Paredes"]["OffsetX"].as<int32_t>()),
                    offset_paredes_y(constantes["WorldView"]["Edificios"]["FabricaPesada"]["Paredes"]["OffsetY"].as<int32_t>()),
                    offset_paredes_tam_x(constantes["WorldView"]["Edificios"]["FabricaPesada"]["Paredes"]["OffsetTamX"].as<int32_t>()) {}

void FabricaPesadaSDL::cambiarHP(uint16_t hp_edificio) {
    if (hp_edificio < limite_hp_debilitar)
        debilitado = true;
}

void FabricaPesadaSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y,
                                long frame_transcurridos, float zoom) {
    this->zoom = zoom;
    destino.SetW(ancho_tile * ancho * zoom);
    destino.SetH(destino.GetW() * textura.GetHeight() / textura.GetWidth());
    destino.SetX(coords.x * ancho_tile * zoom - origen_movil_x);
    destino.SetY((coords.y * largo_tile + padding_edificio_y) * zoom - origen_movil_y);
    destino_paredes.SetX((coords.x * ancho_tile + offset_paredes_x) * zoom - origen_movil_x);
    destino_paredes.SetY((coords.y * largo_tile + offset_paredes_y + padding_edificio_y) * zoom - origen_movil_y);
    destino_paredes.SetW(destino.GetW() + offset_paredes_tam_x * zoom);
    destino_paredes.SetH(destino_paredes.GetW() * textura_paredes.GetHeight() / textura_paredes.GetWidth());
    setearPosicionUI(origen_movil_x, origen_movil_y);
}

void FabricaPesadaSDL::render() {
    renderCimientos();
    renderer.Copy(textura_paredes, SDL2pp::NullOpt, destino_paredes);
    if (debilitado)
        renderer.Copy(textura_debilitado, SDL2pp::NullOpt, destino);
    else
        renderer.Copy(textura, SDL2pp::NullOpt, destino);
    
}
