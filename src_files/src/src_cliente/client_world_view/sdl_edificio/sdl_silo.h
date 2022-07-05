#ifndef SDL_SILO_H
#define SDL_SILO_H

#include "sdl_edificio.h"
#include <vector>

class SiloSDL : public EdificioSDL {
    std::vector<SDL2pp::Texture>& silos;
    const uint32_t limite_hp_debilitar;
    uint8_t estado_especia = 0;
public:
    SiloSDL(uint8_t id, uint8_t id_jugador, uint16_t vida, SDL2pp::Renderer& renderer,
            TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
            uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color);

    bool cambiarHP(uint16_t hp_edificio) override;

    /*
     * Recibe un numero del 0 al 3 que varia la cantidad de especia que se muestra en
     * el silo.
    */
    void cambiarCantidadEspecia(uint8_t estado_especia);

    void update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frames_transcurridos, float zoom) override;

    void render() override;
};

#endif // SDL_SILO_H
