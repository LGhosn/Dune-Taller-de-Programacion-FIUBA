#include "sdl_vehiculo.h"
#include <cmath>

VehiculoSDL::VehiculoSDL(uint8_t id_unidad,
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
                texturas(texturas.obtenerVehiculo(tipo_unidad)) {}

void VehiculoSDL::update(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom) {
    if (!desplegada) {
        updateTiempoRestante(frames_transcurridos);
    }
    updatePosicionUnidad(offset_x, offset_y, frames_transcurridos, zoom);
}

void VehiculoSDL::updatePosicionUnidad(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom) {
    this->zoom = zoom;
    if (!moviendose) {
        destino.SetX(coords.x * ancho_tile * zoom - offset_x);
        destino.SetY((coords.y * largo_tile) * zoom - offset_y);
    } else {
        if (frames_transcurridos > frames_restantes) {
            moviendose = false;
            coords = coords_siguiente;
            destino.SetX(coords.x * ancho_tile * zoom - offset_x);
            destino.SetY((coords.y * largo_tile) * zoom - offset_y);
        } else {
            frames_restantes -= frames_transcurridos;
            float porcentaje_completo = (float) frames_restantes / (float) frames_para_llegar;
            int8_t diferencia_x = coords_siguiente.x - coords.x;
            int8_t diferencia_y = coords_siguiente.y - coords.y;
            destino.SetX((coords.x * largo_tile + diferencia_x * (1 - porcentaje_completo) * ancho_tile) * zoom - offset_x);
            destino.SetY((coords.y * largo_tile + diferencia_y * (1 - porcentaje_completo) * largo_tile) * zoom - offset_y);
        }
    }
    destino.SetW(ancho_tile * zoom);
    destino.SetH(largo_tile * zoom);
}

void VehiculoSDL::disparar() {

}

void VehiculoSDL::render() {
    if (desplegada) {
        renderer.Copy(texturas[direccion_actual], SDL2pp::NullOpt, destino);
        renderUI();
    } else {
        renderer.SetDrawColor(color.obtenerOscuroSemitransparente());
        renderer.FillRect(destino);
    }
}

VehiculoSDL::~VehiculoSDL() {
    std::cout << "VehiculoSDL: destructor" << std::endl;
}
