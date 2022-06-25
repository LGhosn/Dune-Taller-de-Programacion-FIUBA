#include "sdl_edificio_factory.h"
#include "sdl_centro.h"
#include "sdl_cuartel.h"
#include "sdl_fabrica_ligera.h"
#include "sdl_fabrica_pesada.h"
#include "sdl_palacio.h"
#include "sdl_refineria.h"
#include "sdl_silo.h"
#include "sdl_trampa.h"

EdificioFactorySDL::EdificioFactorySDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas,
                                        YAML::Node& constantes, ColoresSDL& colores):
                                    constantes(constantes),
                                    renderer(renderer),
                                    texturas(texturas),
                                    colores(colores) {}

EdificioSDL* EdificioFactorySDL::crearEdificio(uint8_t id_edificio, uint8_t id_jugador, uint8_t casa,
                                uint8_t tipo_edificio, const Coordenadas& coords) {
    // const uint8_t centro = codigos_edificios["CENTRO_DE_CONSTRUCCION"].as<uint8_t>();
    switch (tipo_edificio) {
        case 0: {
            return new CentroSDL(id_edificio, id_jugador, renderer, texturas,
                                coords, 3, 3, casa, constantes,
                                colores.obtenerColor(id_jugador));
        }
        case 1: {
            return new CuartelSDL(id_edificio, id_jugador, renderer, texturas,
                                 coords, 3, 2, casa, constantes,
                                 colores.obtenerColor(id_jugador));
        }
        case 2: {
            return new FabricaLigeraSDL(id_edificio, id_jugador, renderer, texturas,
                                        coords, 3, 3, casa, constantes,
                                        colores.obtenerColor(id_jugador));
        }
        case 3: {
            return new FabricaPesadaSDL(id_edificio, id_jugador, renderer, texturas,
                                        coords, 4, 4, casa, constantes,
                                        colores.obtenerColor(id_jugador));
        }
        case 4: {
            return new PalacioSDL(id_edificio, id_jugador, renderer, texturas,
                                        coords, 3, 3, casa, constantes,
                                        colores.obtenerColor(id_jugador));
        }
        case 5: {
            return new RefineriaSDL(id_edificio, id_jugador, renderer, texturas,
                                coords, 3, 3, casa, constantes,
                                colores.obtenerColor(id_jugador));
        }
        case 6: {
            return new SiloSDL(id_edificio, id_jugador, renderer, texturas,
                                coords, 1, 1, casa, constantes,
                                colores.obtenerColor(id_jugador));
        }
        case 7: {
            return new TrampaSDL(id_edificio, id_jugador, renderer, texturas,
                                coords, 3, 3, casa, constantes,
                                colores.obtenerColor(id_jugador));
        }
        default:
            throw std::runtime_error("EdificioFactory: codigo de edificio invalido");
    }

}
