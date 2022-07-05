#include "CanionDePlasma.h"

CanionDePlasma::CanionDePlasma(YAML::Node& atributos_armamento, uint16_t ticks) :
            Arma(atributos_armamento["Armas"]["CanionDePlasma"]["Dmg"].as<uint8_t>(),
                 atributos_armamento["Armas"]["CanionDePlasma"]["FrecuenciaDisparo"].as<uint16_t>(),
                 atributos_armamento["Armas"]["CanionDePlasma"]["Bonificacion"].as<std::vector<uint8_t>>(),
                 ticks) {}