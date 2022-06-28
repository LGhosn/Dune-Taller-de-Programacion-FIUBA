#include "cmd_empezar_construccion_edificio.h"

CmdEmpezarConstruccionEdificioCliente::CmdEmpezarConstruccionEdificioCliente(uint8_t tipo,
                                                uint16_t tiempo_construccion) :
                                                tipo(tipo),
                                                tiempo_construccion(tiempo_construccion) {}

bool CmdEmpezarConstruccionEdificioCliente::ejecutar(WorldView& worldView) const {
    worldView.empezarConstruccionEdificio(tipo, tiempo_construccion);
    return true;
}
