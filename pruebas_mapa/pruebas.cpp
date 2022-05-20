#include <iostream>
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

#include "../server_mapa.h"
#include "yaml-cpp/yaml.h"

/*
 * Estando parado en la carpeta build, ejecutar:
 * cmake ..
 * cmake --build
 * make
 * ./pruebas_mapa 
*/

TEST(Mapa, un_mapa_comienza_sin_colisiones) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);
    std::vector< Coordenadas > colisiones = mapa.ver_colisiones();
    ASSERT_EQ(colisiones.size(), 0);
}

TEST(Mapa, solo_se_puede_construir_sobre_roca) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);

    for (int i = 0; i < alto; i++){
        for (int j = 0; j < ancho; j++){
            mapa.modificar_terreno(j, i, config["Mapa"][i][j].as<char>());
        }
    }
    
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(3, 0, 0)), false); // No se puede construir sobre precipicios
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(3, 5, 0)), false); // No se puede construir sobre arena
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(3, 5, 6)), false); // No se puede construir sobre dunas
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(3, 1, 4)), false); // No se puede construir sobre cima
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(3, 0, 1)), true); // Se puede construir sobre roca
}

TEST(Mapa, no_se_puede_construir_sobre_arena) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);

    EXPECT_EQ(ancho, 10);
    EXPECT_EQ(alto, 9);

    std::tuple<uint8_t, uint16_t, uint16_t> edificio = std::make_tuple(0x01, 0, 0);
    ASSERT_EQ(mapa.construir_edificio(edificio), false);
}





int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
