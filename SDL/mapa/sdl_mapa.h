#ifndef SDL_MAPA_H
#define SDL_MAPA_H

#include <SDL2pp/SDL2pp.hh>
#include <string>

#define ANCHO_EN_PANTALLA 640
#define LARGO_EN_PANTALLA 640

#define ZOOM 1.3f

#define ANCHO_VENTANA 700
#define LARGO_VENTANA 700

#define PADDING 200

#define ARRIBA 'A'
#define IZQUIERDA 'I'
#define ABAJO 'B'
#define DERECHA 'D'

#define FRAME_RATE 0.1f / 3.0f

#define PASO 6

class MapaSDL {
	SDL2pp::Texture& textura;
	int pos_x;
	int pos_y;
	bool moviendose_h;
	bool moviendose_v;
	char direccion_h;
	char direccion_v;
	float tiempo;

	bool posicion_en_limite() const;

public:
	explicit MapaSDL(SDL2pp::Texture& textura);

	void moverArriba();
	void moverIzquierda();
	void moverAbajo();
	void moverDerecha();
	void dejarDeMoverseHorizontalmente();
	void dejarDeMoverseVerticalmente();

	int obtener_offset_x() const;
	int obtener_offset_y() const;

	void update(float tiempo_transcurrido);
	void render(SDL2pp::Renderer& renderer);
};

#endif
