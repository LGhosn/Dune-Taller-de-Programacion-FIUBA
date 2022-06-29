#ifndef CLIENTE_SDL_BOTON_PAGINAS_H
#define CLIENTE_SDL_BOTON_PAGINAS_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"

class BotonPaginasSDL {
    SDL2pp::Renderer& renderer;
    SDL2pp::Rect destino;
    SDL2pp::Rect destino_texto;
    SDL2pp::Texture& texto;
    SDL2pp::Color color;
    bool seleccionado = false;
public:
    BotonPaginasSDL(SDL2pp::Renderer& renderer, SDL2pp::Rect destino, SDL2pp::Texture& texto,
                    YAML::Node& constantes);

    bool contiene(int pos_x, int pos_y);

    void seleccionar();
    void deseleccionar();

    void render();
};

#endif // CLIENTE_SDL_BOTON_PAGINAS_H
