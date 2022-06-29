#ifndef SERVER_UNIDADES_H
#define SERVER_UNIDADES_H

#include <vector>
#include <unordered_map>

#include "../../server_DTO/dto_unidad_info.h"
#include "../server_jugador/jugador.h"
#include "../server_mapa/server_mapa.h"
#include "../../server_DTO/dto_unidad_info.h"

class Unidad {
protected:
    uint8_t id;
    Coordenadas& origen;
    Jugador& duenio;
    std::vector<char>& terrenos_no_accesibles;
    const std::unordered_map<char, float>& penalizacion_terreno;
    int16_t velocidad;
    int16_t vida;
    Mapa &mapa;
    bool moviendose = false;
    std::stack<Coordenadas> camino;
    long ticks_para_sig_movimiento = 0;
    long ticks_restantes = 0;

    virtual void setTicksParaSigMovimiento() = 0;
    virtual void enviarMovimientoAClientes(long tiempo, char direccion) = 0;

public:
    Unidad();
    virtual Jugador& obtenerJugador();
    virtual UnidadInfoDTO obtenerInfo(const Coordenadas& destino) const;
    virtual void atacar(Unidad& unidad) = 0;
    virtual void empezarMovimiento(const Coordenadas& destino) = 0;
    virtual void update(long ticks_transcurridos, long *tiempo, char *direccion) = 0;
    // virtual void atacar(Edificio& edificio) = 0;
    virtual ~Unidad() = default;
};

class Tanque : public Unidad {
private:
    virtual void setTicksParaSigMovimiento();
    virtual void enviarMovimientoAClientes(long tiempo, char direccion);

public:
    Tanque(uint8_t id, Jugador& duenio, Mapa& mapa);
    virtual void atacar(Unidad& unidad);
    virtual void empezarMovimiento(const Coordenadas& destino);
    virtual void update(long ticks_transcurridos, long *tiempo, char *direccion);
    virtual ~Tanque() = default;
};

#endif // SERVER_UNIDADES_H
