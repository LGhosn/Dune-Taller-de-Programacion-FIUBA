#include "validador_unidades.h"
#include "../../server_comandos/cmd_actualizar_tienda_unidades.h"

ValidadorUnidades::ValidadorUnidades(YAML::Node& constantes,
                                    uint8_t casa,
                                    std::vector<uint8_t>& cantidad_edificios_construidos,
                                    ColaBloqueante<ComandoServer>& cola_comandos) :
        unidades_disponibles_por_casa(constantes["Game"]["Casas"]["UnidadesDisponibles"][casa].as<std::vector<bool>>()),
        edificios_necesarios_segun_unidad(constantes["Game"]["Unidades"]["EdificiosRequeridos"].as<std::vector<std::vector<bool>>>()),
        cantidad_edificios_construidos(cantidad_edificios_construidos),
        cola_comandos(cola_comandos) {}

void ValidadorUnidades::actualizarUnidadesDisponibles(const std::vector<bool>& unidades_comprables) const {
    std::vector<bool> unidades_disponibles(unidades_disponibles_por_casa.size());
    for (size_t i = 0; i < unidades_disponibles_por_casa.size(); i++) {
        unidades_disponibles[i] = unidades_comprables[i] && unidadDisponible(i);
    }
    CmdActualizarTiendaUnidadesServer* comando = new CmdActualizarTiendaUnidadesServer(unidades_disponibles);
    cola_comandos.push(comando);
}

bool ValidadorUnidades::unidadDisponible(uint8_t tipo_de_unidad) const {
    if (unidades_disponibles_por_casa[tipo_de_unidad] == false) {
        return false;
    }

    for (size_t i = 0; i < cantidad_edificios_construidos.size(); i++) {
        if (edificios_necesarios_segun_unidad[tipo_de_unidad][i]) {
            if (!cantidad_edificios_construidos[i]) {
                return false;
            }
        }
    }
    return true;
}
