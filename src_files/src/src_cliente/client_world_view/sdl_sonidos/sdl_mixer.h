#ifndef CLIENTE_SDL_MIXER_H
#define CLIENTE_SDL_MIXER_H

#include <SDL2pp/Mixer.hh>
#include "yaml-cpp/yaml.h"
#include "sdl_sonidos.h"

class MixerSDL {
    SDL2pp::Mixer mixer;
    SonidosSDL sonidos;
    uint8_t volumen;
    uint8_t volumen_musica;
public:
    MixerSDL(uint8_t casa, YAML::Node& constantes);

    SonidosSDL& obtenerSonidosSDL();

    void reproducirMensajeConstruyendo();
    void reproducirMensajeEdificioConstruido();
    void reproducirMensajeConstruccionInvalida();
    void reproducirMensajeNuevosEdificiosDisponibles();

    void reproducirMensajeEntrenando();

    void reproducirMensajeEnergiaBaja();
};

#endif // CLIENTE_SDL_MIXER_H
