#include "sdl_centro.h"

void CentroSDL::actualizarFrameBrazo(long frame_transcurridos) {
    if (frame_transcurridos > frames_restantes) {
        frame_actual_brazo = (frame_actual_brazo + 1) % cant_frames_brazo;
        frames_restantes = rate_brazo;
    } else {
        frames_restantes -= frame_transcurridos;
    }
}

void CentroSDL::setearPosicionBrazo() {
    switch (frame_actual_brazo) {
        case 0: case 13: {
            destino_brazo.SetX(destino.GetX() + (offset_x_brazo - 45) * zoom);
            destino_brazo.SetY(destino.GetY() + (offset_y_brazo - 46) * zoom);
            break;
        }
        case 1: case 5: case 6: {
            destino_brazo.SetX(destino.GetX() + (offset_x_brazo - 45) * zoom);
            destino_brazo.SetY(destino.GetY() + (offset_y_brazo - 47) * zoom);
            break;
        }
        case 2: {
            destino_brazo.SetX(destino.GetX() + (offset_x_brazo - 47) * zoom);
            destino_brazo.SetY(destino.GetY() + (offset_y_brazo - 49) * zoom);
            break;
        }
        case 3: case 4: {
            destino_brazo.SetX(destino.GetX() + (offset_x_brazo - 51) * zoom);
            destino_brazo.SetY(destino.GetY() + (offset_y_brazo - 46) * zoom);
            break;
        }
        case 7: case 8: case 9: case 10: case 11: case 12: {
            destino_brazo.SetX(destino.GetX() + (offset_x_brazo - 45) * zoom);
            destino_brazo.SetY(destino.GetY() + (offset_y_brazo - 45) * zoom);
            break;
        }
    }
}

CentroSDL::CentroSDL(uint8_t id, uint8_t id_jugador, uint16_t vida, SDL2pp::Renderer& renderer,
                    TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
                    uint16_t ancho, uint8_t casa, YAML::Node& constantes, ColorSDL& color):
                    EdificioSDL(id, id_jugador, vida, renderer, texturas.obtenerEdificio(0, casa, false),
                    texturas.obtenerEdificio(0, casa, true), coords, alto, ancho, casa,
                    constantes, color, texturas.obtenerSlab()),
                    frames_brazo(texturas.obtenerFramesBrazoCentro(casa)),
                    padding_edificio_y(constantes["WorldView"]["Edificios"]["Centro"]["PaddingY"].as<uint32_t>()),
                    offset_x_edificio(constantes["WorldView"]["Edificios"]["Centro"]["OffsetX"].as<int32_t>()),
                    limite_hp_debilitar(constantes["WorldView"]["Edificios"]["Centro"]["LimiteHPDebilitar"].as<uint32_t>()),
                    cant_frames_brazo(constantes["WorldView"]["Edificios"]["Centro"]["Brazo"]["CantidadFrames"].as<uint8_t>()),
                    rate_brazo(constantes["WorldView"]["Edificios"]["Centro"]["Brazo"]["Rate"].as<uint32_t>()),
                    offset_x_brazo(constantes["WorldView"]["Edificios"]["Centro"]["Brazo"]["OffsetX"].as<int32_t>()),
                    offset_y_brazo(constantes["WorldView"]["Edificios"]["Centro"]["Brazo"]["OffsetY"].as<int32_t>()),
                    frames_restantes(rate_brazo) {}

bool CentroSDL::cambiarHP(uint16_t hp_edificio) {
    vida_restante = hp_edificio;
    if (hp_edificio < limite_hp_debilitar) {
        debilitado = true;
    }
    std::cout << "Vida restante: " << vida_restante << std::endl;
    return vida_restante > 0;
}

void CentroSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_transcurridos,
                        float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * ancho_tile * zoom - origen_movil_x);
    destino.SetY((coords.y * largo_tile + padding_edificio_y) * zoom - origen_movil_y);
    setearPosicionUI(origen_movil_x, origen_movil_y);
    actualizarFrameBrazo(frame_transcurridos);
    setearPosicionBrazo();
    destino.SetW(ancho_tile * ancho * zoom);
    destino.SetH((largo_tile * alto - 2 * padding_edificio_y) * zoom);
    destino_brazo.SetW(frames_brazo[frame_actual_brazo].GetWidth() * zoom);
    destino_brazo.SetH(frames_brazo[frame_actual_brazo].GetHeight() * zoom);
}

void CentroSDL::render() {
    renderCimientos();
    if (debilitado)
        renderer.Copy(textura_debilitado, SDL2pp::NullOpt, destino);
    else
        renderer.Copy(textura, SDL2pp::NullOpt, destino);
    
    renderer.Copy(frames_brazo[frame_actual_brazo], SDL2pp::NullOpt, destino_brazo);
}
