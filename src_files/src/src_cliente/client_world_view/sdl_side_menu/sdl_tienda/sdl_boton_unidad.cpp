#include "sdl_boton_unidad.h"

BotonUnidadSDL::BotonUnidadSDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas, uint8_t tipo,
                    uint8_t casa, uint8_t id_jugador, SDL2pp::Rect destino,
                    YAML::Node& constantes):
                    renderer(renderer),
                    tipo(tipo),
                    casa(casa),
                    id_jugador(id_jugador),
                    logo(texturas.obtenerLogoUnidad(tipo)),
                    destino(destino) {}

bool BotonUnidadSDL::contiene(int pos_x, int pos_y) const {
    return destino.Contains(pos_x, pos_y);
}

void BotonUnidadSDL::habilitar() {
    habilitado = true;
}

void BotonUnidadSDL::deshabilitar() {
    habilitado = false;
}

void BotonUnidadSDL::empezarConstruccion(uint16_t milisegundos_para_construir) {
    construyendo = true;
    frames_para_construir = milisegundos_para_construir * fps / 1000;
    frames_restantes_construccion = frames_para_construir;
}

SolicitudCliente* BotonUnidadSDL::click(int pos_x, int pos_y) {
    if (!this->contiene(pos_x, pos_y))
        return nullptr;
    if (habilitado && !construyendo) {
        // return new SolComprarEdificioCliente(tipo);
    } else {
        return nullptr;
    }
    return nullptr;
}

void BotonUnidadSDL::update(long frames_transcurridos) {
    if (construyendo) {
        if (frames_restantes_construccion > frames_transcurridos) {
            frames_restantes_construccion -= frames_transcurridos;
            float porciento_completado = (float) frames_restantes_construccion / (float) frames_para_construir;
            destino_construyendo.SetY(destino.GetY() + destino.GetH() * (1 - porciento_completado));
            destino_construyendo.SetH(destino.GetH() * porciento_completado);
        } else {
            construyendo = false;
        }
    }
}

void BotonUnidadSDL::render() {
    renderer.Copy(logo, SDL2pp::NullOpt, destino);
    if (!habilitado && !construyendo) {
        renderer.SetDrawColor(0, 0, 0, 150);
        renderer.FillRect(destino);
    }
    if (construyendo) {
        renderer.SetDrawColor(0, 0, 0, 150);
        renderer.FillRect(destino_construyendo);
    }
}