#include "unidades.h"
#include "../../server_comandos/cmd_mover_unidad.h"
#include <cmath>
#include "../../server_comandos/cmd_enemigo_despliega_unidad.h"
#include "../../server_comandos/cmd_empezar_entrenamiento.h"
#include "../../server_comandos/cmd_modificar_vida_unidad.h"
#include "comportamiento/unidad_modo_ataque.h"
#include "comportamiento/unidad_modo_pasivo.h"

uint8_t Unidad::contador_ids = 0;

Unidad::Unidad(Jugador& duenio,
                uint8_t tipo_unidad,
                Mapa& mapa,
                YAML::Node& constantes,
                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comando,
                uint8_t rango,
                uint16_t velocidad,
                uint16_t tiempo_entrenamiento,
                uint16_t vida,
                uint16_t costo,
                std::vector<float> penalizacion_terreno,
                std::vector<uint8_t> terrenos_no_accesibles,
                ArmaFactory& arma_factory,
                std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
                    duenio(duenio),
                    tipo_unidad(tipo_unidad),
                    id(contador_ids++),
                    ubicacion_actual(mapa.spawnearUnidad(obtenerIdJugador(), tipo_unidad, id)),
                    arma(arma_factory.obtenerArma(tipo_unidad, id)),
                    colas_comandos(colas_comando),
                    rango(rango),
                    velocidad(velocidad),
                    tiempo_entrenamiento(tiempo_entrenamiento),
                    vida(vida),
                    costo(costo),
                    penalizacion_terreno(penalizacion_terreno),
                    terrenos_no_accesibles(terrenos_no_accesibles),
                    mapa(mapa),
                    unidades(unidades),
                    ticks(constantes["TicksPorSegundo"].as<uint16_t>()),
                    multiplicador_tiempo_mov(constantes["Game"]["Unidades"]["ConstanteTiempoMovimiento"].as<uint16_t>()),
                    comportamiento(std::make_unique<UnidadModoPasivo>(this, ubicacion_actual)) {}

void Unidad::enviarComandoEmpezarEntrenamiento() {
    uint16_t tiempo_entrenamiento_unidad = duenio.obtenerTiempoConstruccionUnidad(tipo_unidad);
    CmdEmpezarEntrenamientoServer* comando =
                    new CmdEmpezarEntrenamientoServer(id, tipo_unidad, tiempo_entrenamiento_unidad,
                                                        ubicacion_actual, vida);
    colas_comandos[obtenerIdJugador()]->push(comando);
    for (auto& cola : colas_comandos) {
        if (cola.first == obtenerIdJugador()) {
            continue;
        }
        CmdEnemigoDespliegaUnidadServer* comando =
            new CmdEnemigoDespliegaUnidadServer(id, obtenerIdJugador(), tipo_unidad,
                                        tiempo_entrenamiento_unidad, ubicacion_actual, vida);
        cola.second->push(comando);
    }
}

void Unidad::atacar(std::shared_ptr<EntidadServer> entidad_a_atacar) {
    comportamiento->atacar(entidad_a_atacar);
}

void Unidad::moverA(const Coordenadas& destino) {
    comportamiento->moverA(destino);
}

void Unidad::update(long ticks_transcurridos) {
    if (!sigueViva()) {
        unidades.erase(id);
        mapa.eliminarUnidad(id);
    }
    comportamiento->update(ticks_transcurridos);
    arma->update(ticks_transcurridos);
}

uint8_t Unidad::obtenerIdJugador() const {
    return this->duenio.obtenerId();
}

uint8_t Unidad::obtenerId() const {
    return this->id;
}

bool Unidad::sigueViva() {
    return vida > 0;
}

void Unidad::recibirDmg(uint8_t dmg_entrante, uint8_t id_unidad_atacante) {
    if (sigueViva()) {
        if (this->vida > dmg_entrante) {
            this->vida -= dmg_entrante;
        } else {
            this->mapa.eliminarUnidad(id);
            unidades.erase(this->id);
            this->vida = 0;
        }
        for (auto& cola : colas_comandos) {
            CmdModificarVidaUnidadServer* comando = new CmdModificarVidaUnidadServer(id, this->vida);
            cola.second->push(comando);
        }
    }
}

const Coordenadas& Unidad::ubicacion() const {
    return ubicacion_actual;
}
