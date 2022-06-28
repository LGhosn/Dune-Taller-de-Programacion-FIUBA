#ifndef CLIENTE_EMPEZAR_CONSTRUCCION_EDIFICIO_DTO_H
#define CLIENTE_EMPEZAR_CONSTRUCCION_EDIFICIO_DTO_H

#include <cstdint>

struct CmdEmpezarConstruccionEdificioDTO {
    uint8_t tipo;
    uint16_t tiempo_construccion;

    CmdEmpezarConstruccionEdificioDTO(uint8_t tipo, uint16_t tiempo_construccion) :
                                        tipo(tipo),
                                        tiempo_construccion(tiempo_construccion) {};
};

#endif // CLIENTE_EMPEZAR_CONSTRUCCION_EDIFICIO_DTO_H
