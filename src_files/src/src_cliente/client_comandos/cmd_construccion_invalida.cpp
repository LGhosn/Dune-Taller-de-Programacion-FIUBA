#include "cmd_construccion_invalida.h"

bool CmdConstruccionInvalidaCliente::ejecutar(WorldView& worldView) const {
    worldView.construccionInvalida();
    return true;
}
