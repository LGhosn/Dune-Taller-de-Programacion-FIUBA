#ifndef SERVER_UNIDADES_H
#define SERVER_UNIDADES_H

#define INFANTERIA 'I'
#define VEHICULO 'V'
#define DISTANCIA_A_MOVER 16

#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

#include "yaml-cpp/yaml.h"
#include "../../server_DTO/dto_unidad_info.h"
#include "../server_jugador/jugador.h"
#include "../server_mapa/server_mapa.h"

class Unidad {
protected:
    Jugador& duenio;
    Mapa& mapa;
    Coordenadas& origen;
    uint8_t id;
    bool moviendose = false;
    std::stack<Coordenadas> camino;
    long ticks_para_sig_movimiento = 0;
    long ticks_restantes = 0;
    char tipo_unidad;

    // Atributos
    std::vector<std::string> armas;
    uint8_t rango;
    int16_t velocidad;
    uint16_t tiempo_entrenamiento;
    int16_t vida;
    uint16_t costo;
    std::unordered_map<char, float> penalizacion_terreno;
    std::vector<char> terrenos_no_accesibles;

    virtual void setTicksParaSigMovimiento();

public:
    Unidad(Jugador& duenio, Mapa& mapa, Coordenadas origen);
    virtual uint8_t obtenerIdJugador();
    // virtual void atacar(Unidad& unidad) = 0;
    virtual void empezarMovimiento(const Coordenadas& destino);
    virtual void update(long ticks_transcurridos, long *tiempo, char *direccion);
    // virtual void atacar(Edificio& edificio) = 0;
    virtual ~Unidad() = default;
};

#endif // SERVER_UNIDADES_H
