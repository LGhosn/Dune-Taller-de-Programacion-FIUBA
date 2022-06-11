#ifndef SOLICITUD_UNIRSE_A_PARTIDA_H
#define SOLICITUD_UNIRSE_A_PARTIDA_H

#include "cliente_solicitud.h"

class SolicitudUnirseAPartida : public SolicitudCliente {
    std::string casa;
    std::string nombre_partida;
public:
    SolicitudUnirseAPartida(std::string casa, std::string nombre_partida);

    void enviarSolicitud(ProtocoloCliente& protocolo);

    ~SolicitudUnirseAPartida() = default;
};

#endif // SOLICITUD_UNIRSE_A_PARTIDA_H
