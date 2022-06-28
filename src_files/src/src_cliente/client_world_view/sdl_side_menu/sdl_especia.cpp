#include "sdl_especia.h"
#include <string>

EspeciaSDL::EspeciaSDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas, YAML::Node& constantes,
                        ColorSDL& color_rect):
                    renderer(renderer),
                    color_rect(color_rect),
                    fuente(texturas.obtenerFontDune2000()),
                    texto(renderer,
                        fuente.RenderText_Blended(std::to_string(cantidad_especia) + "$",
                                    SDL_Color{255, 255, 255, 255})),
                    destino_rect(
                        constantes["WorldView"]["Ventana"]["Ancho"].as<uint32_t>() -
                            constantes["WorldView"]["SideMenu"]["Ancho"].as<uint32_t>() -
                                constantes["WorldView"]["SideMenu"]["Especia"]["Ancho"].as<uint32_t>(),
                        0,
                        constantes["WorldView"]["SideMenu"]["Especia"]["Ancho"].as<uint32_t>(),
                        constantes["WorldView"]["SideMenu"]["Especia"]["Alto"].as<uint32_t>()
                    ),
                    padding_texto_x(constantes["WorldView"]["SideMenu"]["Especia"]["PaddingTextoX"].as<uint32_t>()),
                    padding_texto_y(constantes["WorldView"]["SideMenu"]["Especia"]["PaddingTextoY"].as<uint32_t>()),
                    destino_texto(
                        destino_rect.GetX() + padding_texto_x,
                        destino_rect.GetY() + padding_texto_y,
                        destino_rect.GetW() - 2 * padding_texto_x,
                        destino_rect.GetH() - 2 * padding_texto_y
                    ) {}

void EspeciaSDL::modificarEspecia(uint16_t cantidad_especia) {
    this->cantidad_especia = cantidad_especia;
    texto = SDL2pp::Texture(renderer,
                        fuente.RenderText_Blended(std::to_string(cantidad_especia) + "$",
                                    SDL_Color{255, 255, 255, 255}));
    float relacion_ancho_largo_texto = (float) texto.GetWidth() / (float) texto.GetHeight();
    destino_texto.SetW(destino_texto.GetH() * relacion_ancho_largo_texto);
    destino_texto.SetX(destino_rect.GetX() + destino_rect.GetW() -
                        padding_texto_x - destino_texto.GetW());
}

void EspeciaSDL::render() {
    renderer.SetDrawColor(color_rect.obtenerOscuro());
    renderer.FillRect(destino_rect);
    renderer.Copy(texto, SDL2pp::NullOpt, destino_texto);
}
