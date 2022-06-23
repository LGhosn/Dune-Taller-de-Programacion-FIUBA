#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include <list>
#include <tuple>
#include <memory>
#include <stack>

#include "../../../src_common/common_coords.h"
#include "server_camino.h"

class Mapa {
private:
    int ancho;
    int alto;
    std::vector< std::vector<char> > mapa;
    std::vector< Coordenadas > colisiones;
    Camino camino;
    bool primera_construccion = true;
    std::list<Coordenadas> coords_centros;

    /*
     * Dado un edificio, devuelve la cantidad de casillas que ocupa y el tipo de edificio que es 
     * @param edificio: edificio a construir
    */
    std::tuple<int, int, char> propiedadesEdificio(uint8_t edificio);

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
    void edificar(const Coordenadas& coords, std::tuple<int, int, char> propiedades_edif);

    /*
     * @brief Verifica que el terreno sea lo suficiente resistente para las construcciones
     * @param pos_x: posicion en x de donde se quiere colocar el edificio
     * @param pos_y: posicion en y de donde se quiere colocar el edificio 
    */
    bool terrenoFirme(const Coordenadas& coords);

    bool construccionLejana(const Coordenadas &coords);

    void cargarCentrosDeConstruccion(YAML::Node& mapa_config);

public:
    /*
     * Construye un mapa de ancho x alto
     *@param ancho Ancho del mapa
     *@param alto Alto del mapa
    */
    Mapa(const std::string& nombre_mapa);

    //Hago este typedef para no superar los 100 caracteres y que no haya problemas con cpplint
    typedef std::tuple<uint8_t, uint16_t, uint16_t> comando_t;
    /*
     * @brief Coloca un edificio en el mapa en caso de ser posible
     * @param comando una tupla conformada por el edificio(uint8_t), la coordenada x(uint16_t) y la coordenada y(uint16_t)
     * @return un booleano indicando si se pudo construir o no.
     */
    bool construirEdificio(uint16_t id_jugador, uint8_t tipo, const Coordenadas& coords);

    /*
     * Construye un centro de construccion para el jugador con la id dada, en
     * las coordenadas pasadas por parametro.
    */
    void construirCentro(uint16_t id_jugador, const Coordenadas& coords);

    /*
     * Imprime el mapa en consola
    */
    void imprimir();

    std::list<Coordenadas> obtenerCoordsCentros() const;

    std::vector< Coordenadas > ver_colisiones();

    void modificar_terreno(uint16_t pos_x, uint16_t pos_y, char terreno);

    void demoler_edificio(uint8_t edificio, uint16_t pos_x, uint16_t pos_y);

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
    std::stack<Coordenadas> obtener_camino(const Coordenadas& origen,
        const Coordenadas& destino, std::vector<char>& terrenos_no_accesibles,
        const std::unordered_map<char, float>& penalizacion_terreno) const;


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
