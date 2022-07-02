#ifndef SDL_EDIFICIO_FACTORY_H
#define SDL_EDIFICIO_FACTORY_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "sdl_edificio.h"
#include "../sdl_texturas.h"
#include "../sdl_color/sdl_colores.h"
#include <memory>

class EdificioFactorySDL {
    YAML::Node& constantes;
    SDL2pp::Renderer& renderer;
    TexturasSDL& texturas;
    ColoresSDL& colores;

public:
    EdificioFactorySDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas,
                        YAML::Node& constantes, ColoresSDL& colores);

    std::shared_ptr<EdificioSDL> crearEdificio(uint8_t id_edificio, uint8_t id_jugador, uint8_t casa,
                                uint8_t tipo_edificio, const Coordenadas& coords);

    ~EdificioFactorySDL() = default;
};

#endif // SDL_EDIFICIO_FACTORY_H
