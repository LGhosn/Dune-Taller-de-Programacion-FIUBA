#ifndef SERVER_EDIFICIOS_H
#define SERVER_EDIFICIOS_H

#include "yaml-cpp/yaml.h"
#include "../entidades_mapa.h"

class Edificio : public Entidades {
protected:
    int dimension_x;
    int dimension_y;
    uint8_t id_jugador;
    uint8_t tipo_entidad;


public:
    Edificio() = default;
    virtual int obtenerDimensionX();
    virtual int obtenerDimensionY();
    virtual char obtenerIdentificador();
    virtual uint8_t obtenerIdJugador();
    virtual char obtenerTipoDeEntidad();
    virtual ~Edificio() = default;

    Edificio &operator=(const Edificio &edificio) = delete;
    Edificio(const Edificio &edificio) = delete;
    Edificio &operator=(Edificio &&edificio);
    Edificio(Edificio &&edificio); 
};

class Silo: public Edificio {
public:
    Silo(YAML::Node& edificio_config, uint8_t id_jugador);
    virtual ~Silo() = default;
};

class FabricaLigera: public Edificio {
public:
    FabricaLigera(YAML::Node& edificio_config, uint8_t id_jugador);
    virtual ~FabricaLigera() = default;
};

class FabricaPesada: public Edificio {
public:
    FabricaPesada(YAML::Node& edificio_config, uint8_t id_jugador);
    virtual ~FabricaPesada() = default;
};

class Palacio: public Edificio {
public:
    Palacio(YAML::Node& edificio_config, uint8_t id_jugador);
    virtual ~Palacio() = default;
};

class Refineria: public Edificio {
public:
    Refineria(YAML::Node& edificio_config, uint8_t id_jugador);
    virtual ~Refineria() = default;
};

class Cuartel: public Edificio {
public:
    Cuartel(YAML::Node& edificio_config, uint8_t id_jugador);
    virtual ~Cuartel() = default;
};

class TrampaDeAire: public Edificio {
public:
    TrampaDeAire(YAML::Node& edificio_config, uint8_t id_jugador);
    virtual ~TrampaDeAire() = default;
};

class CentroDeConstruccion: public Edificio {
public:
    CentroDeConstruccion(YAML::Node& edificio_config, uint8_t id_jugador);
    virtual ~CentroDeConstruccion() = default;
};

#endif //SERVER_EDIFICIOS_H
