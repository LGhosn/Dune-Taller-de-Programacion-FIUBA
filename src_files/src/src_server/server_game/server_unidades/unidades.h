#ifndef SERVER_UNIDADES_H
#define SERVER_UNIDADES_H

#include <vector>
#include <unordered_map>

#include "../../server_DTO/dto_unidad_info.h"
#include "../server_jugador/jugador.h"

class Unidad {
private:
    uint8_t id;
    const Coordenadas& origen;
    Jugador& duenio;
    std::vector<char>& terrenos_no_accesibles;
    const std::unordered_map<char, float>& penalizacion_terreno;

public:
    Unidad();
    Unidad(uint16_t id, uint16_t x, uint16_t y, Jugador& duenio);
    virtual Jugador& obtenerJugador();
    virtual void mover(uint16_t x, uint16_t y);
    virtual void atacar(Unidad& unidad);
    virtual UnidadInfoDTO obtenerInfo(const Coordenadas& destino) const;
    // virtual void atacar(Edificio& edificio) = 0;
    virtual ~Unidad() = default;
};

#endif // SERVER_UNIDADES_H
