#include "cmd_salir.h"

bool ComandoSalir::ejecutar(WorldView& worldView) const {
    worldView.salir();
    return false;
}