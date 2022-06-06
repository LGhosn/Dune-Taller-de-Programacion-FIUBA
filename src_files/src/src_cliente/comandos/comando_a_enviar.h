#ifndef COMAND_A_ENVIAR_H
#define COMAND_A_ENVIAR_H

#include "comando.h"
#include "../client_protocolo.h"

class ComandoAEnviar {
public:
	virtual void enviar_instruccion(ProtocoloCliente& protocolo) = 0;
};

#endif
