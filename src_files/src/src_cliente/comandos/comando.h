#ifndef COMANDO_H
#define COMANDO_H

#include "world_view.h"

class Comando {
public:
	virtual bool ejecutar(WorldView& worldView, float tiempo_transcurrido);
};

#endif
