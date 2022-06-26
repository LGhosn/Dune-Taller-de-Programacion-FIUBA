#ifndef SERVER_ESPECIA_ACUMULADA_H
#define SERVER_ESPECIA_ACUMULADA_H

#include <cstdint>
#include <vector>
#include "yaml-cpp/yaml.h"

class EspeciaAcumulada {
    uint16_t cantidad_especia;
    std::vector<bool> edificios_comprables;
    std::vector<bool> unidades_comprables;

    // Constantes
    const uint16_t costo_cuartel;
    const uint16_t costo_fabrica_ligera;
    const uint16_t costo_fabrica_pesada;
    const uint16_t costo_palacio;
    const uint16_t costo_refineria;
    const uint16_t costo_silo;
    const uint16_t costo_trampa;

    const uint16_t costo_fremen;
    const uint16_t costo_infanteria_ligera;
    const uint16_t costo_infanteria_pesada;
    const uint16_t costo_sardaukar;

    const uint16_t costo_cosechadora;
    const uint16_t costo_desviador;
    const uint16_t costo_devastador;
    const uint16_t costo_raider;
    const uint16_t costo_tanque;
    const uint16_t costo_tanque_sonico;
    const uint16_t costo_trike;

public:
    EspeciaAcumulada(YAML::Node& constantes);

    const std::vector<bool>& obtenerEdificiosComprables() const;
    const std::vector<bool>& obtenerUnidadesComprables() const;

    bool comprarEdificio(uint8_t tipo);
    bool demolerEdificio(uint8_t tipo);
    bool comprarUnidad(uint8_t tipo);

    void aumentarEspecia(uint16_t cantidad);
};

#endif // SERVER_ESPECIA_ACUMULADA_H
