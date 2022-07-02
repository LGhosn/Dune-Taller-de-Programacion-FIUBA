#ifndef SERVER_ESPECIA_ACUMULADA_H
#define SERVER_ESPECIA_ACUMULADA_H

#include <cstdint>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "../../../src_common/common_colas/cola_bloqueante.h"
#include "../../server_comandos/server_comando.h"

#define CENTRO 0
#define CUARTEL 1
#define FABRICA_LIGERA 2
#define FABRICA_PESADA 3
#define PALACIO 4
#define REFINERIA 5
#define SILO 6
#define TAMPA_DE_AIRE 7

#define INFANTERIA_LIGERA 0
#define INFANTERIA_PESADA 1
#define FREMEN 2
#define SARDAUKAR 3
#define TRIKE 4
#define RAIDER 5
#define TANQUE 6
#define TANQUE_SONICO 7
#define DESVIADOR 8
#define DEVASTADOR 9
#define COSECHADORA 10

#define HARKONNEN 0
#define ATREIDES 1
#define ORDOS 2

class EspeciaAcumulada {
    ColaBloqueante<ComandoServer>& cola_comandos;
    uint16_t cantidad_especia;
    std::vector<bool> edificios_comprables;
    std::vector<bool> unidades_comprables;
    std::vector<uint16_t> costo_edificios;
    std::vector<uint16_t> costo_unidades;

    float fraccion_demoler;

    void actualizarEdificiosComprables();
    void actualizarUnidadesComprables(std::vector<uint8_t>& edificios_comprados, uint8_t& casa);

    void enviarNuevaCantidadEspecia();

    bool validarCompraUnidad(uint8_t unidad, std::vector<uint8_t>& edificios_comprados, uint8_t& casa);

    bool noHayEspeciaSuficienteParaLaUnidad(uint8_t tipo_unidad);

    bool elJugadorConstruyoElCuartel(std::vector<uint8_t>& edificios_comprados);

    bool elJugadorConstruyoElCuartelYElPalacio(std::vector<uint8_t>& edificios_comprados);

    bool elJugadorConstruyoLaFabricaLigera(std::vector<uint8_t>& edificios_comprados);

    bool elJugadorConstruyoLaFabricaPesada(std::vector<uint8_t>& edificios_comprados);

    bool elJugadorConstruyoLaFabricaPesadaYElPalacio(std::vector<uint8_t>& edificios_comprados);

    bool laUnidadARevisarEsInfanteria(uint8_t tipo_unidad);

    bool laUnidadARevisarEsFremen(uint8_t tipo_unidad, uint8_t casa);

    bool laUnidadARevisarEsSardaukar(uint8_t tipo_unidad, uint8_t casa);

    bool laUnidadARevisarEsTrike(uint8_t tipo_unidad, uint8_t casa);

    bool laUnidadARevisarEsRaider(uint8_t tipo_unidad, uint8_t casa);

    bool laUnidadARevisarEsTanque(uint8_t tipo_unidad);

    bool laUnidadARevisarEsTanqueSonico(uint8_t tipo_unidad, uint8_t casa);

    bool laUnidadARevisarEsDesviador(uint8_t tipo_unidad, uint8_t casa);

    bool laUnidadARevisarEsDevastador(uint8_t tipo_unidad, uint8_t casa);

    bool laUnidadARevisarEsCosechadora(uint8_t tipo_unidad);

public:
    EspeciaAcumulada(ColaBloqueante<ComandoServer>& cola_comandos,
                    YAML::Node& constantes);

    /*
     * Le envia al cliente los edificios que se pueden comprar, como asi
     * la especia disponible inicialmente.
    */
    void empezarPartida();

    /*
     * Recibe el tipo de edificio a comprar, y, si es posible comprarlo,
     * resta el valor del edificio a la cantidad de especia actual, actualiza
     * los edificios comprables al cliente, y el nuevo valor de la especia.
     * De no ser posible comprar el edificio, simplemente devuelve false.
    */
    bool comprarEdificio(uint8_t tipo, std::vector<uint8_t>& edificios_comprados, uint8_t& casa);

    /*
     * Recibe el tipo de edificio a demoler, y suma la cantidad de especia
     * correspondiente. A su vez, le envia al cliente la lista actualizada
     * de edificios que se pueden comprar con la especia disponible, como a
     * su vez el nuevo monto en forma de comandos.
    */
    void demolerEdificio(uint8_t tipo);
    bool comprarUnidad(uint8_t tipo);

    void aumentarEspecia(uint16_t cantidad);

    EspeciaAcumulada& operator=(const EspeciaAcumulada& otra) = delete;
    EspeciaAcumulada(const EspeciaAcumulada& otra) = delete;
    EspeciaAcumulada& operator=(EspeciaAcumulada&& otra) = delete;
    EspeciaAcumulada(EspeciaAcumulada&& otra) = delete;

};

#endif // SERVER_ESPECIA_ACUMULADA_H
