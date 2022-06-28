#ifndef SDL_ESPECIA_H
#define SDL_ESPECIA_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "../sdl_texturas.h"
#include "../sdl_color/sdl_color.h"

class EspeciaSDL {
    uint16_t cantidad_especia = 0;
    SDL2pp::Renderer& renderer;
    ColorSDL& color_rect;
    SDL2pp::Font& fuente;
    SDL2pp::Texture texto;
    SDL2pp::Rect destino_rect;
    const uint32_t padding_texto_x;
    const uint32_t padding_texto_y;
    SDL2pp::Rect destino_texto;
public:
    EspeciaSDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas, YAML::Node& constantes,
                ColorSDL& color_rect);

    void modificarEspecia(uint16_t cantidad_especia);

    void render();
};

#endif // SDL_ESPECIA_H
