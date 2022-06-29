#include "terrenos_mapa.h"
#include <iostream>

#define ROCA 'R'
#define CIMA 'I'
#define ARENA 'A'
#define DUNA 'U'
#define PRECIPICIO 'P'


/* ******************************************************************
 *                        TERRENOS
 * *****************************************************************/
char Terrenos::obtenerIdentificador() {
    return this->tipo;
}

char Terrenos::obtenerTipoDeEntidad() {
    return this->tipo_entidad;
}

uint16_t Terrenos::obtenerIdJugador() {
    return this->id_jugador;
}

/* ******************************************************************
 *                        ARENA
 * *****************************************************************/
Arena::Arena() {
    this->tipo = ARENA;
    this->tipo_entidad = 'T';
}

/* ******************************************************************
 *                        DUNA
 * *****************************************************************/
Duna::Duna() {
    this->tipo = DUNA;
    this->tipo_entidad = 'T';
}

/* ******************************************************************
 *                        CIMA
 * *****************************************************************/
Cima::Cima() {
    this->tipo = CIMA;
    this->tipo_entidad = 'T';
}

/* ******************************************************************
 *                        ROCA
 * *****************************************************************/
Roca::Roca() {
    this->tipo = ROCA;
    this->tipo_entidad = 'T';
}

/* ******************************************************************
 *                        PRECIPICIO
 * *****************************************************************/
Precipicio::Precipicio() {
    this->tipo = PRECIPICIO;
    this->tipo_entidad = 'T';
}
