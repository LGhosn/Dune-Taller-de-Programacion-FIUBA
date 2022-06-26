#include "especia_acumulada.h"

EspeciaAcumulada::EspeciaAcumulada(YAML::Node& constantes) :
                    cantidad_especia(constantes["Game"]["Especia"]["ValorInicial"].as<uint16_t>()),
                    edificios_comprables(8, false), unidades_comprables(11, false),
                    costo_cuartel(constantes["Game"]["Precios"]["Edificios"]["Cuartel"].as<uint16_t>()),
                    costo_fabrica_ligera(constantes["Game"]["Precios"]["Edificios"]["FabricaLigera"].as<uint16_t>()),
                    costo_fabrica_pesada(constantes["Game"]["Precios"]["Edificios"]["FabricaPesada"].as<uint16_t>()),
                    costo_palacio(constantes["Game"]["Precios"]["Edificios"]["Palacio"].as<uint16_t>()),
                    costo_refineria(constantes["Game"]["Precios"]["Edificios"]["Refineria"].as<uint16_t>()),
                    costo_silo(constantes["Game"]["Precios"]["Edificios"]["Silo"].as<uint16_t>()),
                    costo_trampa(constantes["Game"]["Precios"]["Edificios"]["Trampa"].as<uint16_t>()),
                    costo_fremen(constantes["Game"]["Precios"]["Unidades"]["Infanteria"]["Fremen"].as<uint16_t>()),
                    costo_infanteria_ligera(constantes["Game"]["Precios"]["Unidades"]["Infanteria"]["InfanteriaLigera"].as<uint16_t>()),
                    costo_infanteria_pesada(constantes["Game"]["Precios"]["Unidades"]["Infanteria"]["InfanteriaPesada"].as<uint16_t>()),
                    costo_sardaukar(constantes["Game"]["Precios"]["Unidades"]["Infanteria"]["Sardaukar"].as<uint16_t>()),
                    costo_cosechadora(constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Cosechadora"].as<uint32_t>()),
                    costo_desviador(constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Desviador"].as<uint32_t>()),
                    costo_devastador(constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Devastador"].as<uint32_t>()),
                    costo_raider(constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Raider"].as<uint32_t>()),
                    costo_tanque(constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Tanque"].as<uint32_t>()),
                    costo_tanque_sonico(constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["TanqueSonico"].as<uint32_t>()),
                    costo_trike(constantes["Game"]["Precios"]["Unidades"]["Vehiculos"]["Trike"].as<uint32_t>()) {}

const std::vector<bool>& EspeciaAcumulada::obtenerEdificiosComprables() const {
    return edificios_comprables;
}

const std::vector<bool>& EspeciaAcumulada::obtenerUnidadesComprables() const {
    return unidades_comprables;
}

bool EspeciaAcumulada::comprarEdificio(uint8_t tipo) {
    switch (tipo) {

    }
}
