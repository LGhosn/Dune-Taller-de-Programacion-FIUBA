#include <exception>
#include <unistd.h>
#include <chrono>
#include <iostream>
#include "hilo_renderer.h"

bool HiloRenderer::handle_command(float tiempo_transcurrido) {
	Command comando = this->cola_eventos.pop();
	if (comando)
		return comando.ejecutar(this->world_view, tiempo_transcurrido);
	return true;
}

void HiloRenderer::update(float tiempo_transcurrido) {
	this->world_view.update(tiempo_transcurrido);
}

void HiloRenderer::render(long frame) {
	this->renderer.Clear();
	this->world_view.render(this->renderer, frame);
	this->renderer.Present();
}

void HiloRenderer::game_loop() {
	bool running = true;
	long frame = 0;
	auto t1 = std::chrono::steady_clock::now();
	while (running) {
		auto t2 = std::chrono::steady_clock::now();
		std::chrono::duration<float> tiempo_transcurrido = std::chrono::duration_cast
		<std::chrono::duration<float>>(t1 - t2);
		t1 = t2;
		running = this->handle_command(tiempo_transcurrido.count());
		this->update(tiempo_transcurrido.count());
		this->render(frame);
		float rest = FRAME_RATE - tiempo_transcurrido.count();
		frame++;
		usleep(rest);
	}
}

void HiloRenderer::manejar_hilo() {
	try {
		this->game_loop();
	} catch (const Exception& e) {
		std::cerr << "Excepcion encontrada en hilo renderer: " << e.what() << std::endl;
	} catch (...) {
		std::cerr << "Excepcion desconocida en hilo renderer" << std::endl;
	}
}

HiloRenderer::HiloRenderer(WorldView& world_view, ColaNoBloqueante<Command>& cola_eventos,
	SDL2pp::Renderer& renderer) : world_view(world_view), cola_eventos(cola_eventos),
	renderer(renderer) {}

void HiloRenderer::start() {
	this->hilo = std::thread(&HiloRenderer::manejar_hilo, this);
}

HiloRenderer::~HiloRenderer() {
	if (this->hilo.joinable())
		this->hilo.join();
}
