#include <iostream>
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

#include "../../src_server/server_game/server_mapa/server_mapa.h"
#include "yaml-cpp/yaml.h"

/*
 * Estando parado en la carpeta build, ejecutar:
 * cmake ..
 * cmake --build .
 * make
 * ./mapa_tests 
*/

TEST(Mapa, un_mapa_comienza_sin_colisiones) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);
    std::vector< Coordenadas > colisiones = mapa.ver_colisiones();
    ASSERT_EQ(colisiones.size(), 0);
}

TEST(Mapa, no_se_puede_construir_sobre_arena) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);

    for (int i = 0; i < alto; i++){
        for (int j = 0; j < ancho; j++){
            mapa.modificar_terreno(j, i, config["Mapa"][i][j].as<char>());
        }
    }

    const uint8_t edificio = config["Silo"]["Valor"].as<uint8_t>();
    const uint16_t x_arena = config["Silo"]["Posicion"]["XArena"].as<uint16_t>();
    const uint16_t y_arena = config["Silo"]["Posicion"]["YArena"].as<uint16_t>();
    
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(edificio, x_arena, y_arena)), false); // No se puede construir sobre arena
}

TEST(Mapa, no_se_puede_construir_sobre_precipicios) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);

    for (int i = 0; i < alto; i++){
        for (int j = 0; j < ancho; j++){
            mapa.modificar_terreno(j, i, config["Mapa"][i][j].as<char>());
        }
    }

    const uint8_t edificio = config["Silo"]["Valor"].as<uint8_t>();
    const uint16_t x_precipicio = config["Silo"]["Posicion"]["XPrecipicio"].as<uint16_t>();
    const uint16_t y_precipicio = config["Silo"]["Posicion"]["YPrecipicio"].as<uint16_t>();
    
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(edificio, x_precipicio, y_precipicio)), false); // No se puede construir sobre precipicio
}

TEST(Mapa, no_se_puede_construir_sobre_duna) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);

    for (int i = 0; i < alto; i++){
        for (int j = 0; j < ancho; j++){
            mapa.modificar_terreno(j, i, config["Mapa"][i][j].as<char>());
        }
    }

    const uint8_t edificio = config["Silo"]["Valor"].as<uint8_t>();
    const uint16_t x_duna = config["Silo"]["Posicion"]["XDuna"].as<uint16_t>();
    const uint16_t y_duna = config["Silo"]["Posicion"]["YDuna"].as<uint16_t>();
    
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(edificio, x_duna, y_duna)), false); // No se puede construir sobre dunas
}

TEST(Mapa, no_se_puede_construir_sobre_cimas) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);

    for (int i = 0; i < alto; i++){
        for (int j = 0; j < ancho; j++){
            mapa.modificar_terreno(j, i, config["Mapa"][i][j].as<char>());
        }
    }

    const uint8_t edificio = config["Silo"]["Valor"].as<uint8_t>();
    const uint16_t x_cima = config["Silo"]["Posicion"]["XCima"].as<uint16_t>();
    const uint16_t y_cima = config["Silo"]["Posicion"]["YCima"].as<uint16_t>();
    
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(edificio, x_cima, y_cima)), false); // No se puede construir sobre cimas
}

TEST(Mapa, se_puede_construir_sobre_rocas) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);

    for (int i = 0; i < alto; i++){
        for (int j = 0; j < ancho; j++){
            mapa.modificar_terreno(j, i, config["Mapa"][i][j].as<char>());
        }
    }

    const uint8_t edificio = config["Silo"]["Valor"].as<uint8_t>();
    const uint16_t x_roca = config["Silo"]["Posicion"]["XRoca"].as<uint16_t>();
    const uint16_t y_roca = config["Silo"]["Posicion"]["YRoca"].as<uint16_t>();
    
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(edificio, x_roca, y_roca)), true); // Se puede construir sobre rocas
}

TEST(Mapa, no_se_puede_construir_sobre_otros_edificios) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);

    for (int i = 0; i < alto; i++){
        for (int j = 0; j < ancho; j++){
            mapa.modificar_terreno(j, i, config["Mapa"][i][j].as<char>());
        }
    }

    const uint8_t edificio = config["Silo"]["Valor"].as<uint8_t>();
    const uint16_t x_roca = config["Silo"]["Posicion"]["XRoca"].as<uint16_t>();
    const uint16_t y_roca = config["Silo"]["Posicion"]["YRoca"].as<uint16_t>();

    mapa.construir_edificio(std::make_tuple(edificio, x_roca, y_roca)); // Se construye un edificio sobre roca
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(edificio, x_roca, y_roca)), false); // No se puede construir sobre un edificio ya construido
}

TEST(Mapa, no_se_puede_edificar_a_menos_de_5_bloques) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);

    for (int i = 0; i < alto; i++){
        for (int j = 0; j < ancho; j++){
            mapa.modificar_terreno(j, i, config["Mapa"][i][j].as<char>());
        }
    }

    const uint8_t edificio = config["Silo"]["Valor"].as<uint8_t>();
    const uint16_t x_roca = config["Silo"]["Posicion"]["XRoca"].as<uint16_t>();
    const uint16_t y_roca = config["Silo"]["Posicion"]["YRoca"].as<uint16_t>();

    mapa.construir_edificio(std::make_tuple(edificio, x_roca, y_roca));
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(edificio, x_roca + 2, y_roca + 2)), false);
}

TEST(Mapa, se_puede_construir_a_mas_de_5_bloques) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);

    for (int i = 0; i < alto; i++){
        for (int j = 0; j < ancho; j++){
            mapa.modificar_terreno(j, i, config["Mapa2"][i][j].as<char>());
        }
    }

    const uint8_t edificio = config["Silo"]["Valor"].as<uint8_t>();
    const uint16_t x_roca = config["Silo"]["Posicion"]["XRoca"].as<uint16_t>();
    const uint16_t y_roca = config["Silo"]["Posicion"]["YRoca"].as<uint16_t>();

    mapa.construir_edificio(std::make_tuple(edificio, x_roca, y_roca));
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(edificio, x_roca, y_roca + 6)), true);
}

TEST(Mapa, se_puede_construir_despues_de_demoler) {
    YAML::Node config = YAML::LoadFile("../config.yaml");

    const int ancho = config["Ancho"].as<int>();
    const int alto = config["Alto"].as<int>();

    Mapa mapa(ancho, alto);

    for (int i = 0; i < alto; i++){
        for (int j = 0; j < ancho; j++){
            mapa.modificar_terreno(j, i, config["Mapa2"][i][j].as<char>());
        }
    }

    const uint8_t edificio = config["Silo"]["Valor"].as<uint8_t>();
    const uint16_t x_roca = config["Silo"]["Posicion"]["XRoca"].as<uint16_t>();
    const uint16_t y_roca = config["Silo"]["Posicion"]["YRoca"].as<uint16_t>();

    mapa.construir_edificio(std::make_tuple(edificio, x_roca, y_roca));
    mapa.demoler_edificio(edificio, x_roca, y_roca);
    ASSERT_EQ(mapa.construir_edificio(std::make_tuple(edificio, x_roca, y_roca)), true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
