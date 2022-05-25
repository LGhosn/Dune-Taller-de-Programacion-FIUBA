#include "sdl_mapa.h"

MapaSDL::MapaSDL(SDL2pp::Texture& textura) : textura(textura),
pos_x((textura.GetWidth() - ANCHO_EN_PANTALLA) / 2), pos_y((textura.GetHeight() - ANCHO_EN_PANTALLA) / 2),
moviendose(false), direccion(ARRIBA), tiempo(0.0f) {}

void MapaSDL::moverArriba() {
	if (pos_y > 0) {
		this->direccion = ARRIBA;
		this->moviendose = true;
	}
}

void MapaSDL::moverIzquierda() {
	if (pos_x > 0) {
		this->direccion = IZQUIERDA;
		this->moviendose = true;
	}
}

void MapaSDL::moverAbajo() {
	if (pos_y < this->textura.GetHeight() - LARGO_EN_PANTALLA) {
		this->direccion = ABAJO;
		this->moviendose = true;
	}
}

void MapaSDL::moverDerecha() {
	if (pos_x < this->textura.GetWidth() - ANCHO_EN_PANTALLA) {
		this->direccion = DERECHA;
		this->moviendose = true;
	}
}

void MapaSDL::dejarDeMoverse() {
	this->moviendose = false;
}

void MapaSDL::update(float tiempo_transcurrido) {
	if (moviendose) {
		switch(this->direccion) {
			case ARRIBA:
				if (this->pos_y > 0) {
					this->tiempo += tiempo_transcurrido;
					while(this->tiempo >= FRAME_RATE) {
						pos_y -= PASO;
						this->tiempo -= FRAME_RATE;
						if (this->pos_y < 0) {
							pos_y = 0;
							this->tiempo = 0.0f;
							this->moviendose = false;
							break;
						}
					}
				}
				break;
			case IZQUIERDA:
				if (this->pos_x > 0) {
					this->tiempo += tiempo_transcurrido;
					while(this->tiempo >= FRAME_RATE) {
						pos_x -= PASO;
						this->tiempo -= FRAME_RATE;
						if (this->pos_x < 0) {
							pos_x = 0;
							this->tiempo = 0.0f;
							this->moviendose = false;
							break;
						}
					}
				}
				break;
			case ABAJO:
				if (this->pos_y < this->textura.GetHeight() - LARGO_EN_PANTALLA) {
					this->tiempo += tiempo_transcurrido;
					while(this->tiempo >= FRAME_RATE) {
						pos_y += PASO;
						this->tiempo -= FRAME_RATE;
						if (this->pos_y > this->textura.GetHeight() - LARGO_EN_PANTALLA) {
							pos_y = this->textura.GetHeight() - LARGO_EN_PANTALLA;
							this->tiempo = 0.0f;
							this->moviendose = false;
							break;
						}
					}
				}
				break;
			case DERECHA:
				if (this->pos_x < this->textura.GetWidth() - ANCHO_EN_PANTALLA) {
					this->tiempo += tiempo_transcurrido;
					while(this->tiempo >= FRAME_RATE) {
						pos_x += PASO;
						this->tiempo -= FRAME_RATE;
						if (this->pos_x > this->textura.GetWidth() - ANCHO_EN_PANTALLA) {
							pos_x = this->textura.GetWidth() - ANCHO_EN_PANTALLA;
							this->tiempo = 0.0f;
							this->moviendose = false;
							break;
						}
					}
				}
				break;
		}
	}
}

void MapaSDL::render(SDL2pp::Renderer& renderer) {
	renderer.Copy(this->textura,
		SDL2pp::Rect(
			this->pos_x,
			this->pos_y,
			ANCHO_EN_PANTALLA,
			LARGO_EN_PANTALLA),
		SDL2pp::Rect(0,0,700,700));
}
