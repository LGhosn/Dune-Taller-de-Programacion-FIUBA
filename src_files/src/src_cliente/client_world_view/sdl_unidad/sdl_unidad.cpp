#include "sdl_unidad.h"
#include <cmath>

UnidadSDL::UnidadSDL(uint8_t id_unidad,
                uint8_t id_jugador,
                uint8_t tipo_unidad,
                SDL2pp::Renderer& renderer,
                TexturasSDL& texturas,
                const Coordenadas& coords,
                YAML::Node& constantes,
                ColorSDL& color,
                uint16_t tiempo_aparicion) :
                id_unidad(id_unidad),
                id_jugador(id_jugador),
                renderer(renderer),
                texturas(texturas.obtenerVehiculo(tipo_unidad)),
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

void UnidadSDL::update(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom) {
    if (!desplegada) {
        updateTiempoRestante(frames_transcurridos);
    }
    updatePosicionUnidad(offset_x, offset_y, frames_transcurridos, zoom);
}

void UnidadSDL::updateTiempoRestante(long frames_transcurridos) {
    if (frames_restantes > frames_transcurridos) {
        frames_restantes -= frames_transcurridos;
    } else {
        desplegada = true;
    }
}

void UnidadSDL::updatePosicionUnidad(uint32_t offset_x, uint32_t offset_y, long frames_transcurridos, float zoom) {
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

void UnidadSDL::render() {
    if (desplegada) {
        renderer.Copy(texturas[direccion_actual], SDL2pp::NullOpt, destino);
        renderUI();
    } else {
        renderer.SetDrawColor(color.obtenerOscuroSemitransparente());
        renderer.FillRect(destino);
    }
}

void UnidadSDL::seleccionar() {
    seleccionado = true;
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

    renderer.SetDrawColor(color.obtenerPrimario());
    renderer.FillRect(
        destino.GetX(),
        destino.GetY(),
        destino.GetX() + destino.GetW(),
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
            std::string error("UnidadSDL: direccion no reconocida" + direccion_actual);
            throw std::runtime_error(error);
        }
    }
}

UnidadSDL::~UnidadSDL() {
    std::cout << "UnidadSDL: destructor" << std::endl;
}
