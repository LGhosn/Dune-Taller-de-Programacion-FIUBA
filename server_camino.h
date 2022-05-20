#ifndef SERVER_CAMINO_H
#define SERVER_CAMINO_H

#include "common_coords.h"
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <map>

class Camino {
	std::vector< std::vector<char> >& mapa;

	float distancia(const Coordenadas& origen, const Coordenadas& destino) const;

	void a_star(const Coordenadas& origen, const Coordenadas& destino,
    std::map<Coordenadas, Coordenadas>& padres) const;

	bool posicion_es_valida(const Coordenadas& pos) const;

	std::list<Coordenadas> get_vecinos(const Coordenadas& origen) const;

	std::stack<Coordenadas> construir_camino(const std::map<Coordenadas,Coordenadas>& padres,
		const Coordenadas& origen, const Coordenadas& destino) const;

public:
	Camino(std::vector< std::vector<char> >& mapa);

	std::stack<Coordenadas> obtener_camino(const Coordenadas& origen, const Coordenadas& destino) const;
};

#endif
