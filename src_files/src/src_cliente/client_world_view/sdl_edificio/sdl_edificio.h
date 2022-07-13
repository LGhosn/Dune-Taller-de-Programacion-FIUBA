#ifndef SDL_EDIFICIO_H
#define SDL_EDIFICIO_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "../../../src_common/common_coords.h"
#include "../sdl_color/sdl_color.h"
#include "../sdl_texturas.h"

class EdificioSDL {
protected:
    uint8_t id;
    uint8_t id_jugador;
    uint16_t vida_restante;
    const uint16_t vida_total;
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& textura;
    SDL2pp::Texture& textura_debilitado;
    SDL2pp::Texture& textura_slab;
    ColorSDL& color;
    SDL2pp::Rect origen;
    SDL2pp::Rect destino;
    SDL2pp::Rect destino_ui;
    Coordenadas coords;
    uint16_t alto, ancho;
    int pos_en_tex_x, pos_en_tex_y;
    long frame_anterior = 0;
    bool seleccionado = false;
    float zoom;
    bool debilitado = false;

    // Constantes
    const int alto_hp;
    const int ancho_hp;
    const int offset_x_hp;
    const int offset_y_hp;
    const int padding_x_hp;
    const int padding_rect_hp;
    const float relacion_lineas_largo;
    const int ancho_tile;
    const int largo_tile;
    const uint8_t codigo_atreides;
    const uint8_t codigo_harkonnen;
    const uint8_t codigo_ordos;

    void setearPosicionUI(uint32_t origen_movil_x, uint32_t origen_movil_y);

    void renderCimientos();

private:
    void renderRectanguloSeleccion();
    void renderHP();

public:
    EdificioSDL(uint8_t id, uint8_t id_jugador, uint16_t vida,
                SDL2pp::Renderer& renderer, SDL2pp::Texture& textura,
                SDL2pp::Texture& textura_debilitado,
                const Coordenadas& coords, uint16_t alto, uint16_t ancho,
                uint8_t casa, YAML::Node& constantes, ColorSDL& color,
                SDL2pp::Texture& textura_slab);

    Coordenadas obtenerDimensiones() const;
    
    virtual bool cambiarHP(uint16_t hp_edificio) = 0;
    
    void seleccionar();
    void deseleccionar();

    bool contiene(uint32_t pos_x, uint32_t pos_y) const;

    virtual void update(uint32_t offset_x, uint32_t offset_y, long frame_transcurridos, float zoom) = 0;

    virtual void render() = 0;

    void renderUI();

    virtual uint8_t obtenerId() const;
    virtual uint8_t obtenerIdJugador() const;

    virtual ~EdificioSDL() = default;
};

#endif
