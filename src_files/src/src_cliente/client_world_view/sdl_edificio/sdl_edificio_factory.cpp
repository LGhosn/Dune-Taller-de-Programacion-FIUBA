#include "sdl_edificio_factory.h"
#include "sdl_centro.h"
#include "sdl_cuartel.h"
#include "sdl_fabrica_ligera.h"
#include "sdl_fabrica_pesada.h"

EdificioFactorySDL::EdificioFactorySDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas):
                                    codigos_edificios(YAML::LoadFile(RUTA_CODIGOS_EDIFICIOS)),
                                    renderer(renderer),
                                    texturas(texturas) {}

EdificioSDL* EdificioFactorySDL::crearEdificio(uint8_t id_edificio, uint8_t id_jugador, uint8_t casa,
                                uint8_t tipo_edificio, const Coordenadas& coords) {
    // const uint8_t centro = codigos_edificios["CENTRO_DE_CONSTRUCCION"].as<uint8_t>();
    switch (tipo_edificio) {
        case 0: {
            return new CentroSDL(id_edificio, id_jugador, renderer,
                                texturas.obtenerTexEdificio(tipo_edificio),
                                coords, 3, 3, casa);
        }
        case 1: {
            return new CuartelSDL(id_edificio, id_jugador, renderer,
                                 texturas.obtenerTexEdificio(tipo_edificio),
                                 coords, 3, 2, casa);
        }
        case 2: {
            return new FabricaLigeraSDL(id_edificio, id_jugador, renderer,
                                        texturas.obtenerTexEdificio(tipo_edificio),
                                        coords, 3, 3, casa);
        }
        case 3: {
            return new FabricaPesadaSDL(id_edificio, id_jugador, renderer,
                                        texturas.obtenerTexEdificio(tipo_edificio),
                                        coords, 4, 4, casa);
        }
        default: {
            return new CentroSDL(id_edificio, id_jugador, renderer,
                                texturas.obtenerTexEdificio(tipo_edificio),
                                coords, 3, 3, casa);        // TODO: Fix
        }
    }

}
