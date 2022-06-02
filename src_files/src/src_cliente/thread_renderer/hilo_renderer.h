#ifndef HILO_RENDERER_H
#define HILO_RENDERER_H

#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Music.hh>
#include <SDL2pp/Mixer.hh>
#include "../world_view/sdl_mapa.h"
#include "../cola_no_bloqueante.h"
#include "../comandos/comando.h"
#include <list>
#include <thread>

class HiloRenderer {
	WorldView world_view;
	ColaNoBloqueante<Comando>& cola_eventos;
	std::thread hilo;

	bool manejar_comando();

	void update(float tiempo_transcurrido);

	void render(long frame);

	void game_loop();

	void manejar_hilo();

public:
	HiloRenderer(ColaNoBloqueante<Comando>& cola_eventos);

	void start();

	~HiloRenderer();
};

#endif
