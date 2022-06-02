#ifndef SDL_MAPA_H
#define SDL_MAPA_H

#include <SDL2pp/SDL2pp.hh>
#include <string>

#define ARRIBA 'A'
#define IZQUIERDA 'I'
#define DERECHA 'D'
#define ABAJO 'B'

#define ZOOM_INICIAL 1.0f
#define ZOOM_INCR 0.1f
#define ZOOM_MIN 1.0f
#define ZOOM_MAX 2.0f

#define ANCHO_VENTANA 1024
#define LARGO_VENTANA 768

#define PADDING_LIMITE_VENTANA 100

#define PADDING 200

#define FRAME_RATE 0.1f / 6.0f

#define PASO 6

class MapaSDL {
	SDL2pp::Renderer& renderer;
	SDL2pp::Texture textura;
	int pos_x;
	int pos_y;
	bool moviendose_h;
	bool moviendose_v;
	char direccion_h;
	char direccion_v;
	float tiempo;
	float zoom;

public:
	explicit MapaSDL(SDL2pp::Renderer& renderer);

	void moverArriba();
	void moverIzquierda();
	void moverAbajo();
	void moverDerecha();
	void dejarDeMoverseHorizontalmente();
	void dejarDeMoverseVerticalmente();

	void zoomIn();
	void zoomOut();

	int obtener_offset_x() const;
	int obtener_offset_y() const;
	float obtener_zoom() const;

	void update(float tiempo_transcurrido);
	void render(long frame);
};

#endif
