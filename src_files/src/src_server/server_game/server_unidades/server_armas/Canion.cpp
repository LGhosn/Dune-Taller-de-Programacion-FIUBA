#include "Canion.h"

Canion::Canion(YAML::Node& atributos_armamento) :
            Arma(atributos_armamento["Canion"]["Dmg"].as<uint8_t>(),
                 atributos_armamento["Canion"]["FrecuenciaDisparo"].as<uint8_t>(),
                 atributos_armamento["Canion"]["Bonificacion"].as<std::vector<uint8_t>>()) {}