#include "sdl_edificio_factory.h"
#include "sdl_centro.h"

EdificioFactorySDL::EdificioFactorySDL(SDL2pp::Renderer& renderer):
                                    codigos_edificios(YAML::LoadFile(RUTA_CODIGOS_EDIFICIOS)),
                                    renderer(renderer),
                                    tex_centro(renderer, RUTA_TEXTURA_CENTRO),
                                    tex_cuartel(renderer, RUTA_TEXTURA_CUARTEL),
                                    tex_fabrica_ligera(renderer, RUTA_TEXTURA_FABRICA_LIGERA),
                                    tex_fabrica_pesada(renderer, RUTA_TEXTURA_FABRICA_PESADA),
                                    tex_palacio(renderer, RUTA_TEXTURA_PALACIO),
                                    tex_refineria(renderer, RUTA_TEXTURA_REFINERIA),
                                    tex_silo(renderer, RUTA_TEXTURA_SILO),
                                    tex_trampa_de_aire(renderer, RUTA_TEXTURA_TRAMPA_DE_AIRE) {}

EdificioSDL* EdificioFactorySDL::crearEdificio(uint8_t id_edificio, uint8_t id_jugador, uint8_t casa,
                                uint8_t tipo_edificio, const Coordenadas& coords) {
    // const uint8_t centro = codigos_edificios["CENTRO_DE_CONSTRUCCION"].as<uint8_t>();
    switch (tipo_edificio) {
        case 0: {
            return new CentroSDL(id_edificio, id_jugador, renderer, tex_centro, coords,
                                3, 3, casa);
        }
        default: {
            return new CentroSDL(id_edificio, id_jugador, renderer, tex_cuartel, coords,
                                3, 3, casa);
        }
    }

}
