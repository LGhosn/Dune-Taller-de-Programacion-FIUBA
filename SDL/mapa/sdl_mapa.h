#ifndef SDL_MAPA_H
#define SDL_MAPA_H

#include <SDL2pp/SDL2pp.hh>
#include <string>

#define ANCHO_EN_PANTALLA 640
#define LARGO_EN_PANTALLA 640

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
	bool moviendose;
	char direccion;
	float tiempo;

	bool posicion_en_limite() const;

public:
	explicit MapaSDL(SDL2pp::Texture& textura);

	void moverArriba();
	void moverIzquierda();
	void moverAbajo();
	void moverDerecha();
	void dejarDeMoverse();

	void update(float tiempo_transcurrido);
	void render(SDL2pp::Renderer& renderer);
};

#endif
