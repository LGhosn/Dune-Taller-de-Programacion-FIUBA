#ifndef SDL_TEXTURAS_H
#define SDL_TEXTURAS_H

#include <vector>
#include <filesystem>
#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"

#define RUTA_TILES_ARENA RESOURCE_PATH "/terrenos/arena/"
#define RUTA_TILES_CIMAS RESOURCE_PATH "/terrenos/cimas/"
#define RUTA_TILES_DUNAS RESOURCE_PATH "/terrenos/dunas/"
#define RUTA_TILES_ESPECIA_ABUNDANTE RESOURCE_PATH "/terrenos/especia_abundante/"
#define RUTA_TILES_ESPECIA_ESCASA RESOURCE_PATH "/terrenos/especia_escasa/"
#define RUTA_TILES_PRECIPICIO RESOURCE_PATH "/terrenos/precipicio/"
#define RUTA_TILES_ROCA RESOURCE_PATH "/terrenos/roca/"

#define RUTA_TILES_SLAB RESOURCE_PATH "/terrenos/slab.bmp"

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

#define RUTA_LOGO_CENTRO RESOURCE_PATH "/logos/edificios/centro_de_construccion_logo.gif"
#define RUTA_LOGO_CUARTEL_ATREIDES RESOURCE_PATH "/logos/edificios/cuartel_atreides_logo.jpg"
#define RUTA_LOGO_CUARTEL_HARKONNEN RESOURCE_PATH "/logos/edificios/cuartel_harkonnen_logo.jpg"
#define RUTA_LOGO_CUARTEL_ORDOS RESOURCE_PATH "/logos/edificios/cuartel_ordos_logo.jpg"
#define RUTA_LOGO_FABRICA_LIGERA RESOURCE_PATH "/logos/edificios/fabrica_ligera_logo.gif"
#define RUTA_LOGO_FABRICA_PESADA RESOURCE_PATH "/logos/edificios/fabrica_pesada_logo.gif"
#define RUTA_LOGO_PALACIO_ATREIDES RESOURCE_PATH "/logos/edificios/palacio_atreides_logo.jpg"
#define RUTA_LOGO_PALACIO_HARKONNEN RESOURCE_PATH "/logos/edificios/palacio_harkonnen_logo.jpg"
#define RUTA_LOGO_PALACIO_ORDOS RESOURCE_PATH "/logos/edificios/palacio_ordos_logo.jpg"
#define RUTA_LOGO_REFINERIA RESOURCE_PATH "/logos/edificios/refineria_logo.gif"
#define RUTA_LOGO_SILO RESOURCE_PATH "/logos/edificios/silo_logo.gif"
#define RUTA_LOGO_TRAMPA_DE_AIRE RESOURCE_PATH "/logos/edificios/trampa_de_aire_logo.gif"

#define RUTA_FONT_DUNE_2K RESOURCE_PATH "/fonts/Dune2k.ttf"

#define TEXTO_LISTO "LISTO"

class TexturasSDL {
    YAML::Node& constantes;
    SDL2pp::SDLTTF sdl_ttf;
    SDL2pp::Renderer& renderer;
    
    std::vector<SDL2pp::Texture> tiles_arena;
    std::vector<SDL2pp::Texture> tiles_cima;
    std::vector<SDL2pp::Texture> tiles_duna;
    std::vector<SDL2pp::Texture> tiles_especia_abundante;
    std::vector<SDL2pp::Texture> tiles_especia_escasa;
    std::vector<SDL2pp::Texture> tiles_precipicio;
    std::vector<SDL2pp::Texture> tiles_roca;
    SDL2pp::Texture slab;

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

    SDL2pp::Texture logo_centro;
    SDL2pp::Texture logo_cuartel_atreides;
    SDL2pp::Texture logo_cuartel_harkonnen;
    SDL2pp::Texture logo_cuartel_ordos;
    SDL2pp::Texture logo_fabrica_ligera;
    SDL2pp::Texture logo_fabrica_pesada;
    SDL2pp::Texture logo_palacio_atreides;
    SDL2pp::Texture logo_palacio_harkonnen;
    SDL2pp::Texture logo_palacio_ordos;
    SDL2pp::Texture logo_refineria;
    SDL2pp::Texture logo_silo;
    SDL2pp::Texture logo_trampa_de_aire;

    std::string texto_listo;
    SDL2pp::Font font_tienda;
    SDL2pp::Texture texto_tienda;

    uint8_t obtenerCantidadTexturas(std::filesystem::path ruta);

public:
    TexturasSDL(SDL2pp::Renderer& renderer, YAML::Node& constantes);

    // SDL2pp::Texture& obtenerTilesBase();
    SDL2pp::Texture& obtenerTexTile(uint8_t tipo_tile, uint8_t tipo_textura);
    SDL2pp::Texture& obtenerTexEdificio(uint8_t tipo);
    SDL2pp::Texture& obtenerLogoCasa(uint8_t casa);
    SDL2pp::Texture& obtenerLogoEdificio(uint8_t tipo, uint8_t casa);
    SDL2pp::Texture& obtenerTextoTiendaListo();
};

#endif // SDL_TEXTURAS_H