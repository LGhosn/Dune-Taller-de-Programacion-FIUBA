#include "server_camino.h"
#include "../src_common/common_coords.h"
#include "server_camino_no_encontrado_exception.h"
#include "server_fuera_de_rango_exception.h"
#include <queue>
#include <cmath>
#include <functional>
#include <algorithm>
#include <memory>

/* ******************************************************************
 *                        PRIVADAS
 * *****************************************************************/

float Camino::distancia(const Coordenadas& origen, const Coordenadas& destino) const {
    return sqrt(pow(origen.x - destino.x, 2) + pow(origen.y - destino.y, 2));
}

float Camino::calcular_costo_adicional(const Coordenadas& actual, const Coordenadas& vecino,
    const std::unordered_map<char, float>& pen_terr) const {
    float dist = distancia(actual, vecino);
    char terreno_actual = get_tipo_de_terreno(actual);
    char terreno_vecino = get_tipo_de_terreno(vecino);
    float pen_actual = pen_terr.find(terreno_actual) == pen_terr.end() ? 1 : pen_terr.at(terreno_actual);
    float pen_vecino = pen_terr.find(terreno_vecino) == pen_terr.end() ? 1 : pen_terr.at(terreno_vecino);
    return (dist * pen_actual) / 2 + (dist * pen_vecino) / 2;
}

void Camino::a_star(const Coordenadas& origen, const Coordenadas& destino,
    std::unordered_map<Coordenadas, Coordenadas, HashCoordenadas>& padres,
    std::vector<char>& terrenos_no_accesibles, const std::unordered_map<char, float>& penalizacion_terreno) const {
    std::unordered_map<Coordenadas, float, HashCoordenadas> costo;
    std::priority_queue<std::pair<float, Coordenadas>,
    std::vector<std::pair<float, Coordenadas>>, std::greater<std::pair<float, Coordenadas>>> frontera;
    frontera.push(std::make_pair(0.0f, origen));
    padres[origen] = origen;
    costo[origen] = this->distancia(origen, destino);
    while (!frontera.empty()) {
        Coordenadas actual;
        float puntaje;
        std::tie(puntaje, actual) = frontera.top();
        frontera.pop();
        if (actual == destino)
            break;
        std::list<Coordenadas> vecinos = this->get_vecinos(actual, terrenos_no_accesibles);
        for (const Coordenadas& vecino : vecinos) {
            float costo_nuevo = costo[actual] + calcular_costo_adicional(actual, vecino, penalizacion_terreno);
            if (costo.find(vecino) == costo.end() || costo_nuevo < costo[vecino]) {
                costo[vecino] = costo_nuevo;
                puntaje = costo_nuevo + this->distancia(vecino, destino);
                frontera.push(std::make_pair(puntaje, vecino));
                padres[vecino] = actual;
            }
        }
    }
    if (padres.find(destino) == padres.end()) {
        throw CaminoNoEncontradoException("No se encontro un camino posible de origen a destino.");
    }
}

char Camino::get_tipo_de_terreno(const Coordenadas& pos) const {
    return (*this->mapa)[pos.y][pos.x]->obtenerIdentificador();
}

bool Camino::posicion_es_valida(const Coordenadas& pos, std::vector<char>& terr_no_accesibles) const {
    if (pos.x < this->mapa[0].size() && pos.y < mapa->size()) {
        char terreno = get_tipo_de_terreno(pos);
        return std::find(terr_no_accesibles.begin(), terr_no_accesibles.end(), terreno) == terr_no_accesibles.end();
    }
    return false;
}

std::list<Coordenadas> Camino::get_vecinos(const Coordenadas& origen,
    std::vector<char>& terrenos_no_accesibles) const {
    std::list<Coordenadas> vecinos;
    for (const Coordenadas& posicion_vecina : this->vecinos_posibles) {
        Coordenadas vecino_posible = posicion_vecina + origen;
        if (posicion_es_valida(vecino_posible, terrenos_no_accesibles))
            vecinos.push_back(vecino_posible);
    }
    return vecinos;
}

std::stack<Coordenadas> Camino::construir_camino
(const std::unordered_map<Coordenadas, Coordenadas, HashCoordenadas>& padres,
    const Coordenadas& origen, const Coordenadas& destino) const {
    std::stack<Coordenadas> pasos;
    Coordenadas actual = destino;
    while (actual != origen) {
        pasos.push(actual);
        actual = padres.at(actual);
    }
    return pasos;
}

/* ******************************************************************
 *                        PUBLICAS
 * *****************************************************************/

Camino::Camino() : mapa(nullptr) {
    this->vecinos_posibles.reserve(8);
    this->vecinos_posibles.emplace_back(1, 0);
    this->vecinos_posibles.emplace_back(0, 1);
    this->vecinos_posibles.emplace_back(1, 1);
    this->vecinos_posibles.emplace_back(-1, 1);
    this->vecinos_posibles.emplace_back(-1, -1);
    this->vecinos_posibles.emplace_back(1, -1);
    this->vecinos_posibles.emplace_back(-1, 0);
    this->vecinos_posibles.emplace_back(0, -1);
}

void Camino::start(std::vector< std::vector<std::unique_ptr<Entidades> > >* mapa) {
    this->mapa = mapa;
}

std::stack<Coordenadas> Camino::obtener_camino(UnidadInfoDTO& unidad_info) const {
    const Coordenadas& origen = unidad_info.origen;
    const Coordenadas& destino = unidad_info.destino;
    std::vector<char>& terrenos_no_accesibles = unidad_info.terrenos_no_accesibles;
    const std::unordered_map<char, float>& penalizacion_terreno = unidad_info.penalizacion_terreno;

    if (!posicion_es_valida(origen, terrenos_no_accesibles) || 
        !posicion_es_valida(destino, terrenos_no_accesibles)) {
        throw FueraDeRangoException("La posicion de origen y/o destino no es valida");
    }
    std::unordered_map<Coordenadas, Coordenadas, HashCoordenadas> padres;
    this->a_star(origen, destino, padres, terrenos_no_accesibles, penalizacion_terreno);
    return this->construir_camino(padres, origen, destino);
}

Camino::Camino(const Camino& otro) : mapa(nullptr) {}

Camino& Camino::operator=(const Camino& otro) {
    // this->mapa = otro.mapa;
    return *this;
}
