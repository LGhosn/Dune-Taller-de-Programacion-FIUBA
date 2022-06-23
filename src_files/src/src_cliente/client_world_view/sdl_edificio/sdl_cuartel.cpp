#include "sdl_cuartel.h"

CuartelSDL::CuartelSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                       SDL2pp::Texture& textura, const Coordenadas& coords, uint16_t alto,
                       uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color) :
                    EdificioSDL(id, id_jugador, renderer, textura, coords, alto, ancho,
                                casa, constantes, color),
                    ancho_edificio_atreides(constantes["WorldView"]["Edificios"]["Cuartel"]["AnchoAtreides"].as<uint32_t>()),
                    ancho_edificio_otros(constantes["WorldView"]["Edificios"]["Cuartel"]["AnchoOtros"].as<uint32_t>()),
                    alto_edificio(constantes["WorldView"]["Edificios"]["Cuartel"]["Alto"].as<uint32_t>()),
                    padding_y(constantes["WorldView"]["Edificios"]["Cuartel"]["PaddingY"].as<uint32_t>()),
                    limite_hp_debilitar(constantes["WorldView"]["Edificios"]["Cuartel"]["LimiteHPDebilitar"].as<uint32_t>()) {
    origen.SetX(0);
    origen.SetH(alto_edificio);
    if (casa == codigo_atreides) {
        origen.SetY(0);
        origen.SetW(ancho_edificio_atreides);
    } else if (casa == codigo_harkonnen) {
        origen.SetY(alto_edificio);
        origen.SetW(ancho_edificio_otros);
    } else if (casa == codigo_ordos) {
        origen.SetY(alto_edificio * 2);
        origen.SetW(ancho_edificio_otros);
    } else {
        throw std::runtime_error("CuartelSDL: Casa no reconocida");
    }
}

void CuartelSDL::cambiarHP(uint16_t hp_edificio) {
    if (hp_edificio < limite_hp_debilitar)
        origen.SetX(origen.GetW());
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
    renderer.Copy(textura, origen, destino);
}
