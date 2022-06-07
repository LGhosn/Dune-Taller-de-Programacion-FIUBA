#ifndef CLIENT_HILO_RENDERER_H
#define CLIENT_HILO_RENDERER_H

#define FRAME_RATE 33.0f

#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Music.hh>
#include <SDL2pp/Mixer.hh>
#include "../client_world_view/sdl_mapa.h"
#include "../client_world_view/world_view.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../../src_common/common_comandos/comando.h"
#include <list>
#include <thread>

class ClientHiloRenderer {
private:
	WorldView world_view;
	ColaNoBloqueante<Comando>& cola_eventos;
	std::thread hilo;

	bool manejar_comando();
	void update(long frame_actual);
	void render();
	void game_loop();
	void manejar_hilo();

public:
    ClientHiloRenderer(ColaNoBloqueante<Comando>& cola_eventos);
	void start();
	~ClientHiloRenderer();
};

#endif
