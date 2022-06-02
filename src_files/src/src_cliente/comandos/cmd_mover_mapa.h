#ifndef CMD_MOVER_MAPA_H
#define CMD_MOVER_MAPA_H

#define ARRIBA 'A'
#define IZQUIERDA 'I'
#define ABAJO 'B'
#define DERECHA 'D'

#include "comando.h"
#include "world_view.h"

class MoverMapa : public Comando {
	const char direccion;

public:
	explicit MoverMapa(char direccion);

	virtual void ejecutar(WorldView& worldView) const;
};

#endif
