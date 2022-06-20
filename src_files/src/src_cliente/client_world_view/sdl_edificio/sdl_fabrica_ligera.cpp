#include "sdl_fabrica_ligera.h"

FabricaLigeraSDL::FabricaLigeraSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                SDL2pp::Texture& textura, const Coordenadas& coords, uint16_t alto,
                uint16_t ancho, uint8_t casa,YAML::Node& constantes) :
                EdificioSDL(id, id_jugador, renderer, textura, coords, alto, ancho,
                            casa, constantes),
                ancho_edificio(constantes["WorldView"]["Edificios"]["FabricaLigera"]["Ancho"].as<uint32_t>()),
                alto_edificio(constantes["WorldView"]["Edificios"]["FabricaLigera"]["Alto"].as<uint32_t>()),
                padding_edificio_y(constantes["WorldView"]["Edificios"]["FabricaLigera"]["PaddingY"].as<uint32_t>()),
                limite_hp_debilitar(constantes["WorldView"]["Edificios"]["FabricaLigera"]["LimiteHPDebilitar"].as<uint32_t>()),
                offset_paredes_x(constantes["WorldView"]["Edificios"]["FabricaLigera"]["Paredes"]["OffsetX"].as<int32_t>()),
                offset_paredes_y(constantes["WorldView"]["Edificios"]["FabricaLigera"]["Paredes"]["OffsetY"].as<int32_t>()) {
    origen.SetX(ancho_edificio);
    origen_paredes.SetX(0);
    if (casa == codigo_atreides) {
        origen.SetY(0);
        origen_paredes.SetY(0);
    } else if (casa == codigo_harkonnen) {
        origen.SetY(alto_edificio);
        origen_paredes.SetY(alto_edificio);
    } else if (casa == codigo_ordos) {
        origen.SetY(alto_edificio * 2);
        origen_paredes.SetY(alto_edificio * 2);
    } else {
        throw std::runtime_error("FabricaLigeraSDL: Casa no reconocida");
    }
    origen.SetW(ancho_edificio);
    origen.SetH(alto_edificio);
    origen_paredes.SetW(ancho_edificio);
    origen_paredes.SetH(alto_edificio);
}

void FabricaLigeraSDL::cambiarHP(uint16_t hp_edificio) {
    if (hp_edificio < limite_hp_debilitar) {
        origen.SetX(2 * ancho_edificio);
    }
}

void FabricaLigeraSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_actual,
                                float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * ancho_tile * zoom - origen_movil_x);
    destino.SetY((coords.y * largo_tile + padding_edificio_y) * zoom - origen_movil_y);
    destino.SetW(ancho_tile * ancho * zoom);
    destino.SetH((largo_tile * alto - 2 * padding_edificio_y) * zoom);
    destino_paredes.SetX((coords.x * ancho_tile + offset_paredes_x) * zoom - origen_movil_x);
    destino_paredes.SetY((coords.y * largo_tile + offset_paredes_y) * zoom - origen_movil_y);
    destino_paredes.SetW(destino.GetW());
    destino_paredes.SetH(destino.GetH());
    setearPosicionUI(origen_movil_x, origen_movil_y);
}

void FabricaLigeraSDL::render() {
    renderer.Copy(textura, origen, destino);
    renderer.Copy(textura, origen_paredes, destino_paredes);
}