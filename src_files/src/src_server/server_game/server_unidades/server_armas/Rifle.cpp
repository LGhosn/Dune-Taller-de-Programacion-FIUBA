#include "Rifle.h"

Rifle::Rifle(YAML::Node& atributos_armamento, uint16_t ticks) :
            Arma(atributos_armamento["Armas"]["Rifle"]["Dmg"].as<uint8_t>(),
                 atributos_armamento["Armas"]["Rifle"]["FrecuenciaDisparo"].as<uint16_t>(),
                 atributos_armamento["Armas"]["Rifle"]["Bonificacion"].as<std::vector<uint8_t>>(),
                 ticks) {}
