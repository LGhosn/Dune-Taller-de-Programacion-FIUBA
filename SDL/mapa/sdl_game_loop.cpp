#include <exception>
#include <unistd.h>
#include <chrono>
#include <iostream>
#include "sdl_game_loop.h"

bool GameLoop::handleEvents() {
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_KEYDOWN: {
				SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
				this->handleKeyDown(keyEvent);
			}
			break;
			case SDL_KEYUP: {
				SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
				this->handleKeyUp(keyEvent);
			}
			break;
			case SDL_QUIT:
				return false;
		}
	}
	return true;
}

void GameLoop::handleKeyDown(SDL_KeyboardEvent& keyEvent) {
	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	if (keyboardState[SDL_SCANCODE_UP]) {
		this->mapa.moverArriba();
	} else if (keyboardState[SDL_SCANCODE_DOWN]) {
		this->mapa.moverAbajo();
	}

	if (keyboardState[SDL_SCANCODE_LEFT]) {
		this->mapa.moverIzquierda();
	} else if (keyboardState[SDL_SCANCODE_RIGHT]) {
		this->mapa.moverDerecha();
	}
}

void GameLoop::handleKeyUp(SDL_KeyboardEvent& keyEvent) {
	switch (keyEvent.keysym.sym) {
		case SDLK_LEFT:
			this->mapa.dejarDeMoverseHorizontalmente();
			break;
		case SDLK_RIGHT:
			this->mapa.dejarDeMoverseHorizontalmente();
			break;
		case SDLK_UP:
			this->mapa.dejarDeMoverseVerticalmente();
			break;
		case SDLK_DOWN:
			this->mapa.dejarDeMoverseVerticalmente();
			break;
	}
}

void GameLoop::update(float tiempo_transcurrido) {
	mapa.update(tiempo_transcurrido);
}

void GameLoop::render() {
	this->renderer.Clear();
	mapa.render(this->renderer);
	this->renderer.Present();
}

GameLoop::GameLoop(MapaSDL& mapa, SDL2pp::Renderer& renderer) : mapa(mapa), renderer(renderer) {}

void GameLoop::start() {
	bool running = true;
	auto t1 = std::chrono::steady_clock::now();
	while (running) {
		auto t2 = std::chrono::steady_clock::now();
		std::chrono::duration<float> tiempo_transcurrido = std::chrono::duration_cast
		<std::chrono::duration<float>>(t1 - t2);
		t1 = t2;
		running = this->handleEvents();
		this->update(FRAME_RATE);
		this->render();	
		float rest = FRAME_RATE - tiempo_transcurrido.count();
		usleep(rest);
	}
}
