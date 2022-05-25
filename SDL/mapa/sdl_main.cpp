#include <exception>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Music.hh>
#include <SDL2pp/Mixer.hh>
#include <unistd.h>
#include <iostream>

#include "sdl_mapa.h"
#include "sdl_game_loop.h"

int main() {
	SDL2pp::SDL sdl(SDL_INIT_VIDEO);
	SDL2pp::Window window("MapaSDL",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			700, 700,
			SDL_WINDOW_RESIZABLE);
	SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL2pp::Texture textura(renderer, RESOURCE_PATH "/maps/ejemplo.png");
	MapaSDL mapa(textura);

	SDL2pp::Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
	SDL2pp::Music music(RESOURCE_PATH "/music/Plotting.mp3");
	mixer.FadeInMusic(music, -1, 2000);

	GameLoop game_loop(mapa, renderer);
	game_loop.start();
	return 0;
}