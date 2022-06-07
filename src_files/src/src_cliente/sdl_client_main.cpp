#include "client_thread_renderer/client_hilo_renderer.h"
#include "../src_common/common_comandos/comando.h"
#include "../src_common/common_colas/cola_no_bloqueante.h"
#include "../src_common/common_comandos/cmd_mover_mapa.h"

int main() {
	ColaNoBloqueante<Comando> cola_eventos;
	Comando* mover_mapa = new MoverMapa('A');
	cola_eventos.push(mover_mapa);
	ClientHiloRenderer hilo_renderer(cola_eventos);
	hilo_renderer.start();
	SDL_Delay(10000);
	return 0;
}
