#include "sdl_edificio.h"

EdificioSDL::EdificioSDL(MapaSDL& mapa, SDL2pp::Texture& textura, int pos_x, int pos_y,
	uint8_t ancho, uint8_t largo) :
	mapa(mapa), textura(textura), pos_x(pos_x), pos_y(pos_y), ancho(ancho), largo(largo) {}


void EdificioSDL::render(SDL2pp::Renderer& renderer) {
	renderer.Copy(
		this->textura,
		SDL2pp::Rect(
			0,
			0,
			this->ancho,
			this->largo
		),
		SDL2pp::Rect(
			(this->pos_x - this->mapa.obtener_offset_x()) * this->mapa.obtener_zoom(),
			(this->pos_y - this->mapa.obtener_offset_y()) * this->mapa.obtener_zoom(),
			ancho * this->mapa.obtener_zoom(),
			largo * this->mapa.obtener_zoom()
		)
	);
}