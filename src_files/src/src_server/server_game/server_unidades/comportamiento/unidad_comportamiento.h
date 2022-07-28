#ifndef SERVER_UNIDAD_COMPORTAMIENTO_H
#define SERVER_UNIDAD_COMPORTAMIENTO_H

#include <cstdint>
#include <memory>
#include <stack>
#include <vector>
#include "../../entidad_server.h"
#include "../../server_mapa/server_mapa.h"
#include "../unidades.h"
#include "../server_armas/arma.h"

class Unidad;

class UnidadComportamiento {
protected:
    Unidad* unidad;
    std::shared_ptr<EntidadServer> entidad_a_atacar;
    std::stack<Coordenadas> camino;
    long ticks_para_sig_movimiento = 0;
    long ticks_restantes = 0;

    void encontrarUnidadAAtacarEnRango();

    bool estaEnRango(const Coordenadas& coords) const;

    void setearNuevoCamino(const Coordenadas& destino);

    void setearNuevoMovimiento();
    uint16_t obtenerTiempoParaMoverse();
    void setTicksParaSigMovimiento(uint16_t tiempo_para_moverse);

    void moverUnidad(Coordenadas& destino);
public:
    UnidadComportamiento(Unidad* unidad);

    /*
     * Realiza el comando de atacar dependiendo del comportamiento actual de la unidad.
     * Puede modificar el comportamiento de la unidad.
    */
    virtual void atacar(std::shared_ptr<EntidadServer> entidad_a_atacar) = 0;

    /*
     * Realiza el comando de mover dependiendo del comportamiento actual de la unidad.
     * Puede modificar el comportamiento de la unidad.
    */
    virtual void moverA(const Coordenadas& destino) = 0;

    virtual void update(long ticks_transcurridos) = 0;
};

#endif // SERVER_UNIDAD_COMPORTAMIENTO_H
