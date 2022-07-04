#ifndef DTO_UNIDAD_INFO_H
#define DTO_UNIDAD_INFO_H

#include "../../src_common/common_coords.h"
#include <vector>
#include <unordered_map>

struct UnidadInfoDTO {
    const Coordenadas& origen;
    const Coordenadas& destino;
    std::vector<char>& terrenos_no_accesibles;
    const std::vector<float>& penalizacion_terreno;

    UnidadInfoDTO(const Coordenadas& origen, const Coordenadas& destino, std::vector<char>& terrenos_no_accesibles, const std::vector<float>& penalizacion_terreno) :
        origen(origen),
        destino(destino),
        terrenos_no_accesibles(terrenos_no_accesibles),
        penalizacion_terreno(penalizacion_terreno) {};
};

#endif // DTO_UNIDAD_INFO_H
