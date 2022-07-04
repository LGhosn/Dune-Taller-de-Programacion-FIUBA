#include "client_serializador.h"
#include <arpa/inet.h>
#include <stdexcept>
#include <iostream>

uint8_t SerializadorCliente::obtenerCodigoCasa(const std::string& casa) const {
    if (casa == "Harkonnen")
        return 0;
    if (casa == "Atreides")
        return 1;
    if (casa == "Ordos")
        return 2;
    else
        throw std::runtime_error("Casa no reconocida");
}

std::vector<uint8_t> SerializadorCliente::serializarSolicitudCrearPartida(
                                                        SolicitudCrearPartidaDTO& solicitud) {
    uint16_t largo_nombre = solicitud.nombre_partida.length();
    uint16_t largo_mapa = solicitud.mapa.length();
    std::vector<uint8_t> buffer(7 + largo_nombre + largo_mapa);

    buffer[0] = CODIGO_SOLICITUD_CREAR_PARTIDA;
    buffer[1] = obtenerCodigoCasa(solicitud.casa);
    buffer[2] = solicitud.jugadores_requeridos;

    uint16_t* ptr_16 = (uint16_t*) (buffer.data() + 3);
    ptr_16[0] = htons(largo_nombre);

    for (int i = 0; i < largo_nombre; i++) {
        buffer[5 + i] = solicitud.nombre_partida[i];
    }

    ptr_16 = (uint16_t*) (buffer.data() + 5 + largo_nombre);
    ptr_16[0] = htons(largo_mapa);

    for (int i = 0; i < largo_mapa; i++) {
        buffer[7 + largo_nombre + i] = solicitud.mapa[i];
    }

    return buffer;
}

std::vector<uint8_t> SerializadorCliente::serializarSolicitudUnirseAPartida(
                                                    SolicitudUnirseAPartidaDTO& solicitud) {
    uint16_t largo_nombre = solicitud.nombre_partida.length();
    std::vector<uint8_t> buffer(4 + largo_nombre);
    buffer[0] = CODIGO_SOLICITUD_UNIRSE_A_PARTIDA;
    buffer[1] = obtenerCodigoCasa(solicitud.casa);
    uint16_t* ptr_16 = (uint16_t*) (buffer.data() + 2);
    ptr_16[0] = htons(largo_nombre);
    for (int i = 0; i < largo_nombre; i++) {
        buffer[4 + i] = solicitud.nombre_partida[i];
    }
    return buffer;
}

std::vector<uint8_t> SerializadorCliente::serializarSolicitudCrearEdificio(uint8_t id_jugador,
                                                                            Coordenadas& coords,
                                                                            uint8_t tipo) {
    std::vector<uint8_t> buffer(7);
    buffer[0] = CODIGO_SOLICITUD_CREAR_EDIFICIO;
    buffer[1] = id_jugador;
    buffer[2] = tipo;
    uint16_t x = htons(coords.x);
    uint16_t y = htons(coords.y);
    uint16_t* ptr_16 = (uint16_t*) (buffer.data() + 3);
    ptr_16[0] = x;
    ptr_16[1] = y;
    return buffer;
}

std::vector<uint8_t> SerializadorCliente::serializarSolicitudComprarUnidad(uint8_t id_jugador, uint8_t tipo) {
    std::vector<uint8_t> buffer(3);
    buffer[0] = CODIGO_SOLICITUD_COMPRAR_UNIDAD;
    buffer[1] = id_jugador;
    buffer[2] = tipo;
    return buffer;
}

std::vector<uint8_t> SerializadorCliente::serializarSolicitudMoverUnidad(uint8_t id_jugador, uint8_t id_unidad,
                                                    Coordenadas& coords_a_moverse) {
    std::vector<uint8_t> buffer(7);
    buffer[0] = CODIGO_SOLICITUD_MOVER_UNIDAD;
    buffer[1] = id_jugador;
    buffer[2] = id_unidad;
    uint16_t* aux = (uint16_t*) (buffer.data() + 3);
    aux[0] = htons(coords_a_moverse.x);
    aux[1] = htons(coords_a_moverse.y);
    return buffer;
}
