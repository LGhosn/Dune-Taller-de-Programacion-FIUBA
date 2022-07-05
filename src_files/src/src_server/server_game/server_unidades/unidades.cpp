#include "unidades.h"
#include "../../server_comandos/cmd_mover_unidad.h"
#include <cmath>

Unidad::Unidad(Jugador& duenio, Mapa& mapa, Coordenadas origen, YAML::Node& constantes,
                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comando,
                std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
                duenio(duenio),
                mapa(mapa),
                origen(origen),
                colas_comandos(colas_comando),
                unidades(unidades),
                ticks(constantes["TicksPorSegundo"].as<uint16_t>()) {}

void Unidad::empezarMovimiento(const Coordenadas& destino) {
    this->atacando = false;
    this->persiguiendo = false;
    unidad_a_atacar = nullptr;
    this->destino = destino;
    setearNuevoCamino();
}

void Unidad::setearNuevoCamino() {
    UnidadInfoDTO info(this->origen, destino, this->terrenos_no_accesibles, this->penalizacion_terreno);
    this->camino = this->mapa.obtenerCamino(info);
    if(this->camino.empty()) {
        return;
    }
    this->moviendose = true;
    setearNuevoMovimiento();
}

void Unidad::setearNuevoMovimiento() {
    uint16_t tiempo_para_moverse = obtenerTiempoParaMoverse();
    setTicksParaSigMovimiento(tiempo_para_moverse);
    uint8_t direccion = mapa.obtenerDireccion(origen, camino.top());
    for (auto& cola : colas_comandos) {
        CmdMoverUnidadServer* comando = new CmdMoverUnidadServer(id, direccion, tiempo_para_moverse);
        cola.second->push(comando);
    }
}

uint16_t Unidad::obtenerTiempoParaMoverse() {
    float distancia = sqrt(pow(origen.x - this->camino.top().x, 2) + pow(origen.y - this->camino.top().y, 2));
    char tipo_de_terreno = this->mapa.obtenerTipoDeTerreno(this->camino.top());
    return (DISTANCIA_A_MOVER / this->velocidad) * penalizacion_terreno[tipo_de_terreno] * 1000 * distancia;
}

void Unidad::setTicksParaSigMovimiento(uint16_t tiempo_para_moverse) {
    this->ticks_para_sig_movimiento =  tiempo_para_moverse * ticks / 1000;
    this->ticks_restantes = this->ticks_para_sig_movimiento;
}

void Unidad::updateMovimiento(long ticks_transcurridos) {
    if (this->moviendose) {
        if (this->ticks_restantes > ticks_transcurridos) {
            this->ticks_restantes -= ticks_transcurridos;
        } else {
            if (persiguiendo && (unidad_a_atacar != nullptr) && estaEnRango(unidad_a_atacar->destino)) {
                moviendose = false;
                atacando = true;
                return;
            } else if ((unidad_a_atacar != nullptr) && persiguiendo && destino != unidad_a_atacar->origen) {
                destino = unidad_a_atacar->origen;
                UnidadInfoDTO info(this->origen, this->destino, this->terrenos_no_accesibles, this->penalizacion_terreno);
                this->camino = mapa.obtenerCamino(info);
            }
            Coordenadas top = this->camino.top();
            if (this->mapa.esCoordenadaValida(top)) {
                this->mapa.moverUnidad(this->origen, top);
                this->origen = top;
                this->camino.pop();
                if (camino.empty()) {
                    moviendose = false;
                } else {
                    setearNuevoMovimiento();
                }
            } else {
                UnidadInfoDTO info(this->origen, this->destino, this->terrenos_no_accesibles, this->penalizacion_terreno);
                this->camino = this->mapa.obtenerCamino(info);
                if(this->camino.size() <= 1) {
                    this->moviendose = false;
                    this->camino = std::stack<Coordenadas>();
                    return;
                }
            }
        }
    }
}

void Unidad::atacar(std::shared_ptr<Unidad> unidad_a_atacar) {
    this->destino = unidad_a_atacar->origen;
    if (!unidad_a_atacar->sigueViva()) {
        return;
    }
    if (estaEnRango(destino)) {
        atacando = true;
        // disparar();
    } else {
        atacando = false;
        Coordenadas coords = this->mapa.obtenerCoordenadasEnRango(this->rango, destino);
        empezarMovimiento(coords);
    }
    persiguiendo = true;
    this->unidad_a_atacar = unidad_a_atacar;
}

void Unidad::updateAtaque(long ticks_transcurridos) {
    // Si la unidad no tiene ordenes del jugador.
    if (!atacando) {
        if (!moviendose && !persiguiendo) {
            atacarUnidadEnRango();
        }
    } else {
        if (!estaEnRango(unidad_a_atacar->origen)) {
            if(persiguiendo) {
                moviendose = true;
                Coordenadas coords = mapa.obtenerCoordenadasEnRango(rango, unidad_a_atacar->origen);
                this->destino = coords;
                UnidadInfoDTO info(this->origen, coords, this->terrenos_no_accesibles, this->penalizacion_terreno);
                this->camino = mapa.obtenerCamino(info);
            } else {
                unidad_a_atacar = nullptr;
            }
            atacando = false;

        } else {
            // disparar
        }
    }

    // Si la unidad a atacar murio hay que esperar una orden del jugador.
    if ((unidad_a_atacar != nullptr) && (!unidad_a_atacar->sigueViva())) {
        unidad_a_atacar = nullptr;
        atacando = false;
    }
}

bool Unidad::update(long ticks_transcurridos) {
    if (!sigueViva()) {
        return false;
    }
    updateAtaque(ticks_transcurridos);
    updateMovimiento(ticks_transcurridos);
    return true;
}

uint8_t Unidad::obtenerIdJugador() {
    return this->duenio.obtenerId();
}

bool Unidad::sigueViva() {
    return esta_viva;
}

bool Unidad::estaEnRango(Coordenadas& coords) const {
    uint16_t distancia = sqrt(pow(origen.x - coords.x, 2) + pow(origen.y - coords.y, 2));
    return distancia <= rango;
}

void Unidad::atacarUnidadEnRango() {
    bool unidad_cerca = false;
    for (auto& unidad : unidades) {
        if ((unidad.second->obtenerIdJugador() != this->obtenerIdJugador()) && estaEnRango(unidad.second->origen)) {
            unidad_cerca = true;
            atacando = true;
            unidad_a_atacar = unidad.second;
            destino = unidad_a_atacar->origen;
            // disparar
            //return;
        }
    }
    if (!unidad_cerca) {
        atacando = false;
        unidad_a_atacar = nullptr;
    }
}
