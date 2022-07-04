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
#define CODIGO_SOLICITUD_COMPRAR_UNIDAD 11
#define CODIGO_SOLICITUD_MOVER_UNIDAD 50
#define CODIGO_SOLICITUD_ATACAR_UNIDAD 51

class SerializadorCliente {
    uint8_t obtenerCodigoCasa(const std::string& casa) const;
public:
    std::vector<uint8_t> serializarSolicitudCrearPartida(SolicitudCrearPartidaDTO& solicitud);
    std::vector<uint8_t> serializarSolicitudUnirseAPartida(SolicitudUnirseAPartidaDTO& solicitud);

    std::vector<uint8_t> serializarSolicitudCrearEdificio(uint8_t id_jugador,
                                                            Coordenadas& coords,
                                                            uint8_t tipo);

    std::vector<uint8_t> serializarSolicitudComprarUnidad(uint8_t id_jugador, uint8_t tipo);

    std::vector<uint8_t> serializarSolicitudMoverUnidad(uint8_t id_jugador, uint8_t id_unidad, Coordenadas& coords_a_moverse);

    std::vector<uint8_t> serializarSolicitudAtacarUnidad(uint8_t id_jugador_atacante, uint8_t id_unidad_atacante, uint8_t id_unidad_atacada, Coordenadas& coords);
};

#endif
