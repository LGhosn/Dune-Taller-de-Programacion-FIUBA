#include "LanzaMisiles.h"

LanzaMisiles::LanzaMisiles(YAML::Node& atributos_armamento) :
            Arma(atributos_armamento["LanzaMisiles"]["Dmg"].as<uint8_t>(),
                 atributos_armamento["LanzaMisiles"]["FrecuenciaDisparo"].as<uint8_t>(),
                 atributos_armamento["LanzaMisiles"]["Bonificacion"].as<std::vector<uint8_t>>()) {}