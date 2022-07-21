#ifndef SERVER_ARMA_FACTORY_H
#define SERVER_ARMA_FACTORY_H

#include "arma.h"
#include <memory>
#include "yaml-cpp/yaml.h"

class ArmaFactory {
    YAML::Node& atributos;
    const uint16_t ticks;
public:
    ArmaFactory(YAML::Node& atributos, uint16_t ticks);

    /*
     * Devuelve el arma correspondiente al tipo de unidad dado.
    */
    std::shared_ptr<Arma> obtenerArma(uint8_t tipo_unidad, uint8_t id_portador) const;
};

#endif // SERVER_ARMA_FACTORY_H
