#ifndef SDL_EDIFICIO_FACTORY_H
#define SDL_EDIFICIO_FACTORY_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "sdl_edificio.h"

#define RUTA_TEXTURA_CENTRO RESOURCE_PATH "/buildings/centro_de_construccion.png"
#define RUTA_TEXTURA_CUARTEL RESOURCE_PATH "/buildings/cuartel.png"
#define RUTA_TEXTURA_FABRICA_LIGERA RESOURCE_PATH "/buildings/fabrica_ligera.png"
#define RUTA_TEXTURA_FABRICA_PESADA RESOURCE_PATH "/buildings/fabrica_pesada.png"
#define RUTA_TEXTURA_FABRICA_LIGERA RESOURCE_PATH "/buildings/fabrica_ligera.png"
#define RUTA_TEXTURA_PALACIO RESOURCE_PATH "/buildings/palacio.png"
#define RUTA_TEXTURA_REFINERIA RESOURCE_PATH "/buildings/refineria.png"
#define RUTA_TEXTURA_SILO RESOURCE_PATH "/buildings/silo.png"
#define RUTA_TEXTURA_TRAMPA_DE_AIRE RESOURCE_PATH "/buildings/trampa_de_aire.png"

#define RUTA_CODIGOS_EDIFICIOS RESOURCE_PATH "/constantes/codigos_edificios.yaml"

class EdificioFactorySDL {
    YAML::Node codigos_edificios;
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture tex_centro;
    SDL2pp::Texture tex_cuartel;
    SDL2pp::Texture tex_fabrica_ligera;
    SDL2pp::Texture tex_fabrica_pesada;
    SDL2pp::Texture tex_palacio;
    SDL2pp::Texture tex_refineria;
    SDL2pp::Texture tex_silo;
    SDL2pp::Texture tex_trampa_de_aire;

public:
    EdificioFactorySDL(SDL2pp::Renderer& renderer);

    EdificioSDL* crearEdificio(uint8_t id_edificio, uint8_t id_jugador, uint8_t casa,
                                uint8_t tipo_edificio, const Coordenadas& coords);

    ~EdificioFactorySDL() = default;
};

#endif // SDL_EDIFICIO_FACTORY_H
