#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include <tuple>
#include <memory>

#include "common_coords.h"

class Mapa {
private:
    int ancho;
    int alto;
    std::vector< std::vector<char> > mapa;
    std::vector< Coordenadas > colisiones;

    /*
     * Dado un edificio, devuelve la cantidad de casillas que ocupa y el tipo de edificio que es 
     * @param edificio: edificio a construir
    */
    std::tuple<int, int, char> propiedades_edificio(uint8_t edificio);

    /*
     * Verifica que no haya colisiones con el edificio a construir, si las hay las agrega a la lista de colisiones
     * @param pos_x: posicion en x de donde se quiere colocar el edificio
     * @param pos_y: posicion en y de donde se quiere colocar el edificio 
     * @param dimension_x: dimension en x del edificio
     * @param dimension_y: dimension en y del edificio
    */
    bool hay_colisiones(uint16_t pos_x, uint16_t pos_y, int dimension_x, int dimension_y);

    /*
     * Edifica el edificio en el mapa en caso de ser posible
     * @param pos_x: posicion en x de donde se quiere colocar el edificio
     * @param pos_y: posicion en y de donde se quiere colocar el edificio 
     * @param propiedades_edif: propiedades del edificio a construir <dimension_x, dimension_y, tipo_edificio>
    */
    void edificar(uint16_t pos_x, uint16_t pos_y, std::tuple<int, int, char> propiedades_edif);

    /*
     * @brief Verifica que el terreno sea lo suficiente resistente para las construcciones
     * @param pos_x: posicion en x de donde se quiere colocar el edificio
     * @param pos_y: posicion en y de donde se quiere colocar el edificio 
    */
    bool terreno_firme(uint16_t pos_x, uint16_t pos_y);


public:
    /*
     * Construye un mapa de ancho x alto
     *@param ancho Ancho del mapa
     *@param alto Alto del mapa
    */
    Mapa(int ancho, int alto);

    //Hago este typedef para no superar los 100 caracteres y que no haya problemas con cpplint
    typedef std::tuple<uint8_t, uint16_t, uint16_t> comando_t;
    /*
     * @brief Coloca un edificio en el mapa en caso de ser posible
     * @param comando una tupla conformada por el edificio(uint8_t), la coordenada x(uint16_t) y la coordenada y(uint16_t)
     * @return un booleano indicando si se pudo construir o no.
     */
    bool construir_edificio(comando_t comando);

    /*
     * Imprime el mapa en consola
    */
    void imprimir();

    std::vector< Coordenadas > ver_colisiones();

    void modificar_terreno(uint16_t pos_x, uint16_t pos_y, char terreno);


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
