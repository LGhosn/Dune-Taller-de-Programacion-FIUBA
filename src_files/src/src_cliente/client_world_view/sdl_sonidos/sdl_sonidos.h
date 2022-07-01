#ifndef CLIENTE_SDL_SONIDOS_H
#define CLIENTE_SDL_SONIDOS_H

#include <SDL2pp/Music.hh>
#include <SDL2pp/Chunk.hh>
#include "yaml-cpp/yaml.h"

#define RUTA_MUSICA RESOURCE_PATH "/musica/"

#define RUTA_SONIDOS RESOURCE_PATH "/sonidos/"

class SonidosSDL {
    uint8_t casa;
    std::vector<SDL2pp::Music> musica;
    std::vector<SDL2pp::Chunk> construyendo;
    std::vector<SDL2pp::Chunk> edificio_construido;
    std::vector<SDL2pp::Chunk> construccion_invalida;
    std::vector<SDL2pp::Chunk> nuevos_edificios_disponibles;

    std::vector<SDL2pp::Chunk> entrenando;

    std::vector<SDL2pp::Chunk> energia_baja;

    void cargarMensajesDeVoz();
    void cargarMusica();
public:
    SonidosSDL(uint8_t casa, YAML::Node& constantes);

    SDL2pp::Music& obtenerMusica();
    SDL2pp::Chunk& obtenerMensajeConstruyendo();
    SDL2pp::Chunk& obtenerMensajeEdificioConstruido();
    SDL2pp::Chunk& obtenerMensajeConstruccionInvalida();
    SDL2pp::Chunk& obtenerMensajeNuevosEdificiosDisponibles();

    SDL2pp::Chunk& obtenerMensajeEntrenando();

    SDL2pp::Chunk& obtenerMensajeEnergiaBaja();

    SonidosSDL(const SonidosSDL&) = delete;
    SonidosSDL& operator=(const SonidosSDL&) = delete;
    SonidosSDL(SonidosSDL&&) = delete;
    SonidosSDL& operator=(SonidosSDL&&) = delete;
};

#endif // CLIENTE_SDL_SONIDOS_H
