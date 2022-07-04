#ifndef CMD_MARCADOR_H
#define CMD_MARCADOR_H

#include "client_comando.h"
#include "../../src_cliente/client_world_view/world_view.h"

class ComandoMarcador : public ComandoCliente {
	bool estado_marcador;
public:
	explicit ComandoMarcador(bool habilitado);

	virtual bool ejecutar(WorldView& worldView) const override;

	virtual ~ComandoMarcador() = default;
};

#endif
