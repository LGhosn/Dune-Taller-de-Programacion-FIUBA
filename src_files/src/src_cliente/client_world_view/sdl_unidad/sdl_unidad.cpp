#include "sdl_unidad.h"

UnidadSDL::UnidadSDL(uint8_t id_unidad,
                uint8_t id_jugador,
                SDL2pp::Renderer& renderer,
                SDL2pp::Texture& textura,
                const Coordenadas& coords,
                YAML::Node& constantes,
                ColorSDL& color,
                long frames_restantes) :
                id_unidad(id_unidad),
                id_jugador(id_jugador),
                renderer(renderer),
                textura(textura),
                coords(coords),
                color(color),
                frames_restantes(frames_restantes),
                offset_x_hp(constantes["WorldView"]["Unidades"]["UI"]["HP"]["OffsetX"].as<int32_t>()),
                offset_y_hp(constantes["WorldView"]["Unidades"]["UI"]["HP"]["OffsetY"].as<int32_t>()),
                alto_hp(constantes["WorldView"]["Unidades"]["UI"]["HP"]["Alto"].as<uint32_t>()),
                padding_x_hp(constantes["WorldView"]["Unidades"]["UI"]["HP"]["PaddingX"].as<uint32_t>()),
                padding_rect_hp(constantes["WorldView"]["Unidades"]["UI"]["HP"]["PaddingRect"].as<uint32_t>()),
                relacion_lineas_largo(constantes["WorldView"]["Unidades"]["UI"]["RelacionLineasLargo"].as<float>()),
                ancho_tile(constantes["WorldView"]["Mapa"]["Tiles"]["Largo"].as<uint32_t>()),
                largo_tile(constantes["WorldView"]["Mapa"]["Tiles"]["Largo"].as<uint32_t>()) {}

void UnidadSDL::update(uint32_t offset_x, uint32_t offset_y, long frame_actual, float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * ancho_tile * zoom - offset_x);
    destino.SetY((coords.y * largo_tile) * zoom - offset_y);
    destino.SetW(ancho_tile * zoom);
    destino.SetH(largo_tile * zoom);
}

void UnidadSDL::render() {
    renderer.Copy(textura, SDL2pp::NullOpt, destino);
    renderUI();
}

bool UnidadSDL::listaParaRenderizar(long frame_actual) {
    if (this->frames_restantes > frame_actual) {
        this->frames_restantes -= frame_actual;
        return false;
    } 
    this->frames_restantes = 0;
    return true;
}

void UnidadSDL::seleccionar() {
    seleccionado = true;
}

void UnidadSDL::deseleccionar() {
    seleccionado = false;
}

bool UnidadSDL::contiene(int pos_x, int pos_y) {
    std::cout << "contine????" << std::endl;
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

void UnidadSDL::moverse(char direccion, long tiempo_movimiento) {}