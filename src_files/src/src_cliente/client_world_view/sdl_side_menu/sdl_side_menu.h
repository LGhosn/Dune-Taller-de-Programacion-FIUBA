#ifndef SDL_SIDE_MENU_H
#define SDL_SIDE_MENU_H

#include <SDL2pp/SDL2pp.hh>
#include "../sdl_texturas.h"
#include "../sdl_sonidos/sdl_mixer.h"
#include "../sdl_sonidos/sdl_sonidos.h"
#include "sdl_tienda/sdl_tienda.h"
#include "sdl_especia.h"
#include "sdl_energia.h"
#include "../../client_solicitudes/cliente_solicitud.h"
#include "../sdl_color/sdl_color.h"

class SideMenuSDL {
    YAML::Node& constantes;
    SDL2pp::Renderer& renderer;
    ColorSDL& color;
    uint8_t casa;
    TiendaSDL tienda;
    EspeciaSDL especia;
    EnergiaSDL energia;
    SDL2pp::Texture& logo_casa;
    SDL2pp::Rect origen_logo_casa;
    SDL2pp::Rect destino_logo_casa;
    SDL2pp::Rect side_menu_rect;

public:
    SideMenuSDL(SDL2pp::Renderer& renderer, MixerSDL& mixer,
                uint8_t casa, TexturasSDL& texturas, uint8_t id_jugador,
                YAML::Node& constantes, ColorSDL& color);

    SolicitudCliente* clickEnMenu(int pos_x, int pos_y);
    SolicitudCliente* clickEnMapa(Coordenadas& coords);

    void modificarEspecia(uint16_t cantidad_especia);
    void modificarEnergia(int16_t cantidad_energia);

    void empezarConstruccionEdificio(uint8_t tipo, uint16_t tiempo_construccion);

    void empezarEntrenamiento(uint8_t tipo, uint16_t tiempo_construccion);

    void actualizarTiendaEdificios(const std::vector<bool>& edificios_comprables);

    /*
     * Le informa al boton del tipo de edificio que fue creado acerca de la construccion del
     * nuevo edificio.
    */
    void edificioCreado(uint8_t tipo);

    void update(long frames_transcurridos);

    void render();
};

#endif
