#ifndef ARMA_H
#define ARMA_H

#include <memory>
#include <cstdint>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "../../entidad_server.h"

class Unidad;

class Arma {
protected:
    uint8_t dmg;
    uint16_t ticks_frecuencia_disparo;
    uint16_t ticks_restantes;
    std::vector<uint8_t> bonificaciones;
    uint8_t id_unidad_portador;
    bool en_cooldown = false;

public:
    Arma(uint8_t dmg,
        uint16_t frecuencia_disparo,
        std::vector<uint8_t> bonificaciones,
        uint16_t ticks,
        uint8_t id_unidad_portador);
    
    virtual void disparar(std::shared_ptr<EntidadServer> entidad_a_disparar);
    virtual void update(long frames_transcurridos);
};

#endif