#include <exception>
#include <unistd.h>
#include <chrono>
#include <iostream>
#include <thread>
#include "client_renderer.h"

bool ClientRenderer::manejar_comando() {
	// popall
	std::unique_ptr<ComandoCliente> comando = this->cola_comandos.pop();
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
	using namespace std::chrono;
	bool running = true;
	long frame = 0;
	time_point t1 = system_clock::now();
	milliseconds frame_rate(1000 / FPS);
	while (running) {
		running = this->manejar_comando();
		this->update(frame);
		this->render();
		time_point t2 = system_clock::now();
		milliseconds tiempo_transcurrido = duration_cast<milliseconds>(t2 - t1);
		t1 = t2;
		milliseconds rest;
		// Equivalente a calcular el rest y preguntar si es menor a cero
		if (tiempo_transcurrido.count() > frame_rate.count()) {
			milliseconds demora = duration_cast<milliseconds>(tiempo_transcurrido - frame_rate);
			rest = duration_cast<milliseconds>(demora % frame_rate);
			milliseconds tiempo_perdido = demora + rest;
			frame += tiempo_perdido.count() / frame_rate.count();
		} else {
			rest = duration_cast<milliseconds>(frame_rate - tiempo_transcurrido);
			frame++;
		}
		std::this_thread::sleep_for(rest);
	}
}

ClientRenderer::ClientRenderer(ColaNoBloqueante<ComandoCliente>& cola_comandos,
								ColaBloqueante<SolicitudCliente>& cola_solicitudes,
								uint8_t id_jugador, InfoPartidaDTO& info_partida,
								YAML::Node& constantes) :
								cola_solicitudes(cola_solicitudes),
								cola_comandos(cola_comandos),
								world_view(cola_solicitudes, id_jugador, info_partida, constantes) {}

void ClientRenderer::start() {
	try {
		this->game_loop();
	} catch (const std::exception& e) {
		std::cerr << "Excepción encontrada en ClientHiloRenderer: " << e.what() << std::endl;
	} catch (...) {
		std::cerr << "Excepción desconocida en ClientHiloRenderer: " << std::endl;
	}
}

ClientRenderer::~ClientRenderer() {
	std::cerr << "Destruyendo ClientHiloRenderer\n";
}
