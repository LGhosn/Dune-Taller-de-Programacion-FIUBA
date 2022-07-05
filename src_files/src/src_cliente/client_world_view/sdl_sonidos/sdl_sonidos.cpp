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

    for (const std::string& casa : casas) {
        std::stringstream stream;
        stream << RUTA_SONIDOS << casa << "/mensajes_de_voz/unidad_creada.mp3";
        unidad_creada.emplace_back(stream.str());
    }
}

void SonidosSDL::cargarMusica() {
    for (const auto& archivo_musica : std::filesystem::directory_iterator(RUTA_MUSICA)) {
        musica.emplace_back(archivo_musica.path());
    }
}

void SonidosSDL::cargarVoces() {
    std::vector<std::string> casas;
    casas.emplace_back("harkonnen");
    casas.emplace_back("atreides");
    casas.emplace_back("ordos");

    uint8_t i = 0;
    for (const auto& casa: casas) {
        for (uint8_t j = 0; j < 3; j++) {
            std::stringstream stream;
            stream << RUTA_SONIDOS << casa << "/unidades/vehiculos/unidad_seleccionada" << (int) j << ".mp3";
            vehiculo_seleccionado[i].emplace_back(stream.str());
        }
        i++;
    }

    i = 0;
    for (const auto& casa: casas) {
        for (uint8_t j = 0; j < 3; j++) {
            std::stringstream stream;
            stream << RUTA_SONIDOS << casa << "/unidades/vehiculos/unidad_movida" << (int) j << ".mp3";
            vehiculo_movido[i].emplace_back(stream.str());
        }
        i++;
    }

    i = 0;
    for (const auto& casa : casas) {
        for (uint8_t j = 0; j < 3; j++) {
            std::stringstream stream;
            stream << RUTA_SONIDOS << casa
                << "/unidades/infanteria/infanteria_ligera/unidad_seleccionada" << (int) j << ".mp3";
            infanteria_ligera_seleccionada[i].emplace_back(stream.str());
        }
        i++;
    }

    i = 0;
    for (const auto& casa : casas) {
        for (uint8_t j = 0; j < 3; j++) {
            std::stringstream stream;
            stream << RUTA_SONIDOS << casa
                << "/unidades/infanteria/infanteria_ligera/unidad_movida" << (int) j << ".mp3";
            infanteria_ligera_movida[i].emplace_back(stream.str());
        }
        i++;
    }

    i = 0;
    for (const auto& casa : casas) {
        int k = 3;
        if (casa == "atreides") {
            k = 2;
        }
        for (uint8_t j = 0; j < k; j++) {
            std::stringstream stream;
            stream << RUTA_SONIDOS << casa
                << "/unidades/infanteria/infanteria_pesada/unidad_seleccionada" << (int) j << ".mp3";
            infanteria_pesada_seleccionada[i].emplace_back(stream.str());
        }
        i++;
    }

    i = 0;
    for (const auto& casa : casas) {
        int k = 3;
        if (casa == "atreides") {
            k = 2;
        }
        for (uint8_t j = 0; j < k; j++) {
            std::stringstream stream;
            stream << RUTA_SONIDOS << casa
                << "/unidades/infanteria/infanteria_pesada/unidad_movida" << (int) j << ".mp3";
            infanteria_pesada_movida[i].emplace_back(stream.str());
        }
        i++;
    }

    for (uint8_t j = 0; j < 3; j++) {
        std::stringstream stream;
        stream << RUTA_SONIDOS
            << "harkonnen/unidades/infanteria/sardaukar/unidad_seleccionada" << (int) j << ".mp3";
        sardaukar_seleccionado.emplace_back(stream.str());
    }

    for (uint8_t j = 0; j < 3; j++) {
        std::stringstream stream;
        stream << RUTA_SONIDOS 
            << "harkonnen/unidades/infanteria/sardaukar/unidad_movida" << (int) j << ".mp3";
        sardaukar_movido.emplace_back(stream.str());
    }

    for (uint8_t j = 0; j < 3; j++) {
        std::stringstream stream;
        stream << RUTA_SONIDOS
            << "atreides/unidades/infanteria/fremen/unidad_seleccionada" << (int) j << ".mp3";
        fremen_seleccionado.emplace_back(stream.str());
    }

    for (uint8_t j = 0; j < 4; j++) {
        std::stringstream stream;
        stream << RUTA_SONIDOS
            << "atreides/unidades/infanteria/fremen/unidad_movida" << (int) j << ".mp3";
        fremen_movido.emplace_back(stream.str());
    }
}

SonidosSDL::SonidosSDL(uint8_t casa, YAML::Node& constantes):
                    casa(casa),
                    vehiculo_seleccionado(3),
                    vehiculo_movido(3),
                    infanteria_ligera_seleccionada(3),
                    infanteria_ligera_movida(3),
                    infanteria_pesada_seleccionada(3),
                    infanteria_pesada_movida(3) {
    cargarMensajesDeVoz();
    cargarMusica();
    cargarVoces();
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

SDL2pp::Chunk& SonidosSDL::obtenerMensajeUnidadCreada() {
    return unidad_creada[casa];
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeUnidadSeleccionada(uint8_t tipo_unidad, uint8_t casa) {
    if (tipo_unidad > 3) {
        uint8_t cant_lineas_de_voz = vehiculo_seleccionado[casa].size();
        uint8_t indice_aleatorio = std::experimental::randint(0, (uint8_t) cant_lineas_de_voz - 1);
        return vehiculo_seleccionado[casa][indice_aleatorio];
    } else {
        if (tipo_unidad == 0) {
            uint8_t cant_lineas_de_voz = fremen_seleccionado.size();
            uint8_t indice_aleatorio = std::experimental::randint(0, (uint8_t) cant_lineas_de_voz - 1);
            return fremen_seleccionado[indice_aleatorio];
        } else if (tipo_unidad == 1) {
            uint8_t cant_lineas_de_voz = infanteria_ligera_seleccionada[casa].size();
            uint8_t indice_aleatorio = std::experimental::randint(0, (uint8_t) cant_lineas_de_voz - 1);
            return infanteria_ligera_seleccionada[casa][indice_aleatorio];
        } else if (tipo_unidad == 2) {
            uint8_t cant_lineas_de_voz = infanteria_pesada_seleccionada[casa].size();
            uint8_t indice_aleatorio = std::experimental::randint(0, (uint8_t) cant_lineas_de_voz - 1);
            return infanteria_pesada_seleccionada[casa][indice_aleatorio];
        } else {
            uint8_t cant_lineas_de_voz = sardaukar_seleccionado.size();
            uint8_t indice_aleatorio = std::experimental::randint(0, (uint8_t) cant_lineas_de_voz - 1);
            return sardaukar_seleccionado[indice_aleatorio];
        }
    }
}

SDL2pp::Chunk& SonidosSDL::obtenerMensajeUnidadMovida(uint8_t tipo_unidad, uint8_t casa) {
    if (tipo_unidad > 3) {
        uint8_t cant_lineas_de_voz = vehiculo_movido[casa].size();
        uint8_t indice_aleatorio = std::experimental::randint(0, (uint8_t) cant_lineas_de_voz - 1);
        return vehiculo_movido[casa][indice_aleatorio];
    } else {
        if (tipo_unidad == 0) {
            uint8_t cant_lineas_de_voz = fremen_movido.size();
            uint8_t indice_aleatorio = std::experimental::randint(0, (uint8_t) cant_lineas_de_voz - 1);
            return fremen_movido[indice_aleatorio];
        } else if (tipo_unidad == 1) {
            uint8_t cant_lineas_de_voz = infanteria_ligera_movida[casa].size();
            uint8_t indice_aleatorio = std::experimental::randint(0, (uint8_t) cant_lineas_de_voz - 1);
            return infanteria_ligera_movida[casa][indice_aleatorio];
        } else if (tipo_unidad == 2) {
            uint8_t cant_lineas_de_voz = infanteria_pesada_movida[casa].size();
            uint8_t indice_aleatorio = std::experimental::randint(0, (uint8_t) cant_lineas_de_voz - 1);
            return infanteria_pesada_movida[casa][indice_aleatorio];
        } else {
            uint8_t cant_lineas_de_voz = sardaukar_movido.size();
            uint8_t indice_aleatorio = std::experimental::randint(0, (uint8_t) cant_lineas_de_voz - 1);
            return sardaukar_movido[indice_aleatorio];
        }
    }
}
