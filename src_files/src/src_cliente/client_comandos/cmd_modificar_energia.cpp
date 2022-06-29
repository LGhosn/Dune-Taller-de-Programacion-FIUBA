#include "cmd_modificar_energia.h"

CmdModificarEnergiaCliente::CmdModificarEnergiaCliente(int16_t cantidad_energia):
                                                cantidad_energia(cantidad_energia) {}

bool CmdModificarEnergiaCliente::ejecutar(WorldView& worldView) const {
    worldView.modificarEnergia(cantidad_energia);
    return true;
}
