#ifndef SDL_COSECHADORA_H
#define SDL_COSECHADORA_H

#include "sdl_unidad.h"

class CosechadoraSDL {
public:
    CosechadoraSDL(uint8_t id_unidad,
                   uint8_t id_jugador,
                   SDL2pp::Renderer& renderer,
                   TexturasSDL& texturas,
                   const Coordenadas& coords,
                   YAML::Node& constantes,
                   ColorSDL& color);

    //void cambiarHP(uint16_t hp_edificio) override;

    void update(uint32_t offset_x, uint32_t offset_y, long frame_actual, float zoom) override;

    void render() override;

    virtual ~CosechadoraSDL() = default;
};


#endif //SDL_COSECHADORA_H
