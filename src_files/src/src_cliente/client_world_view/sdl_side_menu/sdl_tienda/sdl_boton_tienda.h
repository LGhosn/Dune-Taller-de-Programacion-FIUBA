#ifndef SDL_BOTON_TIENDA_H
#define SDL_BOTON_TIENDA_H

#include <SDL2pp/SDL2pp.hh>
#include "../../sdl_texturas.h"
#include "../../../client_solicitudes/cliente_solicitud.h"
#include "../../../../src_common/common_coords.h"

#define RATIO_ANCHO_LARGO_BOTON 1.27f

#define PADDING_TEXTO_X 30
#define TAM_TEXTO_Y 20

#define FPS 60

class BotonTiendaSDL {
    YAML::Node& constantes;
    SDL2pp::Renderer& renderer;
    uint8_t tipo;
    uint8_t casa;
    uint8_t id_jugador;
    SDL2pp::Texture& logo;
    SDL2pp::Texture& texto_listo;
    SDL2pp::Rect origen;
    SDL2pp::Rect destino;
    SDL2pp::Rect destino_construyendo;
    SDL2pp::Rect destino_texto;
    bool habilitado = true;     // temporal
    bool seleccionado = false;
    bool construyendo = false;
    bool listo = true;          // temporal
    long frames_para_construir = 0;
    long frames_restantes_construccion = 0;
    long frame_anterior = 0;
public:
    BotonTiendaSDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas, uint8_t tipo,
                    uint8_t casa, uint8_t id_jugador, SDL2pp::Rect destino,
                    YAML::Node& constantes);

    void habilitar();
    void deshabilitar();

    bool estaSeleccionado() const;

    void empezarConstruccion(int milisegundos_para_construir);

    bool contiene(int pos_x, int pos_y) const;

    SolicitudCliente* click();
    SolicitudCliente* clickEnMapa(Coordenadas& coords);

    void update(long frame_actual);
    void render();

    ~BotonTiendaSDL() = default;
};

#endif
