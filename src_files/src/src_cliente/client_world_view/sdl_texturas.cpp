#include "sdl_texturas.h"
#include <iostream>

uint8_t TexturasSDL::obtenerCantidadTexturas(std::filesystem::path ruta) {
    return std::distance(std::filesystem::directory_iterator{ruta},
                        std::filesystem::directory_iterator{});
}

void TexturasSDL::cargarLogos() {
    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_LOGOS << "edificios/cuartel_" << casa << "_logo.bmp";
        logos_cuartel.emplace_back(renderer, stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_LOGOS << "edificios/fabrica_ligera_" << casa << "_logo.bmp";
        logos_fabrica_ligera.emplace_back(renderer, stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_LOGOS << "edificios/fabrica_pesada_" << casa << "_logo.bmp";
        logos_fabrica_pesada.emplace_back(renderer, stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_LOGOS << "edificios/palacio_" << casa << "_logo.bmp";
        logos_palacio.emplace_back(renderer, stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_LOGOS << "edificios/refineria_" << casa << "_logo.bmp";
        logos_refineria.emplace_back(renderer, stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_LOGOS << "edificios/silo_" << casa << "_logo.bmp";
        logos_silo.emplace_back(renderer, stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_LOGOS << "edificios/trampa_" << casa << "_logo.bmp";
        logos_trampa_de_aire.emplace_back(renderer, stream.str());
    }

    logos_unidades.emplace_back(renderer, RUTA_LOGO_FREMEN);
    logos_unidades.emplace_back(renderer, RUTA_LOGO_INFANTERIA_LIGERA);
    logos_unidades.emplace_back(renderer, RUTA_LOGO_INFANTERIA_PESADA);
    logos_unidades.emplace_back(renderer, RUTA_LOGO_SARDAUKAR);
    logos_unidades.emplace_back(renderer, RUTA_LOGO_COSECHADORA);
    logos_unidades.emplace_back(renderer, RUTA_LOGO_DESVIADOR);
    logos_unidades.emplace_back(renderer, RUTA_LOGO_DEVASTADOR);
    logos_unidades.emplace_back(renderer, RUTA_LOGO_RAIDER);
    logos_unidades.emplace_back(renderer, RUTA_LOGO_TANQUE);
    logos_unidades.emplace_back(renderer, RUTA_LOGO_TANQUE_SONICO);
    logos_unidades.emplace_back(renderer, RUTA_LOGO_TRIKE);
}

void TexturasSDL::cargarTiles() {
    uint8_t cantidad_texturas = obtenerCantidadTexturas(RUTA_TILES_ARENA) - 1;
    for (uint8_t i = 0; i < cantidad_texturas; i++) {
        std::stringstream stream;
        stream << RUTA_TILES_ARENA << "arena" << (int) i << ".bmp";
        tiles_arena.emplace_back(renderer, stream.str());
    }

    cantidad_texturas = obtenerCantidadTexturas(RUTA_TILES_CIMAS) - 1;
    for (uint8_t i = 0; i < cantidad_texturas; i++) {
        std::stringstream stream;
        stream << RUTA_TILES_CIMAS << "cima" << (int) i << ".bmp";
        tiles_cima.emplace_back(renderer, stream.str());
    }
    
    cantidad_texturas = obtenerCantidadTexturas(RUTA_TILES_DUNAS) - 1;
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

    cantidad_texturas = obtenerCantidadTexturas(RUTA_TILES_PRECIPICIO) - 1;
    for (uint8_t i = 0; i < cantidad_texturas; i++) {
        std::stringstream stream;
        stream << RUTA_TILES_PRECIPICIO << "precipicio" << (int) i << ".bmp";
        tiles_precipicio.emplace_back(renderer, stream.str());
    }

    cantidad_texturas = obtenerCantidadTexturas(RUTA_TILES_ROCA) - 1;
    for (uint8_t i = 0; i < cantidad_texturas; i++) {
        std::stringstream stream;
        stream << RUTA_TILES_ROCA << "roca" << (int) i << ".bmp";
        tiles_roca.emplace_back(renderer, stream.str());
    }
}

void TexturasSDL::cargarEdificios() {
    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "centro/" << casa << "/centro_" << casa << ".bmp";
        centros.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }
    uint8_t it = 0;
    centros_brazos = std::vector<std::vector<SDL2pp::Texture>>(3);
    for (const std::string& casa: casas) {
        std::vector<SDL2pp::Texture> frames_brazo;
        for (uint8_t i = 0; i < CANT_FRAMES_BRAZO; i++) {
            std::stringstream stream;
            stream << RUTA_EDIFICIOS << "centro/" << casa << "/brazo" << (int) i << ".bmp";
            centros_brazos[it].emplace_back(renderer,
                                        SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
        }
        it++;
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/cuartel/cuartel_" << casa << ".bmp";
        cuarteles.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/cuartel/cuartel_" << casa << "_debilitado.bmp";
        cuarteles_debilitados.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/fabrica_ligera/fabrica_ligera_" << casa << ".bmp";
        fabricas_ligeras.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/fabrica_ligera/fabrica_ligera_" << casa << "_debilitada.bmp";
        fabricas_ligeras_debilitadas.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/fabrica_ligera/fabrica_ligera_" << casa << "_paredes.bmp";
        fabricas_ligeras_paredes.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/fabrica_pesada/fabrica_pesada_" << casa << ".bmp";
        fabricas_pesadas.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/fabrica_pesada/fabrica_pesada_" << casa << "_debilitada.bmp";
        fabricas_pesadas_debilitadas.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/fabrica_pesada/fabrica_pesada_" << casa << "_paredes.bmp";
        fabricas_pesadas_paredes.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/palacio/palacio_" << casa << ".bmp";
        palacios.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/palacio/palacio_" << casa << "_debilitado.bmp";
        palacios_debilitados.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/refineria/refineria_" << casa << ".bmp";
        refinerias.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/refineria/refineria_" << casa << "_debilitada.bmp";
        refinerias_debilitadas.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/refineria/refineria_" << casa << "_paredes.bmp";
        refinerias_paredes.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    it = 0;
    silos = std::vector<std::vector<SDL2pp::Texture>>(3);
    for (const std::string& casa: casas) {
        for (uint8_t i = 0; i < CANT_FRAMES_SILO; i++) {
            std::stringstream stream;
            stream << RUTA_EDIFICIOS << "silo/silo_" << casa << (int) i << ".bmp";
            silos[it].emplace_back(renderer,
                                    SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
        }
        it++;
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/silo/silo_" << casa << "_debilitado.bmp";
        silos_debilitados.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/trampa/trampa_" << casa << ".bmp";
        trampas.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (const std::string& casa: casas) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/trampa/trampa_" << casa << "_debilitada.bmp";
        trampas_debilitadas.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }

    for (uint8_t i = 0 ; i < CANT_FRAMES_LUCES_TRAMPA; i++) {
        std::stringstream stream;
        stream << RUTA_EDIFICIOS << "/trampa/luz" << (int) i << ".bmp";
        trampas_luces.emplace_back(renderer, SDL2pp::Surface(stream.str()).SetColorKey(true, 0));
    }
}

void TexturasSDL::cargarInfanteria() {

}

void TexturasSDL::cargarVehiculos() {}
TexturasSDL::TexturasSDL(SDL2pp::Renderer& renderer, YAML::Node& constantes) :
                        constantes(constantes),
                        renderer(renderer),
                        slab(renderer, RUTA_TILES_SLAB),
                        edificio_fabrica_ligera(renderer, RUTA_FABRICA_LIGERA),
                        edificio_fabrica_pesada(renderer, RUTA_FABRICA_PESADA),
                        edificio_palacio(renderer, RUTA_PALACIO),
                        edificio_refineria(renderer, RUTA_REFINERIA),
                        edificio_silo(renderer, RUTA_SILO),
                        edificio_trampa_de_aire(renderer, RUTA_TRAMPA_DE_AIRE),
                        logo_atreides(renderer, RUTA_LOGO_ATREIDES),
                        logo_harkonnen(renderer, RUTA_LOGO_HARKONNEN),
                        logo_ordos(renderer, RUTA_LOGO_ORDOS),
                        texto_listo(constantes["WorldView"]["SideMenu"]["Tienda"]["Botones"]["Texto"].as<std::string>()),
                        font_tienda(RUTA_FONT_DUNE_2K, 50),
                        texto_tienda(renderer, font_tienda.RenderText_Blended(
                                                                texto_listo,
                                                                SDL_Color{90, 146, 22, 255}
                                                        )
                                            ),
                        texto_edificios(renderer,
                            font_tienda.RenderText_Blended("Edificios", SDL_Color{255, 255, 255, 255}
                        )),
                        texto_infanteria(renderer,
                            font_tienda.RenderText_Blended("Infanteria", SDL_Color{255, 255, 255, 255}
                        )),
                        texto_vehiculos(renderer,
                            font_tienda.RenderText_Blended("Vehiculos", SDL_Color{255, 255, 255, 255}
                        )) {
    casas.emplace_back("atreides");
    casas.emplace_back("harkonnen");
    casas.emplace_back("ordos");
    cargarLogos();
    cargarTiles();
    cargarEdificios();
}

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

SDL2pp::Texture& TexturasSDL::obtenerSlab() {
    return slab;
}

SDL2pp::Texture& TexturasSDL::obtenerEdificio(uint8_t tipo, uint8_t casa, bool debilitado) {
    switch (tipo) {
        case 0: {
            if (debilitado)
                return centros_debilitados[casa];
            else
                return centros[casa];
            break;
        }
        case 1: {
            if (debilitado)
                return cuarteles_debilitados[casa];
            else
                return cuarteles[casa];
        }
        case 2: {
            if (debilitado)
                return fabricas_ligeras_debilitadas[casa];
            else
                return fabricas_ligeras[casa];
        }
        case 3: {
            if (debilitado)
                return fabricas_pesadas_debilitadas[casa];
            else
                return fabricas_pesadas[casa];
        }
        case 4: {
            if (debilitado)
                return palacios_debilitados[casa];
            else
                return palacios[casa];
        }
        case 5: {
            if (debilitado)
                return refinerias_debilitadas[casa];
            else
                return refinerias[casa];
        }
        case 6: {
            if (debilitado)
                return silos_debilitados[casa];
            else
                throw std::runtime_error("Texturas: codigo de edificio no valido");
        }
        case 7: {
            if (debilitado)
                return trampas_debilitadas[casa];
            else
                return trampas[casa];
        }
        default:
            throw std::runtime_error("Texturas: codigo de edificio no valido");
    }
}

std::vector<SDL2pp::Texture>& TexturasSDL::obtenerFramesBrazoCentro(uint8_t casa) {
    return centros_brazos[casa];
}

SDL2pp::Texture& TexturasSDL::obtenerParedesFabricaLigera(uint8_t casa) {
    return fabricas_ligeras_paredes[casa];
}

SDL2pp::Texture& TexturasSDL::obtenerParedesFabricaPesada(uint8_t casa) {
    return fabricas_pesadas_paredes[casa];
}

SDL2pp::Texture& TexturasSDL::obtenerParedesRefineria(uint8_t casa) {
    return refinerias_paredes[casa];
}

std::vector<SDL2pp::Texture>& TexturasSDL::obtenerFramesSilo(uint8_t casa) {
    return silos[casa];
}

std::vector<SDL2pp::Texture>& TexturasSDL::obtenerLucesTrampa() {
    return trampas_luces;
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
        case 1:
            return logos_cuartel[casa];
        case 2:
            return logos_fabrica_ligera[casa];
        case 3:
            return logos_fabrica_pesada[casa];
        case 4:
            return logos_palacio[casa];
        case 5:
            return logos_refineria[casa];
        case 6:
            return logos_silo[casa];
        case 7:
            return logos_trampa_de_aire[casa];
        default:
            throw std::runtime_error("Tipo de edificio invalido");
    }
}

SDL2pp::Texture& TexturasSDL::obtenerLogoUnidad(uint8_t tipo) {
    return logos_unidades[tipo];
}

SDL2pp::Texture& TexturasSDL::obtenerTextoTiendaListo() {
    return texto_tienda;
}

SDL2pp::Font& TexturasSDL::obtenerFontDune2000() {
    return font_tienda;
}

SDL2pp::Texture& TexturasSDL::obtenerTextoEdificios() {
    return texto_edificios;
}

SDL2pp::Texture& TexturasSDL::obtenerTextoInfanteria() {
    return texto_infanteria;
}

SDL2pp::Texture& TexturasSDL::obtenerTextoVehiculos() {
    return texto_vehiculos;
}
