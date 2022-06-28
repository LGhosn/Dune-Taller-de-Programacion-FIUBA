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
#define ROCA 'R'
#define CIMA 'I'
#define ARENA 'A'
#define DUNA 'U'
#define PRECIPICIO 'P'

/* ******************************************************************
 *                        PRIVADAS
 * *****************************************************************/
template<typename Base, typename T>
inline bool instaciaDe(const T&) {
    return std::is_base_of<Base, T>::value;
}

bool Mapa::hayColisiones(const Coordenadas& coords, int dimension_x, int dimension_y) {
    bool colision = false;
    for (int i = coords.y; i < coords.y + dimension_y; i++){
        for (int j = coords.x; j < coords.x + dimension_x; j++){
            // Verifico que el edificio no se salga del mapa
            if (j >= this->ancho || i >= this->alto){
                // this->colisiones.push_back(Coordenadas(j, i));
                colision = true;
                continue;
            }
            std::unique_ptr<Entidades>& entidad = this->mapa[i][j];

            if (instaciaDe<Edificio>(entidad) || instaciaDe<Unidades>(entidad)){
                // this->colisiones.push_back(Coordenadas(j, i));
                colision = true;
            }
        }
    }
    return colision;
}

void Mapa::edificar(const Coordenadas& coords, std::unique_ptr<Edificio>& edificio) {
    int dimension_x = edificio->obtenerDimensionX();
    int dimension_y = edificio->obtenerDimensionY();
    if (this->colisiones.empty()){
        for (int i = coords.y; i < (coords.y + dimension_y); i++){
            for (int j = coords.x; j < (coords.x + dimension_x); j++){
                std::unique_ptr<Entidades>& entidad = this->mapa[i][j];
                if (0 > j || j >= this->ancho || 0 > i || i >= this->alto || entidad->obtenerTipo() != 'R'){
                    continue;
                }
                this->mapa[i][j] = std::move(edificio); //todo implementar move                
            }
        }
    }
}

bool Mapa::terrenoFirme(const Coordenadas& coords) {
    std::unique_ptr<Entidades>& entidad = this->mapa[coords.y][coords.x];
    char tipo = entidad->obtenerTipo();
    return tipo == ROCA;
}

bool Mapa::construccionLejana(const Coordenadas& coords, uint16_t id_jugador) {
    std::list<uint16_t>::iterator it;
    it = std::find(this->primera_construccion.begin(), this->primera_construccion.end(), id_jugador);
    if (it == this->primera_construccion.end()){
        return false;
    }
    this->primera_construccion.push_front(id_jugador);

    for (int i = (coords.y - DISTANCIA_EDIFICIOS); i < (coords.y + DISTANCIA_EDIFICIOS); i++){
        if (i < 0 || i >= this->alto) continue;

        for (int j = (coords.x - DISTANCIA_EDIFICIOS); j < (coords.x + DISTANCIA_EDIFICIOS); j++){
            if (0 > j || j >= this->ancho) continue;
            std::unique_ptr<Entidades>& entidad = this->mapa[i][j];

            if (instaciaDe<Edificio>(entidad)){
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

std::unique_ptr<Edificio> Mapa::clasificarEdificio(char tipo_edificio, YAML::Node& edificio_config, uint16_t id_jugador) {
    switch (tipo_edificio) {
        case CENTRO:
            return std::unique_ptr<Edificio>(new CentroDeConstruccion(edificio_config, id_jugador));
        case CUARTEL:
            return std::unique_ptr<Edificio>(new Cuartel(edificio_config, id_jugador));
        case FABRICA_LIGERA:
            return std::unique_ptr<Edificio>(new FabricaLigera(edificio_config, id_jugador));
        case FABRICA_PESADA:
            return std::unique_ptr<Edificio>(new FabricaPesada(edificio_config, id_jugador));
        case PALACIO:
            return std::unique_ptr<Edificio>(new Palacio(edificio_config, id_jugador));
        case REFINERIA:
            return std::unique_ptr<Edificio>(new Refineria(edificio_config, id_jugador));
        case SILO:
            return std::unique_ptr<Edificio>(new Silo(edificio_config, id_jugador));
        case TRAMPA_DE_AIRE:
            return std::unique_ptr<Edificio>(new TrampaDeAire(edificio_config, id_jugador));
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

    std::unique_ptr<Edificio> edif = clasificarEdificio(tipo, this->edificio_config, id_jugador);
    int dimension_x = edif->obtenerDimensionX();
    int dimension_y = edif->obtenerDimensionY();

    if (!terrenoFirme(coords) || hayColisiones(coords, dimension_x, dimension_y) || construccionLejana(coords, id_jugador)) {
        return false;
    }
    edificar(coords, edif);
    return true;
}

void Mapa::construirCentro(uint16_t id_jugador, const Coordenadas& coords) {
    std::unique_ptr<Edificio> centro = std::unique_ptr<Edificio>(new CentroDeConstruccion(this->edificio_config, id_jugador));
    int dimension_x = centro->obtenerDimensionX();
    int dimension_y = centro->obtenerDimensionY();
    if (!terrenoFirme(coords) || hayColisiones(coords, dimension_x, dimension_y)) {
        throw std::runtime_error("Coordenadas del centro invalidas");
    }
    edificar(coords, centro);
}

void Mapa::moverUnidad(uint16_t id_jugador, const Coordenadas& coords_actual, const Coordenadas& coords_nueva) {
    std::unique_ptr<Entidades>& entidad = this->mapa[coords_actual.y][coords_actual.x];
    if (!entidad) {
        throw std::runtime_error("No se encontro la unidad en la posicion actual");
    }
    if (hayColisiones(coords_nueva, 1, 1)) {
        throw std::runtime_error("Coordenadas de movimiento invalidas");
    }
    std::unique_ptr<Unidades>& unidad = (std::unique_ptr<Unidades>&)entidad;
    char terreno = unidad->obtenerTerrenoQueEstaParada();

    this->mapa[coords_actual.y][coords_actual.x] = clasificarTerreno(terreno);

    char terreno_nuevo = this->mapa[coords_nueva.y][coords_nueva.x]->obtenerTipo();
    this->mapa[coords_nueva.y][coords_nueva.x] = std::unique_ptr<Entidades>(new Unidades(terreno_nuevo));
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
    std::unique_ptr<Edificio> edif = clasificarEdificio(edificio, this->edificio_config, 0);
    int dimension_x = edif->obtenerDimensionX();
    int dimension_y = edif->obtenerDimensionY();
    for (int i = pos_y; i < (pos_y + dimension_y); i++){
        for (int j = pos_x; j < (pos_x + dimension_x); j++){
            std::unique_ptr<Entidades>& entidad = this->mapa[i][j];
            if (0 > j || j >= this->ancho || 0 > i || i >= this->alto || entidad->obtenerTipo() != edif->obtenerTipo()){
                continue;
            }
            this->mapa[i][j] = std::unique_ptr<Entidades>(new Roca());                
        }
    }
}

std::stack<Coordenadas> Mapa::obtener_camino(const Coordenadas& origen,
        const Coordenadas& destino, std::vector<char>& terrenos_no_accesibles,
        const std::unordered_map<char, float>& penalizacion_terreno) const {
    return this->camino.obtener_camino(origen, destino, terrenos_no_accesibles, penalizacion_terreno);
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

