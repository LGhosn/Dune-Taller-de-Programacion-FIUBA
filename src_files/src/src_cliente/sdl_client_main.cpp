#include "thread_renderer/hilo_renderer.h"
#include "cola_no_bloqueante.h"
#include "comandos/cmd_mover_mapa.h"

int main() {
	ColaNoBloqueante<Comando> cola_eventos;
	Comando* mover_mapa = new MoverMapa('A');
	cola_eventos.push(mover_mapa);
	HiloRenderer hilo_renderer(cola_eventos);
	hilo_renderer.start();
	SDL_Delay(10000);
	return 0;
}
