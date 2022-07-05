#ifndef SDL_UNIDAD_H
#define SDL_UNIDAD_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "../../../src_common/common_coords.h"
#include "../sdl_color/sdl_color.h"
#include "../sdl_sonidos/sdl_mixer.h"


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
    uint8_t casa;
    uint16_t vida_actual;
    uint16_t vida_total;
    bool unidad_amiga;
    MixerSDL& mixer;
    SDL2pp::Renderer& renderer;
    Coordenadas coords;
    Coordenadas coords_siguiente;
    ColorSDL& color;
    long frames_restantes = 0;
    uint16_t frames_para_llegar = 0;
    SDL2pp::Rect destino;
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

    void renderRectanguloSeleccion();
    void renderHP();

    void updateTiempoRestante(long frames_transcurridos);
    void actualizarCoordenadaFutura(uint8_t direccion_actual);

    virtual void updatePosicionUnidad(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom) = 0;

public:
    UnidadSDL(uint8_t id_unidad,
                uint8_t id_jugador,
                uint8_t tipo_unidad,
                uint8_t casa,
                bool unidad_amiga,
                MixerSDL& mixer,
                SDL2pp::Renderer& renderer,
                const Coordenadas& coords,
                YAML::Node& constantes,
                ColorSDL& color,
                uint16_t tiempo_aparicion,
                uint16_t vida);


    void cambiarHP(uint16_t hp_unidad);
    bool contiene(int pos_x, int pos_y);
    void seleccionar();
    void deseleccionar();
    uint8_t obtenerId() const;
    uint8_t obtenerIdJugador() const;
    
    void update(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom);
    virtual void render() = 0;
    void renderUI();
    void moverse(uint8_t direccion, uint16_t tiempo_movimiento);
    virtual ~UnidadSDL() = default;
};

#endif //SDL_UNIDAD_H
