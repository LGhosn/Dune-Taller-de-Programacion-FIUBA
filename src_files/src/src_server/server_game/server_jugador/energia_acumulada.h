#ifndef SERVER_ENERGIA_ACUMULADA_H
#define SERVER_ENERGIA_ACUMULADA_H

#include <cstdint>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "../../../src_common/common_colas/cola_bloqueante.h"
#include "../../server_comandos/server_comando.h"

class EnergiaAcumulada {
    ColaBloqueante<ComandoServer>* cola_comandos;
    int16_t cantidad_energia;
    uint16_t tope_energia;

    // Constantes
    const int16_t energia_centro;
    const int16_t energia_cuartel;
    const int16_t energia_fabrica_ligera;
    const int16_t energia_fabrica_pesada;
    const int16_t energia_palacio;
    const int16_t energia_refineria;
    const int16_t energia_silo;
    const int16_t energia_trampa;
    const float multiplicador_energia_positiva;
    const uint16_t divisor_energia_negativa;
    const uint16_t valor_base_energia_negativa;

    /*
     * Actualiza la cantidad de energia disponible, y a su vez le envia la informacion al
     * cliente.
    */
    void actualizarEnergia(int16_t diferencia);

public:
    EnergiaAcumulada(ColaBloqueante<ComandoServer>* cola_comandos,
                    YAML::Node& constantes);
    
    /*
     * Aumenta/disminuye la energia disponible dependiendo del tipo de edificio, y envia la info
     * al cliente.
    */
    void edificioCreado(uint8_t tipo);

    float obtenerMultiplicadorDeudaEnergetica() const;

    void empezarPartida();
};

#endif // SERVER_ENERGIA_ACUMULADA_H
