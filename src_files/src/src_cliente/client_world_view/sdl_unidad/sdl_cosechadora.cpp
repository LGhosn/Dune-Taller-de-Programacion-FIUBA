#include "sdl_cosechadora.h"

CosechadoraSDL::CosechadoraSDL(uint8_t id_unidad,
                uint8_t id_jugador,
                SDL2pp::Renderer& renderer,
                TexturasSDL& texturas,
                const Coordenadas& coords,
                uint16_t alto,
                uint16_t ancho,
                uint8_t casa,
                YAML::Node& constantes,
                ColorSDL& color);

void CosechadoraSDL::cambiarHP(uint16_t hp_edificio) {

}

void CosechadoraSDL::update(uint32_t offset_x, uint32_t offset_y, long frame_actual, float zoom) {

}

void CosechadoraSDL::render() {

}