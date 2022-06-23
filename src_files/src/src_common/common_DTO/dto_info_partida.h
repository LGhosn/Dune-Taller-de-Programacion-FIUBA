#ifndef COMMON_DTO_INFO_PARTIDA_H
#define COMMON_DTO_INFO_PARTIDA_H

#include <string>
#include <map>
#include <utility>
#include "../common_coords.h"

struct InfoPartidaDTO {
    std::string nombre_mapa;
    std::map<uint8_t, std::pair<uint8_t, std::string>> info_jugadores;
    Coordenadas coords_iniciales;

    InfoPartidaDTO(std::string nombre_mapa,
                std::map<uint8_t, std::pair<uint8_t, std::string>> info_jugadores,
                Coordenadas& coords_iniciales):
                nombre_mapa(nombre_mapa),
                info_jugadores(info_jugadores),
                coords_iniciales(coords_iniciales) {};

    InfoPartidaDTO() = default;

    InfoPartidaDTO(const InfoPartidaDTO& otro) :
                nombre_mapa(otro.nombre_mapa),
                info_jugadores(otro.info_jugadores),
                coords_iniciales(otro.coords_iniciales) {}

    InfoPartidaDTO& operator=(const InfoPartidaDTO& otro) {
        this->nombre_mapa = otro.nombre_mapa;
        this->info_jugadores = otro.info_jugadores;
        this->coords_iniciales = otro.coords_iniciales;
        return *this;
    }
};

#endif
