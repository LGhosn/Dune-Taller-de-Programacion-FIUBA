#include <exception>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Music.hh>
#include <SDL2pp/Mixer.hh>
#include <unistd.h>
#include <iostream>

#include "sdl_mapa.h"
#include "sdl_edificio.h"
#include "sdl_game_loop.h"

int main() {
	SDL2pp::SDL sdl(SDL_INIT_VIDEO);
	SDL2pp::Window window("MapaSDL",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			ANCHO_VENTANA, LARGO_VENTANA,
			0);

	SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL2pp::Texture textura(renderer, RESOURCE_PATH "/maps/ejemplo.png");
	MapaSDL mapa(textura);

	SDL2pp::Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
	SDL2pp::Music music(RESOURCE_PATH "/music/Plotting.mp3");
	mixer.FadeInMusic(music, -1, 2000);

	SDL2pp::Texture textura_edificios(renderer, RESOURCE_PATH "/buildings/construction_yard.png");

	std::list<EdificioSDL> edificios;
	edificios.emplace_back(mapa, textura_edificios, 600, 600, 100, 84);
	edificios.emplace_back(mapa, textura_edificios, 50, 50, 100, 84);

	GameLoop game_loop(mapa, edificios, renderer, textura_edificios);
	game_loop.start();
	return 0;
}