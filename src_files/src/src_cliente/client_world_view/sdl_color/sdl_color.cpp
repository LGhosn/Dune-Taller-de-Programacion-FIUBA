#include "sdl_color.h"

#include "yaml-cpp/yaml.h"
#include <iostream>

ColorSDL::ColorSDL(YAML::Node& archivo_colores, uint8_t id_color) {
    primario.SetRed(archivo_colores[id_color]["Primario"]["R"].as<uint8_t>());
    primario.SetGreen(archivo_colores[id_color]["Primario"]["G"].as<uint8_t>());
    primario.SetBlue(archivo_colores[id_color]["Primario"]["B"].as<uint8_t>());
    primario.SetAlpha(255);

    secundario.SetRed(archivo_colores[id_color]["Secundario"]["R"].as<uint8_t>());
    secundario.SetGreen(archivo_colores[id_color]["Secundario"]["G"].as<uint8_t>());
    secundario.SetBlue(archivo_colores[id_color]["Primario"]["B"].as<uint8_t>());
    secundario.SetAlpha(255);

    oscuro.SetRed(archivo_colores[id_color]["Oscuro"]["R"].as<uint8_t>());
    oscuro.SetGreen(archivo_colores[id_color]["Oscuro"]["G"].as<uint8_t>());
    oscuro.SetBlue(archivo_colores[id_color]["Oscuro"]["B"].as<uint8_t>());
    oscuro.SetAlpha(255);
}

SDL2pp::Color& ColorSDL::obtenerPrimario() {
    return this->primario;
}

SDL2pp::Color& ColorSDL::obtenerSecundario() {
    return this->secundario;
}

SDL2pp::Color& ColorSDL::obtenerOscuro() {
    return this->oscuro;
}
