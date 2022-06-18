#ifndef CLIENT_RENDERER_H
#define CLIENT_RENDERER_H

#define FPS 60

#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Music.hh>
#include <SDL2pp/Mixer.hh>
#include "../client_world_view/sdl_mapa/sdl_mapa.h"
#include "../client_world_view/world_view.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../client_comandos/client_comando.h"
#include "../client_solicitudes/cliente_solicitud.h"
#include <list>

class ClientRenderer {
private:
	ColaBloqueante<SolicitudCliente>& cola_solicitudes;
	ColaNoBloqueante<ComandoCliente>& cola_comandos;
	WorldView world_view;

	bool manejar_comando();
	void update(long frame_actual);
	void render();
	void game_loop();

public:
    ClientRenderer(ColaNoBloqueante<ComandoCliente>& cola_comandos,
					ColaBloqueante<SolicitudCliente>& cola_solicitudes,
					uint8_t id_jugador,
					std::string&  nombre_mapa);

	void start();

	~ClientRenderer();
};

#endif
