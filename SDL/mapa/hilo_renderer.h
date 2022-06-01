#ifndef HILO_RENDERER_H
#define HILO_RENDERER_H

#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Music.hh>
#include <SDL2pp/Mixer.hh>
#include "sdl_mapa.h"
#include "sdl_edificio.h"
#include "cola_no_bloqueante.h"
#include "comando.h"
#include <list>
#include <thread>

class HiloRenderer {
	WorldView& world_view;
	ColaNoBloqueante<Comando>& cola_eventos;
	SDL2pp::Renderer& renderer;
	std::thread hilo;

	bool handle_command(float tiempo_transcurrido);

	void update(float tiempo_transcurrido);

	void render(long frame);

	void game_loop();

	void manejar_hilo();

public:
	HiloRenderer(WorldView& world_view, ColaNoBloqueante<Comando>& cola_eventos,
		SDL2pp::Renderer& renderer);

	void start();

	~HiloRenderer();
};

#endif
