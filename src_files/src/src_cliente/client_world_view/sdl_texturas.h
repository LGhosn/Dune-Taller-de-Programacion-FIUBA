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

#define RUTA_CENTRO RESOURCE_PATH "/edificios/centro_de_construccion.png"
#define RUTA_CUARTEL RESOURCE_PATH "/edificios/cuartel.png"
#define RUTA_FABRICA_LIGERA RESOURCE_PATH "/edificios/fabrica_ligera.png"
#define RUTA_FABRICA_PESADA RESOURCE_PATH "/edificios/fabrica_pesada.png"
#define RUTA_PALACIO RESOURCE_PATH "/edificios/palacio.png"
#define RUTA_REFINERIA RESOURCE_PATH "/edificios/refineria.png"
#define RUTA_SILO RESOURCE_PATH "/edificios/silo.png"
#define RUTA_TRAMPA_DE_AIRE RESOURCE_PATH "/edificios/trampa_de_aire.png"

#define RUTA_LOGO_ATREIDES RESOURCE_PATH "/AtreidesIcon.png"
#define RUTA_LOGO_HARKONNEN RESOURCE_PATH "/HarkonnenIcon.png"
#define RUTA_LOGO_ORDOS RESOURCE_PATH "/OrdosIcon.png"

#define RUTA_LOGOS RESOURCE_PATH "/logos/"
#define RUTA_EDIFICIOS RESOURCE_PATH "/edificios/"
#define CANT_FRAMES_BRAZO 14
#define CANT_FRAMES_SILO 4
#define CANT_FRAMES_LUCES_TRAMPA 5 

#define RUTA_FONT_DUNE_2K RESOURCE_PATH "/fonts/Dune2k.ttf"

#define TEXTO_LISTO "LISTO"

class TexturasSDL {
    YAML::Node& constantes;
    SDL2pp::SDLTTF sdl_ttf;
    SDL2pp::Renderer& renderer;
    std::vector<std::string> casas;
    
    std::vector<SDL2pp::Texture> tiles_arena;
    std::vector<SDL2pp::Texture> tiles_cima;
    std::vector<SDL2pp::Texture> tiles_duna;
    std::vector<SDL2pp::Texture> tiles_especia_abundante;
    std::vector<SDL2pp::Texture> tiles_especia_escasa;
    std::vector<SDL2pp::Texture> tiles_precipicio;
    std::vector<SDL2pp::Texture> tiles_roca;
    SDL2pp::Texture slab;

    std::vector<SDL2pp::Texture> centros;
    std::vector<SDL2pp::Texture> centros_debilitados;
    std::vector<std::vector<SDL2pp::Texture>> centros_brazos;

    std::vector<SDL2pp::Texture> cuarteles;
    std::vector<SDL2pp::Texture> cuarteles_debilitados;

    std::vector<SDL2pp::Texture> fabricas_ligeras;
    std::vector<SDL2pp::Texture> fabricas_ligeras_debilitadas;
    std::vector<SDL2pp::Texture> fabricas_ligeras_paredes;

    std::vector<SDL2pp::Texture> fabricas_pesadas;
    std::vector<SDL2pp::Texture> fabricas_pesadas_debilitadas;
    std::vector<SDL2pp::Texture> fabricas_pesadas_paredes;

    std::vector<SDL2pp::Texture> palacios;
    std::vector<SDL2pp::Texture> palacios_debilitados;

    std::vector<SDL2pp::Texture> refinerias;
    std::vector<SDL2pp::Texture> refinerias_debilitadas;
    std::vector<SDL2pp::Texture> refinerias_paredes;

    std::vector<std::vector<SDL2pp::Texture>> silos;
    std::vector<SDL2pp::Texture> silos_debilitados;

    std::vector<SDL2pp::Texture> trampas;
    std::vector<SDL2pp::Texture> trampas_debilitadas;
    std::vector<SDL2pp::Texture> trampas_luces;

    SDL2pp::Texture edificio_fabrica_ligera;
    SDL2pp::Texture edificio_fabrica_pesada;
    SDL2pp::Texture edificio_palacio;
    SDL2pp::Texture edificio_refineria;
    SDL2pp::Texture edificio_silo;
    SDL2pp::Texture edificio_trampa_de_aire;

    SDL2pp::Texture logo_atreides;
    SDL2pp::Texture logo_harkonnen;
    SDL2pp::Texture logo_ordos;

    std::vector<SDL2pp::Texture> logos_cuartel;
    std::vector<SDL2pp::Texture> logos_fabrica_ligera;
    std::vector<SDL2pp::Texture> logos_fabrica_pesada;
    std::vector<SDL2pp::Texture> logos_palacio;
    std::vector<SDL2pp::Texture> logos_refineria;
    std::vector<SDL2pp::Texture> logos_silo;
    std::vector<SDL2pp::Texture> logos_trampa_de_aire;

    std::string texto_listo;
    SDL2pp::Font font_tienda;
    SDL2pp::Texture texto_tienda;

    SDL2pp::Texture texto_edificios;
    SDL2pp::Texture texto_infanteria;
    SDL2pp::Texture texto_vehiculos; 

    uint8_t obtenerCantidadTexturas(std::filesystem::path ruta);

    void cargarLogos();
    void cargarTiles();
    void cargarEdificios();

public:
    TexturasSDL(SDL2pp::Renderer& renderer, YAML::Node& constantes);

    // SDL2pp::Texture& obtenerTilesBase();
    SDL2pp::Texture& obtenerTexTile(uint8_t tipo_tile, uint8_t tipo_textura);

    SDL2pp::Texture& obtenerSlab();
    SDL2pp::Texture& obtenerEdificio(uint8_t tipo, uint8_t casa, bool debilitado);
    std::vector<SDL2pp::Texture>& obtenerFramesBrazoCentro(uint8_t casa);
    SDL2pp::Texture& obtenerParedesFabricaLigera(uint8_t casa);
    SDL2pp::Texture& obtenerParedesFabricaPesada(uint8_t casa);
    SDL2pp::Texture& obtenerParedesRefineria(uint8_t casa);
    std::vector<SDL2pp::Texture>& obtenerFramesSilo(uint8_t casa);
    std::vector<SDL2pp::Texture>& obtenerLucesTrampa();
    
    SDL2pp::Texture& obtenerLogoCasa(uint8_t casa);
    SDL2pp::Texture& obtenerLogoEdificio(uint8_t tipo, uint8_t casa);
    SDL2pp::Texture& obtenerTextoTiendaListo();

    SDL2pp::Font& obtenerFontDune2000();
    SDL2pp::Texture& obtenerTextoEdificios();
    SDL2pp::Texture& obtenerTextoInfanteria();
    SDL2pp::Texture& obtenerTextoVehiculos();
};

#endif // SDL_TEXTURAS_H