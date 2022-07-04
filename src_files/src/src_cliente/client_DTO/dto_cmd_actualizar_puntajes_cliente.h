#ifndef CLIENTE_DTO_CMD_ACTUALIZAR_PUNTAJES_H
#define CLIENTE_DTO_CMD_ACTUALIZAR_PUNTAJES_H

#include <cstdint>

struct CmdActualizarPuntajesClienteDTO {
    uint8_t id_jugador;
    uint16_t nuevo_puntaje;
public:
    CmdActualizarPuntajesClienteDTO(uint8_t id_jugador, uint16_t nuevo_puntaje) :
                                        id_jugador(id_jugador),
                                        nuevo_puntaje(nuevo_puntaje) {}
};

#endif // CLIENTE_DTO_CMD_ACTUALIZAR_PUNTAJES_H