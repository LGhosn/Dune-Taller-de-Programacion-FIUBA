#include "sdl_boton_paginas.h"

BotonPaginasSDL::BotonPaginasSDL(SDL2pp::Renderer& renderer, SDL2pp::Rect destino,
                                SDL2pp::Texture& texto, YAML::Node& constantes):
                                renderer(renderer),
                                destino(destino),
                                texto(texto),
                                color(55, 71, 79) {
    uint32_t alto = constantes["WorldView"]["SideMenu"]["Tienda"]["BotonesPagina"]["Alto"].as<uint32_t>();
    uint32_t padding_texto = constantes["WorldView"]["SideMenu"]["Tienda"]["BotonesPagina"]["PaddingTexto"].as<uint32_t>();
    
    float relacion_largo_ancho_texto = (float) texto.GetWidth() / (float) texto.GetHeight();
    uint32_t alto_texto = alto - 2 * padding_texto;
    uint32_t ancho_texto = alto * relacion_largo_ancho_texto;
    uint32_t pos_x_texto = destino.GetX() + (destino.GetW() - ancho_texto) / 2;
    uint32_t pos_y_texto = destino.GetY() + padding_texto;
    destino_texto = SDL2pp::Rect(pos_x_texto, pos_y_texto, ancho_texto, alto_texto);
}

bool BotonPaginasSDL::contiene(int pos_x, int pos_y) {
    return destino.Contains(pos_x, pos_y);
}

void BotonPaginasSDL::seleccionar() {
    seleccionado = true;
}

void BotonPaginasSDL::deseleccionar() {
    seleccionado = false;
}

void BotonPaginasSDL::render() {
    renderer.SetDrawColor(color);
    renderer.FillRect(destino);
    renderer.Copy(texto, SDL2pp::NullOpt, destino_texto);
    if (seleccionado) {
        renderer.SetDrawColor(255, 255, 255);
    } else {
        renderer.SetDrawColor(0, 0, 0);
    }
    renderer.DrawRect(destino);
}
