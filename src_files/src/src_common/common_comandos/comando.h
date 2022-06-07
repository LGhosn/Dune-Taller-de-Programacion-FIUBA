#ifndef COMANDO_H
#define COMANDO_H

#include "../../src_cliente/client_world_view/world_view.h"

class Comando {
public:
	virtual bool ejecutar(WorldView& worldView) const = 0;

	virtual ~Comando();
};

#endif
