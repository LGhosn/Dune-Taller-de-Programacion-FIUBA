#include "unidad_modo_ataque.h"
#include "unidad_modo_pasivo.h"

UnidadModoAtaque::UnidadModoAtaque(Unidad* unidad,
                                std::shared_ptr<EntidadServer>& entidad_a_atacar) :
                    UnidadComportamiento(unidad) {
    this->entidad_a_atacar = entidad_a_atacar;
}

void UnidadModoAtaque::update(long ticks_transcurridos) {
    if (!entidad_a_atacar) {
        encontrarUnidadAAtacarEnRango();
    } else if (estaEnRango(entidad_a_atacar->ubicacion())) {
        unidad->arma->disparar(entidad_a_atacar);
        if (!entidad_a_atacar->sigueViva()) {
            entidad_a_atacar = nullptr;
        }
        this->camino = std::stack<Coordenadas>();
        ticks_restantes = 0;
    } else {
        if (camino.empty() && ticks_restantes == 0) {
            setearNuevoCamino(entidad_a_atacar->ubicacion());
        } else {
            if (this->ticks_restantes > ticks_transcurridos) {
                this->ticks_restantes -= ticks_transcurridos;
            } else {
                Coordenadas siguiente_pos = this->camino.top();
                if (unidad->mapa.esCoordenadaValida(siguiente_pos)) {
                    moverUnidad(siguiente_pos);
                } else {
                   setearNuevoCamino(entidad_a_atacar->ubicacion());
                }
            }
        }
    }
}

std::unique_ptr<UnidadComportamiento> UnidadModoAtaque::atacar(std::shared_ptr<EntidadServer> entidad_a_atacar) {
    this->entidad_a_atacar = entidad_a_atacar;
    return nullptr;
}

std::unique_ptr<UnidadComportamiento> UnidadModoAtaque::moverA(const Coordenadas& destino) {
    return std::make_unique<UnidadModoPasivo>(unidad, destino);
}
