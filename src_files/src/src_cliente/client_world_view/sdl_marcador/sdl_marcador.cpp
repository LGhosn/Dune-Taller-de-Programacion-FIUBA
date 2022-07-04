#include "sdl_marcador.h"

MarcadorSDL::MarcadorSDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas, YAML::Node& constantes,
                        InfoPartidaDTO& info_partida, ColorSDL& color):
                        renderer(renderer),
                        fuente(texturas.obtenerFontDune2000()),
                        color(color),
                        info_partida(info_partida),
                        jugadores_maximos(constantes["WorldView"]["Marcador"]["JugadoresMaximos"].as<uint8_t>()),
                        padding_x(constantes["WorldView"]["Marcador"]["PaddingX"].as<uint32_t>()),
                        padding_y(constantes["WorldView"]["Marcador"]["PaddingY"].as<uint32_t>()),
                        padding_interno(constantes["WorldView"]["Marcador"]["PaddingInterno"].as<uint32_t>()),
                        padding_texto(constantes["WorldView"]["Marcador"]["PaddingTexto"].as<uint32_t>()),
                        ancho_posicion(constantes["WorldView"]["Marcador"]["AnchoPosicion"].as<uint32_t>()),
                        ancho_puntaje(constantes["WorldView"]["Marcador"]["AnchoPuntaje"].as<uint32_t>()),
                        ancho_mapa(constantes["WorldView"]["Ventana"]["Ancho"].as<uint32_t>() - 
                                    constantes["WorldView"]["SideMenu"]["Ancho"].as<uint32_t>()),
                        largo_mapa(constantes["WorldView"]["Ventana"]["Alto"].as<uint32_t>()),
                        etiqueta_posiciones(constantes["WorldView"]["Marcador"]["EtiquetaPosiciones"].as<std::string>()),
                        etiqueta_nombres(constantes["WorldView"]["Marcador"]["EtiquetaNombres"].as<std::string>()),
                        etiqueta_puntaje(constantes["WorldView"]["Marcador"]["EtiquetaPuntaje"].as<std::string>()),
                        ancho_marcador(ancho_mapa - 2 * padding_x),
                        largo_marcador(largo_mapa - 2 * padding_y),
                        destino_marcador(ancho_mapa - padding_x - ancho_marcador,
                                        largo_mapa - padding_y - largo_marcador,
                                        ancho_marcador,
                                        largo_marcador),
                        largo_fila(largo_marcador / (jugadores_maximos + 1)),
                        largo_texto(largo_fila - 2 * padding_texto),
                        ancho_nombre(ancho_marcador - ancho_posicion - ancho_puntaje),
                        largo_max_nombre(ancho_nombre - 2 * padding_interno),
                        textura_etiqueta_posiciones(renderer,
                                fuente.RenderText_Blended(etiqueta_posiciones, SDL_Color{255, 255, 255, 255})),
                        textura_etiqueta_nombres(renderer,
                                fuente.RenderText_Blended(etiqueta_nombres, SDL_Color{255, 255, 255, 255})),
                        textura_etiqueta_puntajes(renderer,
                                fuente.RenderText_Blended(etiqueta_puntaje, SDL_Color{255, 255, 255, 255})),
                        destino_etiqueta_posiciones(destino_marcador.GetX() + padding_interno,
                                destino_marcador.GetY() + padding_texto,
                                largo_texto * 
                                    textura_etiqueta_posiciones.GetWidth() / textura_etiqueta_posiciones.GetHeight(),
                                largo_texto),
                        destino_etiqueta_nombres(destino_marcador.GetX() + padding_interno + ancho_posicion,
                                destino_marcador.GetY() + padding_texto,
                                largo_texto * 
                                    textura_etiqueta_nombres.GetWidth() / textura_etiqueta_nombres.GetHeight(),
                                largo_texto),
                        destino_etiqueta_puntajes(destino_marcador.GetX() + padding_interno + ancho_posicion + ancho_nombre,
                                destino_marcador.GetY() + padding_texto,
                                largo_texto * 
                                    textura_etiqueta_puntajes.GetWidth() / textura_etiqueta_puntajes.GetHeight(),
                                largo_texto) {
    size_t cantidad_jugadores = info_partida.info_jugadores.size();
    if (cantidad_jugadores > jugadores_maximos) {
        cantidad_jugadores = jugadores_maximos;
    }
    uint8_t i = 0;
    for (auto jugador : info_partida.info_jugadores) {
        puntajes[jugador.first] = 0;
        posicion_vectores_por_jugador[jugador.first] = i;

        texturas_nombres.emplace_back(renderer,
                    fuente.RenderText_Blended(jugador.second.second, SDL_Color{255, 255, 255, 255}));

        uint32_t altura_fila = destino_marcador.GetY() + (i + 1) * largo_fila + padding_texto;
        destinos_posiciones.emplace_back(
            destino_marcador.GetX() + padding_interno,
            altura_fila, 0, largo_texto
        );

        destinos_nombres.emplace_back(
            destino_marcador.GetX() + ancho_posicion + padding_interno,
            altura_fila,
            largo_texto * texturas_nombres.back().GetWidth() / texturas_nombres.back().GetHeight(),
            largo_texto
        );
        
        destinos_puntajes.emplace_back(
            destino_marcador.GetX() + ancho_posicion + ancho_nombre + padding_interno,
            altura_fila, 0, largo_texto
        );
        i++;
    }
    
}

void MarcadorSDL::actualizarPuntajes(uint8_t id_jugador, uint16_t nuevo_puntaje) {
    puntajes[id_jugador] = nuevo_puntaje;
}

void MarcadorSDL::estaHabilitado(bool habilitar) {
    habilitado = habilitar;
}

void MarcadorSDL::render() {
    if (!habilitado) {
        return;
    }
    renderer.SetDrawColor(color.obtenerOscuroSemitransparente());
    renderer.FillRect(destino_marcador);
    renderer.Copy(textura_etiqueta_posiciones, destino_etiqueta_posiciones);
    renderer.Copy(textura_etiqueta_nombres, destino_etiqueta_nombres);
    renderer.Copy(textura_etiqueta_puntajes, destino_etiqueta_puntajes);
    for (size_t i = 0; i < texturas_nombres.size(); i++) {
        renderer.Copy(texturas_nombres[i], destinos_nombres[i]);
    }
}
