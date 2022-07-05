#include "sdl_unidad.h"

UnidadSDL::UnidadSDL(uint8_t id_unidad,
                uint8_t id_jugador,
                uint8_t tipo_unidad,
                uint8_t casa,
                bool unidad_amiga,
                MixerSDL& mixer,
                SDL2pp::Renderer& renderer,
                const Coordenadas& coords,
                YAML::Node& constantes,
                ColorSDL& color,
                uint16_t tiempo_aparicion,
                uint16_t vida) :
                id_unidad(id_unidad),
                id_jugador(id_jugador),
                tipo_unidad(tipo_unidad),
                casa(casa),
                vida_actual(vida),
                vida_total(vida),
                unidad_amiga(unidad_amiga),
                mixer(mixer),
                renderer(renderer),
                coords(coords),
                coords_siguiente(coords),
                color(color),
                offset_x_hp(constantes["WorldView"]["Unidades"]["UI"]["HP"]["OffsetX"].as<int32_t>()),
                offset_y_hp(constantes["WorldView"]["Unidades"]["UI"]["HP"]["OffsetY"].as<int32_t>()),
                alto_hp(constantes["WorldView"]["Unidades"]["UI"]["HP"]["Alto"].as<uint32_t>()),
                padding_x_hp(constantes["WorldView"]["Unidades"]["UI"]["HP"]["PaddingX"].as<uint32_t>()),
                padding_rect_hp(constantes["WorldView"]["Unidades"]["UI"]["HP"]["PaddingRect"].as<uint32_t>()),
                relacion_lineas_largo(constantes["WorldView"]["Unidades"]["UI"]["RelacionLineasLargo"].as<float>()),
                ancho_tile(constantes["WorldView"]["Mapa"]["Tiles"]["Largo"].as<uint32_t>()),
                largo_tile(constantes["WorldView"]["Mapa"]["Tiles"]["Largo"].as<uint32_t>()),
                fps(constantes["FPS"].as<uint16_t>()) {
    frames_restantes = tiempo_aparicion * fps;
}

void UnidadSDL::updateTiempoRestante(long frames_transcurridos) {
    if (frames_restantes > frames_transcurridos) {
        frames_restantes -= frames_transcurridos;
    } else {
        desplegada = true;
    }
}
void UnidadSDL::seleccionar() {
    if (unidad_amiga) {
        seleccionado = true;
        mixer.reproducirUnidadSeleccionada(tipo_unidad, casa);
    }
}

void UnidadSDL::deseleccionar() {
    seleccionado = false;
}

uint8_t UnidadSDL::obtenerId() const {
    return id_unidad;
}

bool UnidadSDL::contiene(int pos_x, int pos_y) {
    return destino.Contains(pos_x, pos_y);
}

void UnidadSDL::cambiarHP(uint16_t hp_unidad) {
    vida_actual = hp_unidad;
}

void UnidadSDL::renderUI() {
    if (seleccionado) {
        renderRectanguloSeleccion();
    }
    renderHP();
}

void UnidadSDL::renderHP() {
    renderer.SetDrawColor(0, 0, 0, 150);
    renderer.FillRect(
        destino.GetX(),
        destino.GetY(),
        destino.GetX() + destino.GetW(),
        destino.GetY() - alto_hp * zoom
    );

    float porcentaje_restante = (float) vida_actual / (float) vida_total;
    renderer.SetDrawColor(color.obtenerPrimario());
    renderer.FillRect(
        destino.GetX(),
        destino.GetY(),
        destino.GetX() + destino.GetW() * porcentaje_restante,
        destino.GetY() - alto_hp * zoom
    );

    renderer.SetDrawColor(0, 0, 0);
    renderer.DrawRect(
        destino.GetX(),
        destino.GetY(),
        destino.GetX() + destino.GetW(),
        destino.GetY() - alto_hp * zoom
    );
}

void UnidadSDL::renderRectanguloSeleccion() {
    renderer.SetDrawColor(255, 255, 255);
        int largo_lineas_seleccionado = destino.GetW() * relacion_lineas_largo;

        renderer.DrawLine(
            destino.GetX(), destino.GetY(),
            destino.GetX() + largo_lineas_seleccionado, destino.GetY()
        );
        renderer.DrawLine(
            destino.GetX(), destino.GetY(),
            destino.GetX(), destino.GetY() + largo_lineas_seleccionado
        );
        renderer.DrawLine(
            destino.GetX() + destino.GetW(), destino.GetY(),
            destino.GetX() + destino.GetW() - largo_lineas_seleccionado, destino.GetY()
        );
        renderer.DrawLine(
            destino.GetX() + destino.GetW(), destino.GetY(),
            destino.GetX() + destino.GetW(), destino.GetY() + largo_lineas_seleccionado
        );
        renderer.DrawLine(
            destino.GetX(), destino.GetY() + destino.GetH(),
            destino.GetX(), destino.GetY() + destino.GetH() - largo_lineas_seleccionado
        );
        renderer.DrawLine(
            destino.GetX(), destino.GetY() + destino.GetH(),
            destino.GetX() + largo_lineas_seleccionado, destino.GetY() + destino.GetH()
        );
        renderer.DrawLine(
            destino.GetX() + destino.GetW(), destino.GetY() + destino.GetH(),
            destino.GetX() + destino.GetW(), destino.GetY() + destino.GetH() - largo_lineas_seleccionado
        );
        renderer.DrawLine(
            destino.GetX() + destino.GetW(), destino.GetY() + destino.GetH(),
            destino.GetX() + destino.GetW() - largo_lineas_seleccionado, destino.GetY() + destino.GetH()
        );
}

void UnidadSDL::moverse(uint8_t direccion, uint16_t tiempo_movimiento) {
    if (desplegada) {
        if (!moviendose && unidad_amiga) {
            mixer.reproducirUnidadMovida(tipo_unidad, casa);
        }
        coords = coords_siguiente;
        actualizarCoordenadaFutura(direccion);
        frames_para_llegar = fps * tiempo_movimiento / 1000;
        frames_restantes = frames_para_llegar;
        moviendose = true;
    }
}

void UnidadSDL::actualizarCoordenadaFutura(uint8_t direccion) {
    switch(direccion) {
        case ABAJO_UNIDAD: {
            coords_siguiente.y++;
            this->direccion_actual = ABAJO_UNIDAD;
            break;
        }
        case ABAJO_IZQ_UNIDAD: {
            coords_siguiente.x--;
            coords_siguiente.y++;
            this->direccion_actual = ABAJO_IZQ_UNIDAD;
            break;
        }
        case IZQUIERDA_UNIDAD: {
            coords_siguiente.x--;
            this->direccion_actual = IZQUIERDA_UNIDAD;
            break;
        }
        case ARRIBA_IZQ_UNIDAD: {
            coords_siguiente.x--;
            coords_siguiente.y--;
            this->direccion_actual = ARRIBA_IZQ_UNIDAD;
            break;
        }
        case ARRIBA_UNIDAD: {
            coords_siguiente.y--;
            this->direccion_actual = ARRIBA_UNIDAD;
            break;
        }
        case ARRIBA_DER_UNIDAD: {
            coords_siguiente.x++;
            coords_siguiente.y--;
            this->direccion_actual = ARRIBA_DER_UNIDAD;
            break;
        }
        case DERECHA_UNIDAD: {
            coords_siguiente.x++;
            this->direccion_actual = DERECHA_UNIDAD;
            break;
        }
        case ABAJO_DER_UNIDAD: {
            coords_siguiente.y++;
            coords_siguiente.x++;
            this->direccion_actual = ABAJO_DER_UNIDAD;
            break;
        } default: {
            std::string error("VehiculoSDL: direccion no reconocida" + direccion_actual);
            throw std::runtime_error(error);
        }
    }
}

uint8_t UnidadSDL::obtenerIdJugador() const {
    return this->id_jugador;
}

void UnidadSDL::update(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom) {
    if (!desplegada) {
        updateTiempoRestante(frames_transcurridos);
    }
    updatePosicionUnidad(offset_x, offset_y, frames_transcurridos, zoom);
}
