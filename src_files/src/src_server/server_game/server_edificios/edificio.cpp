#include "edificio.h"
#include "../../server_comandos/cmd_crear_edificio.h"
#include "../../server_comandos/cmd_modificar_vida_edificio.h"

uint8_t EdificioServer::contador_ids = 0;

EdificioServer::EdificioServer(Jugador& duenio,
                                Mapa& mapa,
                                uint8_t tipo_edificio,
                                Coordenadas& coords,
                                YAML::Node& constantes,
                                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                                std::unordered_map<uint8_t, std::shared_ptr<EdificioServer> >& edificios)
                                : duenio(duenio),
                                mapa(mapa),
                                tipo_edificio(tipo_edificio),
                                id_edificio(contador_ids++),
                                coords(coords),
                                colas_comandos(colas_comandos),
                                edificios(edificios),
                                es_centro(esCentro()),
                                vida(constantes["Game"]["Edificios"]["HP"][tipo_edificio].as<uint16_t>()) {
    enviarComandoCrearEdificio();
}

void EdificioServer::enviarComandoCrearEdificio() {
    for (auto& cola : colas_comandos) {
        CmdCrearEdificioServer* comando =
        new CmdCrearEdificioServer(duenio.obtenerId(), id_edificio, tipo_edificio, coords, duenio.obtenerCasa(), vida);
        cola.second->push(comando);
    }
}

uint8_t EdificioServer::obtenerId() {
    return id_edificio;
}

void EdificioServer::recibirDmg(uint8_t dmg_entrante, uint8_t id_unidad_atacante) {
    if (sigueViva()) {
        if (this->vida > dmg_entrante) {
            this->vida -= dmg_entrante;
        } else {
            this->mapa.eliminarEdificio(id_edificio);
            edificios.erase(id_edificio);
            this->vida = 0;
        }
        std::cout << "Vida restante: " << vida << std::endl;
        for (auto& cola : colas_comandos) {
            CmdModificarVidaEdificioServer* comando = new CmdModificarVidaEdificioServer(id_edificio, id_unidad_atacante,this->vida);
            cola.second->push(comando);
        }
    }
}

bool EdificioServer::esCentro() const {
    return tipo_edificio == 0;
}

bool EdificioServer::sigueViva() {
    return vida > 0;
}

Coordenadas& EdificioServer::ubicacion() {
    return coords;
}
