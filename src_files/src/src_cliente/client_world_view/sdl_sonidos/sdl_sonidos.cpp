#include "sdl_sonidos.h"
#include <filesystem>
#include <cstdlib>
#include <iostream>
#include <experimental/random>

void SonidosSDL::cargarMensajesDeVoz() {
    std::vector<std::string> casas;
    casas.emplace_back("harkonnen");
    casas.emplace_back("atreides");
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
        stream << RUTA_SONIDOS << casa << "/mensajes_de_voz/construccion_invalida.mp3";
        construccion_invalida.emplace_back(stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_SONIDOS << casa << "/mensajes_de_voz/nuevos_edificios_disponibles.mp3";
        nuevos_edificios_disponibles.emplace_back(stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_SONIDOS << casa << "/mensajes_de_voz/entrenando.mp3";
        entrenando.emplace_back(stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_SONIDOS << casa << "/mensajes_de_voz/energia_baja.mp3";
        energia_baja.emplace_back(stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_SONIDOS << casa << "/mensajes_de_voz/mision_completa.mp3";
        victoria.emplace_back(stream.str());
    }
    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_SONIDOS << casa << "/mensajes_de_voz/mision_fallida.mp3";
        derrota.emplace_back(stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_SONIDOS << casa << "/mensajes_de_voz/ataque_gusano.mp3";
        ataque_gusano.emplace_back(stream.str());
    }

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_SONIDOS << casa << "/mensajes_de_voz/centro_atacado.mp3";
        centro_atacado.emplace_back(stream.str());
    }
}

void SonidosSDL::cargarMusica() {
    for (const auto& archivo_musica : std::filesystem::directory_iterator(RUTA_MUSICA)) {
        musica.emplace_back(archivo_musica.path());
    }
}

SonidosSDL::SonidosSDL(uint8_t casa, YAML::Node& constantes):
                    casa(casa) {
    cargarMensajesDeVoz();
    cargarMusica();
}

SDL2pp::Music& SonidosSDL::obtenerMusica() {
    uint8_t indice_aleatorio = std::experimental::randint(0, (uint8_t) musica.size() - 1);
    return musica[indice_aleatorio];
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeConstruyendo() {
    return construyendo[casa];
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeEdificioConstruido() {
    return edificio_construido[casa];
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeConstruccionInvalida() {
    return construccion_invalida[casa];
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeNuevosEdificiosDisponibles() {
    return nuevos_edificios_disponibles[casa];
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeEntrenando() {
    return entrenando[casa];
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeEnergiaBaja() {
    return energia_baja[casa];
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeVictoria() {
    return victoria[casa];
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeDerrota() {
    return derrota[casa];
}

SDL2pp::Chunk&  SonidosSDL::obtenerMensajeAtaqueGusano() {
    return ataque_gusano[casa];
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeCentroAtacado() {
    return centro_atacado[casa];
}
