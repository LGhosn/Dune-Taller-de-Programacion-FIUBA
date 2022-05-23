#include "../server_camino.h"
#include "../server_camino_no_encontrado_exception.h"
#include "../server_fuera_de_rango_exception.h"
#include "gtest/gtest.h"
#include <vector>
#include <stack>
#include <iostream>

#define ARENA 'A'
#define DUNA 'D'
#define PRECIPICIO 'P'

TEST(CaminoTest, creaUnCamino) {
	std::vector<std::vector<char>> mapa(8, std::vector<char>(8, ARENA));
	Camino camino(mapa);
}

TEST(CaminoTest, caminoTrivial) {
	std::vector<std::vector<char>> mapa(8, std::vector<char>(8, ARENA));
	Camino camino(mapa);
	Coordenadas origen(0,0);
	Coordenadas destino(7,7);
	std::vector<char> terrenos_no_accesibles;
	std::unordered_map<char, float> penalizacion_terreno;
	std::stack<Coordenadas> camino_obtenido = camino.obtener_camino(origen, destino,
		terrenos_no_accesibles, penalizacion_terreno);
	std::stack<Coordenadas> camino_esperado;
	for (int i = 7; i > 0; i--) {
		Coordenadas actual(i,i);
		camino_esperado.push(actual);
	}
	
	ASSERT_EQ(camino_obtenido.size(), camino_esperado.size()) << "El vector esperado deberia ser de largo " 
	 << camino_esperado.size() << " pero es de largo " << camino_obtenido.size() << std::endl;

	while (!camino_obtenido.empty()) {
		Coordenadas celda_obtenida = camino_obtenido.top();
		Coordenadas celda_esperada = camino_esperado.top();
		EXPECT_EQ(celda_obtenida, celda_esperada);
		camino_obtenido.pop();
		camino_esperado.pop();
	}
}

TEST(CaminoTest, caminoConPrecipicio) {
	std::vector<std::vector<char>> mapa(8, std::vector<char>(8, ARENA));
	for (int i = 0; i < 7; i++) {
		mapa[i][4] = PRECIPICIO;
	}
	Camino camino(mapa);
	Coordenadas origen(0,0);
	Coordenadas destino(7,7);
	int largo_esperado = 10;
	std::vector<char> terrenos_no_accesibles;
	terrenos_no_accesibles.push_back(PRECIPICIO);
	std::unordered_map<char, float> penalizacion_terreno;
	std::stack<Coordenadas> camino_obtenido = camino.obtener_camino(origen, destino,
		terrenos_no_accesibles, penalizacion_terreno);
	ASSERT_EQ(camino_obtenido.size(), largo_esperado) << "El vector esperado deberia ser de largo " 
	 << largo_esperado << " pero es de largo " << camino_obtenido.size() << std::endl;
}

TEST(CaminoTest, caminoConZigZag) {
	std::vector<std::vector<char>> mapa(8, std::vector<char>(8, ARENA));
	for (int i = 0; i < 6; i++) {
		mapa[2][i] = PRECIPICIO;
	}
	for (int i = 2; i < 8; i++) {
		mapa[5][i] = PRECIPICIO;
	}
	mapa[1][2] = PRECIPICIO;
	mapa[0][5] = PRECIPICIO;
	mapa[3][6] = PRECIPICIO;
	mapa[3][4] = PRECIPICIO;
	mapa[4][2] = PRECIPICIO;
	mapa[6][4] = PRECIPICIO;
	mapa[6][5] = PRECIPICIO;
	Camino camino(mapa);
	Coordenadas origen(0,0);
	Coordenadas destino(7,7);
	int largo_esperado = 18;
	std::vector<char> terrenos_no_accesibles;
	terrenos_no_accesibles.push_back(PRECIPICIO);
	std::unordered_map<char, float> penalizacion_terreno;
	std::stack<Coordenadas> camino_obtenido = camino.obtener_camino(origen, destino,
		terrenos_no_accesibles, penalizacion_terreno);
	
	ASSERT_EQ(camino_obtenido.size(), largo_esperado) << "El vector esperado deberia ser de largo " 
	 << largo_esperado << " pero es de largo " << camino_obtenido.size() << std::endl;
}

TEST(CaminoTest, caminoImposible) {
	std::vector<std::vector<char>> mapa(8, std::vector<char>(8, ARENA));
	for (int i = 0; i < 8; i++) {
		mapa[3][i] = PRECIPICIO;
	}
	Camino camino(mapa);
	Coordenadas origen(0,0);
	Coordenadas destino(7,7);
	std::vector<char> terrenos_no_accesibles;
	terrenos_no_accesibles.push_back(PRECIPICIO);
	std::unordered_map<char, float> penalizacion_terreno;
	EXPECT_THROW(camino.obtener_camino(origen, destino,
		terrenos_no_accesibles, penalizacion_terreno), CaminoNoEncontradoException);
}

TEST(CaminoTest, caminoConDunas) {
	std::vector<std::vector<char>> mapa(4, std::vector<char>(4, ARENA));
	mapa[1][1] = DUNA;
	mapa[1][2] = DUNA;
	mapa[2][1] = DUNA;
	mapa[2][2] = DUNA;
	Camino camino(mapa);
	Coordenadas origen(0,0);
	Coordenadas destino(3,3);
	std::vector<char> terrenos_no_accesibles;
	std::unordered_map<char, float> penalizacion_terreno;
	penalizacion_terreno[DUNA] = 2;
	int largo_esperado = 5;
	std::stack<Coordenadas> camino_obtenido = camino.obtener_camino(origen, destino,
		terrenos_no_accesibles, penalizacion_terreno);
	ASSERT_EQ(camino_obtenido.size(), largo_esperado) << "El vector esperado deberia ser de largo " 
	 << largo_esperado << " pero es de largo " << camino_obtenido.size() << std::endl;
}

TEST(CaminoTest, caminoConCoordenadasNoValidas) {
	std::vector<std::vector<char>> mapa(4, std::vector<char>(4, ARENA));
	Camino camino(mapa);
	Coordenadas origen(0,0);
	Coordenadas destino(4,4);
	std::vector<char> terrenos_no_accesibles;
	std::unordered_map<char, float> penalizacion_terreno;
	EXPECT_THROW(camino.obtener_camino(origen, destino,
		terrenos_no_accesibles, penalizacion_terreno), FueraDeRangoException);
}

TEST(CaminoTest, caminoConCoordenadasEnTerrenoNoAccesible) {
	std::vector<std::vector<char>> mapa(4, std::vector<char>(4, ARENA));
	mapa[3][3] = PRECIPICIO;
	Camino camino(mapa);
	Coordenadas origen(0,0);
	Coordenadas destino(3,3);
	std::vector<char> terrenos_no_accesibles;
	terrenos_no_accesibles.push_back(PRECIPICIO);
	std::unordered_map<char, float> penalizacion_terreno;
	EXPECT_THROW(camino.obtener_camino(origen, destino,
		terrenos_no_accesibles, penalizacion_terreno), FueraDeRangoException);
}
