#ifndef CLIENT_SDL_COLOR_H
#define CLIENT_SDL_COLOR_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"

class ColorSDL {
    SDL2pp::Color primario;
    SDL2pp::Color secundario;
    SDL2pp::Color oscuro;
public:
    ColorSDL(YAML::Node& archivo_colores, uint8_t id_color);

    SDL2pp::Color& obtenerPrimario();
    SDL2pp::Color& obtenerSecundario();
    SDL2pp::Color& obtenerOscuro();
};

#endif
