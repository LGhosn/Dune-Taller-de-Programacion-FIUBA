#ifndef SERVER_CAMINO_H
#define SERVER_CAMINO_H

#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <memory>
#include <unordered_map>

#include "../../../src_common/common_coords.h"
#include "entidades/entidades_mapa.h"
#include "../../server_DTO/dto_unidad_info.h"

class Camino {
	std::vector< std::vector<std::unique_ptr<Entidades> > >* mapa;
	std::vector<std::pair<int8_t, int8_t>> vecinos_posibles;

	float distancia(const Coordenadas& origen, const Coordenadas& destino) const;

	float calcular_costo_adicional(const Coordenadas& actual, const Coordenadas& vecino,
    const std::vector<float>& pen_terr) const;

	bool a_star(const Coordenadas& origen, const Coordenadas& destino,
    std::unordered_map<Coordenadas, Coordenadas, HashCoordenadas>& padres,
    std::vector<uint8_t>& terrenos_no_accesibles, const std::vector<float>& penalizacion_terrenoo) const;

	char getTipoDeSuperficie(const Coordenadas& pos) const;

	char getTipoDeTerreno(const Coordenadas& pos) const;

	bool posicion_es_valida(const Coordenadas& pos, std::vector<uint8_t>& terr_no_accesibles) const;

	std::list<Coordenadas> get_vecinos(const Coordenadas& origen,
		std::vector<uint8_t>& terrenos_no_accesibles) const;

	std::stack<Coordenadas> construir_camino(const std::unordered_map<Coordenadas,Coordenadas, HashCoordenadas>& padres,
		const Coordenadas& origen, const Coordenadas& destino) const;

public:
	Camino();

	void start(std::vector< std::vector<std::unique_ptr<Entidades> > >* mapa);

	std::stack<Coordenadas> obtener_camino(UnidadInfoDTO& unidad_info) const;

	Camino(const Camino&);
    Camino& operator=(const Camino&);
};

#endif
