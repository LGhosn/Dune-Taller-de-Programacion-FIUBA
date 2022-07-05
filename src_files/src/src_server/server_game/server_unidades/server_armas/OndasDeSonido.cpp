#include "OndasDeSonido.h"

OndasDeSonido::OndasDeSonido(YAML::Node& atributos_armamento) :
            Arma(atributos_armamento["OndasDeSonido"]["Dmg"].as<uint8_t>(),
                 atributos_armamento["OndasDeSonido"]["FrecuenciaDisparo"].as<uint8_t>(),
                 atributos_armamento["OndasDeSonido"]["Bonificacion"].as<std::vector<uint8_t>>()) {}