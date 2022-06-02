#include <exception>
#include <unistd.h>
#include <chrono>
#include <iostream>
#include "hilo_renderer.h"

bool HiloRenderer::manejar_comando() {
	std::unique_ptr<Comando> comando = this->cola_eventos.pop();
	if (comando)
		return comando->ejecutar(this->world_view);
	return true;
}

void HiloRenderer::update(long frame_actual) {
	this->world_view.update(frame_actual);
}

void HiloRenderer::render() {
	this->world_view.render();
}

void HiloRenderer::game_loop() {
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

void HiloRenderer::manejar_hilo() {
	try {
		this->game_loop();
	} catch (const std::exception& e) {
		std::cerr << "Excepcion encontrada en hilo renderer: " << e.what() << std::endl;
	} catch (...) {
		std::cerr << "Excepcion desconocida en hilo renderer" << std::endl;
	}
}

HiloRenderer::HiloRenderer(ColaNoBloqueante<Comando>& cola_eventos) : cola_eventos(cola_eventos) {}

void HiloRenderer::start() {
	this->hilo = std::thread(&HiloRenderer::manejar_hilo, this);
}

HiloRenderer::~HiloRenderer() {
	if (this->hilo.joinable())
		this->hilo.join();
}
