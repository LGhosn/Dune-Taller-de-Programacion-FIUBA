#include "energia_acumulada.h"
#include "../../server_comandos/cmd_modificar_energia.h"

void EnergiaAcumulada::actualizarEnergia(int16_t diferencia) {
    cantidad_energia -= diferencia;
    CmdModificarEnergiaServer* comando = new CmdModificarEnergiaServer(cantidad_energia);
    cola_comandos->push(comando);
}

EnergiaAcumulada::EnergiaAcumulada(ColaBloqueante<ComandoServer>* cola_comandos,
                                    YAML::Node& constantes) :
			cola_comandos(cola_comandos),
            cantidad_energia(constantes["Game"]["Energia"]["ValorInicial"].as<int16_t>()),
            energia_centro(constantes["Game"]["Energia"]["Valor"]["Centro"].as<int16_t>()),
            energia_cuartel(constantes["Game"]["Energia"]["Valor"]["Cuartel"].as<int16_t>()),
            energia_fabrica_ligera(constantes["Game"]["Energia"]["Valor"]["FabricaLigera"].as<int16_t>()),
            energia_fabrica_pesada(constantes["Game"]["Energia"]["Valor"]["FabricaPesada"].as<int16_t>()),
            energia_palacio(constantes["Game"]["Energia"]["Valor"]["Palacio"].as<int16_t>()),
            energia_refineria(constantes["Game"]["Energia"]["Valor"]["Refineria"].as<int16_t>()),
            energia_silo(constantes["Game"]["Energia"]["Valor"]["Silo"].as<int16_t>()),
            energia_trampa(constantes["Game"]["Energia"]["Valor"]["Trampa"].as<int16_t>()),
            multiplicador_energia_positiva(constantes["Game"]["Energia"]["MultiplicadorEnergiaPositiva"].as<float>()),
            divisor_energia_negativa(constantes["Game"]["Energia"]["DivisorEnergiaNegativa"].as<uint16_t>()),
            valor_base_energia_negativa(constantes["Game"]["Energia"]["ValorBaseEnergiaNegativa"].as<uint16_t>()) {}

void EnergiaAcumulada::edificioCreado(uint8_t tipo) {
    uint16_t diferencia;
    switch(tipo) {
        case 0: diferencia = energia_centro;
                break;
        case 1: diferencia = energia_cuartel;
                break;
        case 2: diferencia = energia_fabrica_ligera;
                break;
        case 3: diferencia = energia_fabrica_pesada;
                break;
        case 4: diferencia = energia_palacio;
                break;
        case 5: diferencia = energia_refineria;
                break;
        case 6: diferencia = energia_silo;
                break;
        case 7: diferencia = energia_trampa;
                break;
        default:
                throw std::runtime_error("EnergiaAcumulada: codigo de edificio no reconocido");
    }
    actualizarEnergia(diferencia);
}

float EnergiaAcumulada::obtenerMultiplicadorDeudaEnergetica() const {
    if (cantidad_energia >= 0)
        return multiplicador_energia_positiva;
    return - cantidad_energia / divisor_energia_negativa + valor_base_energia_negativa;
}

void EnergiaAcumulada::empezarPartida() {
	CmdModificarEnergiaServer* comando = new CmdModificarEnergiaServer(cantidad_energia);
    cola_comandos->push(comando);
}
