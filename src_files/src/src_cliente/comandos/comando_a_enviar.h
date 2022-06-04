#ifndef COMAND_A_ENVIAR_H
#define COMAND_A_ENVIAR_H

#include "comando.h"
#include "../client_protocolo.h"

class ComandoAEnviar : Comando {
public:
<<<<<<< HEAD
	virtual void enviar_instruccion(Protocolo& protocolo);
=======
	virtual void enviar_instruccion(ProtocoloCliente& protocolo, Socket& socket);
>>>>>>> 3ef1c9bd8d1cbc9e45286ec03b47b8d6e0eaa14f
};

#endif
