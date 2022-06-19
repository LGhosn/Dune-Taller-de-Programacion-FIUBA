#include "sdl_fabrica_ligera.h"

FabricaLigeraSDL::FabricaLigeraSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                SDL2pp::Texture& textura, const Coordenadas& coords, uint16_t alto,
                uint16_t ancho, uint8_t casa) :
                EdificioSDL(id, id_jugador, renderer, textura, coords, alto, ancho, casa) {
    origen.SetX(ANCHO_TEX_EDIFICIO_FL);
    origen_paredes.SetX(0);
    switch(casa) {
        case 0: {
            origen.SetY(0);
            origen_paredes.SetY(0);
            break;
        }
        case 1: {
            origen.SetY(ALTO_TEX_EDIFICIO_FL);
            origen_paredes.SetY(ALTO_TEX_EDIFICIO_FL);
            break;
        }
        case 2: {
            origen.SetY(ALTO_TEX_EDIFICIO_FL * 2);
            origen_paredes.SetY(ALTO_TEX_EDIFICIO_FL * 2);
            break;
        }
        default:
            throw std::runtime_error("Casa no valida");   
    }
    origen.SetW(ANCHO_TEX_EDIFICIO_FL);
    origen.SetH(ALTO_TEX_EDIFICIO_FL);
    origen_paredes.SetW(ANCHO_TEX_EDIFICIO_FL);
    origen_paredes.SetH(ALTO_TEX_EDIFICIO_FL);
}

void FabricaLigeraSDL::cambiarHP(uint16_t hp_edificio) {
    if (hp_edificio < LIMITE_HP_DEBILITAR) {
        origen.SetX(2 * ANCHO_TEX_EDIFICIO_FL);
    }
}

void FabricaLigeraSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_actual,
                                float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * LARGO_TILE * zoom - origen_movil_x);
    destino.SetY((coords.y * LARGO_TILE + PADDING_EDIFICIO_FL_Y) * zoom - origen_movil_y);
    destino.SetW(LARGO_TILE * ancho * zoom);
    destino.SetH((LARGO_TILE * alto - 2 * PADDING_EDIFICIO_FL_Y) * zoom);
    destino_paredes.SetX((coords.x * LARGO_TILE + OFFSET_PAREDES_FL_X) * zoom - origen_movil_x);
    destino_paredes.SetY((coords.y * LARGO_TILE + OFFSET_PAREDES_FL_Y) * zoom - origen_movil_y);
    destino_paredes.SetW(destino.GetW());
    destino_paredes.SetH(destino.GetH());
    setearPosicionUI(origen_movil_x, origen_movil_y);
}

void FabricaLigeraSDL::render() {
    renderer.Copy(textura, origen, destino);
    renderer.Copy(textura, origen_paredes, destino_paredes);
}
