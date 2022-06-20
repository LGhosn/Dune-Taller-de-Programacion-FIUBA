#include "sdl_centro.h"

void CentroSDL::actualizarFrameBrazo(long frame_actual) {
    long cant_frames = (frame_actual - frame_anterior) / rate_brazo;
    if (cant_frames > 0) {
        frame_actual_brazo = (frame_actual_brazo + cant_frames) % cant_frames_brazo;
        origen_brazo.SetX(frame_actual_brazo * ancho_brazo); 
        frame_anterior = frame_actual;
    }
}

void CentroSDL::setearPosicionBrazo() {
    destino_brazo.SetY(destino.GetY() + offset_y_brazo * zoom);
    switch (frame_actual_brazo) {
        case 0:
            destino_brazo.SetX(destino.GetX() + (offset_x_brazo - 1) * zoom);
            break;
        case 3:
            destino_brazo.SetX(destino.GetX() + (offset_x_brazo - 2) * zoom);
            break;
        case 4:
            destino_brazo.SetX(destino.GetX() + (offset_x_brazo - 2) * zoom);
            break;
        default:
            destino_brazo.SetX(destino.GetX() + offset_x_brazo * zoom);
            break;
    }
}

CentroSDL::CentroSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                    SDL2pp::Texture& textura, const Coordenadas& coords, uint16_t alto,
                    uint16_t ancho, uint8_t casa, YAML::Node& constantes):
                    EdificioSDL(id, id_jugador, renderer, textura, coords, alto, ancho, casa,
                                constantes),
                    ancho_edificio(constantes["WorldView"]["Edificios"]["Centro"]["Ancho"].as<uint32_t>()),
                    alto_edificio(constantes["WorldView"]["Edificios"]["Centro"]["Alto"].as<uint32_t>()),
                    padding_edificio_y(constantes["WorldView"]["Edificios"]["Centro"]["PaddingY"].as<uint32_t>()),
                    offset_x_edificio(constantes["WorldView"]["Edificios"]["Centro"]["OffsetX"].as<int32_t>()),
                    limite_hp_debilitar(constantes["WorldView"]["Edificios"]["Centro"]["LimiteHPDebilitar"].as<uint32_t>()),
                    ancho_brazo(constantes["WorldView"]["Edificios"]["Centro"]["Brazo"]["Ancho"].as<uint32_t>()),
                    alto_brazo(constantes["WorldView"]["Edificios"]["Centro"]["Brazo"]["Alto"].as<uint32_t>()),
                    cant_frames_brazo(constantes["WorldView"]["Edificios"]["Centro"]["Brazo"]["CantidadFrames"].as<uint8_t>()),
                    rate_brazo(constantes["WorldView"]["Edificios"]["Centro"]["Brazo"]["Rate"].as<uint32_t>()),
                    offset_x_brazo(constantes["WorldView"]["Edificios"]["Centro"]["Brazo"]["OffsetX"].as<int32_t>()),
                    offset_y_brazo(constantes["WorldView"]["Edificios"]["Centro"]["Brazo"]["OffsetY"].as<int32_t>()){
    origen.SetX(0);
    if (casa == codigo_atreides)
        origen.SetY(0);
    else if (casa == codigo_harkonnen)
        origen.SetY(alto_edificio + alto_brazo + 1);
    else if (casa == codigo_ordos)
        origen.SetY(2 * (alto_edificio + alto_brazo) + 1);
    else
        throw std::runtime_error("CentroSDL: casa no reconocida");
    origen.SetW(ancho_edificio);
    origen.SetH(alto_edificio);
    origen_brazo.SetX(0);
    origen_brazo.SetY(origen.GetY() + alto_edificio);
    origen_brazo.SetW(ancho_edificio);
    origen_brazo.SetH(alto_edificio);
}

void CentroSDL::cambiarHP(uint16_t hp_edificio) {
    if (hp_edificio < limite_hp_debilitar)
        origen.SetX(ancho_edificio);
}

void CentroSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_actual,
                        float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * ancho_tile * zoom - origen_movil_x);
    destino.SetY((coords.y * largo_tile + padding_edificio_y) * zoom - origen_movil_y);
    setearPosicionUI(origen_movil_x, origen_movil_y);
    actualizarFrameBrazo(frame_actual);
    setearPosicionBrazo();
    destino.SetW(ancho_tile * ancho * zoom);
    destino.SetH((largo_tile * alto - 2 * padding_edificio_y) * zoom);
    destino_brazo.SetW(ancho_brazo * zoom);
    destino_brazo.SetH(alto_brazo * zoom);
}

void CentroSDL::render() {
    renderer.Copy(textura, origen, destino);
    renderer.Copy(textura, origen_brazo, destino_brazo);
}
