#include "unidades.h"
#include "../../server_comandos/cmd_mover_unidad.h"

Unidad::Unidad(Jugador& duenio, Mapa& mapa, Coordenadas origen, YAML::Node& constantes,
                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comando) :
                duenio(duenio),
                mapa(mapa),
                origen(origen),
                colas_comandos(colas_comando),
                ticks(constantes["TicksPorSegundo"].as<uint16_t>()) {}

void Unidad::empezarMovimiento(const Coordenadas& destino) {
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
        }else {
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
            }
        }
    }
}

void Unidad::update(long ticks_transcurridos) {
    updateMovimiento(ticks_transcurridos);
}

uint8_t Unidad::obtenerIdJugador() {
    return this->duenio.obtenerId();
}
