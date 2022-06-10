#include <exception>
#include <unistd.h>
#include <chrono>
#include <iostream>
#include "client_renderer.h"

bool ClientRenderer::manejar_comando() {
	// popall
	std::unique_ptr<ComandoCliente> comando = this->cola_eventos.pop();
	if (comando)
		return comando->ejecutar(this->world_view);
	return true;
}

void ClientRenderer::update(long frame_actual) {
	this->world_view.update(frame_actual);
}

void ClientRenderer::render() {
	this->world_view.render();
}

void ClientRenderer::game_loop() {
	bool running = true;
	long frame = 0;
	auto t1 = std::chrono::steady_clock::now();
	while (running) {
		auto t2 = std::chrono::steady_clock::now();
		float tiempo_transcurrido = std::chrono::duration<float, std::milli>(t2 - t1).count();
		t1 = t2;
		running = this->manejar_comando();
		this->update(frame);
		this->render();
		float rest = FRAME_RATE - tiempo_transcurrido;
		if (rest < 0) {
			float demora = - rest;
			rest = FRAME_RATE - (int) demora % (int) FRAME_RATE;
			float tiempo_perdido = demora + rest;
			frame += tiempo_perdido / FRAME_RATE;
		}
		usleep(rest);
		frame++;
	}
}

ClientRenderer::ClientRenderer(ColaNoBloqueante<ComandoCliente>& cola_eventos) : cola_eventos(cola_eventos) {}

void ClientRenderer::start() {
	try {
		this->game_loop();
	} catch (const std::exception& e) {
		std::cerr << "Excepción encontrada en ClientHiloRenderer: " << e.what() << std::endl;
	} catch (...) {
		std::cerr << "Excepción desconocida en ClientHiloRenderer: " << std::endl;
	}
}
