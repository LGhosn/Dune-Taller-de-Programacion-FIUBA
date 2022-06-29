#include "unidades.h"

#include <stack>

#define DISTANCIA_A_MOVER 8

Tanque::Tanque(uint8_t id, Jugador& duenio, Mapa& mapa) {
    this->id = id;
    this->duenio = std::move(duenio);
    this->mapa = std::move(mapa);
    // this->terrenos_no_accesibles = obtenerTerrenosNoAccesibles();
    // this->penalizacion_terreno = obtenerPenalizacionTerreno();
    // this->velocidad = obtenerVelocidad();
    // this->vida = obtenerVida();
}

void Tanque::empezarMovimiento(const Coordenadas& destino) {
    UnidadInfoDTO info(this->origen, destino, this->terrenos_no_accesibles, this->penalizacion_terreno);
    this->camino = mapa.obtenerCamino(info);
    this->moviendose = true;
    setTicksParaSigMovimiento();
}

void Tanque::setTicksParaSigMovimiento() {
    Coordenadas sig_coord = camino.top();
    this->ticks_para_sig_movimiento = (DISTANCIA_A_MOVER / velocidad) * 100;
    this->ticks_restantes = ticks_para_sig_movimiento;
}

void Tanque::update(long ticks_transcurridos, long *tiempo, char *direccion) {
    if (this->moviendose) {
        if (this->ticks_restantes > ticks_transcurridos) {
            this->ticks_restantes -= ticks_transcurridos;

        }else {
            Coordenadas top = camino.top();
            if (mapa.esCoordenadaValida(top)) {
                *tiempo = this->ticks_para_sig_movimiento;
                *direccion = mapa.moverUnidad(origen, top);
                this->origen = top;
                camino.pop();
                setTicksParaSigMovimiento();
            }

        }
    }
}

