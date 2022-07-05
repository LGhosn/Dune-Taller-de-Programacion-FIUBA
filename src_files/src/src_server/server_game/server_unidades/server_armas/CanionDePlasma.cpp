#include "CanionDePlasma.h"

CanionDePlasma::CanionDePlasma(YAML::Node& atributos_armamento) :
            Arma(atributos_armamento["CanionDePlasma"]["Dmg"].as<uint8_t>(),
                 atributos_armamento["CanionDePlasma"]["FrecuenciaDisparo"].as<uint8_t>(),
                 atributos_armamento["CanionDePlasma"]["Bonificacion"].as<std::vector<uint8_t>>()) {}