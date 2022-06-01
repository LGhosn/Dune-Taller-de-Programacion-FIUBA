#include <exception>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Music.hh>
#include <SDL2pp/Mixer.hh>
#include <unistd.h>
#include <iostream>

#include "hilo_renderer.h"
#include "world_view.h"
#include "cola_no_bloqueante.h"
#include "cmd_mover_mapa.h"

int main() {
	SDL2pp::SDL sdl(SDL_INIT_VIDEO);
	SDL2pp::Window window("MapaSDL",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			ANCHO_VENTANA, LARGO_VENTANA,
			0);

	SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL2pp::Texture textura(renderer, RESOURCE_PATH "/maps/ejemplo.png");
	
	WorldView world_view(textura);

	ColaNoBloqueante<Comando> cola_eventos;
	MoverMapa mover_arriba('A');
	cola_eventos.push(mover_arriba);
	cola_eventos.push(mover_arriba);
	cola_eventos.push(mover_arriba);
	cola_eventos.push(mover_arriba);
	cola_eventos.push(mover_arriba);

	SDL2pp::Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
	SDL2pp::Music music(RESOURCE_PATH "/music/Plotting.mp3");
	mixer.FadeInMusic(music, -1, 2000);

	HiloRenderer hilo_renderer(world_view, cola_eventos, renderer);
	hilo_renderer.start();

	SDL_Delay(10000);
	return 0;
}