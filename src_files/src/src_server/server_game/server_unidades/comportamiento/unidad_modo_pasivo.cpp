#include "unidad_modo_pasivo.h"
#include "unidad_modo_ataque.h"

UnidadModoPasivo::UnidadModoPasivo(Unidad* unidad, const Coordenadas& destino_inicial) :
                    UnidadComportamiento(unidad),
                    destino(destino_inicial) {}

void UnidadModoPasivo::atacar(std::shared_ptr<EntidadServer> entidad_a_atacar) {                            
    unidad->comportamiento = std::make_unique<UnidadModoAtaque>(unidad, entidad_a_atacar);
}

void UnidadModoPasivo::moverA(const Coordenadas& destino) {
    moviendose = true;
    this->destino = destino;
    camino = std::stack<Coordenadas>();
}

void UnidadModoPasivo::update(long ticks_transcurridos) {
    if (!moviendose) {
        if (!entidad_a_atacar) {
            encontrarUnidadAAtacarEnRango();
        } else if (estaEnRango(entidad_a_atacar->ubicacion())) {
            unidad->arma->disparar(entidad_a_atacar);
            if (!entidad_a_atacar->sigueViva()) {
                entidad_a_atacar = nullptr;
            }
        } else {
            entidad_a_atacar = nullptr;
        }
    } else {
        if (camino.empty()) {
            if (unidad->ubicacion_actual == destino) {
                moviendose = false;
            } else {
                setearNuevoCamino(destino);
            }
        } else {
            if (this->ticks_restantes > ticks_transcurridos) {
                this->ticks_restantes -= ticks_transcurridos;
            } else {
                Coordenadas siguiente_pos = this->camino.top();
                if (unidad->mapa.esCoordenadaValida(siguiente_pos)) {
                    moverUnidad(siguiente_pos);
                } else {
                   setearNuevoCamino(destino);
                }
            }
        }
    }
}
