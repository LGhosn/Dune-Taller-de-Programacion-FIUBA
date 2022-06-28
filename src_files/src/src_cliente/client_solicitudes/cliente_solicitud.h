#ifndef CLIENTE_SOLICITUD_H
#define CLIENTE_SOLICITUD_H

#include "../client_protocolo.h"

class SolicitudCliente {
public:
	virtual void enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador) = 0;

	virtual ~SolicitudCliente() = default;
};

#endif
