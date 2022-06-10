#include "client_thread_renderer/client_hilo_renderer.h"
#include "client_comandos/client_comando.h"
#include "../src_common/common_colas/cola_no_bloqueante.h"
#include "../src_common/common_colas/cola_bloqueante.h"
#include "client_comandos/cmd_mover_mapa.h"
#include "client_thread_sdl/client_hilo_sdl.h"
#include "client_solicitudes/cliente_solicitud.h"

int main() {
	SDL2pp::SDL sdl(SDL_INIT_VIDEO);
	ColaNoBloqueante<ComandoCliente> cola_comandos;
	ColaBloqueante<SolicitudCliente> cola_solicitudes;
	ClientHiloRenderer hilo_renderer(cola_comandos);
	ManejadorEventos hilo_sdl(cola_solicitudes, cola_comandos);
	SDL_Delay(50000);
	return 0;
}
