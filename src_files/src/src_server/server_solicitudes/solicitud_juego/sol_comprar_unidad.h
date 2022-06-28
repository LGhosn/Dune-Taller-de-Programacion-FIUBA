#ifndef SOL_COMPRAR_UNIDAD_H
#define SOL_COMPRAR_UNIDAD_H

#include "server_solicitud.h"
#include "../../server_DTO/dto_sol_comprar_unidad.h"

class SolicitudComprarUnidad : public SolicitudServer {
private:
    uint8_t id_jugador;
    uint8_t tipo;

public:
    SolicitudComprarUnidad(SolicitudComprarUnidadDTO &dto);

    virtual bool ejecutar(Game& game) const override;

    virtual ~SolicitudComprarUnidad() = default;
};

#endif