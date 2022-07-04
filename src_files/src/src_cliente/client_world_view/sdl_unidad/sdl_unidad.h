#ifndef SDL_UNIDAD_H
#define SDL_UNIDAD_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "../../../src_common/common_coords.h"
#include "../sdl_color/sdl_color.h"
#include "../sdl_texturas.h"

#define ABAJO_UNIDAD 0
#define ABAJO_IZQ_UNIDAD 1
#define IZQUIERDA_UNIDAD 2
#define ARRIBA_IZQ_UNIDAD 3
#define ARRIBA_UNIDAD 4
#define ARRIBA_DER_UNIDAD 5
#define DERECHA_UNIDAD 6
#define ABAJO_DER_UNIDAD 7

class UnidadSDL {
protected:
    uint8_t id_unidad;
    uint8_t id_jugador;
    uint8_t tipo_unidad;
    SDL2pp::Renderer& renderer;
    std::vector<SDL2pp::Texture>& texturas;
    Coordenadas coords;
    Coordenadas coords_siguiente;
    ColorSDL& color;
    long frames_restantes = 0;
    uint16_t frames_para_llegar = 0;
    SDL2pp::Rect destino;
    SDL2pp::Rect destino_ui;
    bool seleccionado = false;
    bool desplegada = false;
    bool moviendose = false;
    float zoom;
    uint8_t direccion_actual = 0;
    float distancia = 0.0f;

    // Constantes
    const int32_t offset_x_hp;
    const int32_t offset_y_hp;
    const uint32_t alto_hp;
    const uint32_t padding_x_hp;
    const uint32_t padding_rect_hp;
    const float relacion_lineas_largo;
    const uint32_t ancho_tile;
    const uint32_t largo_tile;
    const uint16_t fps;
    //const uint8_t codigo_atreides;
    //const uint8_t codigo_harkonnen;
    //const uint8_t codigo_ordos;*/

    //void setearPosicionUI(uint32_t origen_movil_x, uint32_t origen_movil_y);

private:
    void renderRectanguloSeleccion();
    void renderHP();

    void updatePosicionUnidad(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom);
    void updateTiempoRestante(long frames_transcurridos);

    void actualizarCoordenadaFutura(uint8_t direccion_actual);

public:
    UnidadSDL(uint8_t id_unidad,
                uint8_t id_jugador,
                uint8_t tipo_unidad,
                SDL2pp::Renderer& renderer,
                TexturasSDL& texturas,
                const Coordenadas& coords,
                YAML::Node& constantes,
                ColorSDL& color,
                uint16_t tiempo_aparicion);


    void cambiarHP(uint16_t hp_edificio);
    bool contiene(int pos_x, int pos_y);
    void seleccionar();
    void deseleccionar();
    uint8_t obtenerId() const;

    void update(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom);
    void render();
    void renderUI();
    void moverse(uint8_t direccion, uint16_t tiempo_movimiento);
    ~UnidadSDL();
};

#endif //SDL_UNIDAD_H
