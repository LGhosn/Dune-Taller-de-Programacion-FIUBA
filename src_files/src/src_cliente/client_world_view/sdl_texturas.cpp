#include "sdl_texturas.h"

TexturasSDL::TexturasSDL(SDL2pp::Renderer& renderer) :
                        renderer(renderer),
                        tiles_base(renderer, RUTA_TILES_BASE),
                        edificio_centro(renderer, RUTA_CENTRO),
                        edificio_cuartel(renderer, RUTA_CUARTEL),
                        edificio_fabrica_ligera(renderer, RUTA_FABRICA_LIGERA),
                        edificio_fabrica_pesada(renderer, RUTA_FABRICA_PESADA),
                        edificio_palacio(renderer, RUTA_PALACIO),
                        edificio_refineria(renderer, RUTA_REFINERIA),
                        edificio_silo(renderer, RUTA_SILO),
                        edificio_trampa_de_aire(renderer, RUTA_TRAMPA_DE_AIRE),
                        logo_atreides(renderer, RUTA_LOGO_ATREIDES),
                        logo_harkonnen(renderer, RUTA_LOGO_HARKONNEN),
                        logo_ordos(renderer, RUTA_LOGO_ORDOS) {}

SDL2pp::Texture& TexturasSDL::obtenerTilesBase() {
    return tiles_base;
}

SDL2pp::Texture& TexturasSDL::obtenerTexEdificio(uint8_t tipo) {
    switch (tipo) {
        case 0:
            return edificio_centro;
        case 1:
            return edificio_cuartel;
        case 2:
            return edificio_fabrica_ligera;
        case 3:
            return edificio_fabrica_pesada;
        case 4:
            return edificio_palacio;
        case 5:
            return edificio_refineria;
        case 6:
            return edificio_silo;
        case 7:
            return edificio_trampa_de_aire;
        default:
            throw std::runtime_error("Tipo de edificio invalido");
    }
}

SDL2pp::Texture& TexturasSDL::obtenerLogoCasa(uint8_t casa) {
    switch (casa) {
        case 0:
            return logo_atreides;
        case 1:
            return logo_harkonnen;
        case 2:
            return logo_ordos;
        default:
            throw std::runtime_error("Casa invalida");
    }
}
