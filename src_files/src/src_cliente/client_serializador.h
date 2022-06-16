#ifndef CLIENT_SERIALIZADOR_H
#define CLIENT_SERIALIZADOR_H

#include <vector>
#include <cstdint>
#include "../src_common/common_coords.h"
#include "../src_common/common_DTO/dto_sol_crear_partida.h"
#include "../src_common/common_DTO/dto_sol_unirse_a_partida.h"

#define CODIGO_SOLICITUD_UNIRSE_A_PARTIDA 1
#define CODIGO_SOLICITUD_CREAR_PARTIDA 3
#define CODIGO_SOLICITUD_CREAR_EDIFICIO 5

class SerializadorCliente {
    uint8_t obtenerCodigoCasa(const std::string& casa) const;
public:
    std::vector<uint8_t> serializarSolicitudCrearPartida(SolicitudCrearPartidaDTO& solicitud);
    std::vector<uint8_t> serializarSolicitudUnirseAPartida(SolicitudUnirseAPartidaDTO& solicitud);

    std::vector<uint8_t> serializarSolicitudCrearEdificio(uint8_t id_jugador,
                                                            Coordenadas& coords,
                                                            uint8_t tipo);
};

#endif
