#include "sdl_mapa.h"

MapaSDL::MapaSDL(SDL2pp::Texture& textura) : textura(textura),
pos_x((textura.GetWidth() - ANCHO_VENTANA / ZOOM_INICIAL) / 2), pos_y((textura.GetHeight() - LARGO_VENTANA / ZOOM_INICIAL) / 2),
moviendose_h(false), moviendose_v(false), direccion_h(ARRIBA), direccion_v(IZQUIERDA), tiempo(0.0f), zoom(ZOOM_INICIAL) {}

void MapaSDL::moverArriba() {
	if (pos_y > 0 - PADDING && !this->moviendose_v) {
		this->direccion_v = ARRIBA;
		this->moviendose_v = true;
	}
}

void MapaSDL::moverIzquierda() {
	if (pos_x > 0 - PADDING && !this->moviendose_h) {
		this->direccion_h = IZQUIERDA;
		this->moviendose_h = true;
	}
}

void MapaSDL::moverAbajo() {
	if (pos_y < this->textura.GetHeight() - LARGO_VENTANA / this->zoom + PADDING && !this->moviendose_v) {
		this->direccion_v = ABAJO;
		this->moviendose_v = true;
	}
}

void MapaSDL::moverDerecha() {
	if (pos_x < this->textura.GetWidth() - ANCHO_VENTANA / this->zoom + PADDING && !this->moviendose_h) {
		this->direccion_h = DERECHA;
		this->moviendose_h = true;
	}
}

void MapaSDL::dejarDeMoverseHorizontalmente() {
	this->moviendose_h = false;
}

void MapaSDL::dejarDeMoverseVerticalmente() {
	this->moviendose_v = false;
}

void MapaSDL::zoomIn() {
	if (this->zoom < ZOOM_MAX)
		this->zoom += ZOOM_INCR;
}

void MapaSDL::zoomOut() {
	if (this->zoom > ZOOM_MIN)
		this->zoom -= ZOOM_INCR;
}

int MapaSDL::obtener_offset_x() const {
	return this->pos_x;
}

int MapaSDL::obtener_offset_y() const {
	return this->pos_y;
}

float MapaSDL::obtener_zoom() const {
	return this->zoom;
}

void MapaSDL::update(float tiempo_transcurrido) {
	if (this->moviendose_h) {
		switch(this->direccion_h) {
			case IZQUIERDA:
				if (this->pos_x > 0 - PADDING) {
					this->tiempo += tiempo_transcurrido;
					while(this->tiempo >= FRAME_RATE) {
						pos_x -= PASO / this->zoom;
						this->tiempo -= FRAME_RATE;
						if (this->pos_x < 0 - PADDING) {
							pos_x = 0 - PADDING;
							this->tiempo = 0.0f;
							this->moviendose_h = false;
							break;
						}
					}
				}
				break;
			case DERECHA:
				if (this->pos_x < this->textura.GetWidth() - ANCHO_VENTANA / this->zoom + PADDING) {
					this->tiempo += tiempo_transcurrido;
					while(this->tiempo >= FRAME_RATE) {
						pos_x += PASO / this->zoom;
						this->tiempo -= FRAME_RATE;
						if (this->pos_x > this->textura.GetWidth() - ANCHO_VENTANA / this->zoom + PADDING) {
							pos_x = this->textura.GetWidth() - ANCHO_VENTANA / this->zoom + PADDING;
							this->tiempo = 0.0f;
							this->moviendose_h = false;
							break;
						}
					}
				}
				break;
		}
	}

	if (this->moviendose_v) {
		switch(this->direccion_v) {
			case ARRIBA:
				if (this->pos_y > 0 - PADDING) {
					this->tiempo += tiempo_transcurrido;
					while(this->tiempo >= FRAME_RATE) {
						pos_y -= PASO / this->zoom;
						this->tiempo -= FRAME_RATE;
						if (this->pos_y < 0 - PADDING) {
							pos_y = 0 - PADDING;
							this->tiempo = 0.0f;
							this->moviendose_v = false;
							break;
						}
					}
				}
				break;
			case ABAJO:
				if (this->pos_y < this->textura.GetHeight() - LARGO_VENTANA / this->zoom + PADDING) {
					this->tiempo += tiempo_transcurrido;
					while(this->tiempo >= FRAME_RATE) {
						pos_y += PASO / this->zoom;
						this->tiempo -= FRAME_RATE;
						if (this->pos_y > this->textura.GetHeight() - LARGO_VENTANA / this->zoom + PADDING) {
							pos_y = this->textura.GetHeight() - LARGO_VENTANA / this->zoom + PADDING;
							this->tiempo = 0.0f;
							this->moviendose_v = false;
							break;
						}
					}
				}
				break;
		}
	}
}

void MapaSDL::render(SDL2pp::Renderer& renderer) {
	int origen_x, origen_y;
	int pos_x_pantalla, pos_y_pantalla;
	int tam_x_pantalla, tam_y_pantalla;
	if (this->pos_x < 0) {
		origen_x = 0;
		pos_x_pantalla = - this->pos_x * this->zoom;
		tam_x_pantalla = (ANCHO_VENTANA + this->pos_x) / this->zoom;
	} else if (this->pos_x > (this->textura.GetWidth() - ANCHO_VENTANA)) {
		origen_x = this->pos_x;
		pos_x_pantalla = 0;
		tam_x_pantalla = this->textura.GetWidth() - this->pos_x;
	} else {
		origen_x = this->pos_x;
		pos_x_pantalla = 0;
		tam_x_pantalla = ANCHO_VENTANA / this->zoom;
	}
	if (this->pos_y < 0) {
		origen_y = 0;
		pos_y_pantalla = - this->pos_y * this->zoom;
		tam_y_pantalla = (LARGO_VENTANA + this->pos_y) / this->zoom;
	} else if (this->pos_y > (this->textura.GetHeight() - LARGO_VENTANA)) {
		origen_y = this->pos_y;
		pos_y_pantalla = 0;
		tam_y_pantalla = this->textura.GetHeight() - this->pos_y;
	} else {
		origen_y = this->pos_y;
		pos_y_pantalla = 0;
		tam_y_pantalla = LARGO_VENTANA / this->zoom;
	}
	renderer.Copy(this->textura,
		SDL2pp::Rect(
			origen_x,
			origen_y,
			tam_x_pantalla,
			tam_y_pantalla),
		SDL2pp::Rect(
			pos_x_pantalla,
			pos_y_pantalla,
			tam_x_pantalla * this->zoom,
			tam_y_pantalla * this->zoom));
}
