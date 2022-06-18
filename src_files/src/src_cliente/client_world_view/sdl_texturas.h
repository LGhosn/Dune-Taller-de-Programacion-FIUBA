#ifndef SDL_TEXTURAS_H
#define SDL_TEXTURAS_H

#include <SDL2pp/SDL2pp.hh>

#define RUTA_TILES_BASE RESOURCE_PATH "/terrain/d2k_BLOXBASE.bmp"

#define RUTA_CENTRO RESOURCE_PATH "/buildings/centro_de_construccion.png"
#define RUTA_CUARTEL RESOURCE_PATH "/buildings/cuartel.png"
#define RUTA_FABRICA_LIGERA RESOURCE_PATH "/buildings/fabrica_ligera.png"
#define RUTA_FABRICA_PESADA RESOURCE_PATH "/buildings/fabrica_pesada.png"
#define RUTA_PALACIO RESOURCE_PATH "/buildings/palacio.png"
#define RUTA_REFINERIA RESOURCE_PATH "/buildings/refineria.png"
#define RUTA_SILO RESOURCE_PATH "/buildings/silo.png"
#define RUTA_TRAMPA_DE_AIRE RESOURCE_PATH "/buildings/trampa_de_aire.png"

#define RUTA_LOGO_ATREIDES RESOURCE_PATH "/AtreidesIcon.png"
#define RUTA_LOGO_HARKONNEN RESOURCE_PATH "/HarkonnenIcon.png"
#define RUTA_LOGO_ORDOS RESOURCE_PATH "/OrdosIcon.png"

class TexturasSDL {
    SDL2pp::Renderer& renderer;
    
    SDL2pp::Texture tiles_base;

    SDL2pp::Texture edificio_centro;
    SDL2pp::Texture edificio_cuartel;
    SDL2pp::Texture edificio_fabrica_ligera;
    SDL2pp::Texture edificio_fabrica_pesada;
    SDL2pp::Texture edificio_palacio;
    SDL2pp::Texture edificio_refineria;
    SDL2pp::Texture edificio_silo;
    SDL2pp::Texture edificio_trampa_de_aire;

    SDL2pp::Texture logo_atreides;
    SDL2pp::Texture logo_harkonnen;
    SDL2pp::Texture logo_ordos;

public:
    TexturasSDL(SDL2pp::Renderer& renderer);

    SDL2pp::Texture& obtenerTilesBase();
    SDL2pp::Texture& obtenerTexEdificio(uint8_t tipo);
    SDL2pp::Texture& obtenerLogoCasa(uint8_t casa);
};

#endif // SDL_TEXTURAS_H