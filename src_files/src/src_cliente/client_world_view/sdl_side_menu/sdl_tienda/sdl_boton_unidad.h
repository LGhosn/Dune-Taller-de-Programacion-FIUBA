#ifndef SDL_BOTON_UNIDAD_H
#define SDL_BOTON_UNIDAD_H

#include "../../sdl_texturas.h"
#include "../../../client_solicitudes/cliente_solicitud.h"
#include "../../sdl_sonidos/sdl_mixer.h"

class BotonUnidadSDL {
    SDL2pp::Renderer& renderer;
    MixerSDL& mixer;
    uint8_t tipo_unidad;
    uint8_t casa;
    uint8_t id_jugador;
    SDL2pp::Texture& logo;
    bool habilitado = false;
    bool entrenando = false;
    uint16_t frames_para_entrenar = 0;
    uint16_t frames_restantes_entrenamiento = 0;

    // Constantes
    float relacion_ancho_largo;
    uint32_t padding_texto_x;
    uint32_t tam_texto_y;
    uint16_t fps;
    
    SDL2pp::Rect destino;
    SDL2pp::Rect destino_construyendo;

    bool contiene(int pos_x, int pos_y) const;
public:
    BotonUnidadSDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas, MixerSDL& mixer,
                    uint8_t tipo,
                    uint8_t casa, uint8_t id_jugador, SDL2pp::Rect destino,
                    YAML::Node& constantes);

    void habilitar();
    void deshabilitar();

    void empezarEntrenamiento(uint16_t segundos_para_construir);

    SolicitudCliente* click(int pos_x, int pos_y);

    void update(long frames_transcurridos);
    void render();

    ~BotonUnidadSDL() = default;

};

#endif // SDL_BOTON_UNIDAD_H
