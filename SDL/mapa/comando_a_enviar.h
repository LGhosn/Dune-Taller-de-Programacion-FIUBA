#ifndef COMAND_A_ENVIAR_H
#define COMAND_A_ENVIAR_H

#include "comando.h"

class ComandoAEnviar : Comando {
public:
	virtual void enviar_instruccion(Protocolo& protocolo, Socket& socket);
};

#endif
