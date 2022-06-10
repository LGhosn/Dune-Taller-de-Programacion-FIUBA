#ifndef COMANDO_ZOOM_H
#define COMANDO_ZOOM_H

#include "client_comando.h"

#define ZOOM_IN 'I'
#define ZOOM_OUT 'O'

class ComandoZoom : public ComandoCliente {
    char sentido;
public:
    ComandoZoom(char sentido);
    virtual bool ejecutar(WorldView& worldView) const override;

    virtual ~ComandoZoom() = default;
};

#endif
