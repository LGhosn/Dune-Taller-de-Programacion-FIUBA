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
			case SDL_MOUSEWHEEL: {
				SDL_MouseWheelEvent& mWheelEvent = (SDL_MouseWheelEvent&) event;
				this->handleMouseWheel(mWheelEvent);
			}
			break;
			case SDL_MOUSEMOTION: {
				SDL_MouseMotionEvent& mouseEvent = (SDL_MouseMotionEvent&) event;
				this->handleMouseMotion(mouseEvent);
			}
			break;
			case SDL_MOUSEBUTTONDOWN: {
				SDL_MouseButtonEvent& mouseEvent = (SDL_MouseButtonEvent&) event;
				this->handleMouseButton(mouseEvent);
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

void GameLoop::handleMouseWheel(SDL_MouseWheelEvent& mWheelEvent) {
	if (mWheelEvent.y > 0) {
		this->mapa.zoomIn();
	} else if (mWheelEvent.y < 0) {
		this->mapa.zoomOut();
	}
}

void GameLoop::handleMouseMotion(SDL_MouseMotionEvent& mouseEvent) {
	if (mouseEvent.y <= PADDING_LIMITE_VENTANA) {
		this->mapa.moverArriba();
	} else if (mouseEvent.y >= LARGO_VENTANA - PADDING_LIMITE_VENTANA) {
		this->mapa.moverAbajo();
	} else {
		this->mapa.dejarDeMoverseVerticalmente();
	}

	if (mouseEvent.x <= PADDING_LIMITE_VENTANA) {
		this->mapa.moverIzquierda();
	} else if (mouseEvent.x >= ANCHO_VENTANA - PADDING_LIMITE_VENTANA) {
		this->mapa.moverDerecha();
	} else {
		this->mapa.dejarDeMoverseHorizontalmente();
	}
}

void GameLoop::handleMouseButton (SDL_MouseButtonEvent& mouseEvent) {
	int coords_x = (this->mapa.obtener_offset_x() + mouseEvent.x / this->mapa.obtener_zoom()) / 32;
	int coords_y = (this->mapa.obtener_offset_y() + mouseEvent.y / this->mapa.obtener_zoom()) / 32;
	this->edificios.emplace_back(mapa, this->textura_edificios, coords_x * 32, coords_y * 32, 100, 84);
}

void GameLoop::update(float tiempo_transcurrido) {
	mapa.update(tiempo_transcurrido);
}

void GameLoop::render() {
	this->renderer.Clear();
	mapa.render(this->renderer);
	this->render_edificios();
	this->renderer.Present();
}

void GameLoop::render_edificios() {
	for (EdificioSDL& edificio: edificios) {
		edificio.render(this->renderer);
	}
}

GameLoop::GameLoop(MapaSDL& mapa, std::list<EdificioSDL>& edificios, SDL2pp::Renderer& renderer,
	SDL2pp::Texture& textura_edificios) : 
mapa(mapa), edificios(edificios), renderer(renderer), textura_edificios(textura_edificios) {}

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
