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

std::shared_ptr<EdificioSDL> EdificioFactorySDL::crearEdificio(uint8_t id_edificio, uint8_t id_jugador, uint8_t casa,
                                uint8_t tipo_edificio, const Coordenadas& coords, uint16_t vida) {
    // const uint8_t centro = codigos_edificios["CENTRO_DE_CONSTRUCCION"].as<uint8_t>();
    switch (tipo_edificio) {
        case 0: {
            return std::shared_ptr<EdificioSDL>( new CentroSDL(id_edificio, id_jugador, vida, renderer, texturas,
                                coords, 3, 3, casa, constantes,
                                colores.obtenerColor(id_jugador)));
        }
        case 1: {
            return std::shared_ptr<EdificioSDL>(new CuartelSDL(id_edificio, id_jugador, vida, renderer, texturas,
                                 coords, 3, 2, casa, constantes,
                                 colores.obtenerColor(id_jugador)));
        }
        case 2: {
            return std::shared_ptr<EdificioSDL>(new FabricaLigeraSDL(id_edificio, id_jugador, vida, renderer, texturas,
                                        coords, 3, 3, casa, constantes,
                                        colores.obtenerColor(id_jugador)));
        }
        case 3: {
            return std::shared_ptr<EdificioSDL>(new FabricaPesadaSDL(id_edificio, id_jugador, vida, renderer, texturas,
                                        coords, 4, 4, casa, constantes,
                                        colores.obtenerColor(id_jugador)));
        }
        case 4: {
            return std::shared_ptr<EdificioSDL>(new PalacioSDL(id_edificio, id_jugador, vida, renderer, texturas,
                                        coords, 3, 3, casa, constantes,
                                        colores.obtenerColor(id_jugador)));
        }
        case 5: {
            return std::shared_ptr<EdificioSDL>(new RefineriaSDL(id_edificio, id_jugador, vida, renderer, texturas,
                                coords, 3, 3, casa, constantes,
                                colores.obtenerColor(id_jugador)));
        }
        case 6: {
            return std::shared_ptr<EdificioSDL>(new SiloSDL(id_edificio, id_jugador, vida, renderer, texturas,
                                coords, 1, 1, casa, constantes,
                                colores.obtenerColor(id_jugador)));
        }
        case 7: {
            return std::shared_ptr<EdificioSDL>(new TrampaSDL(id_edificio, id_jugador, vida, renderer, texturas,
                                coords, 3, 3, casa, constantes,
                                colores.obtenerColor(id_jugador)));
        }
        default:
            throw std::runtime_error("EdificioFactory: codigo de edificio invalido");
    }
}
