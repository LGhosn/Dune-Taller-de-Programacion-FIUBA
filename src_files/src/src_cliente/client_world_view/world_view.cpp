#include "world_view.h"
#include "../client_solicitudes/client_sol_crear_edificio.h"
#include "../client_solicitudes/sol_mover_unidad.h"
#include "../client_solicitudes/sol_atacar_unidad.h"
#include "../client_solicitudes/sol_atacar_edificio.h"
#include "sdl_unidad/sdl_infanteria/sdl_infanteria.h"
#include <functional>
#include <algorithm>

void WorldView::renderUI() {
	for (auto edificio : edificios_construidos) {
		edificio.second->renderUI();
	}
	this->side_menu.render();
    this->marcador.render();
    this->estado.render();
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
                    marcador(renderer, texturas, constantes, info_partida, colores.obtenerColor(id_jugador)),
					estado(renderer, mixer, texturas, colores.obtenerColor(id_jugador), constantes),
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

    for (auto& edificio : this->edificios_construidos) {
        edificio.second->update(mapa.obtener_offset_x(), mapa.obtener_offset_y(), frames_transcurridos, zoom);
    }

    for (auto & unidad: this->unidades) {
        unidad.second->update(mapa.obtener_offset_x(), mapa.obtener_offset_y(), frames_transcurridos, zoom);
    }

    this->side_menu.update(frames_transcurridos);
    this->frame_anterior = frame_actual;
}

void WorldView::render() {
    this->renderer.Clear();
    // this->renderer.SetScale(this->zoom, this->zoom);
    this->mapa.render();
    for (auto& edificio : this->edificios_construidos)
        edificio.second->render();
    for (auto& unidad : this->unidades) {
        unidad.second->render();
    }
    this->renderUI();
    this->renderer.Present();
}

void WorldView::actualizarPuntaje(uint8_t id_jugador, uint16_t nuevo_puntaje) {
    marcador.actualizarPuntajes(id_jugador, nuevo_puntaje);
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
                              uint8_t casa,
                              uint16_t vida) {
    std::shared_ptr<EdificioSDL> edificio = edificio_factory.crearEdificio
            (id_edificio, id_jugador, casa, tipo, coords, vida);
    edificios_construidos.emplace(id_edificio, edificio);
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

void WorldView::deseleccionarEdificio(std::shared_ptr<EdificioSDL> edificio) {
    edificio->deseleccionar();
    edificios_seleccionados.erase(std::find(edificios_seleccionados.begin(), edificios_seleccionados.end(), edificio));
}

void WorldView::deseleccionarEdificios() {
    for (auto edificio : edificios_seleccionados) {
        edificio->deseleccionar();
    }
    edificios_seleccionados.clear();
}

void WorldView::seleccionarEdificio(std::shared_ptr<EdificioSDL> edificio) {
    deseleccionarEdificios();
    edificio->seleccionar();
    edificios_seleccionados.push_back(edificio);
}

std::shared_ptr<EdificioSDL> WorldView::edificioEnPosicion(uint32_t pos_x, uint32_t pos_y) const {
    for (const auto& edificio: edificios_construidos) {
        if (edificio.second->contiene(pos_x, pos_y)) {
            return edificio.second;
        }
    }
    return nullptr;
}

void WorldView::atacarEdificio(std::shared_ptr<EdificioSDL> edificio_a_atacar) {
    uint8_t id_edificio_a_atacar = edificio_a_atacar->obtenerId();
    uint8_t id_duenio_edificio = edificio_a_atacar->obtenerIdJugador();
    if (id_duenio_edificio == id_jugador) {
        return;
    }
    for (auto& unidad : unidades_seleccionadas) {
        SolicitudCliente* solicitud = new SolicitudAtacarEdificio(unidad->obtenerId(), id_edificio_a_atacar);
        cola_solicitudes.push(solicitud);
    }
}

bool WorldView::edificioEstaSeleccionado(std::shared_ptr<EdificioSDL>& edificio) const {
    return std::find(edificios_seleccionados.begin(), edificios_seleccionados.end(), edificio)
                    != edificios_seleccionados.end();
}

void WorldView::actualizarTiendaEdificios(const std::vector<bool>& edificios_comprables) {
    side_menu.actualizarTiendaEdificios(edificios_comprables);
}

void WorldView::actualizarTiendaUnidades(const std::vector<bool>& unidades_comprables) {
    side_menu.actualizarTiendaUnidades(unidades_comprables);
}

/* *****************************************************************
 *                METODOS REFERIDOS A UNIDADES
 * *****************************************************************/

void WorldView::moverUnidad(uint8_t id_unidad, uint8_t direccion, uint16_t tiempo_movimiento) {
    this->unidades[id_unidad]->moverse(direccion, tiempo_movimiento);
}

void WorldView::empezarEntrenamiento(uint8_t id_unidad, uint8_t tipo_unidad, uint16_t tiempo_aparicion,
                                    Coordenadas& coords_spawn, uint16_t vida) {
    if (tipo_unidad < 4) {
        side_menu.empezarEntrenamientoInfanteria(tipo_unidad, tiempo_aparicion);
    } else {
        side_menu.empezarEntrenamientoVehiculo(tipo_unidad, tiempo_aparicion);
    }
    empezarAparicionDeUnidad(id_unidad, this->id_jugador, tipo_unidad, true, tiempo_aparicion, coords_spawn, vida);
}

void WorldView::empezarAparicionDeUnidad(uint8_t id_unidad,
                                                uint8_t id_jugador,
                                                uint8_t tipo_unidad,
                                                bool unidad_amiga,
                                                uint16_t tiempo_entrenamiento,
                                                Coordenadas& coords_spawn,
                                                uint16_t vida) {
    if (tipo_unidad < 4) {
        this->unidades[id_unidad] = std::shared_ptr<InfanteriaSDL>(new InfanteriaSDL(id_unidad,
                                                                         id_jugador,
                                                                         tipo_unidad,
                                                                         casa,
                                                                         unidad_amiga,
                                                                         mixer,
                                                                         renderer,
                                                                         texturas,
                                                                         coords_spawn,
                                                                         constantes,
                                                                         colores.obtenerColor(id_jugador),
                                                                         tiempo_entrenamiento,
                                                                         vida));
    } else {
        this->unidades[id_unidad] = std::shared_ptr<VehiculoSDL>(new VehiculoSDL(id_unidad,
                                                                         id_jugador,
                                                                         tipo_unidad,
                                                                         casa,
                                                                         unidad_amiga,
                                                                         mixer,
                                                                         renderer,
                                                                         texturas,
                                                                         coords_spawn,
                                                                         constantes,
                                                                         colores.obtenerColor(id_jugador),
                                                                         tiempo_entrenamiento,
                                                                         vida));
    }
}

void WorldView::seleccionarUnidad(std::shared_ptr<UnidadSDL> unidad) {
    unidad->seleccionar();
    unidades_seleccionadas.push_back(unidad);
}

void WorldView::deseleccionarUnidad(std::shared_ptr<UnidadSDL> unidad) {
    unidad->deseleccionar();
    unidades_seleccionadas.erase(std::find(unidades_seleccionadas.begin(), unidades_seleccionadas.end(), unidad));
}

void WorldView::deseleccionarUnidades() {
    for (auto& unidad : unidades_seleccionadas) {
        unidad->deseleccionar();
    }
    unidades_seleccionadas.clear();
}

std::shared_ptr<UnidadSDL> WorldView::unidadEnPosicion(uint32_t pos_x, uint32_t pos_y) const {
    for (const auto& unidad: unidades) {
        if (unidad.second->contiene(pos_x, pos_y)) {
            return unidad.second;
        }
    }
    return nullptr;
}

bool WorldView::unidadEstaSeleccionada(std::shared_ptr<UnidadSDL>& unidad) const {
    return std::find(unidades_seleccionadas.begin(), unidades_seleccionadas.end(), unidad)
                    != unidades_seleccionadas.end();
}

void WorldView::atacarUnidad(std::shared_ptr<UnidadSDL> unidad_a_atacar) {
    for (auto& unidad: unidades_seleccionadas) {
        SolicitudCliente* solicitud = new SolicitudAtacarUnidad(unidad->obtenerId(), unidad_a_atacar->obtenerId());
        cola_solicitudes.push(solicitud);
    }
}

void WorldView::moverUnidades(uint32_t pos_x, uint32_t pos_y) {
    Coordenadas coords = mapa.obtenerCoords(pos_x, pos_y);
    for (auto& unidad: unidades_seleccionadas) {
        SolicitudCliente* solicitud = new SolicitudMoverUnidad(unidad->obtenerId(), coords);
        cola_solicitudes.push(solicitud);
    }
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

void WorldView::clickDerecho(uint32_t pos_x, uint32_t pos_y) {
    if (unidades_seleccionadas.empty()) {
        return;
    }
    if (pos_x < ancho_ventana - ancho_menu) {       // Click en mapa
        bool entidad_encontrada = false;
        std::shared_ptr<EdificioSDL> edificio = edificioEnPosicion(pos_x, pos_y);
        if (edificio) {
            atacarEdificio(edificio);
            entidad_encontrada = true;
            return;
        }
        std::shared_ptr<UnidadSDL> unidad = unidadEnPosicion(pos_x, pos_y);
        if (unidad && !unidadEstaSeleccionada(unidad)) {
            atacarUnidad(unidad);
            entidad_encontrada = true;
        }
        if (!entidad_encontrada) {
            moverUnidades(pos_x, pos_y);
        }
    }
}

void WorldView::click(uint32_t pos_x, uint32_t pos_y) {
    if (pos_x < ancho_ventana - ancho_menu) {       // Click en mapa
        std::shared_ptr<EdificioSDL> edificio = edificioEnPosicion(pos_x, pos_y);
        if (edificio) {
            if (edificioEstaSeleccionado(edificio)) {
                deseleccionarEdificio(edificio);
            } else {
                seleccionarEdificio(edificio);
            }
            return;
        }
        std::shared_ptr<UnidadSDL> unidad = unidadEnPosicion(pos_x, pos_y);
        if (unidad) {
            if (unidadEstaSeleccionada(unidad)) {
                deseleccionarUnidad(unidad);
            } else {
                seleccionarUnidad(unidad);
            }
            return;
        }
        // No se clickeo ni en una unidad ni en un edificio
        Coordenadas coords = mapa.obtenerCoords(pos_x, pos_y);
        SolicitudCliente* solicitud = side_menu.clickEnMapa(coords);
        if (solicitud) {
            cola_solicitudes.push(solicitud);
        }
    } else {        // Click en menu
        SolicitudCliente* solicitud = side_menu.clickEnMenu(pos_x, pos_y);
        if (solicitud) {
            cola_solicitudes.push(solicitud);
        }
    }
    deseleccionarEdificios();
    deseleccionarUnidades();
}

void WorldView::establecerEstadoDelMarcador(bool estado) {
    marcador.estaHabilitado(estado);
}

void WorldView::modificarVidaUnidad(uint8_t id_unidad, uint16_t vida) {
    bool esta_viva = unidades[id_unidad]->cambiarHP(vida);
    if (!esta_viva) {
        unidades.erase(id_unidad);
    }
}

void WorldView::modificarVidaEdificio(uint8_t id_edificio, uint8_t unidad_atacante,
							uint16_t vida) {
    bool esta_construido = edificios_construidos.at(id_edificio)->cambiarHP(vida);
    if (!esta_construido) {
        edificios_construidos.erase(id_edificio);
    }
    unidades[unidad_atacante]->disparar();
}

void WorldView::terminarPartida(uint8_t id_ganador) {
    estado.mostrarEstado(id_ganador == id_jugador);
}

void WorldView::salir() {}

