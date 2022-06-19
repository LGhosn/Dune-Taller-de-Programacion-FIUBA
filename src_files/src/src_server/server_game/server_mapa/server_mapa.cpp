#include <algorithm>
#include <iostream>
#include <sstream>

#include "yaml-cpp/yaml.h"
#include "server_mapa.h"

#define DISTANCIA_EDIFICIOS 5
#define TORRE_DE_AIRE 'T'
#define CUARTEL 'C'
#define SILO 'S'

enum dimensiones {
    una_dimension = 1,
    dos_dimensiones = 2,
    tres_dimension = 3
};

/* ******************************************************************
 *                        PRIVADAS
 * *****************************************************************/
std::tuple<int, int, char> Mapa::propiedadesEdificio(uint8_t edificio) {
    int dimension_x = 0, dimension_y = 0;
    char tipo_edificio = 0;
    switch (edificio) {
        case 0:
            dimension_x = tres_dimension;
            dimension_y = tres_dimension;
            tipo_edificio = TORRE_DE_AIRE;
            break;
        case 1:
            dimension_x = dos_dimensiones;
            dimension_y = tres_dimension;
            tipo_edificio = CUARTEL;
            break;
        case 2:
            dimension_x = una_dimension;
            dimension_y = una_dimension;
            tipo_edificio = SILO;
            break;
        default:
            std::cout << "Error: edificio no reconocido" << std::endl;
            break;
    }
    return std::make_tuple(dimension_x, dimension_y, tipo_edificio);
}

bool Mapa::hayColisiones(const Coordenadas& coords, int dimension_x, int dimension_y) {
    bool colision = false;
    for (int i = coords.y; i < coords.y + dimension_y; i++){
        for (int j = coords.x; j < coords.x + dimension_x; j++){
            // Verifico que el edificio no se salga del mapa
            if (j >= this->ancho || i >= this->alto){
                this->colisiones.push_back(Coordenadas(j, i));
                colision = true;
                continue;
            }
            // temporal hasta implementar los edificios
            if (this->mapa[i][j] == TORRE_DE_AIRE || this->mapa[i][j] == CUARTEL || this->mapa[i][j] == SILO){
                this->colisiones.push_back(Coordenadas(j, i));
                colision = true;
            }
        }
    }
    return colision;
}

void Mapa::edificar(const Coordenadas& coords, std::tuple<int, int, char> propiedades) {
    int dimension_x = 0, dimension_y = 0;
    char tipo_edificio = 0;
    std::tie(dimension_x, dimension_y, tipo_edificio) = propiedades;
    if (this->colisiones.empty()){
        for (int i = coords.y; i < (coords.y + dimension_y); i++){
            for (int j = coords.x; j < (coords.x + dimension_x); j++){
                if (0 > j || j >= this->ancho || 0 > i || i >= this->alto || this->mapa[i][j] != 'R'){
                    continue;
                }
                this->mapa[i][j] = tipo_edificio;                
            }
        }
    }
}

bool Mapa::terrenoFirme(const Coordenadas& coords) {
    return this->mapa[coords.y][coords.x] == 'R' ? true : false;
}

/* ******************************************************************
 *                        PUBLICAS
 * *****************************************************************/

Mapa::Mapa(const std::string& nombre_mapa) : camino(this->mapa) {
    std::stringstream ruta_mapa;
    ruta_mapa << RESOURCE_PATH << "/maps/" << nombre_mapa << ".yaml";
    YAML::Node mapa_config = YAML::LoadFile(ruta_mapa.str());

    this->ancho = mapa_config["Ancho"].as<int>();
    this->alto = mapa_config["Alto"].as<int>();
    this->mapa = std::vector<std::vector<char>>(this->alto, std::vector<char>(this->ancho));
    for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++){
            this->mapa[i][j] = mapa_config["TiposTerrenos"][i][j].as<char>();
        }
    }
    this->camino = this->mapa;
}

bool Mapa::construirEdificio(uint16_t id_jugador, uint8_t tipo, const Coordenadas& coords) {
    // Cada vez que se intente construir un edificio, se limpia la lista de colisiones
    this->colisiones = std::vector< Coordenadas >();
    std::tuple<int, int, char> propiedades_del_edificio = propiedadesEdificio(tipo);

    int dimension_x = 0, dimension_y = 0;
    char tipo_edificio = 0;
    std::tie(dimension_x, dimension_y, tipo_edificio) = propiedades_del_edificio;
    if (!terrenoFirme(coords) || hayColisiones(coords, dimension_x, dimension_y)) {
        return false;
    }
    edificar(coords, propiedades_del_edificio);
    return true;
}

void Mapa::imprimir() {
    for (int i = 0; i < this->alto; i++){
        for (int j = 0; j < this->ancho; j++){
            std::cout << this->mapa[i][j];
        }
        std::cout << std::endl;
    }
}

std::vector< Coordenadas > Mapa::ver_colisiones() {
    return this->colisiones;
}

void Mapa::modificar_terreno(uint16_t pos_x, uint16_t pos_y, const char terreno) {
    this->mapa[pos_y][pos_x] = terreno;
}

void Mapa::demoler_edificio(uint8_t edificio, uint16_t pos_x, uint16_t pos_y) {
    int dimension_x = 0, dimension_y = 0;
    char tipo_edificio = 0;
    std::tie(dimension_x, dimension_y, tipo_edificio) = propiedadesEdificio(edificio);
    for (int i = pos_y - DISTANCIA_EDIFICIOS; i < (pos_y + dimension_y + DISTANCIA_EDIFICIOS); i++){
        for (int j = pos_x - DISTANCIA_EDIFICIOS; j < (pos_x + dimension_x + DISTANCIA_EDIFICIOS); j++){
            if (0 > j || j >= this->ancho || 0 > i || i >= this->alto || this->mapa[i][j] != tipo_edificio){
                continue;
            }
            this->mapa[i][j] = 'R';                
        }
    }
}

std::stack<Coordenadas> Mapa::obtener_camino(const Coordenadas& origen,
        const Coordenadas& destino, std::vector<char>& terrenos_no_accesibles,
        const std::unordered_map<char, float>& penalizacion_terreno) const {
    return this->camino.obtener_camino(origen, destino, terrenos_no_accesibles, penalizacion_terreno);
}

Mapa::Mapa(Mapa&& otro) : ancho(otro.ancho), alto(otro.alto), mapa(otro.mapa), camino(mapa) {
    otro.mapa = std::vector< std::vector<char> > (otro.alto);
}

Mapa& Mapa::operator=(Mapa&& mapa) {
    // Caso de querer moverse asi mismo.
    if (this == &mapa){
        return *this;
    }

    // Transfiero los recursos del otro mapa al nuestro.
    this->ancho = mapa.ancho;
    this->alto = mapa.alto;
    this->mapa = mapa.mapa;
    this->camino = Camino(this->mapa);

    // Limpio el otro mapa.
    mapa.alto = -1;
    mapa.ancho = -1;
    mapa.mapa = std::vector< std::vector<char> > (mapa.alto);
    
    return *this;
}

