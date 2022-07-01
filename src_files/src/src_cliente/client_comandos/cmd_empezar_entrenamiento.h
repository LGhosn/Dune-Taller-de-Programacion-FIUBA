#ifndef CMD_EMPEZAR_ENTRENAMIENTO_H
#define CMD_EMPEZAR_ENTRENAMIENTO_H

#include "client_comando.h"
#include "../client_DTO/dto_cmd_empezar_entrenamiento_unidad.h"

class CmdEmpezarEntrenamientoCliente : public ComandoCliente {
    CmdEmpezarEntrenamientoClienteDTO dto;
public:
    CmdEmpezarEntrenamientoCliente(CmdEmpezarEntrenamientoClienteDTO& dto);

    virtual bool ejecutar(WorldView& worldView) const;

    virtual ~CmdEmpezarEntrenamientoCliente() = default;
};

#endif // CMD_EMPEZAR_ENTRENAMIENTO_H
