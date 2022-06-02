#include "server_camino.h"
#include "gtest/gtest.h"
#include <vector>
#include <stack>
#include <iostream>

TEST(CaminoTest, creaUnCamino) {
	std::vector<std::vector<char>> mapa(8, std::vector<char>(8, '.'));
	Camino camino(mapa);
}

TEST(CaminoTest, caminoTrivial) {
	std::vector<std::vector<char>> mapa(8, std::vector<char>(8, '.'));
	Camino camino(mapa);
	Coordenadas origen(0,0);
	Coordenadas destino(7,7);
	std::stack<Coordenadas> camino_obtenido = camino.obtener_camino(origen, destino);
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
