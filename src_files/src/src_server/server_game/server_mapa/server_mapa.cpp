#include "server_mapa.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <typeinfo>
#include <iterator>
#include <cstdlib>

#define DISTANCIA_EDIFICIOS 5
#define CENTRO 0
#define CUARTEL 1
#define FABRICA_LIGERA 2
#define FABRICA_PESADA 3
#define PALACIO 4
#define REFINERIA 5
#define SILO 6
#define TRAMPA_DE_AIRE 7
#define ROCA 5
#define CIMA 1
#define ARENA 0
#define DUNA 2
#define PRECIPICIO 4
#define ESPECIA 3

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

void Mapa::edificar(const Coordenadas& coords, std::unique_ptr<Edificio>& edificio, uint8_t id_jugador) {
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
            if (entidad->obtenerTipoDeEntidad() == 'T' && entidad->obtenerIdentificador() != ROCA){
                return false;
            }
        }
    }
    return true;
}

bool Mapa::construccionLejana(const Coordenadas& coords, uint8_t id_jugador) {
    for (int i = (coords.y - DISTANCIA_EDIFICIOS); i < (coords.y + DISTANCIA_EDIFICIOS); i++){
        if (i < 0 || i >= this->alto) continue;

        for (int j = (coords.x - DISTANCIA_EDIFICIOS); j < (coords.x + DISTANCIA_EDIFICIOS); j++){
            if (0 > j || j >= this->ancho) continue;
            std::unique_ptr<Entidades>& entidad = this->mapa[i][j];

            char tipo_entidad = entidad->obtenerTipoDeEntidad();
            if (tipo_entidad == 'E'){
                uint8_t id_actual_jugador = entidad->obtenerIdJugador();
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

std::unique_ptr<Entidades> Mapa::clasificarEdificio(char tipo_edificio, YAML::Node& edificio_config, uint8_t id_jugador) {
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

std::unique_ptr<Entidades> Mapa::clasificarTerreno(int tipo) {
    switch (tipo) {
        case ROCA:
            return std::unique_ptr<Entidades>(new Roca());
        case ARENA:
            return std::unique_ptr<Entidades>(new Arena());
        case CIMA:
            return std::unique_ptr<Entidades>(new Cima());
        case DUNA:
            return std::unique_ptr<Entidades>(new Duna());
        case ESPECIA:
            return std::unique_ptr<Entidades>(new Arena()); // Placeholder
        case PRECIPICIO:
            return std::unique_ptr<Entidades>(new Precipicio());
        default:
            std::cout << "Tipo: " << tipo << std::endl;
            throw std::runtime_error("Mapa: tipo de terreno no reconocido");
    }
}

bool Mapa::esCoordenadaValida(const Coordenadas& posicion) {
    return this->mapa[posicion.y][posicion.x]->obtenerTipoDeEntidad() == 'T';
}

Coordenadas Mapa::coordenadaLibreMasCercana(Coordenadas& posicion) {
    Coordenadas coordenada_libre(0,0);
    for (int i = posicion.y; i > (posicion.y - DISTANCIA_EDIFICIOS); i--){
        if (i < 0 || i >= this->alto) continue;
        for (int j = posicion.x; j > (posicion.x - DISTANCIA_EDIFICIOS); j--){
            if (0 > j || j >= this->ancho) continue;

            if (this->mapa[i][j]->obtenerTipoDeEntidad() == 'T'){
                coordenada_libre.x = j;
                coordenada_libre.y = i;
                return coordenada_libre;
            }
        }
    }
    for (int i = posicion.y; i < (posicion.y + DISTANCIA_EDIFICIOS); i++){
        if (i < 0 || i >= this->alto) continue;
        for (int j = posicion.x; j < (posicion.x + DISTANCIA_EDIFICIOS); j++){
            if (0 > j || j >= this->ancho) continue;

            if (this->mapa[i][j]->obtenerTipoDeEntidad() == 'T'){
                coordenada_libre.x = j;
                coordenada_libre.y = i;
                return coordenada_libre;
            }
        }
    }
    return coordenada_libre;
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
            this->mapa[i][j] = clasificarTerreno(mapa_config["TiposTerrenos"][i][j].as<int>());
        }
    }
    cargarCentrosDeConstruccion(mapa_config);
    this->camino.start(&this->mapa);
}

bool Mapa::construirEdificio(uint8_t id_jugador, uint8_t tipo, const Coordenadas& coords) {
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

void Mapa::construirCentro(uint8_t id_jugador, const Coordenadas& coords) {
    std::unique_ptr<Entidades> entidad = std::unique_ptr<Entidades>(new CentroDeConstruccion(this->edificio_config, id_jugador));
    std::unique_ptr<Edificio>& centro = ((std::unique_ptr<Edificio>&)entidad);
    int dimension_x = centro->obtenerDimensionX();
    int dimension_y = centro->obtenerDimensionY();
    if (!terrenoFirme(coords, dimension_x, dimension_y) || hayColisiones(coords, dimension_x, dimension_y)) {
        throw std::runtime_error("Mapa: Coordenadas del centro invalidas");
    }
    edificar(coords, centro, id_jugador);
}

void Mapa::moverUnidad(const Coordenadas& coords_actual, const Coordenadas& coords_nueva) {
    std::unique_ptr<Entidades>& entidad = this->mapa[coords_actual.y][coords_actual.x];
    if (!entidad) {
        throw std::runtime_error("No se encontro la unidad en la posicion actual");
    }
    if (hayColisiones(coords_nueva, 1, 1)) {
        throw std::runtime_error("Coordenadas de movimiento invalidas");
    }
    std::unique_ptr<UnidadesMapa>& unidad = (std::unique_ptr<UnidadesMapa>&)entidad;
    uint8_t id_jug = unidad->obtenerIdJugador();
    uint8_t tipo = unidad->obtenerTipoDeUnidad();
    uint8_t id_unidad = unidad->obtenerIdUnidad();
    char terreno = unidad->obtenerTerrenoQueEstaParada();

    auto it = unidades_en_mapa.find(id_unidad);
    if (it != unidades_en_mapa.end()) {
        it->second = coords_nueva;
    }
    this->mapa[coords_actual.y][coords_actual.x] = clasificarTerreno(terreno);

    char terreno_nuevo = this->mapa[coords_nueva.y][coords_nueva.x]->obtenerIdentificador();
    this->mapa[coords_nueva.y][coords_nueva.x] = std::unique_ptr<Entidades>(new UnidadesMapa(terreno_nuevo, id_jug, tipo, id_unidad));
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

Coordenadas Mapa::obtenerCoordenadasSpawn(uint8_t id_jugador) {
    for (auto& coordenada : this->coords_centros) {
        std::unique_ptr<Entidades>& entidad = this->mapa[coordenada.y][coordenada.x];
        if (entidad->obtenerIdJugador() == id_jugador) {
            return coordenadaLibreMasCercana(coordenada);
        }
    }
    throw std::runtime_error("No se encontro spawn para el jugador");
}

void Mapa::spawnearUnidad(uint8_t id_jugador, uint8_t tipo_unidad, uint8_t id_uni, Coordenadas coords_spawn){
    std::unique_ptr<Entidades>& entidad = this->mapa[coords_spawn.y][coords_spawn.x];
    char terreno = entidad->obtenerIdentificador();
    this->mapa[coords_spawn.y][coords_spawn.x] = std::unique_ptr<Entidades>(new UnidadesMapa(terreno, tipo_unidad, id_jugador, id_uni));
    unidades_en_mapa.emplace(id_uni, coords_spawn);
}

bool Mapa::obtenerUnidadRandomSobreArena(uint8_t *id_victima) {
    uint8_t cont = 0;
    uint8_t cant_unidades = unidades_en_mapa.size();
    while (cont != cant_unidades) {
        auto it = unidades_en_mapa.begin();
        std::advance(it, rand() % cant_unidades);
        Coordenadas& coords = it->second;
        std::unique_ptr<Entidades>& entidad = this->mapa[coords.y][coords.x];
        std::unique_ptr<UnidadesMapa>& unidad = (std::unique_ptr<UnidadesMapa>&)entidad;
        char terreno = unidad->obtenerTerrenoQueEstaParada();
        if (terreno == 'A') {
            *id_victima = it->first;
            return true;
        }
        cont++;
    }
    return false;
}

char Mapa::obtenerTipoDeTerreno(Coordenadas& coords) {
    std::unique_ptr<Entidades>& entidad = this->mapa[coords.y][coords.x];
    if (entidad->obtenerIdentificador() == 'U') {
        std::unique_ptr<UnidadesMapa>& unidad = ((std::unique_ptr<UnidadesMapa>&)entidad);
        return unidad->obtenerTerrenoQueEstaParada();
    }
    return entidad->obtenerIdentificador();
}

uint8_t Mapa::obtenerDireccion(const Coordenadas& origen, const Coordenadas& destino) {
    if (origen.x == destino.x && origen.y > destino.y) {
        return ARRIBA_UNIDAD;
    } else if (origen.x == destino.x && origen.y < destino.y) {
        return ABAJO_UNIDAD;
    } else if (origen.x < destino.x && origen.y == destino.y) {
        return DERECHA_UNIDAD;
    } else if (origen.x > destino.x && origen.y == destino.y) {
        return IZQUIERDA_UNIDAD;
    } else if (origen.x > destino.x && origen.y > destino.y) {
        return ARRIBA_IZQ_UNIDAD;
    } else if (origen.x < destino.x && origen.y > destino.y) {
        return ARRIBA_DER_UNIDAD;
    } else if (origen.x > destino.x && origen.y < destino.y) {
        return ABAJO_IZQ_UNIDAD;
    } else if (origen.x < destino.x && origen.y < destino.y) {
        return ABAJO_DER_UNIDAD;
    } else {
        throw std::runtime_error("Mapa: No cambio de posicion");
    }
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

