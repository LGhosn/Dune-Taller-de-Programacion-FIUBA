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
	std::vector< std::vector<std::shared_ptr<Entidades> > >* mapa;
	std::vector<std::pair<int8_t, int8_t>> vecinos_posibles;

	float distancia(const Coordenadas& origen, const Coordenadas& destino) const;

	float calcular_costo_adicional(const Coordenadas& actual, const Coordenadas& vecino,
    const std::vector<float>& pen_terr) const;

	bool a_star(const Coordenadas& origen, Coordenadas& destino,
    std::unordered_map<Coordenadas, Coordenadas, HashCoordenadas>& padres,
    std::vector<uint8_t>& terrenos_no_accesibles, const std::vector<float>& penalizacion_terrenoo) const;

	char getTipoDeSuperficie(const Coordenadas& pos) const;

	char getTipoDeTerreno(const Coordenadas& pos) const;

	bool posicion_es_valida(const Coordenadas& pos, std::vector<uint8_t>& terr_no_accesibles) const;

	/*
	 * Encuentra los vecinos posibles desde la ubicacion dada, teniendo en cuenta los terrenos
	 * no accesibles dados por parametro. Si el destino no es accesible y es un vecino, se
	 * modifica para que pase a ser la ubicacion actual, haciendo que se devuelva el camino mas
	 * cercano posible al destino.
	*/
	std::list<Coordenadas> get_vecinos(const Coordenadas& ubicacion_actual,
									Coordenadas& destino,
									std::vector<uint8_t>& terrenos_no_accesibles) const;

	/*
	 * A partir del mapa de padres, construye el camino, devolviendo un stack en donde el ultimo
	 * elemento en colocarse es el primer movimiento, y el ultimo es el destino.
	*/
	std::stack<Coordenadas> construir_camino(const std::unordered_map<Coordenadas,Coordenadas, HashCoordenadas>& padres,
		const Coordenadas& origen, const Coordenadas& destino) const;

public:
	Camino();

	void start(std::vector< std::vector<std::shared_ptr<Entidades> > >* mapa);

	/*
	 * Recibe la informacion acerca de la unidad, incluyendo el destino deseado, y devuelve
	 * el camino mas corto posible hacia el, teniendo en cuenta los terrenos no accesibles.
	 * En el caso de que el destino sea inaccesible (por ejemplo, porque es un edificio o 
	 * unidad) se busca el camino a la celda vecina al destino que este mas cercana a la
	 * unidad. En caso de que no haya camino posible, se devuelve un stack vacio.
	*/
	std::stack<Coordenadas> obtener_camino(UnidadInfoDTO& unidad_info) const;

	Camino(const Camino&);
    Camino& operator=(const Camino&);
};

#endif
