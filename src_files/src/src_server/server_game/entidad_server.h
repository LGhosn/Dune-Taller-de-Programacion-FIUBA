#ifndef ENTIDAD_SERVER_H
#define ENTIDAD_SERVER_H

#include "../../src_common/common_coords.h"

class EntidadServer {
public:
    EntidadServer() = default;
    virtual Coordenadas& ubicacion() = 0;
    virtual bool sigueViva() = 0;
    virtual void recibirDmg(uint8_t dmg_entrante, uint8_t id_unidad_atacante) = 0;
    virtual ~EntidadServer() = default;
};

#endif // ENTIDAD_SERVER_H
