#include "cmd_modificar_vida_edificio.h"

CmdModificarVidaEdificioCliente::CmdModificarVidaEdificioCliente(uint8_t id_edificio,
                                        uint8_t unidad_atacante, uint16_t vida):
                                        id_edificio(id_edificio),
                                        unidad_atacante(unidad_atacante),
                                        vida(vida) {}

bool CmdModificarVidaEdificioCliente::ejecutar(WorldView& worldView) const {
    worldView.modificarVidaEdificio(id_edificio, unidad_atacante, vida);
    return true;
}
