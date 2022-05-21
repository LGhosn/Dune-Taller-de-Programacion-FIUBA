#ifndef SERVER_CAMINO_H
#define SERVER_CAMINO_H

#include "common_coords.h"
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <unordered_map>

class Camino {
	std::vector< std::vector<char> >& mapa;

	float distancia(const Coordenadas& origen, const Coordenadas& destino) const;

	void a_star(const Coordenadas& origen, const Coordenadas& destino,
    std::unordered_map<Coordenadas, Coordenadas, HashCoordenadas>& padres, std::vector<char>& terrenos_no_accesibles) const;

	char get_tipo_de_terreno(const Coordenadas& pos) const;

	bool posicion_es_valida(const Coordenadas& pos, std::vector<char>& terr_no_accesibles) const;

	std::list<Coordenadas> get_vecinos(const Coordenadas& origen,
		std::vector<char>& terrenos_no_accesibles) const;

	std::stack<Coordenadas> construir_camino(const std::unordered_map<Coordenadas,Coordenadas, HashCoordenadas>& padres,
		const Coordenadas& origen, const Coordenadas& destino) const;

public:
	Camino(std::vector< std::vector<char> >& mapa);

	std::stack<Coordenadas> obtener_camino(const Coordenadas& origen, const Coordenadas& destino,
		std::vector<char>& terrenos_no_accesibles) const;
};

#endif
