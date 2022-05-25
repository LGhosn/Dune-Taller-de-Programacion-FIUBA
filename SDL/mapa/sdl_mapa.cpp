#include "sdl_mapa.h"

MapaSDL::MapaSDL(SDL2pp::Texture& textura) : textura(textura),
pos_x((textura.GetWidth() - ANCHO_VENTANA / ZOOM) / 2), pos_y((textura.GetHeight() - LARGO_VENTANA / ZOOM) / 2),
moviendose_h(false), moviendose_v(false), direccion_h(ARRIBA), direccion_v(IZQUIERDA), tiempo(0.0f) {}

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
	if (pos_y < this->textura.GetHeight() - LARGO_VENTANA / ZOOM + PADDING && !this->moviendose_v) {
		this->direccion_v = ABAJO;
		this->moviendose_v = true;
	}
}

void MapaSDL::moverDerecha() {
	if (pos_x < this->textura.GetWidth() - ANCHO_VENTANA / ZOOM + PADDING && !this->moviendose_h) {
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

int MapaSDL::obtener_offset_x() const {
	return this->pos_x;
}

int MapaSDL::obtener_offset_y() const {
	return this->pos_y;
}

void MapaSDL::update(float tiempo_transcurrido) {
	if (this->moviendose_h) {
		switch(this->direccion_h) {
			case IZQUIERDA:
				if (this->pos_x > 0 - PADDING) {
					this->tiempo += tiempo_transcurrido;
					while(this->tiempo >= FRAME_RATE) {
						pos_x -= PASO;
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
				if (this->pos_x < this->textura.GetWidth() - ANCHO_VENTANA / ZOOM + PADDING) {
					this->tiempo += tiempo_transcurrido;
					while(this->tiempo >= FRAME_RATE) {
						pos_x += PASO;
						this->tiempo -= FRAME_RATE;
						if (this->pos_x > this->textura.GetWidth() - ANCHO_VENTANA / ZOOM + PADDING) {
							pos_x = this->textura.GetWidth() - ANCHO_VENTANA / ZOOM + PADDING;
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
						pos_y -= PASO;
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
				if (this->pos_y < this->textura.GetHeight() - LARGO_VENTANA / ZOOM + PADDING) {
					this->tiempo += tiempo_transcurrido;
					while(this->tiempo >= FRAME_RATE) {
						pos_y += PASO;
						this->tiempo -= FRAME_RATE;
						if (this->pos_y > this->textura.GetHeight() - LARGO_VENTANA / ZOOM + PADDING) {
							pos_y = this->textura.GetHeight() - LARGO_VENTANA / ZOOM + PADDING;
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
	int pos_x_pantalla, pos_y_pantalla;
	int tam_x_pantalla, tam_y_pantalla;
	if (this->pos_x < 0) {
		pos_x_pantalla = - this->pos_x;
		tam_x_pantalla = ANCHO_VENTANA - pos_x_pantalla;
	} else if (this->pos_x > this->textura.GetWidth() - ANCHO_VENTANA / ZOOM) {
		pos_x_pantalla = 0;
		tam_x_pantalla = ANCHO_VENTANA - (pos_x - (this->textura.GetWidth() - ANCHO_VENTANA / ZOOM));
	} else {
		pos_x_pantalla = 0;
		tam_x_pantalla = ANCHO_VENTANA;
	}
	if (this->pos_y < 0) {
		pos_y_pantalla = - this->pos_y;
		tam_y_pantalla = LARGO_VENTANA - pos_y_pantalla;
	} else if (this->pos_y > this->textura.GetHeight() - LARGO_VENTANA / ZOOM) {
		pos_y_pantalla = 0;
		tam_y_pantalla = LARGO_VENTANA - (pos_y - (this->textura.GetHeight() - LARGO_VENTANA / ZOOM));
	} else {
		pos_y_pantalla = 0;
		tam_y_pantalla = LARGO_VENTANA;
	}
	renderer.Copy(this->textura,
		SDL2pp::Rect(
			this->pos_x,
			this->pos_y,
			ANCHO_VENTANA / ZOOM,
			LARGO_VENTANA / ZOOM),
		SDL2pp::Rect(pos_x_pantalla, pos_y_pantalla, tam_x_pantalla, tam_y_pantalla));
}
