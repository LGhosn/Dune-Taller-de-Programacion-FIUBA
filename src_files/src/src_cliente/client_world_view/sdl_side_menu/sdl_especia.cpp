#include "sdl_especia.h"
#include <string>

EspeciaSDL::EspeciaSDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas, YAML::Node& constantes):
                    renderer(renderer),
                    fuente(texturas.obtenerFontDune2000()),
                    texto(renderer,
                        fuente.RenderText_Blended(std::to_string(cantidad_especia),
                                    SDL_Color{255, 255, 255, 255})),
                    destino_rect(
                        constantes["WorldView"]["Ventana"]["Ancho"].as<uint32_t>() -
                            constantes["WorldView"]["SideMenu"]["Ancho"].as<uint32_t>() -
                                constantes["WorldView"]["SideMenu"]["Especia"]["Ancho"].as<uint32_t>(),
                        0,
                        constantes["WorldView"]["SideMenu"]["Especia"]["Ancho"].as<uint32_t>(),
                        constantes["WorldView"]["SideMenu"]["Especia"]["Alto"].as<uint32_t>()
                    ),
                    padding_texto(constantes["WorldView"]["SideMenu"]["Especia"]["PaddingTexto"].as<uint32_t>()),
                    destino_texto(
                        destino_rect.GetX() + padding_texto,
                        destino_rect.GetY() + padding_texto,
                        destino_rect.GetW() - 2 * padding_texto,
                        destino_rect.GetY() - 2 * padding_texto
                    ) {}

void EspeciaSDL::modificarEspecia(uint16_t cantidad_especia) {
    this->cantidad_especia = cantidad_especia;
    texto = SDL2pp::Texture(renderer,
                        fuente.RenderText_Blended(std::to_string(cantidad_especia),
                                    SDL_Color{255, 255, 255, 255}));
}

void EspeciaSDL::render() {
    renderer.SetDrawColor(0,0,0);
    renderer.FillRect(destino_rect);
    renderer.Copy(texto, SDL2pp::NullOpt, destino_rect);
}
