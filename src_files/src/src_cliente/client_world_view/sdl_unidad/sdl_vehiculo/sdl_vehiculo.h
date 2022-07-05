#ifndef SDL_VEHICULO_H
#define SDL_VEHICULO_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "../../sdl_texturas.h"
#include "../sdl_unidad.h"


#define ABAJO_UNIDAD 0
#define ABAJO_IZQ_UNIDAD 1
#define IZQUIERDA_UNIDAD 2
#define ARRIBA_IZQ_UNIDAD 3
#define ARRIBA_UNIDAD 4
#define ARRIBA_DER_UNIDAD 5
#define DERECHA_UNIDAD 6
#define ABAJO_DER_UNIDAD 7

class VehiculoSDL : public UnidadSDL {
private:
    std::vector<SDL2pp::Texture>& texturas;

    void updatePosicionUnidad(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom);

public:
    VehiculoSDL(uint8_t id_unidad,
                uint8_t id_jugador,
                uint8_t tipo_unidad,
                uint8_t casa,
                bool unidad_amiga,
                MixerSDL& mixer,
                SDL2pp::Renderer& renderer,
                TexturasSDL& texturas,
                const Coordenadas& coords,
                YAML::Node& constantes,
                ColorSDL& color,
                uint16_t tiempo_aparicion,
                uint16_t vida);

    virtual void disparar();

    void update(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom);
    void render();
    ~VehiculoSDL();
};

#endif //SDL_VEHICULO_H
