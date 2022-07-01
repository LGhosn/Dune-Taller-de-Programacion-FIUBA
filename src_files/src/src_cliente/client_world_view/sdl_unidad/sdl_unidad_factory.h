#ifndef SDL_UNIDAD_FACTORY_H
#define SDL_UNIDAD_FACTORY_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "sdl_unidad.h"
#include "../sdl_texturas.h"
#include "../sdl_color/sdl_colores.h"

class UnidadFactorySDL {
private:
    YAML::Node& constantes;
    SDL2pp::Renderer& renderer;
    TexturasSDL& texturas;
    ColoresSDL& colores;
public:
    UnidadFactorySDL(SDL2pp::Renderer& renderer,
                     TexturasSDL& texturas,
                     YAML::Node& constantes,
                     ColoresSDL& colores) :
                     constantes(constantes),
                     renderer(renderer),
                     texturas(texturas),
                     colores(colores) {}

    //UnidadSDL* crearEdificio(uint8_t id_edificio, uint8_t id_jugador, uint8_t casa, uint8_t tipo_edificio, const Coordenadas& coords);

    ~UnidadFactorySDL() = default;
};

#endif //SDL_UNIDAD_FACTORY_H
