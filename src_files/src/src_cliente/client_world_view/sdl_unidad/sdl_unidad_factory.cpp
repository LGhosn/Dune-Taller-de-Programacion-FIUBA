#include "sdl_unidad_factory.h"

std::shared_ptr<UnidadSDL> UnidadFactorySDL::crearUnidad(uint8_t id_unidad,
                                        uint8_t id_jugador,
                                        SDL2pp::Renderer& renderer,
                                        TexturasSDL& texturas,
                                        const Coordenadas& coords,
                                        YAML::Node& constantes,
                                        ColoresSDL& colores,
                                        long tiempo_aparicion,
                                        uint8_t tipo_unidad) {
    // switch (tipo_unidad) {
       /* case 0: {
            return new InfanteriaLigeraSDL(id_unidad,
                                           id_jugador,
                                           renderer,
                                           texturas,
                                           coords,
                                           constantes,
                                           color,
                                           tiempo_aparicion);
        }
        case 1: {
            return new InfanteriaPesadaSDL( id_unidad,
                                             id_jugador,
                                            renderer,
                                            texturas,
                                            coords,
                                            constantes,
                                            color,
                                            tiempo_aparicion);
        }
        case 2: {
            return new FremenSDL(id_unidad,
                                id_jugador,
                                renderer,
                                texturas,
                                coords,
                                constantes,
                                color,
                                tiempo_aparicion);
        }
        case 3: {
            return new SardaukarSDL(id_unidad,
                                    id_jugador,
                                    renderer,
                                    texturas,
                                    coords,
                                    constantes,
                                    color,
                                    tiempo_aparicion);
        }
        case 4: {
            return new TrikeSDL(id_unidad,
                                id_jugador,
                                renderer,
                                texturas,
                                coords,
                                constantes,
                                color,
                                tiempo_aparicion);
        }
        case 5: {
            return new RaiderSDL(id_unidad,
                                id_jugador,
                                renderer,
                                texturas,
                                coords,
                                constantes,
                                color,
                                tiempo_aparicion);
        }
        case 6: {
            return new TanqueSDL(id_unidad,
                                id_jugador,
                                renderer,
                                texturas,
                                coords,
                                constantes,
                                color,
                                tiempo_aparicion);
        }
        case 7: {
            return new TanqueSonicoSDL(id_unidad,
                                        id_jugador,
                                        renderer,
                                        texturas,
                                        coords,
                                        constantes,
                                        color,
                                        tiempo_aparicion);
        }
        case 8: {
            return new DesviadorSDL(id_unidad,
                                    id_jugador,
                                    renderer,
                                    texturas,
                                    coords,
                                    constantes,
                                    color,
                                    tiempo_aparicion);
        }
        case 9: {
            return new DevastadorSDL(id_unidad,
                                    id_jugador,
                                    renderer,
                                    texturas,
                                    coords,
                                    constantes,
                                    color,
                                    tiempo_aparicion);
        }
        case 10: {
            return new CosechadoraSDL(id_unidad,
                                        id_jugador,
                                        renderer,
                                        texturas,
                                        coords,
                                        constantes,
                                        color,
                                        tiempo_aparicion);
        }*/
        // default:
        //     throw std::runtime_error("UnidadFactory: codigo de Unidad invalido");
    // }
    return std::shared_ptr<UnidadSDL>(new UnidadSDL(
        id_unidad, id_jugador, renderer, texturas, coords, constantes,
        colores.obtenerColor(id_jugador), tiempo_aparicion));
}
