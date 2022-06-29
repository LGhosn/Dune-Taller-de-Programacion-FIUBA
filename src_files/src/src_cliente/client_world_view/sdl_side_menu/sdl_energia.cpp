#include "sdl_energia.h"

EnergiaSDL::EnergiaSDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas,
                        YAML::Node& constantes, ColorSDL& color_rect) :
                        renderer(renderer),
                        color_rect(color_rect),
                        fuente(texturas.obtenerFontDune2000()),
                        texto(renderer,
                            fuente.RenderText_Blended(std::to_string(cantidad_energia) + "E",
                                        SDL_Color{255, 255, 255, 255})),
                        destino_rect(
                            constantes["WorldView"]["Ventana"]["Ancho"].as<uint32_t>() -
                                constantes["WorldView"]["SideMenu"]["Ancho"].as<uint32_t>() -
                                    constantes["WorldView"]["SideMenu"]["Energia"]["Ancho"].as<uint32_t>(),
                            constantes["WorldView"]["SideMenu"]["Especia"]["Alto"].as<uint32_t>(),
                            constantes["WorldView"]["SideMenu"]["Energia"]["Ancho"].as<uint32_t>(),
                            constantes["WorldView"]["SideMenu"]["Energia"]["Alto"].as<uint32_t>()
                        ),
                        padding_texto_x(constantes["WorldView"]["SideMenu"]["Energia"]["PaddingTextoX"].as<uint32_t>()),
                        padding_texto_y(constantes["WorldView"]["SideMenu"]["Energia"]["PaddingTextoY"].as<uint32_t>()),
                        destino_texto(
                            destino_rect.GetX() + padding_texto_x,
                            destino_rect.GetY() + padding_texto_y,
                            destino_rect.GetW() - 2 * padding_texto_x,
                            destino_rect.GetH() - 2 * padding_texto_y
                        ) {}

void EnergiaSDL::modificarEnergia(int16_t cantidad_energia) {
    this->cantidad_energia = cantidad_energia;
    SDL2pp::Color color_texto;
    if (cantidad_energia > 0) {
        color_texto = SDL2pp::Color(124, 179, 66);
    } else if (cantidad_energia == 0) {
        color_texto = SDL2pp::Color(255, 255, 255);
    } else {
        color_texto = SDL2pp::Color(229, 57, 53);
    }
    texto = SDL2pp::Texture(renderer,
                        fuente.RenderText_Blended(std::to_string(cantidad_energia) + "E",
                                    color_texto));
    float relacion_ancho_largo_texto = (float) texto.GetWidth() / (float) texto.GetHeight();
    destino_texto.SetW(destino_texto.GetH() * relacion_ancho_largo_texto);
    destino_texto.SetX(destino_rect.GetX() + destino_rect.GetW() -
                        padding_texto_x - destino_texto.GetW());
}

void EnergiaSDL::render() {
    renderer.SetDrawColor(color_rect.obtenerOscuro());
    renderer.FillRect(destino_rect);
    renderer.Copy(texto, SDL2pp::NullOpt, destino_texto);
}
