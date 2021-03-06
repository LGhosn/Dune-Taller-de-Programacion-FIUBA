#include "server_camino.h"
#include "server_camino_no_encontrado_exception.h"
#include "server_fuera_de_rango_exception.h"
#include "entidades/unidades/unidades_mapa.h"
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
    const std::vector<float>& pen_terr) const {
    float dist = distancia(actual, vecino);
    char terreno_actual = getTipoDeTerreno(actual);
    char terreno_vecino = getTipoDeTerreno(vecino);
    float pen_actual = pen_terr.at(terreno_actual);
    float pen_vecino = pen_terr.at(terreno_vecino);
    return (dist * pen_actual) / 2 + (dist * pen_vecino) / 2;
}

bool Camino::a_star(const Coordenadas& origen,
                    Coordenadas& destino,
                    std::unordered_map<Coordenadas,Coordenadas, HashCoordenadas>& padres,
                    std::vector<uint8_t>& terrenos_no_accesibles,
                    const std::vector<float>& penalizacion_terreno) const {
    std::unordered_map<Coordenadas, float, HashCoordenadas> costo;
    std::priority_queue<std::pair<float, Coordenadas>,
                        std::vector<std::pair<float, Coordenadas>>,
                        std::greater<std::pair<float, Coordenadas>>> frontera;
    frontera.push(std::make_pair(0.0f, origen));
    padres[origen] = origen;
    costo[origen] = this->distancia(origen, destino);
    while (!frontera.empty()) {
        Coordenadas actual;
        float puntaje;
        std::tie(puntaje, actual) = frontera.top();
        frontera.pop();
        std::list<Coordenadas> vecinos = this->get_vecinos(actual, destino, terrenos_no_accesibles);
        if (actual == destino) {
            break;
        }
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
        return false;
    }
    return true;
}

char Camino::getTipoDeSuperficie(const Coordenadas& pos) const {
    std::shared_ptr<Entidades>& entidad = (*this->mapa)[pos.y][pos.x];
    if (entidad->obtenerTipoDeEntidad() == 'T') {
        return entidad->obtenerIdentificador();
    }
    return entidad->obtenerTipoDeEntidad();
}

char Camino::getTipoDeTerreno(const Coordenadas& pos) const {
    std::shared_ptr<Entidades>& entidad = (*this->mapa)[pos.y][pos.x];
    if (entidad->obtenerTipoDeEntidad() == 'U') {
        std::shared_ptr<UnidadesMapa>& unidad = (std::shared_ptr<UnidadesMapa>&) entidad;
        return unidad->obtenerTerrenoQueEstaParada();
    }
    return entidad->obtenerIdentificador();
}

bool Camino::posicion_es_valida(const Coordenadas& pos, std::vector<uint8_t>& terr_no_accesibles) const {
    if (pos.x < this->mapa[0].size() && pos.y < mapa->size()) {
        char terreno = getTipoDeSuperficie(pos);
        return std::find(terr_no_accesibles.begin(), terr_no_accesibles.end(), terreno) == terr_no_accesibles.end();
    }
    return false;
}

std::list<Coordenadas> Camino::get_vecinos(const Coordenadas& ubicacion_actual,
                                        Coordenadas& destino,
                                        std::vector<uint8_t>& terrenos_no_accesibles) const {
    std::list<Coordenadas> vecinos;
    for (const auto& posicion_vecina : this->vecinos_posibles) {
        Coordenadas vecino_posible;
        vecino_posible.x = posicion_vecina.first + ubicacion_actual.x;
        vecino_posible.y = posicion_vecina.second + ubicacion_actual.y;
        if (posicion_es_valida(vecino_posible, terrenos_no_accesibles)) {
            vecinos.push_back(vecino_posible);
        } else if (vecino_posible == destino) {
            destino.x = ubicacion_actual.x;
            destino.y = ubicacion_actual.y;
            break;
        }
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

void Camino::start(std::vector< std::vector<std::shared_ptr<Entidades> > >* mapa) {
    this->mapa = mapa;
}

std::stack<Coordenadas> Camino::obtener_camino(UnidadInfoDTO& unidad_info) const {
    std::unordered_map<Coordenadas, Coordenadas, HashCoordenadas> padres;
    Coordenadas destino_actual = unidad_info.destino;
    bool se_pudo_encontrar = this->a_star(unidad_info.origen, destino_actual,
                                padres, unidad_info.terrenos_no_accesibles,
                                unidad_info.penalizacion_terreno);
    if (se_pudo_encontrar) {
        return this->construir_camino(padres, unidad_info.origen, destino_actual);
    } else {
        return std::stack<Coordenadas>();
    }
}

Camino::Camino(const Camino& otro) : mapa(nullptr) {}

Camino& Camino::operator=(const Camino& otro) {
    // this->mapa = otro.mapa;
    return *this;
}
