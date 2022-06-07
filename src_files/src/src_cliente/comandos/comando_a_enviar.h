#ifndef COMAND_A_ENVIAR_H
#define COMAND_A_ENVIAR_H

#include "../client_protocolo.h"

class ComandoAEnviar {
public:
	virtual void enviar_instruccion(ProtocoloCliente& protocolo, Socket& socket) const = 0;

	virtual ~ComandoAEnviar();
};

#endif
