#include "unidades.h"

void Unidad::empezarMovimiento(const Coordenadas& destino) {
    UnidadInfoDTO info(this->origen, destino, this->terrenos_no_accesibles, this->penalizacion_terreno);
    this->camino = this->mapa.obtenerCamino(info);
    this->moviendose = true;
    setTicksParaSigMovimiento();
}

void Unidad::setTicksParaSigMovimiento() {
    this->ticks_para_sig_movimiento = (DISTANCIA_A_MOVER / this->velocidad) * 60;
    this->ticks_restantes = this->ticks_para_sig_movimiento;
}

void Unidad::update(long ticks_transcurridos, long *tiempo, char *direccion) {
    if (this->moviendose) {
        if (this->ticks_restantes > ticks_transcurridos) {
            this->ticks_restantes -= ticks_transcurridos;
        }else {
            Coordenadas top = this->camino.top();
            if (this->mapa.esCoordenadaValida(top)) {
                *tiempo = this->ticks_para_sig_movimiento;
                *direccion = this->mapa.moverUnidad(this->origen, top);
                this->origen = top;
                this->camino.pop();
                setTicksParaSigMovimiento();
            }
        }
    }
}

uint8_t Unidad::obtenerIdJugador() {
    return this->duenio.obtenerId();
}

Unidad::Unidad(Jugador& duenio, Mapa& mapa, Coordenadas origen) : duenio(duenio), mapa(mapa), origen(origen) {}
