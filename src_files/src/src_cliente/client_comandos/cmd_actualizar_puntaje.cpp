#include "cmd_actualizar_puntaje.h"

CmdActualizarPuntajeCliente::CmdActualizarPuntajeCliente(uint8_t id_jugador, uint16_t nuevo_puntaje) :
                                                        id_jugador(id_jugador),
                                                        nuevo_puntaje(nuevo_puntaje) {}

bool CmdActualizarPuntajeCliente::ejecutar(WorldView& worldView) const {
    worldView.actualizarPuntaje(id_jugador, nuevo_puntaje);
    return true;
}