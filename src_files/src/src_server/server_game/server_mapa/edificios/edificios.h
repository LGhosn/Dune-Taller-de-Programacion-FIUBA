#ifndef SERVER_EDIFICIOS_H
#define SERVER_EDIFICIOS_H

#include "yaml-cpp/yaml.h"

class Edificio {
protected:
    int dimension_x;
    int dimension_y;
    bool valido;
    uint16_t id_jugador;

public:
    Edificio() = default;
    virtual int obtenerDimensionX() = 0;
    virtual int obtenerDimensionY() = 0;
    virtual ~Edificio();
};

class Silo: public Edificio {
public:
    Silo(YAML::Node& edificio_config, uint16_t id_jugador);
    virtual int obtenerDimensionX();
    virtual int obtenerDimensionY();
    ~Silo();
};

class FabricaLigera: public Edificio {
public:
    FabricaLigera(YAML::Node& edificio_config, uint16_t id_jugador);
    virtual int obtenerDimensionX();
    virtual int obtenerDimensionY();
    ~FabricaLigera();
};

class FabricaPesada: public Edificio {
public:
    FabricaPesada(YAML::Node& edificio_config, uint16_t id_jugador);
    virtual int obtenerDimensionX();
    virtual int obtenerDimensionY();
    ~FabricaPesada();
};

class Palacio: public Edificio {
public:
    Palacio(YAML::Node& edificio_config, uint16_t id_jugador);
    virtual int obtenerDimensionX();
    virtual int obtenerDimensionY();
    ~Palacio();
};

class Refineria: public Edificio {
public:
    Refineria(YAML::Node& edificio_config, uint16_t id_jugador);
    virtual int obtenerDimensionX();
    virtual int obtenerDimensionY();
    ~Refineria();
};

class Cuartel: public Edificio {
public:
    Cuartel(YAML::Node& edificio_config, uint16_t id_jugador);
    virtual int obtenerDimensionX();
    virtual int obtenerDimensionY();
    ~Cuartel();
};

class TrampaDeAire: public Edificio {
public:
    TrampaDeAire(YAML::Node& edificio_config, uint16_t id_jugador);
    virtual int obtenerDimensionX();
    virtual int obtenerDimensionY();
    ~TrampaDeAire();
};

class CentroDeConstruccion: public Edificio {
public:
    CentroDeConstruccion(YAML::Node& edificio_config, uint16_t id_jugador);
    virtual int obtenerDimensionX();
    virtual int obtenerDimensionY();
    ~CentroDeConstruccion();
};

class EdificioNulo: public Edificio {
public:
    EdificioNulo();
    virtual int obtenerDimensionX();
    virtual int obtenerDimensionY();
    ~EdificioNulo();
};

#endif //SERVER_EDIFICIOS_H
