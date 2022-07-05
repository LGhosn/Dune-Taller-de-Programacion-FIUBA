#include "sdl_estado_partida.h"

EstadoPartidaSDL::EstadoPartidaSDL(SDL2pp::Renderer& renderer, MixerSDL& mixer,
                TexturasSDL& texturas, ColorSDL& color,
                YAML::Node& constantes):
                renderer(renderer),
                mixer(mixer),
                victoria(texturas.obtenerTextoVictoria()),
                derrota(texturas.obtenerTextoDerrota()),
                color(color),
                ancho_mapa(constantes["WorldView"]["Ventana"]["Ancho"].as<uint32_t>() -
                            constantes["WorldView"]["SideMenu"]["Ancho"].as<uint32_t>()),
                largo_mapa(constantes["WorldView"]["Ventana"]["Alto"].as<uint32_t>()),
                padding_x(constantes["WorldView"]["EstadoPartida"]["PaddingX"].as<uint32_t>()),
                padding_y(constantes["WorldView"]["EstadoPartida"]["PaddingY"].as<uint32_t>()),
                largo_texto(constantes["WorldView"]["EstadoPartida"]["LargoTexto"].as<uint32_t>()),
                destino_cartel(padding_x, padding_y,
                        ancho_mapa - 2 * padding_x,
                        largo_mapa - 2 * padding_y) {}
                

void EstadoPartidaSDL::mostrarEstado(bool esGanador) {
    renderizar = true;
    this->esGanador = esGanador;
    if (esGanador) {
        mixer.reproducirMensajeVictoria();
    } else {
        mixer.reproducirMensajeDerrota();
    }
}

void EstadoPartidaSDL::render() {
    if (renderizar) {
        renderer.SetDrawColor(color.obtenerOscuroSemitransparente());
        renderer.FillRect(destino_cartel);
        if (esGanador) {
            renderer.Copy(victoria, SDL2pp::NullOpt, destino_cartel);
        } else {
            renderer.Copy(derrota, SDL2pp::NullOpt, destino_cartel);
        }
    }
}
