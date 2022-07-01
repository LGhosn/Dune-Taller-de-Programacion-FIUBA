#include "world_view.h"
#include "../client_solicitudes/client_sol_crear_edificio.h"
#include <functional>

void WorldView::deseleccionarEdificios() {
	for (auto edificio : edificios_seleccionados) {
		edificio->deseleccionar();
	}
	edificios_seleccionados.clear();
}

void WorldView::seleccionarEdificio(EdificioSDL* edificio) {
	deseleccionarEdificios();
	edificio->seleccionar();
	edificios_seleccionados.push_back(edificio);
}

void WorldView::renderUI() {
	for (auto edificio : edificios) {
		edificio.second->renderUI();
	}
	this->side_menu.render();
}

WorldView::WorldView(ColaBloqueante<SolicitudCliente>& cola_solicitudes, uint8_t id_jugador,
					InfoPartidaDTO& info_partida, YAML::Node& constantes) :
					constantes(constantes),
					casa(info_partida.info_jugadores[id_jugador].first),
					ancho_ventana(constantes["WorldView"]["Ventana"]["Ancho"].as<uint32_t>()),
					largo_ventana(constantes["WorldView"]["Ventana"]["Alto"].as<uint32_t>()),
					ancho_menu(constantes["WorldView"]["SideMenu"]["Ancho"].as<uint32_t>()),
					zoom_inicial(constantes["WorldView"]["Zoom"]["Inicial"].as<float>()),
					zoom_minimo(constantes["WorldView"]["Zoom"]["Minimo"].as<float>()),
					zoom_maximo(constantes["WorldView"]["Zoom"]["Maximo"].as<float>()),
					velocidad_zoom(constantes["WorldView"]["Zoom"]["Velocidad"].as<float>()),
					biblioteca_sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO),
					biblioteca_sdl_mixer(MIX_INIT_OGG),
					window("Dune 2000", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							ancho_ventana, largo_ventana, 0),
					renderer(window, -1, SDL_RENDERER_ACCELERATED),
					mixer(casa, constantes),
					texturas(renderer, constantes),
					cola_solicitudes(cola_solicitudes),
					zoom(zoom_inicial),
					mapa(
						renderer,
						info_partida.nombre_mapa,
						texturas,
						constantes,
						info_partida.coords_iniciales,
						zoom_inicial
					),
					side_menu(renderer, mixer, casa, texturas, id_jugador, constantes,
								colores.obtenerColor(id_jugador)),
					edificio_factory(renderer, texturas, constantes, colores),
					id_jugador(id_jugador),
					info_partida(info_partida) {
	renderer.SetDrawBlendMode(SDL_BLENDMODE_BLEND);
}

void WorldView::moverMapaArriba() {
	this->mapa.moverArriba();
}

void WorldView::moverMapaIzquierda() {
	this->mapa.moverIzquierda();
}

void WorldView::moverMapaDerecha() {
	this->mapa.moverDerecha();
}

void WorldView::moverMapaAbajo() {
	this->mapa.moverAbajo();
}

void WorldView::dejarDeMoverMapaHorizontalmente() {
	this->mapa.dejarDeMoverseHorizontalmente();
}

void WorldView::dejarDeMoverMapaVerticalmente() {
	this->mapa.dejarDeMoverseVerticalmente();
}

void WorldView::zoomIn() {
	if (this->zoom < zoom_maximo) {
		this->zoom += velocidad_zoom;
	}
}

void WorldView::zoomOut() {
	if (this->zoom > zoom_minimo) {
		this->zoom -= velocidad_zoom;
	}
}

void WorldView::empezarConstruccionEdificio(uint8_t tipo, uint16_t tiempo_construccion) {
	side_menu.empezarConstruccionEdificio(tipo, tiempo_construccion);
}

void WorldView::construccionInvalida() {
	mixer.reproducirMensajeConstruccionInvalida();
}

void WorldView::empezarEntrenamiento(uint8_t tipo, uint16_t tiempo_construccion) {
	side_menu.empezarEntrenamiento(tipo, tiempo_construccion);
}

void WorldView::crearEdificio(uint16_t id_edificio, uint8_t id_jugador,
							const Coordenadas& coords, uint8_t tipo, uint8_t casa) {
	EdificioSDL* edificio = edificio_factory.crearEdificio
												(id_edificio, id_jugador, casa, tipo, coords);
	Coordenadas dimensiones = edificio->obtenerDimensiones();
	for (int i = 0; i < dimensiones.x; i++) {
		for (int j = 0; j < dimensiones.y; j++) {
			Coordenadas coord_actual(coords.x + i, coords.y + j);
			edificios.insert(std::make_pair(coord_actual, edificio));
		}
	}
	if (id_jugador == this->id_jugador) {
		side_menu.edificioCreado(tipo);
	}
	
}

void WorldView::click(uint32_t pos_x, uint32_t pos_y) {
	if (pos_x < ancho_ventana - ancho_menu) {
		Coordenadas coords = mapa.obtenerCoords(pos_x, pos_y);
		if (edificios.find(coords) != edificios.end()) {
			seleccionarEdificio(edificios.at(coords));
		} else {
			SolicitudCliente* solicitud = side_menu.clickEnMapa(coords);
			if (solicitud)
				cola_solicitudes.push(solicitud);
			deseleccionarEdificios();
		}
	} else {
		SolicitudCliente* solicitud = side_menu.clickEnMenu(pos_x, pos_y);
		if (solicitud) {
			cola_solicitudes.push(solicitud);
			deseleccionarEdificios();
		}
	}
}

void WorldView::modificarEspecia(uint16_t cantidad_especia) {
	side_menu.modificarEspecia(cantidad_especia);
}

void WorldView::modificarEnergia(int16_t cantidad_energia) {
	side_menu.modificarEnergia(cantidad_energia);
}

void WorldView::actualizarTiendaEdificios(const std::vector<bool>& edificios_comprables) {
	side_menu.actualizarTiendaEdificios(edificios_comprables);
}

void WorldView::salir() {

}

void WorldView::update(long frame_actual) {
	long frames_transcurridos = frame_actual - this->frame_anterior;
	for (int i = 0; i < frames_transcurridos; i++) {
		this->mapa.update(this->zoom);
	}
	for (auto& edificio : this->edificios)
		edificio.second->update(mapa.obtener_offset_x(), mapa.obtener_offset_y(),
								frame_actual, zoom);
	
	this->side_menu.update(frames_transcurridos);
	this->frame_anterior = frame_actual;
}

void WorldView::render() {
	this->renderer.Clear();
	// this->renderer.SetScale(this->zoom, this->zoom);
	this->mapa.render();
	for (auto& edificio : this->edificios)
		edificio.second->render();
	this->renderUI();
	this->renderer.Present();
}

WorldView::~WorldView() {
	for (auto& edificio : this->edificios)
		delete edificio.second;
}
