#ifndef CLIENT_SDL_ESTADO_PARTIDA_H
#define CLIENT_SDL_ESTADO_PARTIDA_H

#include <SDL2pp/SDL2pp.hh>
#include "../sdl_sonidos/sdl_mixer.h"
#include "../sdl_color/sdl_color.h"


class EstadoPartidaSDL {
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& victoria;
    SDL2pp::Texture& derrota;
    ColorSDL& color;

public:
    EstadoPartidaSDL(SDL2pp::Renderer& renderer, MixerSDL& mixer,
                    TexturasSDL& texturas, ColorSDL& color);
};

#endif // CLIENT_SDL_ESTADO_PARTIDA_H
