#ifndef CLIENT_SDL_INFANTERIA_H
#define CLIENT_SDL_INFANTERIA_H

#include "../sdl_unidad.h"
#include "../../sdl_texturas.h"
#include <vector>

class InfanteriaSDL : public UnidadSDL {
    std::vector<SDL2pp::Texture>& texturas_moviendose;
    std::vector<SDL2pp::Texture>& texturas_quieta;
    std::vector<SDL2pp::Texture>& texturas_disparando;
    bool disparando = false;
    
    // Constantes
    const uint16_t alto;

    void updatePosicionUnidad(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom);

    SDL2pp::Texture& texturaActual();
public:
    InfanteriaSDL(uint8_t id_unidad,
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
    
    void update(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom);
    void render();

    ~InfanteriaSDL() = default;
};

#endif // CLIENT_SDL_INFANTERIA_H
