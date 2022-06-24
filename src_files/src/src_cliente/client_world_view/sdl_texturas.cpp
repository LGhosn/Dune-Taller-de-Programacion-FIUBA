#include "sdl_texturas.h"

uint8_t TexturasSDL::obtenerCantidadTexturas(std::filesystem::path ruta) {
    return std::distance(std::filesystem::directory_iterator{ruta},
                        std::filesystem::directory_iterator{});
}

TexturasSDL::TexturasSDL(SDL2pp::Renderer& renderer, YAML::Node& constantes) :
                        constantes(constantes),
                        renderer(renderer),
                        slab(renderer, RUTA_TILES_SLAB),
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
                                            ) {
    uint8_t cantidad_texturas = obtenerCantidadTexturas(RUTA_TILES_ARENA);
    for (uint8_t i = 0; i < cantidad_texturas; i++) {
        std::stringstream stream;
        stream << RUTA_TILES_ARENA << "arena" << (int) i << ".bmp";
        tiles_arena.emplace_back(renderer, stream.str());
    }

    cantidad_texturas = obtenerCantidadTexturas(RUTA_TILES_CIMAS);
    for (uint8_t i = 0; i < cantidad_texturas; i++) {
        std::stringstream stream;
        stream << RUTA_TILES_CIMAS << "cima" << (int) i << ".bmp";
        tiles_cima.emplace_back(renderer, stream.str());
    }
    
    cantidad_texturas = obtenerCantidadTexturas(RUTA_TILES_DUNAS);
    for (uint8_t i = 0; i < cantidad_texturas; i++) {
        std::stringstream stream;
        stream << RUTA_TILES_DUNAS << "duna" << (int) i << ".bmp";
        tiles_duna.emplace_back(renderer, stream.str());
    }

    cantidad_texturas = obtenerCantidadTexturas(RUTA_TILES_ESPECIA_ABUNDANTE);
    for (uint8_t i = 0; i < cantidad_texturas; i++) {
        std::stringstream stream;
        stream << RUTA_TILES_ESPECIA_ABUNDANTE << "especia_abundante" << (int) i << ".bmp";
        tiles_especia_abundante.emplace_back(renderer, stream.str());
    }

    cantidad_texturas = obtenerCantidadTexturas(RUTA_TILES_ESPECIA_ESCASA);
    for (uint8_t i = 0; i < cantidad_texturas; i++) {
        std::stringstream stream;
        stream << RUTA_TILES_ESPECIA_ESCASA << "especia_escasa" << (int) i << ".bmp";
        tiles_especia_escasa.emplace_back(renderer, stream.str());
    }

    cantidad_texturas = obtenerCantidadTexturas(RUTA_TILES_PRECIPICIO);
    for (uint8_t i = 0; i < cantidad_texturas; i++) {
        std::stringstream stream;
        stream << RUTA_TILES_PRECIPICIO << "precipicio" << (int) i << ".bmp";
        tiles_precipicio.emplace_back(renderer, stream.str());
    }

    cantidad_texturas = obtenerCantidadTexturas(RUTA_TILES_ROCA);
    for (uint8_t i = 0; i < cantidad_texturas; i++) {
        std::stringstream stream;
        stream << RUTA_TILES_ROCA << "roca" << (int) i << ".bmp";
        tiles_roca.emplace_back(renderer, stream.str());
    }
}

// SDL2pp::Texture& TexturasSDL::obtenerTilesBase() {
//     return tiles_base;
// }

SDL2pp::Texture& TexturasSDL::obtenerTexTile(uint8_t tipo_tile, uint8_t tipo_textura) {
    switch (tipo_tile) {
        case 'A':
            return tiles_arena[tipo_textura];
        case 'C':
            return tiles_cima[tipo_textura];
        case 'D':
            return tiles_duna[tipo_textura];
        case 'E':
            return tiles_especia_abundante[tipo_textura];
        case 'P':
            return tiles_precipicio[tipo_textura];
        case 'R':
            return tiles_roca[tipo_textura];
        default:
            throw std::runtime_error("Texturas: Tipo de tile no reconocido.");
    }
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
