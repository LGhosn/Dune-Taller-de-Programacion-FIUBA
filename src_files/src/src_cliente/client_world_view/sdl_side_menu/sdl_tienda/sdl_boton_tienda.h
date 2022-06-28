#ifndef SDL_BOTON_TIENDA_H
#define SDL_BOTON_TIENDA_H

#include <SDL2pp/SDL2pp.hh>
#include "../../sdl_texturas.h"
#include "../../../client_solicitudes/cliente_solicitud.h"
#include "../../../../src_common/common_coords.h"

class BotonTiendaSDL {
    SDL2pp::Renderer& renderer;
    uint8_t tipo;
    uint8_t casa;
    uint8_t id_jugador;
    SDL2pp::Texture& logo;
    SDL2pp::Texture& texto_listo;
    
    bool habilitado = false;
    bool seleccionado = false;
    bool construyendo = false;
    bool listo = false;
    uint16_t frames_para_construir = 0;
    uint16_t frames_restantes_construccion = 0;

    // Constantes
    const float relacion_ancho_largo;
    const uint32_t padding_texto_x;
    const uint32_t tam_texto_y;
    const uint8_t fps;

    SDL2pp::Rect origen;
    SDL2pp::Rect destino;
    SDL2pp::Rect destino_construyendo;
    SDL2pp::Rect destino_texto;

    bool contiene(int pos_x, int pos_y) const;

public:
    BotonTiendaSDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas, uint8_t tipo,
                    uint8_t casa, uint8_t id_jugador, SDL2pp::Rect destino,
                    YAML::Node& constantes);

    void habilitar();
    void deshabilitar();

    /*
     * Quita el texto "listo" del boton debido a que ya se creo el edificio.
    */
    void edificioCreado();

    bool estaSeleccionado() const;

    void empezarConstruccion(uint16_t milisegundos_para_construir);

    SolicitudCliente* click(int pos_x, int pos_y);
    SolicitudCliente* clickEnMapa(Coordenadas& coords);

    void update(long frames_transcurridos);
    void render();

    ~BotonTiendaSDL() = default;
};

#endif
