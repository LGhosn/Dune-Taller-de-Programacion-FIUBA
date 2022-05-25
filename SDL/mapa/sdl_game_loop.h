#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Music.hh>
#include <SDL2pp/Mixer.hh>
#include "sdl_mapa.h"

class GameLoop {
	MapaSDL& mapa;
	SDL2pp::Renderer& renderer;

	bool handleEvents();

	void handleKeyDown(SDL_KeyboardEvent& keyEvent);

	void handleKeyUp(SDL_KeyboardEvent& keyEvent);

	void handleMouseWheel(SDL_MouseWheelEvent& mWheelEvent);

	void update(float tiempo_transcurrido);

	void render();

public:
	GameLoop(MapaSDL& mapa, SDL2pp::Renderer& renderer);

	void start();
};

#endif
