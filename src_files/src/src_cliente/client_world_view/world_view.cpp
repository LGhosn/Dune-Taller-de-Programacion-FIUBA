#include "world_view.h"
#include "../client_solicitudes/client_sol_crear_edificio.h"
#include <functional>

void WorldView::renderUI() {
	for (auto edificio : edificios) {
		edificio.second->renderUI();
	}
	this->side_menu.render();
}

WorldView::WorldView(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                     uint8_t id_jugador,
                     InfoPartidaDTO& info_partida,
                     YAML::Node& constantes) :
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
					window("Dune 2000",
                           SDL_WINDOWPOS_UNDEFINED,
                           SDL_WINDOWPOS_UNDEFINED,
                           ancho_ventana,
                           largo_ventana,
                           0),
					renderer(window,
                             -1,
                             SDL_RENDERER_ACCELERATED),
					mixer(casa,
                          constantes),
					texturas(renderer,
                             constantes),
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

void WorldView::update(long frame_actual) {
    long frames_transcurridos = frame_actual - this->frame_anterior;
    for (int i = 0; i < frames_transcurridos; i++) {
        this->mapa.update(this->zoom);
    }

    for (auto& edificio : this->edificios) {
        edificio.second->update(mapa.obtener_offset_x(), mapa.obtener_offset_y(), frame_actual, zoom);
    }

    for (auto & unidad: this->unidades) {
        unidad.second->update(mapa.obtener_offset_x(), mapa.obtener_offset_y(), frame_actual, zoom);
    }

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

/* *****************************************************************
 *              METODOS REFERIDOS A ESPECIA Y ENERGÍA
 * *****************************************************************/

void WorldView::modificarEspecia(uint16_t cantidad_especia) {
    side_menu.modificarEspecia(cantidad_especia);
}

void WorldView::modificarEnergia(int16_t cantidad_energia) {
    side_menu.modificarEnergia(cantidad_energia);
}

/* *****************************************************************
 *                 METODOS REFERIDOS A EDIFICIOS
 * *****************************************************************/

void WorldView::crearEdificio(uint16_t id_edificio,
                              uint8_t id_jugador,
                              const Coordenadas& coords,
                              uint8_t tipo,
                              uint8_t casa) {
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

void WorldView::empezarConstruccionEdificio(uint8_t tipo, uint16_t tiempo_construccion) {
    side_menu.empezarConstruccionEdificio(tipo, tiempo_construccion);
}

void WorldView::construccionInvalida() {
    mixer.reproducirMensajeConstruccionInvalida();
}

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

void WorldView::actualizarTiendaEdificios(const std::vector<bool>& edificios_comprables) {
    side_menu.actualizarTiendaEdificios(edificios_comprables);
}

/* *****************************************************************
 *                METODOS REFERIDOS A UNIDADES
 * *****************************************************************/

void WorldView::moverUnidad(uint8_t id_unidad, char direccion, long tiempo_movimiento) {
    UnidadSDL* unidad_a_mover = unidades[id_unidad];
    unidad_a_mover->moverse(direccion, tiempo_movimiento);
}

void WorldView::empezarEntrenamiento(uint8_t tipo, uint16_t tiempo_construccion, Coordenadas& coords_spawn) {
    if (tipo < 4) {
        side_menu.empezarEntrenamientoInfanteria(tipo, tiempo_construccion, coords_spawn);
    } else {
        side_menu.empezarEntrenamientoVehiculo(tipo, tiempo_construccion, coords_spawn);
    }
}

void WorldView::seleccionarUnidad(UnidadSDL* unidad) {
    deseleccionarEdificios();
    deseleccionarUnidades();
    unidad->seleccionar();
    unidades_seleccionadas.push_back(unidad);
}

void WorldView::deseleccionarUnidades() {
    for (auto& unidad : unidades_seleccionadas) {
        unidad->deseleccionar();
    }
    unidades_seleccionadas.clear();
}

/* *****************************************************************
 *                  METODOS REFERIDOS AL MAPA
 * *****************************************************************/

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

void WorldView::click(uint32_t pos_x, uint32_t pos_y) {
    if (pos_x < ancho_ventana - ancho_menu) {
        Coordenadas coords = mapa.obtenerCoords(pos_x, pos_y);
        bool entidad_seleccionada = false;
        if (edificios.find(coords) != edificios.end()) {
            seleccionarEdificio(edificios.at(coords));
            entidad_seleccionada = true;
        } else {
            for (auto & unidad: unidades) {
                if (unidad.second->contiene(pos_x, pos_y)) {
                    seleccionarUnidad(unidad.second);
                    entidad_seleccionada = true;
                }
            }
        }
        if (!entidad_seleccionada) {
            SolicitudCliente* solicitud = side_menu.clickEnMapa(coords);
            if (solicitud) {
                cola_solicitudes.push(solicitud);
            } else {
                deseleccionarEdificios();
                //unidades.emplace_back(new UnidadSDL(0, id_jugador, renderer, texturas.obtenerCosechadora(), coords, constantes, colores.obtenerColor(id_jugador)));
            }
        }
    } else {
        SolicitudCliente* solicitud = side_menu.clickEnMenu(pos_x, pos_y);
        if (solicitud) {
            cola_solicitudes.push(solicitud);
            deseleccionarEdificios();
        }
    }
}

void WorldView::salir() {}
