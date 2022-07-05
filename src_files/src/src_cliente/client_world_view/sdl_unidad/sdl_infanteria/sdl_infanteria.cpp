#include "sdl_infanteria.h"

InfanteriaSDL::InfanteriaSDL(uint8_t id_unidad,
                uint8_t id_jugador,
                uint8_t tipo_unidad,
                uint8_t casa,
                bool unidad_amiga,
                MixerSDL& mixer,
                SDL2pp::Renderer& renderer,
                TexturasSDL& texturas,
                const Coordenadas& coords,
                YAML::Node& constantes,
                ColorSDL& color,
                uint16_t tiempo_aparicion,
                uint16_t vida) :
                UnidadSDL(id_unidad, id_jugador, tipo_unidad, casa, unidad_amiga, mixer, renderer,
                        coords, constantes, color, tiempo_aparicion, vida),
                texturas_moviendose(texturas.obtenerInfanteriaMoviendose(tipo_unidad)),
                texturas_quieta(texturas.obtenerInfanteriaQuieta(tipo_unidad)),
                texturas_disparando(texturas.obtenerInfanteriaDisparando(tipo_unidad)),
                alto(constantes["WorldView"]["Unidades"]["Alto"].as<uint16_t>()) {}

void InfanteriaSDL::updatePosicionUnidad(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom) {
    this->zoom = zoom;
    float relacion_ancho_largo = (float) texturaActual().GetWidth() / (float) texturaActual().GetHeight();
    uint16_t ancho = relacion_ancho_largo * alto;
    uint16_t padding_x = (ancho_tile - ancho) / 2;
    uint16_t padding_y = (largo_tile - alto) / 2;
    if (!moviendose) {
        destino.SetX((coords.x * ancho_tile + padding_x) * zoom - offset_x);
        destino.SetY((coords.y * largo_tile + padding_y) * zoom - offset_y);
    } else {
        if (frames_transcurridos > frames_restantes) {
            moviendose = false;
            coords = coords_siguiente;
            destino.SetX((coords.x * ancho_tile + padding_x) * zoom - offset_x);
            destino.SetY((coords.y * largo_tile + padding_y) * zoom - offset_y);
        } else {
            frames_restantes -= frames_transcurridos;
            float porcentaje_completo = (float) frames_restantes / (float) frames_para_llegar;
            int8_t diferencia_x = coords_siguiente.x - coords.x;
            int8_t diferencia_y = coords_siguiente.y - coords.y;
            destino.SetX((coords.x * largo_tile + diferencia_x * (1 - porcentaje_completo) * ancho_tile + padding_x) * zoom - offset_x);
            destino.SetY((coords.y * largo_tile + diferencia_y * (1 - porcentaje_completo) * largo_tile + padding_y) * zoom - offset_y);
        }
    }
    destino.SetW(ancho * zoom);
    destino.SetH(alto * zoom);
}

SDL2pp::Texture& InfanteriaSDL::texturaActual() {
    if (disparando) {
        return texturas_disparando[direccion_actual];
    } else if (moviendose) {
        return texturas_moviendose[direccion_actual];
    } else {
        return texturas_quieta[direccion_actual];
    }
}

void InfanteriaSDL::render() {
    if (desplegada) {
        renderer.Copy(texturaActual(), SDL2pp::NullOpt, destino);
        renderUI();
    } else {
        renderer.SetDrawColor(color.obtenerOscuroSemitransparente());
        renderer.FillRect(destino);
    }
}