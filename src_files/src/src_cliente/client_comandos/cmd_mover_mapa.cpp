#include "cmd_mover_mapa.h"

MoverMapa::MoverMapa(char direccion) : direccion(direccion) {}

bool MoverMapa::ejecutar(WorldView& worldView) const {
	switch (this->direccion) {
		case ARRIBA:
			worldView.moverMapaArriba();
			break;
		case IZQUIERDA:
			worldView.moverMapaIzquierda();
			break;
		case DERECHA:
			worldView.moverMapaDerecha();
			break;
		case ABAJO:
			worldView.moverMapaAbajo();
			break;
		case DEJAR_DE_MOVER_H:
			worldView.dejarDeMoverMapaHorizontalmente();
			break;
		case DEJAR_DE_MOVER_V:
			worldView.dejarDeMoverMapaVerticalmente();
			break;
	}
	return true;
}
