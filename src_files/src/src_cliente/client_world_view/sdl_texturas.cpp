#include "sdl_texturas.h"

TexturasSDL::TexturasSDL(SDL2pp::Renderer& renderer, YAML::Node& constantes) :
                        constantes(constantes),
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
                        logo_ordos(renderer, RUTA_LOGO_ORDOS),
                        logo_centro(renderer, RUTA_LOGO_CENTRO),
                        logo_cuartel_atreides(renderer, RUTA_LOGO_CUARTEL_ATREIDES),
                        logo_cuartel_harkonnen(renderer, RUTA_LOGO_CUARTEL_HARKONNEN),
                        logo_cuartel_ordos(renderer, RUTA_LOGO_CUARTEL_ORDOS),
                        logo_fabrica_ligera(renderer, RUTA_LOGO_FABRICA_LIGERA),
                        logo_fabrica_pesada(renderer, RUTA_LOGO_FABRICA_PESADA),
                        logo_palacio_atreides(renderer, RUTA_LOGO_PALACIO_ATREIDES),
                        logo_palacio_harkonnen(renderer, RUTA_LOGO_PALACIO_HARKONNEN),
                        logo_palacio_ordos(renderer, RUTA_LOGO_PALACIO_ORDOS),
                        logo_refineria(renderer, RUTA_LOGO_REFINERIA),
                        logo_silo(renderer, RUTA_LOGO_SILO),
                        logo_trampa_de_aire(renderer, RUTA_LOGO_TRAMPA_DE_AIRE),
                        texto_listo(constantes["WorldView"]["SideMenu"]["Tienda"]["Botones"]["Texto"].as<std::string>()),
                        font_tienda(RUTA_FONT_DUNE_2K, 20),
                        texto_tienda(renderer, font_tienda.RenderText_Blended(
                                                                texto_listo,
                                                                SDL_Color{90, 146, 22, 255}
                                                        )
                                            ) {}

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

SDL2pp::Texture& TexturasSDL::obtenerLogoEdificio(uint8_t tipo, uint8_t casa) {
    switch (tipo) {
        case 0:
            return logo_centro;
        case 1: {
            switch (casa) {
                case 0:
                    return logo_cuartel_atreides;
                case 1:
                    return logo_cuartel_harkonnen;
                case 2:
                    return logo_cuartel_ordos;
                default:
                    throw std::runtime_error("Casa invalida");
            }
            break;
        }
        case 2:
            return logo_fabrica_ligera;
        case 3:
            return logo_fabrica_pesada;
        case 4: {
            switch (casa) {
                case 0:
                    return logo_palacio_atreides;
                case 1:
                    return logo_palacio_harkonnen;
                case 2:
                    return logo_palacio_ordos;
                default:
                    throw std::runtime_error("Casa invalida");
            }
            break;
        }
        case 5:
            return logo_refineria;
        case 6:
            return logo_silo;
        case 7:
            return logo_trampa_de_aire;
        default:
            throw std::runtime_error("Tipo de edificio invalido");
    }
}

SDL2pp::Texture& TexturasSDL::obtenerTextoTiendaListo() {
    return texto_tienda;
}
