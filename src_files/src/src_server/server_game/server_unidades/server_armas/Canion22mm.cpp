#include "Canion22mm.h"

Canion22mm::Canion22mm(YAML::Node& atributos_armamento, uint16_t ticks) :
            Arma(atributos_armamento["Armas"]["Canion22mm"]["Dmg"].as<uint8_t>(),
                 atributos_armamento["Armas"]["Canion22mm"]["FrecuenciaDisparo"].as<uint16_t>(),
                 atributos_armamento["Armas"]["Canion22mm"]["Bonificacion"].as<std::vector<uint8_t>>(),
                 ticks) {}