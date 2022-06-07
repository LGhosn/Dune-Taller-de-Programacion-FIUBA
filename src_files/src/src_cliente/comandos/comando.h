#ifndef COMANDO_H
#define COMANDO_H

#include "../world_view/world_view.h"

class Comando {
public:
	virtual bool ejecutar(WorldView& worldView) const = 0;

	virtual ~Comando();
};

#endif
