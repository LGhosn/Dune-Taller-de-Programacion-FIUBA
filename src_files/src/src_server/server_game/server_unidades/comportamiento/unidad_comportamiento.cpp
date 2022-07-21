#include "unidad_comportamiento.h"
#include "../../../server_DTO/dto_unidad_info.h"
#include "../../../server_comandos/cmd_mover_unidad.h"

UnidadComportamiento::UnidadComportamiento(Unidad* unidad) : unidad(unidad) {}

void UnidadComportamiento::encontrarUnidadAAtacarEnRango() {
    for (auto& otra_unidad : unidad->unidades) {
        if ((otra_unidad.second->obtenerIdJugador() != this->unidad->duenio.obtenerId()) && 
        estaEnRango(otra_unidad.second->ubicacion())) {
            entidad_a_atacar = otra_unidad.second;
            break;
        }
    }
}

bool UnidadComportamiento::estaEnRango(Coordenadas& coords) const {
    uint16_t distancia = sqrt(pow(unidad->ubicacion_actual.x - coords.x, 2) + pow(unidad->ubicacion_actual.y - coords.y, 2));
    return distancia <= unidad->rango;
}

void UnidadComportamiento::setearNuevoCamino(Coordenadas& destino) {
    UnidadInfoDTO info(unidad->ubicacion_actual, destino, unidad->terrenos_no_accesibles, unidad->penalizacion_terreno);
    camino = unidad->mapa.obtenerCamino(info);
    if(this->camino.empty()) {
        return;
    }
    setearNuevoMovimiento();
}

void UnidadComportamiento::setearNuevoMovimiento() {
    uint16_t tiempo_para_moverse = obtenerTiempoParaMoverse();
    setTicksParaSigMovimiento(tiempo_para_moverse);
}

void UnidadComportamiento::setTicksParaSigMovimiento(uint16_t tiempo_para_moverse) {
    this->ticks_para_sig_movimiento =  tiempo_para_moverse * unidad->ticks;
    this->ticks_restantes = this->ticks_para_sig_movimiento;
}

uint16_t UnidadComportamiento::obtenerTiempoParaMoverse() {
    float distancia = sqrt(pow(unidad->ubicacion_actual.x - this->camino.top().x, 2) + pow(unidad->ubicacion_actual.y - this->camino.top().y, 2));
    char tipo_de_terreno = unidad->mapa.obtenerTipoDeTerreno(this->camino.top());
    return (distancia / unidad->velocidad) * unidad->penalizacion_terreno[tipo_de_terreno] * unidad->multiplicador_tiempo_mov;
}

void UnidadComportamiento::moverUnidad(Coordenadas& destino) {
    uint16_t tiempo_para_moverse = obtenerTiempoParaMoverse();
    uint8_t direccion = unidad->mapa.obtenerDireccion(unidad->ubicacion_actual, camino.top());
    for (auto& cola : unidad->colas_comandos) {
        CmdMoverUnidadServer* comando = new CmdMoverUnidadServer(unidad->id, direccion, tiempo_para_moverse);
        cola.second->push(comando);
    }
    unidad->mapa.moverUnidad(unidad->ubicacion_actual, destino);
    unidad->ubicacion_actual = destino;
    this->camino.pop();
    if (!camino.empty()) {
        setearNuevoMovimiento();
    } else {
        ticks_restantes = 0;
    }
}
