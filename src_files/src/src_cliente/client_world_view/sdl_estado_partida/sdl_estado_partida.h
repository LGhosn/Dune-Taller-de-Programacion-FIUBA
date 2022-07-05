#ifndef CLIENT_SDL_ESTADO_PARTIDA_H
#define CLIENT_SDL_ESTADO_PARTIDA_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "../sdl_sonidos/sdl_mixer.h"
#include "../sdl_color/sdl_color.h"
#include "../sdl_texturas.h"


class EstadoPartidaSDL {
    SDL2pp::Renderer& renderer;
    MixerSDL& mixer;
    SDL2pp::Texture& victoria;
    SDL2pp::Texture& derrota;
    ColorSDL& color;
    bool renderizar = false;
    bool esGanador = false;

    // Constantes
    const uint32_t ancho_mapa;
    const uint32_t largo_mapa;
    const uint32_t padding_x;
    const uint32_t padding_y;
    const uint32_t largo_texto;

    SDL2pp::Rect destino_cartel;

public:
    EstadoPartidaSDL(SDL2pp::Renderer& renderer, MixerSDL& mixer,
                    TexturasSDL& texturas, ColorSDL& color,
                    YAML::Node& constantes);
    
    void mostrarEstado(bool esGanador);

    void render();
};

#endif // CLIENT_SDL_ESTADO_PARTIDA_H
