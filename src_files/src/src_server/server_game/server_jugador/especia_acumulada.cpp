#include "especia_acumulada.h"
#include "../../server_comandos/cmd_modificar_especia.h"
#include "../../server_comandos/cmd_actualizar_tienda_edificios.h"
#include "../../server_comandos/cmd_actualizar_tienda_unidades.h"

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

void EspeciaAcumulada::enviarNuevaCantidadEspecia() {
    CmdModificarEspeciaServer* comando = new CmdModificarEspeciaServer(cantidad_especia);
    cola_comandos.push(comando);
}

void EspeciaAcumulada::actualizarEdificiosComprables() {
    for (int i = 1; i < 8; i++) {
        edificios_comprables[i] = cantidad_especia >= costo_edificios[i] ? true : false;
    }
    CmdActualizarTiendaEdificiosServer* comando =
                    new CmdActualizarTiendaEdificiosServer(edificios_comprables);
    cola_comandos.push(comando);
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

void EspeciaAcumulada::aumentarEspecia(uint16_t cantidad) {
    cantidad_especia += cantidad;
    enviarNuevaCantidadEspecia();
}

void EspeciaAcumulada::actualizarUnidadesComprables(std::vector<uint8_t>& edificios_comprados, uint8_t& casa) {
    for (uint8_t i = 0; i < 11 ; i++) {
        unidades_comprables[i] = validarCompraUnidad(i, edificios_comprados, casa);        
    }
    CmdActualizarTiendaUnidadesServer* comando =
                    new CmdActualizarTiendaUnidadesServer(unidades_comprables);
    cola_comandos.push(comando);
}

/* *****************************************************************
 *          METODOS SOBRE VALIDACION DE COMPRA DE UNIDADES
 * *****************************************************************/

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

bool EspeciaAcumulada::validarCompraUnidad(uint8_t tipo_unidad,
                                           std::vector<uint8_t>& edificios_comprados,
                                           uint8_t& casa) {
    // Primero corroboramos que el jugador tenga la especia suficiente.
    if (noHayEspeciaSuficienteParaLaUnidad(tipo_unidad)) {
        return false;
    }

    // Luego corroboramos que el jugador tenga los edificios adecuados para comprar la unidad.
    if (laUnidadAComprarEsInfanteria(tipo_unidad) && elJugadorConstruyoElCuartel(edificios_comprados)) {
        return true;
    } else if (laUnidadAComprarEsFremen(tipo_unidad, casa) && elJugadorConstruyoElCuartelYElPalacio(edificios_comprados)) {
        return true;
    } else if (laUnidadAComprarEsSardaukar(tipo_unidad, casa) && elJugadorConstruyoElCuartelYElPalacio(edificios_comprados)) {
        return true;
    } else if (laUnidadAComprarEsTrike(tipo_unidad, casa) && elJugadorConstruyoLaFabricaLigera(edificios_comprados)) {
        return true;
    } else if (laUnidadAComprarEsRaider(tipo_unidad, casa) && elJugadorConstruyoLaFabricaLigera(edificios_comprados)) {
        return true;
    } else if (laUnidadAComprarEsTanque(tipo_unidad) && elJugadorConstruyoLaFabricaPesada(edificios_comprados)) {
        return true;
    } else if (laUnidadAComprarEsTanqueSonico(tipo_unidad, casa) && elJugadorConstruyoLaFabricaPesadaYElPalacio(edificios_comprados)) {
        return true;
    } else if (laUnidadAComprarEsDesviador(tipo_unidad, casa) && elJugadorConstruyoLaFabricaPesadaYElPalacio(edificios_comprados)) {
        return true;
    } else if (laUnidadAComprarEsDevastador(tipo_unidad, casa) && elJugadorConstruyoLaFabricaPesadaYElPalacio(edificios_comprados)) {
        return true;
    } else if(laUnidadAComprarEsCosechadora(tipo_unidad) && elJugadorConstruyoLaFabricaPesada(edificios_comprados)) {
        return true;
    } else {
        return false;
    }
}

bool EspeciaAcumulada::noHayEspeciaSuficienteParaLaUnidad(uint8_t tipo_unidad) {
    return cantidad_especia < costo_unidades[tipo_unidad];
}

/* *****************************************************************
 *          METODOS BOOL SOBRE EXISTENCIA DE EDIFICIOS
 * *****************************************************************/

bool EspeciaAcumulada::elJugadorConstruyoElCuartel(std::vector<uint8_t>& edificios_comprados) {
    return edificios_comprados[CUARTEL];
}

bool EspeciaAcumulada::elJugadorConstruyoElCuartelYElPalacio(std::vector<uint8_t>& edificios_comprados) {
    return edificios_comprados[CUARTEL] && edificios_comprados[PALACIO];
}

bool EspeciaAcumulada::elJugadorConstruyoLaFabricaLigera(std::vector<uint8_t>& edificios_comprados) {
    return edificios_comprados[FABRICA_LIGERA];
}

bool EspeciaAcumulada::elJugadorConstruyoLaFabricaPesada(std::vector<uint8_t>& edificios_comprados) {
    return edificios_comprados[FABRICA_PESADA];
}

bool EspeciaAcumulada::elJugadorConstruyoLaFabricaPesadaYElPalacio(std::vector<uint8_t>& edificios_comprados) {
    return edificios_comprados[FABRICA_PESADA] && edificios_comprados[PALACIO];
}

/* *****************************************************************
 *          METODOS BOOL SOBRE CASO DE UNIDADES
 * *****************************************************************/

bool EspeciaAcumulada::laUnidadAComprarEsInfanteria(uint8_t tipo_unidad) {
    return tipo_unidad == INFANTERIA_LIGERA || tipo_unidad == INFANTERIA_PESADA;
}

bool EspeciaAcumulada::laUnidadAComprarEsFremen(uint8_t tipo_unidad, uint8_t casa) {
    return tipo_unidad == FREMEN && casa == ATREIDES;
}

bool EspeciaAcumulada::laUnidadAComprarEsSardaukar(uint8_t tipo_unidad, uint8_t casa) {
    return tipo_unidad == SARDAUKAR && casa == HARKONNEN;
}

bool EspeciaAcumulada::laUnidadAComprarEsTrike(uint8_t tipo_unidad, uint8_t casa) {
    return tipo_unidad == TRIKE && (casa == ORDOS || casa == HARKONNEN);
}

bool EspeciaAcumulada::laUnidadAComprarEsRaider(uint8_t tipo_unidad, uint8_t casa) {
    return tipo_unidad == RAIDER && casa == ORDOS;
}

bool EspeciaAcumulada::laUnidadAComprarEsTanque(uint8_t tipo_unidad) {
    return tipo_unidad == TANQUE;
}

bool EspeciaAcumulada::laUnidadAComprarEsTanqueSonico(uint8_t tipo_unidad, uint8_t casa) {
    return tipo_unidad == TANQUE_SONICO && casa == ATREIDES;
}

bool EspeciaAcumulada::laUnidadAComprarEsDesviador(uint8_t tipo_unidad, uint8_t casa) {
    return tipo_unidad == DESVIADOR && casa == ORDOS;
}

bool EspeciaAcumulada::laUnidadAComprarEsDevastador(uint8_t tipo_unidad, uint8_t casa) {
    return tipo_unidad == DEVASTADOR && casa == HARKONNEN;
}

bool EspeciaAcumulada::laUnidadAComprarEsCosechadora(uint8_t tipo_unidad) {
    return tipo_unidad == COSECHADORA;
}