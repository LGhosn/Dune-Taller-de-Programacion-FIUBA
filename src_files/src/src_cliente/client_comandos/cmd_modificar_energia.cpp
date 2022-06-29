#include "cmd_modificar_energia.h"

CmdModificarEnergiaCliente::CmdModificarEnergiaCliente(int16_t cantidad_energia, uint16_t tope_energia):
                                                cantidad_energia(cantidad_energia),
                                                tope_energia(tope_energia) {}

bool CmdModificarEnergiaCliente::ejecutar(WorldView& worldView) const {
    worldView.modificarEnergia(cantidad_energia,tope_energia);
    return true;
}
