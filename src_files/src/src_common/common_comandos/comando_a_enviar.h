#ifndef COMAND_A_ENVIAR_H
#define COMAND_A_ENVIAR_H

#include "comando.h"
#include "../../src_cliente/client_protocolo.h"
#include "../../src_server/server_protocolo.h"

class ComandoAEnviar {
public:
    virtual void enviar_instruccion(Protocolo_servidor& protocolo) = 0;
	virtual void enviar_solicitud(ProtocoloCliente& protocolo) = 0;
};

#endif
