#include "unidades.h"
#include "../../server_comandos/cmd_mover_unidad.h"
#include <cmath>
#include "../../server_comandos/cmd_enemigo_despliega_unidad.h"
#include "../../server_comandos/cmd_empezar_entrenamiento.h"
#include "../../server_comandos/cmd_modificar_vida_unidad.h"

uint8_t Unidad::contador_ids = 0;

Unidad::Unidad(Jugador& duenio,
                uint8_t tipo_unidad,
                Mapa& mapa,
                YAML::Node& constantes,
                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comando,
                std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
                    duenio(duenio),
                    tipo_unidad(tipo_unidad),
                    mapa(mapa),
                    origen(this->mapa.obtenerCoordenadasSpawn(obtenerIdJugador())),
                    id(contador_ids++),
                    colas_comandos(colas_comando),
                    unidades(unidades),
                    ticks(constantes["TicksPorSegundo"].as<uint16_t>()) {
    this->mapa.spawnearUnidad(obtenerIdJugador(), tipo_unidad, id, origen);
}

void Unidad::enviarComandoEmpezarEntrenamiento() {
    uint16_t tiempo_entrenamiento_unidad = duenio.obtenerTiempoConstruccionUnidad(tipo_unidad);
    CmdEmpezarEntrenamientoServer* comando =
                    new CmdEmpezarEntrenamientoServer(id, tipo_unidad, tiempo_entrenamiento_unidad, origen, vida);
    colas_comandos[obtenerIdJugador()]->push(comando);
    for (auto& cola : colas_comandos) {
        if (cola.first == obtenerIdJugador()) {
            continue;
        }
        CmdEnemigoDespliegaUnidadServer* comando =
            new CmdEnemigoDespliegaUnidadServer(id, obtenerIdJugador(), tipo_unidad, tiempo_entrenamiento_unidad, origen, vida);
        cola.second->push(comando);
    }
}

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
}

void Unidad::enviarComando() {
    uint16_t tiempo_para_moverse = obtenerTiempoParaMoverse();
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
            if (persiguiendo && (unidad_a_atacar != nullptr) && estaEnRango(unidad_a_atacar->ubicacion())) {
                moviendose = false;
                atacando = true;
                this->camino = std::stack<Coordenadas>();
                return;
            }
            Coordenadas top = this->camino.top();
            if (this->mapa.esCoordenadaValida(top)) {
                enviarComando();
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

void Unidad::atacar(std::shared_ptr<EntidadServer> entidad_a_atacar) {
    if (!entidad_a_atacar->sigueViva()) {
        atacando = false;
        return;
    }
    if (estaEnRango(entidad_a_atacar->ubicacion())) {
        atacando = true;
        arma->disparar(entidad_a_atacar);
    } else {
        atacando = false;
        this->destino = this->mapa.obtenerCoordenadasEnRango(this->rango, entidad_a_atacar->ubicacion());
        setearNuevoCamino();
    }
    persiguiendo = true;
    this->unidad_a_atacar = entidad_a_atacar;
}

void Unidad::updateAtaque(long ticks_transcurridos) {
    // Si la unidad no tiene ordenes del jugador.
    if (!atacando) {
        if (!moviendose && !persiguiendo) {
            atacarUnidadEnRango();
        }
    } else if (persiguiendo) {
        if (!moviendose && !estaEnRango(unidad_a_atacar->ubicacion())) {
            moviendose = true;
            this->destino = mapa.obtenerCoordenadasEnRango(rango, unidad_a_atacar->ubicacion());
            setearNuevoCamino();
        } else if (!moviendose && estaEnRango(unidad_a_atacar->ubicacion())) {
            atacando = true;
            arma->disparar(unidad_a_atacar);
            if (!unidad_a_atacar->sigueViva()) {
                atacando = false;
                unidad_a_atacar = nullptr;
                persiguiendo = false;
                moviendose = false;
            }
        }
    } else if (atacando) {
        if (!estaEnRango(unidad_a_atacar->ubicacion())) {
            atacando = false;
        } else {
            arma->disparar(unidad_a_atacar);
            if (!unidad_a_atacar->sigueViva()) {
                atacando = false;
                unidad_a_atacar = nullptr;
                persiguiendo = false;
                moviendose = false;
            }
        }
    }
}

bool Unidad::update(long ticks_transcurridos) {
    if (!sigueViva()) {
        return false;
    }
    updateAtaque(ticks_transcurridos);
    updateMovimiento(ticks_transcurridos);
    arma->update(ticks_transcurridos);
    return true;
}

uint8_t Unidad::obtenerIdJugador() {
    return this->duenio.obtenerId();
}

uint8_t Unidad::obtenerId() const {
    return this->id;
}

bool Unidad::sigueViva() {
    return esta_viva;
}

bool Unidad::estaEnRango(Coordenadas& coords) const {
    uint16_t distancia = sqrt(pow(origen.x - coords.x, 2) + pow(origen.y - coords.y, 2));
    return distancia <= rango;
}

void Unidad::atacarUnidadEnRango() {
    for (auto& unidad : unidades) {
        if ((unidad.second->obtenerIdJugador() != this->obtenerIdJugador()) && estaEnRango(unidad.second->origen)) {
            std::cout << "Unidad en rango" << std::endl;
            atacando = true;
            this->unidad_a_atacar = unidad.second;
            arma->disparar(this->unidad_a_atacar);
            return;
        }
    }
    atacando = false;
    unidad_a_atacar = nullptr;
}

void Unidad::recibirDmg(uint8_t dmg_entrante, uint8_t id_unidad_atacante) {
    if (sigueViva()) {
        if (this->vida > dmg_entrante) {
            this->vida -= dmg_entrante;
        } else {
            this->mapa.eliminarUnidad(id);
            unidades.erase(this->id);
            this->vida = 0;
            moviendose = false;
            persiguiendo = false;
            atacando = false;
            esta_viva = false;
        }
        for (auto& cola : colas_comandos) {
            CmdModificarVidaUnidadServer* comando = new CmdModificarVidaUnidadServer(id, this->vida);
            cola.second->push(comando);
        }
    }
}

Coordenadas& Unidad::ubicacion() {
    return this->origen;
}
