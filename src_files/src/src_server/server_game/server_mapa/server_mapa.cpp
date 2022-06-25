#include <algorithm>
#include <iostream>
#include <sstream>

#include "yaml-cpp/yaml.h"
#include "server_mapa.h"

#define DISTANCIA_EDIFICIOS 5
#define CODIGO_CENTRO 0
#define CENTRO 'D'
#define CUARTEL 'C'
#define FABRICA_LIGERA 'F'
#define FABRICA_PESADA 'H'
#define PALACIO 'P'
#define REFINERIA 'R'
#define SILO 'S'
#define TRAMPA_DE_AIRE 'T'

enum dimensiones {
    una_dimension = 1,
    dos_dimensiones = 2,
    tres_dimension = 3,
    cuatro_dimension = 4
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
            tipo_edificio = CENTRO;
            break;
        case 1:
            dimension_x = dos_dimensiones;
            dimension_y = tres_dimension;
            tipo_edificio = CUARTEL;
            break;
        case 2:
            dimension_x = tres_dimension;
            dimension_y = tres_dimension;
            tipo_edificio = FABRICA_LIGERA;
            break;
        case 3:
            dimension_x = cuatro_dimension;
            dimension_y = cuatro_dimension;
            tipo_edificio = FABRICA_PESADA;
            break;
        case 4:
            dimension_x = tres_dimension;
            dimension_y = tres_dimension;
            tipo_edificio = PALACIO;
            break;
        case 5:
            dimension_x = tres_dimension;
            dimension_y = tres_dimension;
            tipo_edificio = REFINERIA;
            break;
        case 6:
            dimension_x = una_dimension;
            dimension_y = una_dimension;
            tipo_edificio = SILO;
            break;
        case 7:
            dimension_x = tres_dimension;
            dimension_y = tres_dimension;
            tipo_edificio = TRAMPA_DE_AIRE;
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
            if (this->mapa[i][j] == TRAMPA_DE_AIRE || this->mapa[i][j] == CUARTEL || this->mapa[i][j] == SILO){
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

bool Mapa::construccionLejana(const Coordenadas& coords) {
    if (this->primera_construccion){
        this->primera_construccion = false;
        return false;
    }
    for (int i = (coords.y - DISTANCIA_EDIFICIOS); i < (coords.y + DISTANCIA_EDIFICIOS); i++){
        if (i < 0 || i >= this->alto) continue;

        for (int j = (coords.x - DISTANCIA_EDIFICIOS); j < (coords.x + DISTANCIA_EDIFICIOS); j++){
            if (0 > j || j >= this->ancho) continue;
            if (this->mapa[i][j] == TRAMPA_DE_AIRE || this->mapa[i][j] == CUARTEL || this->mapa[i][j] == SILO){
                return false;
            }
        }
    }
    return true;
}

void Mapa::cargarCentrosDeConstruccion(YAML::Node& mapa_config) {
    const YAML::Node& centros = mapa_config["CentrosDeConstruccion"];
    for (YAML::const_iterator it = centros.begin(); it != centros.end(); it++) {
        const YAML::Node& centro = *it;
        uint16_t x = centro["x"].as<uint16_t>();
        uint16_t y = centro["y"].as<uint16_t>();
        coords_centros.emplace_back(x, y);
    }
}

std::unique_ptr<Edificio> Mapa::clasificarEdificio(char tipo_edificio, YAML::Node& edificio_config) {
    switch (tipo_edificio) {
        case CENTRO:
            return std::unique_ptr<Edificio>(new CentroDeConstruccion(edificio_config));
        case CUARTEL:
            return std::unique_ptr<Edificio>(new Cuartel(edificio_config));
        case FABRICA_LIGERA:
            return std::unique_ptr<Edificio>(new FabricaLigera(edificio_config));
        case FABRICA_PESADA:
            return std::unique_ptr<Edificio>(new FabricaPesada(edificio_config));
        case PALACIO:
            return std::unique_ptr<Edificio>(new Palacio(edificio_config));
        case REFINERIA:
            return std::unique_ptr<Edificio>(new Refineria(edificio_config));
        case SILO:
            return std::unique_ptr<Edificio>(new Silo(edificio_config));
        case TRAMPA_DE_AIRE:
            return std::unique_ptr<Edificio>(new TrampaDeAire(edificio_config));
        default:
            return std::unique_ptr<Edificio>(new EdificioNulo());
    }
}


/* ******************************************************************
 *                        PUBLICAS
 * *****************************************************************/

Mapa::Mapa(const std::string& nombre_mapa) : camino(this->mapa) {
    std::stringstream ruta_mapa;
    ruta_mapa << RESOURCE_PATH << "/maps/" << nombre_mapa << ".yaml";
    YAML::Node mapa_config = YAML::LoadFile(ruta_mapa.str());

    std::stringstream ruta_dimensiones;
    ruta_dimensiones << RESOURCE_PATH << "/edificios/dimensiones.yaml";
    this->edificio_config = YAML::LoadFile(ruta_dimensiones.str());

    this->ancho = mapa_config["Ancho"].as<int>();
    this->alto = mapa_config["Alto"].as<int>();
    this->mapa = std::vector<std::vector<char>>(this->alto, std::vector<char>(this->ancho));
    for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++){
            std::unique_ptr<Edificio> edi = clasificarEdificio(mapa_config["TiposTerrenos"][i][j].as<char>(), edificio_config);
            // this->mapa[i][j] = edi; 
        }
    }
    cargarCentrosDeConstruccion(mapa_config);
    this->camino = this->mapa;      // TODO: ver
}

bool Mapa::  construirEdificio(uint16_t id_jugador, uint8_t tipo, const Coordenadas& coords) {
    // Cada vez que se intente construir un edificio, se limpia la lista de colisiones
    this->colisiones = std::vector< Coordenadas >();
    std::tuple<int, int, char> propiedades_del_edificio = propiedadesEdificio(tipo);

    int dimension_x = 0, dimension_y = 0;
    char tipo_edificio = 0;
    std::tie(dimension_x, dimension_y, tipo_edificio) = propiedades_del_edificio;

    std::cout << "Coords: " << coords.x << " " << coords.y << std::endl;
    
    if (!terrenoFirme(coords) || hayColisiones(coords, dimension_x, dimension_y) || construccionLejana(coords)) {
        return false;
    }
    edificar(coords, propiedades_del_edificio);
    return true;
}

void Mapa::construirCentro(uint16_t id_jugador, const Coordenadas& coords) {
    std::tuple<int, int, char> propiedades_del_edificio = propiedadesEdificio(CODIGO_CENTRO);
    int dimension_x = 0, dimension_y = 0;
    char tipo_edificio = 0;
    std::tie(dimension_x, dimension_y, tipo_edificio) = propiedades_del_edificio;
    if (!terrenoFirme(coords) || hayColisiones(coords, dimension_x, dimension_y)) {
        throw std::runtime_error("Coordenadas del centro invalidas");
    }
    edificar(coords, propiedades_del_edificio);
}

void Mapa::imprimir() {
    for (int i = 0; i < this->alto; i++){
        for (int j = 0; j < this->ancho; j++){
            std::cout << this->mapa[i][j];
        }
        std::cout << std::endl;
    }
}

std::list<Coordenadas> Mapa::obtenerCoordsCentros() const {
    return this->coords_centros;
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
    for (int i = pos_y; i < (pos_y + dimension_y); i++){
        for (int j = pos_x; j < (pos_x + dimension_x); j++){
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

