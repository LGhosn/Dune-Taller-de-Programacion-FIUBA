#include "especia_acumulada.h"
#include "../../server_comandos/cmd_modificar_especia.h"
#include "../../server_comandos/cmd_actualizar_tienda_edificios.h"
#include "../../server_comandos/cmd_actualizar_tienda_unidades.h"

void EspeciaAcumulada::actualizarEdificiosComprables() {
    for (int i = 1; i < 8; i++) {
        edificios_comprables[i] = cantidad_especia >= costo_edificios[i] ? true : false;
    }
    CmdActualizarTiendaEdificiosServer* comando =
                    new CmdActualizarTiendaEdificiosServer(edificios_comprables);
    cola_comandos.push(comando);
}

void EspeciaAcumulada::actualizarUnidadesComprables(std::vector<uint8_t>& edificios_comprados, uint8_t& casa) {
    for (uint8_t i = 0; i < 11 ; i++) {
        unidades_comprables[i] = validarCompraUnidad(i, edificios_comprados, casa);        
    }
    

    CmdActualizarTiendaUnidadesServer* comando =
                    new CmdActualizarTiendaUnidadesServer(unidades_comprables);
    cola_comandos.push(comando);
}


bool EspeciaAcumulada::validarCompraUnidad(uint8_t tipo_unidad,
                                            std::vector<uint8_t>& edificios_comprados,
                                            uint8_t& casa) {
    if (cantidad_especia < costo_unidades[tipo_unidad]) {
        return false;
    }
    
    if ((tipo_unidad == INFANTERIA_LIGERA || tipo_unidad == INFANTERIA_PESADA)) {
        return true;
    }// else if (tipo_unidad == FREMEN && (edificios_comprados[] == 2))
    return false;
}

// bool EspeciaAcumulada::validarCompraInfanteria(uint8_t tipo_edificio) {

// }

void EspeciaAcumulada::enviarNuevaCantidadEspecia() {
    CmdModificarEspeciaServer* comando = new CmdModificarEspeciaServer(cantidad_especia);
    cola_comandos.push(comando);
}

EspeciaAcumulada::EspeciaAcumulada(ColaBloqueante<ComandoServer>& cola_comandos,
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

bool EspeciaAcumulada::comprarEdificio(uint8_t tipo_edificio, std::vector<uint8_t>& edificios_comprados, uint8_t& casa) {
    if (cantidad_especia >= costo_edificios[tipo_edificio]) {
        cantidad_especia -= costo_edificios[tipo_edificio];
        edificios_comprados[tipo_edificio]++;
        actualizarEdificiosComprables();
        actualizarUnidadesComprables(edificios_comprados, casa);
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
        // actualizarUnidadesComprables(tipo_edificio, edificios_comprados, casa);
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
