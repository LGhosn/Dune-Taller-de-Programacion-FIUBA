#ifndef SERVER_ESPECIA_ACUMULADA_H
#define SERVER_ESPECIA_ACUMULADA_H

#include <cstdint>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "../../../src_common/common_colas/cola_bloqueante.h"
#include "../../server_comandos/server_comando.h"

class EspeciaAcumulada {
    ColaBloqueante<ComandoServer>* cola_comandos;
    uint16_t cantidad_especia;
    std::vector<bool> edificios_comprables;
    std::vector<bool> unidades_comprables;
    std::vector<uint16_t> costo_edificios;
    std::vector<uint16_t> costo_unidades;

    float fraccion_demoler;

    void actualizarEdificiosComprables();
    void actualizarUnidadesComprables();

    void enviarNuevaCantidadEspecia();

public:
    EspeciaAcumulada(ColaBloqueante<ComandoServer>* cola_comandos,
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
    bool comprarEdificio(uint8_t tipo);

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

    EspeciaAcumulada& operator=(EspeciaAcumulada&& otra);
    EspeciaAcumulada(EspeciaAcumulada&& otra);

};

#endif // SERVER_ESPECIA_ACUMULADA_H
