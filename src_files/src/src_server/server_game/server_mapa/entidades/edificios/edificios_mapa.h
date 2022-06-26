#ifndef SERVER_EDIFICIOS_H
#define SERVER_EDIFICIOS_H

#include "yaml-cpp/yaml.h"
#include "../entidades_mapa.h"

class Edificio : public Entidades {
protected:
    int dimension_x;
    int dimension_y;
    uint16_t id_jugador;
    uint16_t hp;

public:
    Edificio() = default;
    virtual int obtenerDimensionX();
    virtual int obtenerDimensionY();
    virtual char obtenerTipo();
    virtual ~Edificio();
};

class Silo: public Edificio {
public:
    Silo(YAML::Node& edificio_config, uint16_t id_jugador);
    ~Silo();
};

class FabricaLigera: public Edificio {
public:
    FabricaLigera(YAML::Node& edificio_config, uint16_t id_jugador);
    ~FabricaLigera();
};

class FabricaPesada: public Edificio {
public:
    FabricaPesada(YAML::Node& edificio_config, uint16_t id_jugador);
    ~FabricaPesada();
};

class Palacio: public Edificio {
public:
    Palacio(YAML::Node& edificio_config, uint16_t id_jugador);
    ~Palacio();
};

class Refineria: public Edificio {
public:
    Refineria(YAML::Node& edificio_config, uint16_t id_jugador);
    ~Refineria();
};

class Cuartel: public Edificio {
public:
    Cuartel(YAML::Node& edificio_config, uint16_t id_jugador);
    ~Cuartel();
};

class TrampaDeAire: public Edificio {
public:
    TrampaDeAire(YAML::Node& edificio_config, uint16_t id_jugador);
    ~TrampaDeAire();
};

class CentroDeConstruccion: public Edificio {
public:
    CentroDeConstruccion(YAML::Node& edificio_config, uint16_t id_jugador);
    ~CentroDeConstruccion();
};

#endif //SERVER_EDIFICIOS_H
