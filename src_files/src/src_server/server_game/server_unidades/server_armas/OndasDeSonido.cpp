#include "OndasDeSonido.h"

OndasDeSonido::OndasDeSonido(YAML::Node& atributos_armamento, uint8_t id_unidad_portador, uint16_t ticks) :
            Arma(atributos_armamento["Armas"]["OndasDeSonido"]["Dmg"].as<uint8_t>(),
                 atributos_armamento["Armas"]["OndasDeSonido"]["FrecuenciaDisparo"].as<uint16_t>(),
                 atributos_armamento["Armas"]["OndasDeSonido"]["Bonificacion"].as<std::vector<uint8_t>>(),
                 ticks,
                 id_unidad_portador) {}