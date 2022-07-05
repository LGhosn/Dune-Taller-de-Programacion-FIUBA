#include "LanzaMisiles.h"

LanzaMisiles::LanzaMisiles(YAML::Node& atributos_armamento, uint16_t ticks) :
            Arma(atributos_armamento["Armas"]["LanzaMisiles"]["Dmg"].as<uint8_t>(),
                 atributos_armamento["Armas"]["LanzaMisiles"]["FrecuenciaDisparo"].as<uint16_t>(),
                 atributos_armamento["Armas"]["LanzaMisiles"]["Bonificacion"].as<std::vector<uint8_t>>(),
                 ticks) {}