#ifndef SDL_UNIDAD_H
#define SDL_UNIDAD_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "../../../src_common/common_coords.h"
#include "../sdl_color/sdl_color.h"
#include "../sdl_texturas.h"

class UnidadSDL {
protected:
    uint8_t id_unidad;
    uint8_t id_jugador;
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& textura;
    Coordenadas coords;
    ColorSDL& color;
    long frames_restantes;
    SDL2pp::Rect destino;
    SDL2pp::Rect destino_ui;
    bool seleccionado = false;
    float zoom;

    // Constantes
    const int32_t offset_x_hp;
    const int32_t offset_y_hp;
    const uint32_t alto_hp;
    const uint32_t padding_x_hp;
    const uint32_t padding_rect_hp;
    const float relacion_lineas_largo;
    const uint32_t ancho_tile;
    const uint32_t largo_tile;
    //const uint8_t codigo_atreides;
    //const uint8_t codigo_harkonnen;
    //const uint8_t codigo_ordos;*/

    //void setearPosicionUI(uint32_t origen_movil_x, uint32_t origen_movil_y);

private:
    void renderRectanguloSeleccion();
    void renderHP();

public:
    UnidadSDL(uint8_t id_unidad,
                uint8_t id_jugador,
                SDL2pp::Renderer& renderer,
                SDL2pp::Texture& textura,
                const Coordenadas& coords,
                YAML::Node& constantes,
                ColorSDL& color,
                long frames_restantes);


    void cambiarHP(uint16_t hp_edificio);
    bool contiene(int pos_x, int pos_y);
    void seleccionar();
    void deseleccionar();
    bool listaParaRenderizar(long frames_actual);
    virtual void update(uint32_t offset_x, uint32_t offset_y, long frame_actual, float zoom);
    virtual void render();
    void renderUI();
    void moverse(char direccion, long tiempo_movimiento);
    virtual ~UnidadSDL() = default;
};

#endif //SDL_UNIDAD_H
