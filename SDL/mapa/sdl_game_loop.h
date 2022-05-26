#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Music.hh>
#include <SDL2pp/Mixer.hh>
#include "sdl_mapa.h"
#include "sdl_edificio.h"
#include <list>

class GameLoop {
	MapaSDL& mapa;
	std::list<EdificioSDL>& edificios;
	SDL2pp::Renderer& renderer;

	bool handleEvents();

	void handleKeyDown(SDL_KeyboardEvent& keyEvent);

	void handleKeyUp(SDL_KeyboardEvent& keyEvent);

	void handleMouseWheel(SDL_MouseWheelEvent& mWheelEvent);

	void update(float tiempo_transcurrido);

	void render();

	void render_edificios();

public:
	GameLoop(MapaSDL& mapa, std::list<EdificioSDL>& edificios, SDL2pp::Renderer& renderer);

	void start();
};

#endif
