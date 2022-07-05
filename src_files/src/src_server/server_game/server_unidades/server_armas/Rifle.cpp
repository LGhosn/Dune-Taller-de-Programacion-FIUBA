#include "Rifle.h"

Rifle::Rifle(YAML::Node& atributos_armamento) :
            Arma(atributos_armamento["Rifle"]["Dmg"].as<uint8_t>(),
                 atributos_armamento["Rifle"]["FrecuenciaDisparo"].as<uint8_t>(),
                 atributos_armamento["Rifle"]["Bonificacion"].as<std::vector<uint8_t>>()) {}
