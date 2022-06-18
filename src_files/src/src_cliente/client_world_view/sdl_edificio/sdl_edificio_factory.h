#ifndef SDL_EDIFICIO_FACTORY_H
#define SDL_EDIFICIO_FACTORY_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "sdl_edificio.h"
#include "../sdl_texturas.h"

#define RUTA_CODIGOS_EDIFICIOS RESOURCE_PATH "/constantes/codigos_edificios.yaml"

class EdificioFactorySDL {
    YAML::Node codigos_edificios;
    SDL2pp::Renderer& renderer;
    TexturasSDL& texturas;

public:
    EdificioFactorySDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas);

    EdificioSDL* crearEdificio(uint8_t id_edificio, uint8_t id_jugador, uint8_t casa,
                                uint8_t tipo_edificio, const Coordenadas& coords);

    ~EdificioFactorySDL() = default;
};

#endif // SDL_EDIFICIO_FACTORY_H
