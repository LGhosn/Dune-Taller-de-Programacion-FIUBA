#ifndef SOL_CREAR_PARTIDA_H
#define SOL_CREAR_PARTIDA_H

#include <string>
#include "server_solicitud_menu.h"

class SolCrearPartidaServer : public SolicitudMenuServer {
    std::string nombre_partida;
    uint8_t jugadores_requeridos;
    std::string nombre_mapa;
public:
    SolCrearPartidaServer(const std::string& nombre_partida, uint8_t jugadores_requeridos, const std::string& nombre_mapa);
    void manejarSolicitud(Lobby& lobby) const override;
    ~SolCrearPartidaServer() = default;
};
#endif
