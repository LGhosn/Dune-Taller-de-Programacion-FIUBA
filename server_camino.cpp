#include "server_camino.h"
#include "common_coords.h"
#include <queue>
#include <cmath>
#include <functional>

/* ******************************************************************
 *                        PRIVADAS
 * *****************************************************************/

float Camino::distancia(const Coordenadas& origen, const Coordenadas& destino) const {
    return sqrt(pow(origen.x - destino.x, 2) + pow(origen.y - destino.y, 2));
}

void Camino::a_star(const Coordenadas& origen, const Coordenadas& destino,
    std::map<Coordenadas, Coordenadas>& padres) const {
    std::map<Coordenadas, float> costo;
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
        std::list<Coordenadas> vecinos = this->get_vecinos(actual);
        for (const Coordenadas& vecino : vecinos) {
            float costo_nuevo = costo[actual] + 1;
            if (costo.find(vecino) == costo.end() || costo_nuevo < costo[vecino]) {
                costo[vecino] = costo_nuevo;
                puntaje = costo_nuevo + this->distancia(vecino, destino);
                frontera.push(std::make_pair(puntaje, vecino));
                padres[vecino] = actual;
            }
        }
    }
}

bool Camino::posicion_es_valida(const Coordenadas& pos) const {
    return (pos.x < mapa[0].size() && pos.y < mapa.size());
}

std::list<Coordenadas> Camino::get_vecinos(const Coordenadas& origen) const {
    Coordenadas limites(mapa[0].size(), mapa.size());
    std::list<Coordenadas> vecinos;

    Coordenadas actual(origen.x, origen.y + 1);
    if (posicion_es_valida(actual))
        vecinos.push_back(actual);
    
    actual.x = origen.x + 1;
    actual.y = origen.y + 1;
    if (posicion_es_valida(actual))
        vecinos.push_back(actual);

    actual.x = origen.x + 1;
    actual.y = origen.y;
    if (posicion_es_valida(actual))
        vecinos.push_back(actual);

    actual.x = origen.x + 1;
    actual.y = origen.y - 1;
    if (posicion_es_valida(actual))
        vecinos.push_back(actual);

    actual.x = origen.x;
    actual.y = origen.y - 1;
    if (posicion_es_valida(actual))
        vecinos.push_back(actual);

    actual.x = origen.x - 1;
    actual.y = origen.y - 1;
    if (posicion_es_valida(actual))
        vecinos.push_back(actual);

    actual.x = origen.x - 1;
    actual.y = origen.y;
    if (posicion_es_valida(actual))
        vecinos.push_back(actual);

    actual.x = origen.x - 1;
    actual.y = origen.y + 1;
    if (posicion_es_valida(actual))
        vecinos.push_back(actual);

    return vecinos;
}

std::stack<Coordenadas> Camino::construir_camino(const std::map<Coordenadas, Coordenadas>& padres,
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

Camino::Camino(std::vector< std::vector<char> >& mapa) : mapa(mapa) {}

std::stack<Coordenadas> Camino::obtener_camino(const Coordenadas& origen, const Coordenadas& destino) const {
    std::map<Coordenadas, Coordenadas> padres;
    this->a_star(origen, destino, padres);
    return this->construir_camino(padres, origen, destino);
}
