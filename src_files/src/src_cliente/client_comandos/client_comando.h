#ifndef COMANDO_H
#define COMANDO_H

#include "../client_world_view/world_view.h"

class ComandoCliente {
public:
	virtual bool ejecutar(WorldView& worldView) const = 0;

	virtual ~ComandoCliente() = default;
};

#endif
