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
    std::vector<SDL2pp::Chunk> victoria;
    std::vector<SDL2pp::Chunk> derrota;
    std::vector<SDL2pp::Chunk> ataque_gusano;
    std::vector<SDL2pp::Chunk> centro_atacado;

    std::vector<std::vector<SDL2pp::Chunk>> vehiculo_seleccionado;
    std::vector<std::vector<SDL2pp::Chunk>> vehiculo_movido;
    std::vector<std::vector<SDL2pp::Chunk>> infanteria_ligera_seleccionada;
    std::vector<std::vector<SDL2pp::Chunk>> infanteria_ligera_movida;
    std::vector<std::vector<SDL2pp::Chunk>> infanteria_pesada_seleccionada;
    std::vector<std::vector<SDL2pp::Chunk>> infanteria_pesada_movida;
    std::vector<SDL2pp::Chunk> sardaukar_seleccionado;
    std::vector<SDL2pp::Chunk> sardaukar_movido;
    std::vector<SDL2pp::Chunk> fremen_seleccionado;
    std::vector<SDL2pp::Chunk> fremen_movido;

    void cargarMensajesDeVoz();
    void cargarMusica();
    void cargarVoces();
public:
    SonidosSDL(uint8_t casa, YAML::Node& constantes);

    SDL2pp::Music& obtenerMusica();
    SDL2pp::Chunk& obtenerMensajeConstruyendo();
    SDL2pp::Chunk& obtenerMensajeEdificioConstruido();
    SDL2pp::Chunk& obtenerMensajeConstruccionInvalida();
    SDL2pp::Chunk& obtenerMensajeNuevosEdificiosDisponibles();
    SDL2pp::Chunk& obtenerMensajeEntrenando();
    SDL2pp::Chunk& obtenerMensajeEnergiaBaja();
    SDL2pp::Chunk& obtenerMensajeVictoria();
    SDL2pp::Chunk& obtenerMensajeDerrota();
    SDL2pp::Chunk& obtenerMensajeAtaqueGusano();
    SDL2pp::Chunk& obtenerMensajeCentroAtacado();
    SDL2pp::Chunk& obtenerMensajeUnidadSeleccionada(uint8_t tipo_unidad, uint8_t casa);
    SDL2pp::Chunk& obtenerMensajeUnidadMovida(uint8_t tipo_unidad, uint8_t casa);

    SonidosSDL(const SonidosSDL&) = delete;
    SonidosSDL& operator=(const SonidosSDL&) = delete;
    SonidosSDL(SonidosSDL&&) = delete;
    SonidosSDL& operator=(SonidosSDL&&) = delete;
};

#endif // CLIENTE_SDL_SONIDOS_H
