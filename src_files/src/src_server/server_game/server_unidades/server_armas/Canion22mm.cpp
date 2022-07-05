#include "Canion22mm.h"

Canion22mm::Canion22mm(YAML::Node& atributos_armamento) :
            Arma(atributos_armamento["Canion22mm"]["Dmg"].as<uint8_t>(),
                 atributos_armamento["Canion22mm"]["FrecuenciaDisparo"].as<uint8_t>(),
                 atributos_armamento["Canion22mm"]["Bonificacion"].as<std::vector<uint8_t>>()) {}