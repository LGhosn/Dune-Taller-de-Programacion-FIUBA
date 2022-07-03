#ifndef SERVER_VALIDADOR_UNIDADES_H
#define SERVER_VALIDADOR_UNIDADES_H

#include "yaml-cpp/yaml.h"
#include <vector>
#include "../../../src_common/common_colas/cola_bloqueante.h"
#include "../../server_comandos/server_comando.h"

class ValidadorUnidades {
    std::vector<bool> unidades_disponibles_por_casa;
    std::vector<std::vector<bool>> edificios_necesarios_segun_unidad;
    std::vector<uint8_t>& cantidad_edificios_construidos;
    ColaBloqueante<ComandoServer>& cola_comandos;
public:
    ValidadorUnidades(YAML::Node& constantes,
                    uint8_t casa,
                    std::vector<uint8_t>& cantidad_edificios_construidos,
                    ColaBloqueante<ComandoServer>& cola_comandos);

    /*
     *
    */
    void actualizarUnidadesDisponibles(const std::vector<bool>& unidades_comprables) const;

    bool unidadDisponible(uint8_t tipo_de_unidad) const;
};

#endif // SERVER_VALIDADOR_UNIDADES_H
