#ifndef CLIENTE_SDL_ENERGIA_H
#define CLIENTE_SDL_ENERGIA_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "../sdl_texturas.h"
#include "../sdl_color/sdl_color.h"

class EnergiaSDL {
    SDL2pp::Renderer& renderer;
    ColorSDL& color_rect;
    SDL2pp::Font& fuente;
    SDL2pp::Texture texto;
    SDL2pp::Rect destino_rect;
    const uint32_t padding_texto_x;
    const uint32_t padding_texto_y;
    SDL2pp::Rect destino_texto;
    int16_t cantidad_energia = 0;
public:
    EnergiaSDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas,
                YAML::Node& constantes, ColorSDL& color_rect);

    void modificarEnergia(int16_t cantidad_energia);

    void render();
};

#endif // CLIENTE_SDL_ENERGIA_H
