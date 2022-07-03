#ifndef CLIENT_SDL_MARCADOR_H
#define CLIENT_SDL_MARCADOR_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "../sdl_color/sdl_color.h"
#include "../sdl_texturas.h"
#include "../../../src_common/common_DTO/dto_info_partida.h"
#include <string>

class MarcadorSDL {
    SDL2pp::Renderer& renderer;
    SDL2pp::Font& fuente;
    ColorSDL& color;
    std::vector<SDL2pp::Rect> destinos_posiciones;
    std::vector<SDL2pp::Rect> destinos_nombres;
    std::vector<SDL2pp::Rect> destinos_puntajes;
    std::map<uint8_t, uint16_t> puntajes;
    InfoPartidaDTO& info_partida;
    bool habilitado = false;

    // Constantes
    const uint8_t jugadores_maximos;
    const uint32_t padding_x;
    const uint32_t padding_y;
    const uint32_t padding_interno;
    const uint32_t padding_texto;
    const uint32_t ancho_posicion;
    const uint32_t ancho_puntaje;
    const uint32_t ancho_mapa;
    const uint32_t largo_mapa;
    const std::string etiqueta_posiciones;
    const std::string etiqueta_nombres;
    const std::string etiqueta_puntaje;

    // Calculos en base a las constantes
    const uint32_t ancho_marcador;
    const uint32_t largo_marcador;
    const SDL2pp::Rect destino_marcador;
    const uint32_t largo_fila;
    const uint32_t largo_texto;
    const uint32_t ancho_nombre;
    const uint32_t largo_max_nombre;
    SDL2pp::Texture textura_etiqueta_posiciones;
    SDL2pp::Texture textura_etiqueta_nombres;
    SDL2pp::Texture textura_etiqueta_puntajes;
    const SDL2pp::Rect destino_etiqueta_posiciones;
    const SDL2pp::Rect destino_etiqueta_nombres;
    const SDL2pp::Rect destino_etiqueta_puntajes;

public:
    MarcadorSDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas, YAML::Node& constantes,
                InfoPartidaDTO& info_partida, ColorSDL& color);

    void actualizarPuntajes(uint8_t id_jugador, uint16_t nuevo_puntaje);

    void habilitar();
    void deshabilitar();

    void render();
};

#endif // CLIENT_SDL_MARCADOR_H
