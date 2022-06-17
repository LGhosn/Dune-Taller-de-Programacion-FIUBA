#ifndef CLIENT_SOLICITUD_UNIRSE_A_PARTIDA_DTO_H
#define CLIENT_SOLICITUD_UNIRSE_A_PARTIDA_DTO_H

#include <string>

struct SolicitudUnirseAPartidaDTO {
    const std::string nombre_partida;
    std::string casa;
    uint8_t casa_codigo;

    SolicitudUnirseAPartidaDTO(std::string& nombre_partida, std::string& casa) :
            nombre_partida(std::move(nombre_partida)),
            casa(std::move(casa)) {}

    SolicitudUnirseAPartidaDTO(std::string& nombre_partida, uint8_t casa_codigo) :
            nombre_partida(std::move(nombre_partida)),
            casa_codigo(casa_codigo) {}
};

#endif //CLIENT_SOLICITUD_UNIRSE_A_PARTIDA_DTO_H
