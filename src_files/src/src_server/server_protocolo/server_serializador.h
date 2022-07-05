#ifndef SERVER_SERIALIZADOR_H
#define SERVER_SERIALIZADOR_H

#include <vector>
#include "../../src_common/common_coords.h"
#include "../../src_common/common_DTO/dto_info_partida.h"
#include "yaml-cpp/yaml.h"
#include <cstdint>

#define RUTA_CODIGOS "codigos.yaml"

#define CODIGO_EMPEZAR_ENTRENAMIENTO 11
#define CODIGO_ENEMIGO_DESPLIEGA_UNIDAD 13
#define CODIGO_ACTUALIZAR_PUNTAJE 40
#define CODIGO_MOVER_UNIDAD 50
#define CODIGO_MODIFICAR_VIDA_UNIDAD 60
#define CODIGO_TERMINAR_PARTIDA 70

class SerializadorServer {
private:
    YAML::Node& codigos;

/* *****************************************************************
 *                          METODOS AUXILIARES
 * *****************************************************************/

    void concatenarBuffers(std::vector<uint8_t> buffer_destino,
                            std::vector<uint8_t> buffer_origen) const;

public:
    explicit SerializadorServer(YAML::Node& codigos);
/* *****************************************************************
 *             METODOS REFERIDOS A CREAR EDIFICIOS
 * *****************************************************************/

    std::vector<uint8_t> serializarString(const std::string& string) const;

    std::vector<uint8_t> serializarComandoEmpezarConstruccionEdificio(uint8_t tipo_edificio,
                                                            uint16_t tiempo_construccion);

    std::vector<uint8_t> serializarComandoCrearEdificio(uint8_t id_jugador, uint8_t id_edificio,
    uint8_t tipo, const Coordenadas& coords, uint8_t casa) const;

/* *****************************************************************
 *             METODOS REFERIDOS A ACTUALIZAR ESPECIA
 * *****************************************************************/

    std::vector<uint8_t> serializarComandoModificarEspecia(uint16_t cantidad_especia);

/* *****************************************************************
 * METODOS REFERIDOS A ACTUALIZAR ESTADO COMPRA EDIFICIOS Y UNIDADES
 * *****************************************************************/

    std::vector<uint8_t> serializarComandoActualizarTiendaEdificios(const std::vector<bool>& edificios_comprables);
    std::vector<uint8_t> serializarComandoActualizarTiendaUnidades(const std::vector<bool>& unidades_comprables);
    std::vector<uint8_t> serializarEmpezarEntrenamientoUnidad(uint8_t id_unidad, uint8_t tipo_unidad,
                                                            uint16_t tiempo_construccion, Coordenadas& coords_spawn,
                                                            uint16_t vida);
    std::vector<uint8_t> serializarComandoEnemigoDespliegaUnidad(uint8_t id_unidad, uint8_t id_jugador,
                                                                uint8_t tipo_unidad, uint16_t tiempo,
                                                                Coordenadas& coords, uint16_t vida);

/* *****************************************************************
 *               METODOS REFERIDOS A MOVER UNIDAD
 * *****************************************************************/
    std::vector<uint8_t> serializarComandoMoverUnidad(uint8_t id_unidad, uint8_t direccion, uint16_t tiempo);

/* *****************************************************************
 *                  METODOS REFERIDOS A PUNTAJE
 * *****************************************************************/

    std::vector<uint8_t> serializarComandoActualizarPuntaje(uint8_t id_jugador, uint16_t nuevo_puntaje);

/* *****************************************************************
 *                  METODOS REFERIDOS A ATAQUES
 * *****************************************************************/

    std::vector<uint8_t> serializarComandoModificarVidaUnidad(uint8_t id_unidad, uint16_t vida);

/* *****************************************************************
 *                          MOVE SEMANTICS
 * *****************************************************************/

    SerializadorServer(const SerializadorServer& otro) = delete;
    SerializadorServer& operator=(const SerializadorServer& otro) = delete;
    SerializadorServer(SerializadorServer&& otro) = delete;
    SerializadorServer& operator=(SerializadorServer&& otro) = delete;
};

#endif  // SERVER_SERIALIZADOR_H