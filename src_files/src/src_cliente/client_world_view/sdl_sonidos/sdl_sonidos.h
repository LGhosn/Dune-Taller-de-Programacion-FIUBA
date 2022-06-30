#ifndef CLIENTE_SDL_SONIDOS_H
#define CLIENTE_SDL_SONIDOS_H

#include <SDL2pp/Music.hh>
#include <SDL2pp/Chunk.hh>
#include "yaml-cpp/yaml.h"

#define RUTA_PLOTTING RESOURCE_PATH "/musica/plotting.mp3"

#define RUTA_SONIDOS RESOURCE_PATH "/sonidos/"

class SonidosSDL {
    uint8_t casa;
    SDL2pp::Music plotting;
    std::vector<SDL2pp::Chunk> construyendo;
    std::vector<SDL2pp::Chunk> edificio_construido;
    std::vector<SDL2pp::Chunk> nuevos_edificios_disponibles;

    void cargarMensajesDeVoz();
public:
    SonidosSDL(uint8_t casa, YAML::Node& constantes);

    SDL2pp::Music& obtenerMusica();
    SDL2pp::Chunk& obtenerMensajeConstruyendo();
    SDL2pp::Chunk& obtenerMensajeEdificioConstruido();
    SDL2pp::Chunk& obtenerMensajeNuevosEdificiosDisponibles();

    SonidosSDL(const SonidosSDL&) = delete;
    SonidosSDL& operator=(const SonidosSDL&) = delete;
    SonidosSDL(SonidosSDL&&) = delete;
    SonidosSDL& operator=(SonidosSDL&&) = delete;
};

#endif // CLIENTE_SDL_SONIDOS_H
