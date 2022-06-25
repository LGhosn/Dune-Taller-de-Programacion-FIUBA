#include "sdl_trampa.h"

void TrampaSDL::actualizarFrameLuces(long frame_actual) {
    long cant_frames = (frame_actual - frame_anterior) / frame_rate_luces;
    if (cant_frames > 0) {
        frame_actual_luces = (frame_actual_luces + cant_frames) % cantidad_frames;
        frame_anterior = frame_actual;
    }
}

TrampaSDL::TrampaSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
            TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
            uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color):
            EdificioSDL(id, id_jugador, renderer, texturas.obtenerEdificio(7, casa, false),
                    texturas.obtenerEdificio(7, casa, true), coords, alto, ancho, casa,
                    constantes, color, texturas.obtenerSlab()),
            luces(texturas.obtenerLucesTrampa()),
            limite_hp_debilitar(constantes["WorldView"]["Edificios"]["Trampa"]["LimiteHPDebilitar"].as<uint32_t>()),
            frame_rate_luces(constantes["WorldView"]["Edificios"]["Trampa"]["Luces"]["Rate"].as<uint32_t>()),
            offset_luces_x(constantes["WorldView"]["Edificios"]["Trampa"]["Luces"]["OffsetX"].as<int32_t>()),
            offset_luces_y(constantes["WorldView"]["Edificios"]["Trampa"]["Luces"]["OffsetY"].as<int32_t>()),
            cantidad_frames(constantes["WorldView"]["Edificios"]["Trampa"]["Luces"]["CantidadFrames"].as<uint8_t>()) {}

void TrampaSDL::cambiarHP(uint16_t hp_edificio) {
    if (hp_edificio < limite_hp_debilitar)
        debilitado = true;
}

void TrampaSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_actual, float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * ancho_tile * zoom - origen_movil_x);
    destino.SetY(coords.y * largo_tile * zoom - origen_movil_y);
    destino.SetW(ancho_tile * ancho * zoom);
    destino.SetH(largo_tile * alto * zoom);
    destino_luces.SetX(destino.GetX() + offset_luces_x * zoom);
    destino_luces.SetY(destino.GetY() + offset_luces_y * zoom);
    destino_luces.SetW(destino.GetW());
    destino_luces.SetH(destino.GetH());
    // actualizarFrameLuces(frame_actual);
    setearPosicionUI(origen_movil_x, origen_movil_y);
}

void TrampaSDL::render() {
    renderCimientos();
    if (debilitado) {
        renderer.Copy(textura_debilitado, SDL2pp::NullOpt, destino);
    } else {
        renderer.Copy(textura, SDL2pp::NullOpt, destino);
        // renderer.Copy(luces[frame_actual_luces], SDL2pp::NullOpt, destino_luces);   
    }
}
