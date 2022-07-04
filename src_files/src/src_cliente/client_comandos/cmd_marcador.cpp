#include "cmd_marcador.h"

ComandoMarcador::ComandoMarcador(bool estado_marcador) : estado_marcador(estado_marcador) {}

bool ComandoMarcador::ejecutar(WorldView& worldView) const {
    worldView.establecerEstadoDelMarcador(estado_marcador);
    return true;
}