#ifndef ARMA_H
#define ARMA_H

#include <memory>
#include <cstdint>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "../unidades.h"

class Unidad;

class Arma {
protected:
    uint8_t dmg;
    uint16_t frecuencia_disparo;
    std::vector<uint8_t> bonificaciones;
public:
    Arma(uint8_t dmg, uint16_t frecuencia_disparo, std::vector<uint8_t> bonificaciones);
    virtual void disparar(std::shared_ptr<Unidad> unidad_a_disparar);
};

#endif