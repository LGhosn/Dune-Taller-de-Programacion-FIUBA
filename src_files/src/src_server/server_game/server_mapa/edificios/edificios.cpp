#include "edificios.h"

Cuartel::Cuartel(YAML::Node& edificio_config) {
    dimension_x = edificio_config["Cuartel"]["DimensionX"].as<int>();
    dimension_y = edificio_config["Cuartel"]["DimensionY"].as<int>();
    valido = true;
}

FabricaLigera::FabricaLigera(YAML::Node& edificio_config) {
    dimension_x = edificio_config["FabricaLigera"]["DimensionX"].as<int>();
    dimension_y = edificio_config["FabricaLigera"]["DimensionY"].as<int>();
    valido = true;
}

FabricaPesada::FabricaPesada(YAML::Node& edificio_config) {
    dimension_x = edificio_config["FabricaPesada"]["DimensionX"].as<int>();
    dimension_y = edificio_config["FabricaPesada"]["DimensionY"].as<int>();
    valido = true;
}

Palacio::Palacio(YAML::Node& edificio_config) {
    dimension_x = edificio_config["Palacio"]["DimensionX"].as<int>();
    dimension_y = edificio_config["Palacio"]["DimensionY"].as<int>();
    valido = true;
}

Refineria::Refineria(YAML::Node& edificio_config) {
    dimension_x = edificio_config["Refineria"]["DimensionX"].as<int>();
    dimension_y = edificio_config["Refineria"]["DimensionY"].as<int>();
    valido = true;
}

Silo::Silo(YAML::Node& edificio_config) {
    dimension_x = edificio_config["Silo"]["DimensionX"].as<int>();
    dimension_y = edificio_config["Silo"]["DimensionY"].as<int>();
    valido = true;
}

TrampaDeAire::TrampaDeAire(YAML::Node& edificio_config) {
    dimension_x = edificio_config["TrampaDeAire"]["DimensionX"].as<int>();
    dimension_y = edificio_config["TrampaDeAire"]["DimensionY"].as<int>();
    valido = true;
}

EdificioNulo::EdificioNulo() {
    dimension_x = 0;
    dimension_y = 0;
    valido = false;
}
