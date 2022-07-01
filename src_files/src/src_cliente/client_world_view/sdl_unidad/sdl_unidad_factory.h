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

    UnidadSDL* crearUnidad(uint8_t id_unidad,
                            uint8_t id_jugador,
                            SDL2pp::Renderer& renderer,
                            TexturasSDL& texturas,
                            const Coordenadas& coords,
                            YAML::Node& constantes,
                            ColoresSDL& colores,
                            long tiempo_aparicion,
                            uint8_t tipo_unidad);

    ~UnidadFactorySDL() = default;
};

#endif //SDL_UNIDAD_FACTORY_H
