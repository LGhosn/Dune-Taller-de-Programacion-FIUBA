#include "especia_acumulada.h"
#include "../../server_comandos/cmd_modificar_especia.h"
#include "../../server_comandos/cmd_actualizar_tienda_edificios.h"
#include "../../server_comandos/cmd_actualizar_tienda_unidades.h"

void EspeciaAcumulada::actualizarEdificiosComprables() {
    edificios_comprables[1] = cantidad_especia >= costo_edificios[1] ? true : false;
    edificios_comprables[2] = cantidad_especia >= costo_edificios[2] ? true : false;
    edificios_comprables[3] = cantidad_especia >= costo_edificios[3] ? true : false;
    edificios_comprables[4] = cantidad_especia >= costo_edificios[4] ? true : false;
    edificios_comprables[5] = cantidad_especia >= costo_edificios[5] ? true : false;
    edificios_comprables[6] = cantidad_especia >= costo_edificios[6] ? true : false;
    edificios_comprables[7] = cantidad_especia >= costo_edificios[7] ? true : false;
    CmdActualizarTiendaEdificiosServer* comando =
                    new CmdActualizarTiendaEdificiosServer(edificios_comprables);
    cola_comandos->push(comando);
}

void EspeciaAcumulada::actualizarUnidadesComprables() {
    unidades_comprables[0] = cantidad_especia >= costo_unidades[0] ? true : false;
    unidades_comprables[1] = cantidad_especia >= costo_unidades[1] ? true : false;
    unidades_comprables[2] = cantidad_especia >= costo_unidades[2] ? true : false;
    unidades_comprables[3] = cantidad_especia >= costo_unidades[3] ? true : false;
    unidades_comprables[4] = cantidad_especia >= costo_unidades[4] ? true : false;
    unidades_comprables[5] = cantidad_especia >= costo_unidades[5] ? true : false;
    unidades_comprables[6] = cantidad_especia >= costo_unidades[6] ? true : false;
    unidades_comprables[7] = cantidad_especia >= costo_unidades[7] ? true : false;
    unidades_comprables[8] = cantidad_especia >= costo_unidades[8] ? true : false;
    unidades_comprables[9] = cantidad_especia >= costo_unidades[9] ? true : false;
    unidades_comprables[10] = cantidad_especia >= costo_unidades[10] ? true : false;
    CmdActualizarTiendaUnidadesServer* comando =
                    new CmdActualizarTiendaUnidadesServer(unidades_comprables);
    cola_comandos->push(comando);
}

void EspeciaAcumulada::enviarNuevaCantidadEspecia() {
    CmdModificarEspeciaServer* comando = new CmdModificarEspeciaServer(cantidad_especia);
    cola_comandos->push(comando);
}

EspeciaAcumulada::EspeciaAcumulada(ColaBloqueante<ComandoServer>* cola_comandos,
                                    YAML::Node& constantes) :
                    cola_comandos(cola_comandos),
                    cantidad_especia(constantes["Game"]["Especia"]["ValorInicial"].as<uint16_t>()),
                    edificios_comprables(8, false), unidades_comprables(11, false),
                    costo_edificios(8), costo_unidades(11),
                    fraccion_demoler(constantes["Game"]["Precios"]["Edificios"]["FraccionDemoler"].as<float>()) {
    costo_edificios[0] = 0;
    costo_edificios[1] = constantes["Game"]["Precios"]["Edificios"]["Cuartel"].as<uint16_t>();
    costo_edificios[2] = constantes["Game"]["Precios"]["Edificios"]["FabricaLigera"].as<uint16_t>();
    costo_edificios[3] = constantes["Game"]["Precios"]["Edificios"]["FabricaPesada"].as<uint16_t>();
    costo_edificios[4] = constantes["Game"]["Precios"]["Edificios"]["Palacio"].as<uint16_t>();
    costo_edificios[5] = constantes["Game"]["Precios"]["Edificios"]["Refineria"].as<uint16_t>();
    costo_edificios[6] = constantes["Game"]["Precios"]["Edificios"]["Silo"].as<uint16_t>();
    costo_edificios[7] = constantes["Game"]["Precios"]["Edificios"]["Trampa"].as<uint16_t>();

    costo_unidades[0] = constantes["Game"]["Precios"]["Unidades"]["Infanteria"]["Fremen"].as<uint16_t>();
    costo_unidades[1] = constantes["Game"]["Precios"]["Unidades"]["Infanteria"]["InfanteriaLigera"].as<uint16_t>();
    costo_unidades[2] = constantes["Game"]["Precios"]["Unidades"]["Infanteria"]["InfanteriaPesada"].as<uint16_t>();
    costo_unidades[3] = constantes["Game"]["Precios"]["Unidades"]["Infanteria"]["Sardaukar"].as<uint16_t>();
    costo_unidades[4] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Cosechadora"].as<uint16_t>();
    costo_unidades[5] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Desviador"].as<uint16_t>();
    costo_unidades[6] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Devastador"].as<uint16_t>();
    costo_unidades[7] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Raider"].as<uint16_t>();
    costo_unidades[8] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Tanque"].as<uint16_t>();
    costo_unidades[9] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["TanqueSonico"].as<uint16_t>();
    costo_unidades[10] = constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Trike"].as<uint16_t>();
}

void EspeciaAcumulada::empezarPartida() {
    enviarNuevaCantidadEspecia();
    actualizarEdificiosComprables();
}

const std::vector<bool>& EspeciaAcumulada::obtenerEdificiosComprables() const {
    return edificios_comprables;
}

const std::vector<bool>& EspeciaAcumulada::obtenerUnidadesComprables() const {
    return unidades_comprables;
}

bool EspeciaAcumulada::comprarEdificio(uint8_t tipo) {
    if (cantidad_especia >= costo_edificios[tipo]) {
        cantidad_especia -= costo_edificios[tipo];
        actualizarEdificiosComprables();
        // actualizarUnidadesComprables();
        enviarNuevaCantidadEspecia();
        return true;
    } else {
        return false;
    }
}

void EspeciaAcumulada::demolerEdificio(uint8_t tipo) {
    cantidad_especia += costo_edificios[tipo] * fraccion_demoler;
    enviarNuevaCantidadEspecia();
}

bool EspeciaAcumulada::comprarUnidad(uint8_t tipo) {
    if (cantidad_especia >= costo_unidades[tipo]) {
        cantidad_especia -= costo_unidades[tipo];
        actualizarEdificiosComprables();
        // actualizarUnidadesComprables();
        enviarNuevaCantidadEspecia();
        return true;
    } else {
        return false;
    }
}

void EspeciaAcumulada::aumentarEspecia(uint16_t cantidad) {
    cantidad_especia += cantidad;
    enviarNuevaCantidadEspecia();
}

EspeciaAcumulada& EspeciaAcumulada::operator=(EspeciaAcumulada&& otra) {
    if (this == &otra)
        return *this;
    cola_comandos = otra.cola_comandos;
    cantidad_especia = otra.cantidad_especia;
    edificios_comprables = std::move(otra.edificios_comprables);
    unidades_comprables = std::move(otra.unidades_comprables);
    costo_edificios = std::move(otra.costo_edificios);
    costo_unidades = std::move(otra.costo_unidades);
    fraccion_demoler = std::move(otra.fraccion_demoler);
    return *this;
}

EspeciaAcumulada::EspeciaAcumulada(EspeciaAcumulada&& otra):
                                cola_comandos(otra.cola_comandos),
                                cantidad_especia(otra.cantidad_especia),
                                edificios_comprables(std::move(otra.edificios_comprables)),
                                unidades_comprables(std::move(otra.unidades_comprables)),
                                costo_edificios(std::move(otra.costo_edificios)),
                                costo_unidades(std::move(otra.costo_unidades)),
                                fraccion_demoler(otra.fraccion_demoler) {}
