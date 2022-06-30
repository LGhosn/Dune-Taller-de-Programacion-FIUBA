#include "yaml-cpp/yaml.h"
#include "server_mapa.h"
#include <iostream>
#include <typeinfo>

#define DISTANCIA_EDIFICIOS 5
#define CENTRO 0
#define CUARTEL 1
#define FABRICA_LIGERA 2
#define FABRICA_PESADA 3
#define PALACIO 4
#define REFINERIA 5
#define SILO 6
#define TRAMPA_DE_AIRE 7
#define ROCA 'R'
#define CIMA 'I'
#define ARENA 'A'
#define DUNA 'U'
#define PRECIPICIO 'P'

/* ******************************************************************
 *                        PRIVADAS
 * *****************************************************************/

bool Mapa::hayColisiones(const Coordenadas& coords, int dimension_x, int dimension_y) {
    for (int i = coords.y; i < coords.y + dimension_y; i++){
        // Verifico que el edificio no se salga del mapa
        if (i < 0 || i >= this->alto) return true;

        for (int j = coords.x; j < coords.x + dimension_x; j++){
            // Verifico que el edificio no se salga del mapa
            if (j >= this->ancho || j < 0) return true;

            std::unique_ptr<Entidades>& entidad = this->mapa[i][j];

            char tipo_entidad = entidad->obtenerTipoDeEntidad();
            if (tipo_entidad == 'E' || tipo_entidad == 'U'){
                return true;
            }
        }
    }
    return false;
}

void Mapa::edificar(const Coordenadas& coords, std::unique_ptr<Edificio>& edificio, uint16_t id_jugador) {
    char tipo_edificio = edificio->obtenerIdentificador();
    int dimension_x = edificio->obtenerDimensionX();
    int dimension_y = edificio->obtenerDimensionY();
    for (int i = coords.y; i < (coords.y + dimension_y); i++){
        for (int j = coords.x; j < (coords.x + dimension_x); j++){
            this->mapa[i][j] = clasificarEdificio(tipo_edificio, this->edificio_config, id_jugador);
        }
    }
}

bool Mapa::terrenoFirme(const Coordenadas& coords, int dimension_x, int dimension_y) {
    for (int i = coords.y; i < (coords.y + dimension_y); i++){
        if (0 > i || i >= this->alto) return false;

        for (int j = coords.x; j < (coords.x + dimension_x); j++){
            if (0 > j || j >= this->ancho) return false;

            std::unique_ptr<Entidades>& entidad = this->mapa[i][j];
            if (entidad->obtenerIdentificador() != ROCA){
                return false;
            }
        }
    }
    return true;
}

bool Mapa::construccionLejana(const Coordenadas& coords, uint16_t id_jugador) {
    for (int i = (coords.y - DISTANCIA_EDIFICIOS); i < (coords.y + DISTANCIA_EDIFICIOS); i++){
        if (i < 0 || i >= this->alto) continue;

        for (int j = (coords.x - DISTANCIA_EDIFICIOS); j < (coords.x + DISTANCIA_EDIFICIOS); j++){
            if (0 > j || j >= this->ancho) continue;
            std::unique_ptr<Entidades>& entidad = this->mapa[i][j];

            char tipo_entidad = entidad->obtenerTipoDeEntidad();
            if (tipo_entidad == 'E'){
                uint16_t id_actual_jugador = entidad->obtenerIdJugador();
                if (id_actual_jugador == id_jugador){
                    return false;
                }
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

std::unique_ptr<Entidades> Mapa::clasificarEdificio(char tipo_edificio, YAML::Node& edificio_config, uint16_t id_jugador) {
    switch (tipo_edificio) {
        case CENTRO:
            return std::unique_ptr<Entidades>(new CentroDeConstruccion(edificio_config, id_jugador));
        case CUARTEL:
            return std::unique_ptr<Entidades>(new Cuartel(edificio_config, id_jugador));
        case FABRICA_LIGERA:
            return std::unique_ptr<Entidades>(new FabricaLigera(edificio_config, id_jugador));
        case FABRICA_PESADA:
            return std::unique_ptr<Entidades>(new FabricaPesada(edificio_config, id_jugador));
        case PALACIO:
            return std::unique_ptr<Entidades>(new Palacio(edificio_config, id_jugador));
        case REFINERIA:
            return std::unique_ptr<Entidades>(new Refineria(edificio_config, id_jugador));
        case SILO:
            return std::unique_ptr<Entidades>(new Silo(edificio_config, id_jugador));
        case TRAMPA_DE_AIRE:
            return std::unique_ptr<Entidades>(new TrampaDeAire(edificio_config, id_jugador));
        default:
            return nullptr;
    }
}

std::unique_ptr<Entidades> Mapa::clasificarTerreno(char tipo) {
    switch (tipo) {
        case ROCA:
            return std::unique_ptr<Entidades>(new Roca());
        case ARENA:
            return std::unique_ptr<Entidades>(new Arena());
        case CIMA:
            return std::unique_ptr<Entidades>(new Cima());
        case DUNA:
            return std::unique_ptr<Entidades>(new Duna());
        case PRECIPICIO:
            return std::unique_ptr<Entidades>(new Precipicio());
        default:
            return nullptr;
    }
}

char Mapa::obtenerDireccion(const Coordenadas& origen, const Coordenadas& destino) {
    char arriba = 'a', abajo = 'b', izquierda = 'i', derecha = 'd';
    if (origen.x == destino.x){
        if (origen.y < destino.y){
            return arriba;
        }
        return abajo;
    } else if (origen.y == destino.y){
        if (origen.x < destino.x){
            return derecha;
        }
        return izquierda;
    }
    return ' ';
}

bool Mapa::esCoordenadaValida(const Coordenadas& posicion) {
    return this->mapa[posicion.y][posicion.x]->obtenerTipoDeEntidad() == 'T';
}

/* ******************************************************************
 *                        PUBLICAS
 * *****************************************************************/

Mapa::Mapa(const std::string& nombre_mapa) {
    std::stringstream ruta_mapa;
    ruta_mapa << RESOURCE_PATH << "/maps/" << nombre_mapa << ".yaml";
    YAML::Node mapa_config = YAML::LoadFile(ruta_mapa.str());

    std::stringstream ruta_dimensiones;
    ruta_dimensiones << RESOURCE_PATH << "/edificios/dimensiones.yaml";
    this->edificio_config = YAML::LoadFile(ruta_dimensiones.str());

    this->ancho = mapa_config["Ancho"].as<int>();
    this->alto = mapa_config["Alto"].as<int>();
    // this->mapa = std::vector<std::vector<std::unique_ptr<Entidades> > >(this->alto, std::vector<std::unique_ptr<Entidades> >(this->ancho));
    this->mapa.resize(this->alto);
    for (int i = 0; i < this->alto; i++){
        this->mapa[i].resize(this->ancho);
    }
    for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++){
            this->mapa[i][j] = clasificarTerreno(mapa_config["TiposTerrenos"][i][j].as<char>());
        }
    }
    cargarCentrosDeConstruccion(mapa_config);
    this->camino.start(&this->mapa);
}

bool Mapa::construirEdificio(uint16_t id_jugador, uint8_t tipo, const Coordenadas& coords) {
    // Cada vez que se intente construir un edificio, se limpia la lista de colisiones
    this->colisiones = std::vector< Coordenadas >();

    std::unique_ptr<Entidades> entidad = clasificarEdificio(tipo, this->edificio_config, id_jugador);
    std::unique_ptr<Edificio>& edif = ((std::unique_ptr<Edificio>&)entidad);

    int dimension_x = edif->obtenerDimensionX();
    int dimension_y = edif->obtenerDimensionY();

    if (!terrenoFirme(coords, dimension_x, dimension_y) || hayColisiones(coords, dimension_x, dimension_y) || construccionLejana(coords, id_jugador)) {
        return false;
    }
    edificar(coords, edif, id_jugador);
    return true;
}

void Mapa::construirCentro(uint16_t id_jugador, const Coordenadas& coords) {
    std::unique_ptr<Entidades> entidad = std::unique_ptr<Entidades>(new CentroDeConstruccion(this->edificio_config, id_jugador));
    std::unique_ptr<Edificio>& centro = ((std::unique_ptr<Edificio>&)entidad);
    int dimension_x = centro->obtenerDimensionX();
    int dimension_y = centro->obtenerDimensionY();
    if (!terrenoFirme(coords, dimension_x, dimension_y) || hayColisiones(coords, dimension_x, dimension_y)) {
        throw std::runtime_error("Coordenadas del centro invalidas");
    }
    edificar(coords, centro, id_jugador);
}

char Mapa::moverUnidad(const Coordenadas& coords_actual, const Coordenadas& coords_nueva) {
    std::unique_ptr<Entidades>& entidad = this->mapa[coords_actual.y][coords_actual.x];
    if (!entidad) {
        throw std::runtime_error("No se encontro la unidad en la posicion actual");
    }
    if (hayColisiones(coords_nueva, 1, 1)) {
        throw std::runtime_error("Coordenadas de movimiento invalidas");
    }
    std::unique_ptr<UnidadesMapa>& unidad = (std::unique_ptr<UnidadesMapa>&)entidad;
    char terreno = unidad->obtenerTerrenoQueEstaParada();

    this->mapa[coords_actual.y][coords_actual.x] = clasificarTerreno(terreno);

    char terreno_nuevo = this->mapa[coords_nueva.y][coords_nueva.x]->obtenerIdentificador();
    this->mapa[coords_nueva.y][coords_nueva.x] = std::unique_ptr<Entidades>(new UnidadesMapa(terreno_nuevo));
    return obtenerDireccion(coords_actual, coords_nueva);
}

std::list<Coordenadas> Mapa::obtenerCoordsCentros() const {
    return this->coords_centros;
}

std::vector< Coordenadas > Mapa::ver_colisiones() {
    return this->colisiones;
}

void Mapa::modificar_terreno(uint16_t pos_x, uint16_t pos_y, const char terreno) {
    this->mapa[pos_x][pos_y] = clasificarTerreno(terreno);
}

void Mapa::demoler_edificio(uint8_t edificio, uint16_t pos_x, uint16_t pos_y) {
    std::unique_ptr<Entidades> entidad = clasificarEdificio(edificio, this->edificio_config, 0);
    std::unique_ptr<Edificio>& edif = ((std::unique_ptr<Edificio>&)entidad);

    int dimension_x = edif->obtenerDimensionX();
    int dimension_y = edif->obtenerDimensionY();
    for (int i = pos_y; i < (pos_y + dimension_y); i++){
        for (int j = pos_x; j < (pos_x + dimension_x); j++){
            std::unique_ptr<Entidades>& entidad = this->mapa[i][j];
            if (0 > j || j >= this->ancho || 0 > i || i >= this->alto || entidad->obtenerIdentificador() != edif->obtenerIdentificador()){
                continue;
            }
            this->mapa[i][j] = std::unique_ptr<Entidades>(new Roca());                
        }
    }
}

std::stack<Coordenadas> Mapa::obtenerCamino(UnidadInfoDTO& unidad_info) const {
    return this->camino.obtener_camino(unidad_info);
}

Mapa::Mapa(Mapa&& otro) : ancho(otro.ancho), alto(otro.alto), camino(otro.camino) {
    // otro.mapa = std::vector< std::vector<std::unique_ptr<Entidades> > > (otro.alto);
}

Mapa& Mapa::operator=(Mapa&& mapa) {
    // Caso de querer moverse asi mismo.
    if (this == &mapa){
        return *this;
    }

    // Transfiero los recursos del otro mapa al nuestro.
    this->ancho = mapa.ancho;
    this->alto = mapa.alto;
    // this->mapa = mapa.mapa;
    this->camino = Camino();

    // Limpio el otro mapa.
    mapa.alto = -1;
    mapa.ancho = -1;
    // mapa.mapa = std::vector< std::vector<std::unique_ptr<Entidades> > > (mapa.alto);
    
    return *this;
}

