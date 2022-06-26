#ifndef SERVER_SERIALIZADOR_H
#define SERVER_SERIALIZADOR_H

#include <vector>
#include "../../src_common/common_coords.h"
#include "../../src_common/common_DTO/dto_info_partida.h"
#include "yaml-cpp/yaml.h"
#include <cstdint>

#define RUTA_CODIGOS "codigos.yaml"

class SerializadorServer {
private:
    YAML::Node* codigos;

/* *****************************************************************
 *                          METODOS AUXILIARES
 * *****************************************************************/

    void concatenarBuffers(std::vector<uint8_t> buffer_destino,
                            std::vector<uint8_t> buffer_origen) const;

public:
    explicit SerializadorServer(YAML::Node* codigos);
/* *****************************************************************
 *             METODOS REFERIDOS A CREAR EDIFICIOS
 * *****************************************************************/

    std::vector<uint8_t> serializarString(const std::string& string) const;

    std::vector<uint8_t> serializarComandoCrearEdificio(uint8_t id_jugador, uint8_t id_edificio,
    uint8_t tipo, const Coordenadas& coords, uint8_t casa) const;

/* *****************************************************************
 *             METODOS REFERIDOS A EMPEZAR PARTIDAS
 * *****************************************************************/

    std::vector<uint8_t> serializarComienzoDePartida(const InfoPartidaDTO& info_partida) const;

/* *****************************************************************
 *             METODOS REFERIDOS A ACTUALIZAR ESPECIA
 * *****************************************************************/

    std::vector<uint8_t> serializarComandoModificarEspecia(uint16_t cantidad_especia);

    SerializadorServer(const SerializadorServer& otro) = delete;
    SerializadorServer& operator=(const SerializadorServer& otro) = delete;
    SerializadorServer(SerializadorServer&& otro);
    SerializadorServer& operator=(SerializadorServer&& otro);
};

#endif  // SERVER_SERIALIZADOR_H