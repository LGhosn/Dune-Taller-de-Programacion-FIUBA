#ifndef CLIENTE_DTO_CMD_EMPEZAR_ENTRENAMIENTO_UNIDAD_H
#define CLIENTE_DTO_CMD_EMPEZAR_ENTRENAMIENTO_UNIDAD_H

struct CmdEmpezarEntrenamientoClienteDTO {
    uint8_t tipo;
    uint16_t tiempo_construccion;

    CmdEmpezarEntrenamientoClienteDTO(uint8_t tipo, uint16_t tiempo_construccion) :
                                        tipo(tipo),
                                        tiempo_construccion(tiempo_construccion) {};
};

#endif // CLIENTE_DTO_CMD_EMPEZAR_ENTRENAMIENTO_UNIDAD_H
