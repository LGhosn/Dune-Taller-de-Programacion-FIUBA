#ifndef SDL_EDIFICIO_H
#define SDL_EDIFICIO_H

#include <SDL2pp/SDL2pp.hh>
#include "../../../src_common/common_coords.h"

#define LARGO_TILE 32

#define ALTO_HP 6
#define ANCHO_HP 40

class EdificioSDL {
public:
    EdificioSDL() = default;

    virtual Coordenadas obtenerDimensiones() const = 0;
    
    virtual void cambiarHP(uint16_t hp_edificio) = 0;
    
    virtual void seleccionar() = 0;
    virtual void deseleccionar() = 0;

    virtual void update(uint32_t offset_x, uint32_t offset_y, long frame_actual) = 0;

    virtual void render() = 0;

    virtual ~EdificioSDL() = default;
};

#endif
