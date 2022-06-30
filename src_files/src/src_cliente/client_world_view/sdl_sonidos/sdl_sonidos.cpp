#include "sdl_sonidos.h"

void SonidosSDL::cargarMensajesDeVoz() {
    std::vector<std::string> casas;
    casas.emplace_back("atreides");
    casas.emplace_back("harkonnen");
    casas.emplace_back("ordos");

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_SONIDOS << casa << "/mensajes_de_voz/construyendo.mp3";
        construyendo.emplace_back(stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_SONIDOS << casa << "/mensajes_de_voz/edificio_construido.mp3";
        edificio_construido.emplace_back(stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_SONIDOS << casa << "/mensajes_de_voz/nuevos_edificios_disponibles.mp3";
        nuevos_edificios_disponibles.emplace_back(stream.str());
    }
}

SonidosSDL::SonidosSDL(uint8_t casa, YAML::Node& constantes):
                    casa(casa),
                    plotting(RUTA_PLOTTING) {
    cargarMensajesDeVoz();
}

SDL2pp::Music& SonidosSDL::obtenerMusica() {
    return plotting;
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeConstruyendo() {
    return construyendo[casa];
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeEdificioConstruido() {
    return edificio_construido[casa];
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeNuevosEdificiosDisponibles() {
    return nuevos_edificios_disponibles[casa];
}
