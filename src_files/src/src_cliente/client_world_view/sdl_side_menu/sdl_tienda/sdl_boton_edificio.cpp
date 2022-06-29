#include "sdl_boton_edificio.h"
#include "../../../client_solicitudes/client_sol_crear_edificio.h"
#include "../../../client_solicitudes/sol_comprar_edificio.h"

bool BotonEdificioSDL::contiene(int pos_x, int pos_y) const {
    return destino.Contains(pos_x, pos_y);
}

BotonEdificioSDL::BotonEdificioSDL(SDL2pp::Renderer& renderer, TexturasSDL& texturas, uint8_t tipo,
                                uint8_t casa, uint8_t id_jugador, const SDL2pp::Rect destino,
                                YAML::Node& constantes) :
                                renderer(renderer),
                                tipo(tipo),
                                casa(casa),
                                id_jugador(id_jugador),
                                logo(texturas.obtenerLogoEdificio(tipo, casa)),
                                texto_listo(texturas.obtenerTextoTiendaListo()),
                                relacion_ancho_largo(constantes["WorldView"]["SideMenu"]["Tienda"]["Botones"]["RelacionAnchoLargo"].as<float>()),
                                padding_texto_x(constantes["WorldView"]["SideMenu"]["Tienda"]["Botones"]["PaddingTexto"].as<uint32_t>()),
                                tam_texto_y(constantes["WorldView"]["SideMenu"]["Tienda"]["Botones"]["TamTexto"].as<uint32_t>()),
                                fps(constantes["FPS"].as<uint8_t>()),
                                origen(0,
                                        0,
                                        logo.GetHeight() * relacion_ancho_largo,
                                        logo.GetHeight()),
                                destino(destino), destino_construyendo(destino),
                                destino_texto(
                                    destino.GetX() + padding_texto_x,
                                    destino.GetY() + (destino.GetH() - tam_texto_y) / 2,
                                    destino.GetW() - 2 * padding_texto_x,
                                    tam_texto_y
                                ) {}

void BotonEdificioSDL::habilitar() {
    habilitado = true;
    std::cout << "Habilito el boton " << (int) tipo << std::endl;
}

void BotonEdificioSDL::deshabilitar() {
    habilitado = false;
    std::cout << "Deshabilito el boton " << (int) tipo << std::endl;
}

void BotonEdificioSDL::edificioCreado() {
    listo = false;
}

bool BotonEdificioSDL::estaSeleccionado() const {
    return seleccionado;
}

void BotonEdificioSDL::empezarConstruccion(uint16_t milisegundos_para_construir) {
    construyendo = true;
    frames_para_construir = milisegundos_para_construir * fps / 1000;
    frames_restantes_construccion = frames_para_construir;
}

SolicitudCliente* BotonEdificioSDL::click(int pos_x, int pos_y) {
    if (!this->contiene(pos_x, pos_y))
        return nullptr;
    if (listo) {
        if (seleccionado) {
            seleccionado = false;
            return nullptr;
        } else {
            seleccionado = true;
            return nullptr;
        }
    }
    if (habilitado && !construyendo && !listo) {
        return new SolComprarEdificioCliente(tipo);
    }
    return nullptr;
}

SolicitudCliente* BotonEdificioSDL::clickEnMapa(Coordenadas& coords) {
    if (listo && seleccionado) {
        seleccionado = false;
        return new SolicitudCrearEdificio(coords, tipo);
    }
    return nullptr;
}

void BotonEdificioSDL::update(long frames_transcurridos) {
    if (construyendo) {
        if (frames_restantes_construccion > frames_transcurridos) {
            frames_restantes_construccion -= frames_transcurridos;
            float porciento_completado = (float) frames_restantes_construccion / (float) frames_para_construir;
            destino_construyendo.SetY(destino.GetY() + destino.GetH() * (1 - porciento_completado));
            destino_construyendo.SetH(destino.GetH() * porciento_completado);
        } else {
            construyendo = false;
            listo = true;
        }
    }
}

void BotonEdificioSDL::render() {
    renderer.Copy(logo, origen, destino);
    if (!habilitado && !construyendo) {
        renderer.SetDrawColor(0, 0, 0, 150);
        renderer.FillRect(destino);
    } 
    if (construyendo) {
        renderer.SetDrawColor(0, 0, 0, 150);
        renderer.FillRect(destino_construyendo);
    }
    if (listo) {
        renderer.SetDrawColor(0, 0, 0, 150);
        renderer.FillRect(destino);
        renderer.Copy(texto_listo, SDL2pp::NullOpt, destino_texto);
    }
    if (seleccionado) {
        renderer.SetDrawColor(255, 255, 255);
        renderer.DrawRect(destino);
    }
}
