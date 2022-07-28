#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include <list>
#include <memory>
#include <stack>
#include <algorithm>
#include <sstream>
#include <unordered_map>


#include "../../../src_common/common_coords.h"
#include "server_camino.h"
#include "entidades/edificios/edificios_mapa.h"
#include "entidades/terrenos/terrenos_mapa.h"
#include "entidades/unidades/unidades_mapa.h"
#include "../../server_DTO/dto_unidad_info.h"

#define ABAJO_UNIDAD 0
#define ABAJO_IZQ_UNIDAD 1
#define IZQUIERDA_UNIDAD 2
#define ARRIBA_IZQ_UNIDAD 3
#define ARRIBA_UNIDAD 4
#define ARRIBA_DER_UNIDAD 5
#define DERECHA_UNIDAD 6
#define ABAJO_DER_UNIDAD 7

class Mapa {
private:
    int ancho;
    int alto;
    std::vector<std::vector<std::shared_ptr<Entidades> > > mapa;
    std::vector< Coordenadas > colisiones;
    Camino camino;
    std::list<Coordenadas> coords_centros;
    YAML::Node edificio_config;
    std::unordered_map <uint8_t, Coordenadas> unidades_en_mapa;
    std::unordered_map <uint8_t, Coordenadas > edificios_en_mapa;


    /*
     * Verifica que no haya colisiones con el edificio a construir, si las hay las agrega a la lista de colisiones
     * @param pos_x: posicion en x de donde se quiere colocar el edificio
     * @param pos_y: posicion en y de donde se quiere colocar el edificio 
     * @param dimension_x: dimension en x del edificio
     * @param dimension_y: dimension en y del edificio
    */
    bool hayColisiones(const Coordenadas& coords, int dimension_x, int dimension_y);

    /*
     * Edifica el edificio en el mapa en caso de ser posible
     * @param pos_x: posicion en x de donde se quiere colocar el edificio
     * @param pos_y: posicion en y de donde se quiere colocar el edificio 
     * @param propiedades_edif: propiedades del edificio a construir <dimension_x, dimension_y, tipo_edificio>
    */
    void edificar(const Coordenadas& coords, std::shared_ptr<Edificio>& edificio, uint8_t id_jugador, uint8_t id_edificio);

    /*
     * @brief Verifica que el terreno sea lo suficiente resistente para las construcciones
     * @param pos_x: posicion en x de donde se quiere colocar el edificio
     * @param pos_y: posicion en y de donde se quiere colocar el edificio 
    */
    bool terrenoFirme(const Coordenadas& coords, int dimension_x, int dimension_y);

    bool construccionLejana(const Coordenadas &coords, uint8_t id_jugador);

    void cargarCentrosDeConstruccion(YAML::Node& mapa_config);

    std::shared_ptr<Entidades> clasificarEdificio(char tipo, YAML::Node& edificio_config, uint8_t id_jugador);

    std::shared_ptr<Entidades> clasificarTerreno(int tipo);

    std::shared_ptr<Entidades> clasificarUnidad(uint8_t tipo_unidad, uint8_t id_jugador, uint8_t id_unidad);

    Coordenadas coordenadaLibreMasCercana(Coordenadas& coordenada);

    Coordenadas obtenerCoordenadasSpawn(uint8_t id_jugador);

public:
    /*
     * Construye un mapa de ancho x alto
     *@param ancho Ancho del mapa
     *@param alto Alto del mapa
    */
    Mapa(const std::string& nombre_mapa);

    /*
     * @brief Coloca un edificio en el mapa en caso de ser posible
     * @param comando una tupla conformada por el edificio(uint8_t), la coordenada x(uint16_t) y la coordenada y(uint16_t)
     * @return un booleano indicando si se pudo construir o no.
     */
    bool construirEdificio(uint8_t id_jugador, uint8_t tipo, const Coordenadas& coords, uint8_t id_edificio);

    /*
     * Construye un centro de construccion para el jugador con la id dada, en
     * las coordenadas pasadas por parametro.
    */
    void construirCentro(uint8_t id_jugador, const Coordenadas& coords, uint8_t id_edificio);

    /*
     * Imprime el mapa en consola
    */
    void imprimir();

    std::list<Coordenadas> obtenerCoordsCentros() const;

    std::vector< Coordenadas > ver_colisiones();

    void modificar_terreno(uint16_t pos_x, uint16_t pos_y, char terreno);

    void demoler_edificio(uint8_t edificio, uint16_t pos_x, uint16_t pos_y);

    void moverUnidad(const Coordenadas& desde, const Coordenadas& hasta);

    bool esCoordenadaValida(const Coordenadas& coords);

    /*
     * Encuentra una ubicacion en la que pueda spawnear la unidad, y la devuelve.
     * En caso de no encontrar un lugar en donde spawnear una unidad, lanza una excepcion.
    */
    Coordenadas spawnearUnidad(uint8_t id_jugador, uint8_t tipo_unidad, uint8_t id_uni);

    Coordenadas& obtenerCoordenadasRefinamiento();

    bool obtenerUnidadRandomSobreArena(uint8_t *id_victima);

    char obtenerTipoDeTerreno(Coordenadas& coords);

    uint8_t obtenerDireccion(const Coordenadas& coords_actual,const Coordenadas& coords_nueva);

    bool obtenerUnidadEnemigaEnRango(uint8_t id_jugador, uint8_t rango,  uint8_t& id_unidad, Coordenadas& coords);

    /*
     * @brief Crea el camino que lleve menos tiempo recorrer desde un origen indicado hasta un destino.
     * @param origen: origen del camino a crear.
     * @param destino: destino del camino a crear.
     * @param terrenos_no_accesibles: vector con los terrenos (en forma de char) por los que no se puede pasar.
     * @param penalizacion_terreno: diccionario con la penalizacion de terrenos.
     * @return vector de coordenadas con las posiciones del camino en orden, desde el origen (sin incluir) hasta el destino.
     * No hace falta incluir todos los terrenos en penalizacion_terreno.
     * En caso de que no pueda encontrar un camino, se lanzara una excepcion de tipo CaminoNoEncontradoException. Si las
     * coordenadas de origen y/o destino no son validas o estan en un terreno no accesible, lanzara una FueraDeRangoException.
    */
    std::stack<Coordenadas> obtenerCamino(UnidadInfoDTO& unidad_info) const;

    void eliminarUnidad(uint8_t id_unidad);
    void eliminarEdificio(uint8_t id_edificio);

    // Destructor del mapa
    ~Mapa() = default;

    /* 
     * Copiar y/o asignar un mapa que esta ligado a un servidor no tiene sentido
    */
    Mapa(const Mapa&) = delete;
    Mapa& operator=(const Mapa&) = delete;

    /*
     * Mapa es movible
    */
    Mapa(Mapa &&);
    Mapa &operator=(Mapa &&);
};

#endif
