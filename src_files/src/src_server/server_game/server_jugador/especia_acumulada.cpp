#include "especia_acumulada.h"
#include "../../server_comandos/cmd_modificar_especia.h"
#include "../../server_comandos/cmd_actualizar_tienda_edificios.h"
#include "../../server_comandos/cmd_actualizar_tienda_unidades.h"
#include "../../server_comandos/cmd_actualizar_puntaje.h"

EspeciaAcumulada::EspeciaAcumulada(std::map<uint8_t, ColaBloqueante<ComandoServer>*>& colas_comandos,
                                    uint8_t id_jugador, YAML::Node& constantes) :
        id_jugador(id_jugador),
        colas_comandos(colas_comandos),
        cantidad_especia(constantes["Game"]["Especia"]["ValorInicial"].as<uint16_t>()),
        edificios_comprables(8, false), unidades_comprables(11, false),
        costo_edificios(8), costo_unidades(11),
        fraccion_demoler(constantes["Game"]["Precios"]["Edificios"]["FraccionDemoler"].as<float>()),
        divisor_puntaje(constantes["Game"]["Especia"]["DivisorPuntaje"].as<uint16_t>()) {
    costo_edificios[0] = 0;
    costo_edificios[1] = constantes["Game"]["Precios"]["Edificios"]["Cuartel"].as<uint16_t>();
    costo_edificios[2] = constantes["Game"]["Precios"]["Edificios"]["FabricaLigera"].as<uint16_t>();
    costo_edificios[3] = constantes["Game"]["Precios"]["Edificios"]["FabricaPesada"].as<uint16_t>();
    costo_edificios[4] = constantes["Game"]["Precios"]["Edificios"]["Palacio"].as<uint16_t>();
    costo_edificios[5] = constantes["Game"]["Precios"]["Edificios"]["Refineria"].as<uint16_t>();
    costo_edificios[6] = constantes["Game"]["Precios"]["Edificios"]["Silo"].as<uint16_t>();
    costo_edificios[7] = constantes["Game"]["Precios"]["Edificios"]["Trampa"].as<uint16_t>();

    costo_unidades[0] = constantes["Game"]["Precios"]["Unidades"]["Infanteria"]["InfanteriaLigera"].as<uint16_t>();
    costo_unidades[1] = constantes["Game"]["Precios"]["Unidades"]["Infanteria"]["InfanteriaPesada"].as<uint16_t>();
    costo_unidades[2] = constantes["Game"]["Precios"]["Unidades"]["Infanteria"]["Fremen"].as<uint16_t>();
    costo_unidades[3] = constantes["Game"]["Precios"]["Unidades"]["Infanteria"]["Sardaukar"].as<uint16_t>();
    costo_unidades[4] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Trike"].as<uint16_t>();
    costo_unidades[5] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Raider"].as<uint16_t>();
    costo_unidades[6] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Tanque"].as<uint16_t>();
    costo_unidades[7] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["TanqueSonico"].as<uint16_t>();
    costo_unidades[8] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Desviador"].as<uint16_t>();
    costo_unidades[9] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Devastador"].as<uint16_t>();
    costo_unidades[10] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Cosechadora"].as<uint16_t>();
}

void EspeciaAcumulada::empezarPartida() {
    enviarNuevaCantidadEspecia();
    actualizarYEnviarEdificiosComprables();
}

void EspeciaAcumulada::enviarNuevaCantidadEspecia() {
    CmdModificarEspeciaServer* comando = new CmdModificarEspeciaServer(cantidad_especia);
    colas_comandos[id_jugador]->push(comando);
}

void EspeciaAcumulada::actualizarYEnviarEdificiosComprables() {
    for (size_t i = 1; i < edificios_comprables.size(); i++) {
        edificios_comprables[i] = cantidad_especia >= costo_edificios[i] ? true : false;
    }
    CmdActualizarTiendaEdificiosServer* comando =
                    new CmdActualizarTiendaEdificiosServer(edificios_comprables);
    colas_comandos[id_jugador]->push(comando);
}

void EspeciaAcumulada::actualizarYEnviarNuevoPuntaje(uint16_t diferencia) {
    puntaje_actual += diferencia / divisor_puntaje;
    for (auto& cola : colas_comandos) {
        CmdActualizarPuntajeServer* comando = new CmdActualizarPuntajeServer(id_jugador, puntaje_actual);
        cola.second->push(comando);
    }
}

bool EspeciaAcumulada::comprarEdificio(uint8_t tipo_edificio, std::vector<uint8_t>& edificios_comprados, uint8_t& casa) {
    if (cantidad_especia >= costo_edificios[tipo_edificio]) {
        cantidad_especia -= costo_edificios[tipo_edificio];
        edificios_comprados[tipo_edificio]++;
        actualizarYEnviarEdificiosComprables();
        actualizarUnidadesComprables();
        enviarNuevaCantidadEspecia();
        actualizarYEnviarNuevoPuntaje(costo_edificios[tipo_edificio]);
        return true;
    } else {
        return false;
    }
}

void EspeciaAcumulada::demolerEdificio(uint8_t tipo) {
    cantidad_especia += costo_edificios[tipo] * fraccion_demoler;
    enviarNuevaCantidadEspecia();
    actualizarYEnviarNuevoPuntaje( - costo_edificios[tipo] * fraccion_demoler);
}

void EspeciaAcumulada::aumentarEspecia(uint16_t cantidad) {
    cantidad_especia += cantidad;
    enviarNuevaCantidadEspecia();
}

void EspeciaAcumulada::actualizarUnidadesComprables() {
    for (size_t i = 0; i < unidades_comprables.size(); i++) {
        unidades_comprables[i] = cantidad_especia >= costo_unidades[i] ? true : false;
    }
}

/* *****************************************************************
 *          METODOS SOBRE VALIDACION DE COMPRA DE UNIDADES
 * *****************************************************************/

bool EspeciaAcumulada::comprarUnidad(uint8_t tipo) {
    if (cantidad_especia >= costo_unidades[tipo]) {
        cantidad_especia -= costo_unidades[tipo];
        actualizarYEnviarEdificiosComprables();
        actualizarUnidadesComprables();
        enviarNuevaCantidadEspecia();
        actualizarYEnviarNuevoPuntaje(costo_unidades[tipo]);
        return true;
    } else {
        return false;
    }
}

bool EspeciaAcumulada::noHayEspeciaSuficienteParaLaUnidad(uint8_t tipo_unidad) {
    return cantidad_especia < costo_unidades[tipo_unidad];
}

std::vector<bool> EspeciaAcumulada::obtenerUnidadesComprables() {
    return unidades_comprables;
}
