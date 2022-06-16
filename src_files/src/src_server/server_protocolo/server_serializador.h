#ifndef SERVER_SERIALIZADOR_H
#define SERVER_SERIALIZADOR_H

#include <vector>
#include "../../src_common/common_coords.h"
#include "yaml-cpp/yaml.h"

#define RUTA_CODIGOS "codigos.yaml"

class SerializadorServer {
private:
    YAML::Node* codigos;

public:
    SerializadorServer(YAML::Node* codigos);
/* *****************************************************************
 *             METODOS REFERIDOS A CREAR EDIFICIOS
 * *****************************************************************/

    std::vector<uint8_t> serializarComandoCrearEdificio(uint8_t id_jugador, uint8_t id_edificio,
    uint8_t tipo, const Coordenadas& coords, uint8_t casa) const;

    SerializadorServer(const SerializadorServer& otro) = delete;
    SerializadorServer& operator=(const SerializadorServer& otro) = delete;
    SerializadorServer(SerializadorServer&& otro);
    SerializadorServer& operator=(SerializadorServer&& otro);
};

#endif  // SERVER_SERIALIZADOR_H