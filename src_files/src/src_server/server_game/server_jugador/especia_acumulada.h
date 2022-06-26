#ifndef SERVER_ESPECIA_ACUMULADA_H
#define SERVER_ESPECIA_ACUMULADA_H

#include <cstdint>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "../../../src_common/common_colas/cola_bloqueante.h"
#include "../../server_comandos/server_comando.h"

class EspeciaAcumulada {
    ColaBloqueante<ComandoServer>& cola_comandos;
    uint16_t cantidad_especia;
    std::vector<bool> edificios_comprables;
    std::vector<bool> unidades_comprables;
    std::vector<uint16_t> costo_edificios;
    std::vector<uint16_t> costo_unidades;

    const float fraccion_demoler;

    void actualizarEdificiosComprables();
    void actualizarUnidadesComprables();

    void enviarNuevaCantidadEspecia();

public:
    EspeciaAcumulada(ColaBloqueante<ComandoServer>& cola_comandos,
                    YAML::Node& constantes);

    const std::vector<bool>& obtenerEdificiosComprables() const;
    const std::vector<bool>& obtenerUnidadesComprables() const;

    bool comprarEdificio(uint8_t tipo);
    void demolerEdificio(uint8_t tipo);
    bool comprarUnidad(uint8_t tipo);

    void aumentarEspecia(uint16_t cantidad);
};

#endif // SERVER_ESPECIA_ACUMULADA_H
