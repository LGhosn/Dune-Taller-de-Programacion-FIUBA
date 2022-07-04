#include "sdl_boton_unidad.h"
#include "../../../client_solicitudes/sol_comprar_unidad.h"
#include <utility>


BotonUnidadSDL::BotonUnidadSDL(SDL2pp::Renderer& renderer,
                                TexturasSDL& texturas,
                                MixerSDL& mixer,
                                uint8_t tipo_unidad,
                                uint8_t casa,
                                uint8_t id_jugador,
                                SDL2pp::Rect destino,
                                YAML::Node& constantes):
                                renderer(renderer),
                                mixer(mixer),
                                tipo_unidad(tipo_unidad),
                                casa(casa),
                                id_jugador(id_jugador),
                                logo(texturas.obtenerLogoUnidad(tipo_unidad)),
                                fps(constantes["FPS"].as<uint16_t>()),
                                destino(destino),
                                destino_construyendo(destino.GetX(), destino.GetY(), destino.GetW(), destino.GetH()) {}

bool BotonUnidadSDL::contiene(int pos_x, int pos_y) const {
    return destino.Contains(pos_x, pos_y);
}

void BotonUnidadSDL::habilitar() {
    habilitado = true;
}

void BotonUnidadSDL::deshabilitar() {
    habilitado = false;
}

void BotonUnidadSDL::empezarEntrenamiento(uint16_t segundos_para_construir) {
    entrenando = true;
    frames_para_entrenar = segundos_para_construir * fps;
    frames_restantes_entrenamiento = frames_para_entrenar;
    mixer.reproducirMensajeEntrenando();
}

SolicitudCliente* BotonUnidadSDL::click(int pos_x, int pos_y) {
    if (!this->contiene(pos_x, pos_y))
        return nullptr;
    if (habilitado && !entrenando) {
        return new SolComprarUnidadCliente(tipo_unidad);
    }
    return nullptr;
}

void BotonUnidadSDL::update(long frames_transcurridos) {
    if (entrenando) {
        if (frames_restantes_entrenamiento > frames_transcurridos) {
            frames_restantes_entrenamiento -= frames_transcurridos;
            float porciento_completado = (float) frames_restantes_entrenamiento / (float) frames_para_entrenar;
            destino_construyendo.SetY(destino.GetY() + (float) destino.GetH() * (1 - porciento_completado));
            destino_construyendo.SetH(destino.GetH() * porciento_completado);
        } else {
            entrenando = false;
        }
    }
}

void BotonUnidadSDL::render() {
    renderer.Copy(logo, SDL2pp::NullOpt, destino);
    if (!habilitado && !entrenando) {
        renderer.SetDrawColor(0, 0, 0, 150);
        renderer.FillRect(destino);
    }
    if (entrenando) {
        renderer.SetDrawColor(0, 0, 0, 150);
        renderer.FillRect(destino_construyendo);
    }
}
