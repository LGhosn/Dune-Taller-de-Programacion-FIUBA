#ifndef SDL_EDIFICIO_H
#define SDL_EDIFICIO_H

#include <SDL2pp/SDL2pp.hh>
#include "../../../src_common/common_coords.h"

#define LARGO_TILE 16

class EdificioSDL {
public:
    EdificioSDL() = default;
    
    virtual void cambiarHP(uint16_t hp_edificio) = 0;
    
    virtual void update(uint32_t offset_x, uint32_t offset_y, long frame_actual) = 0;

    virtual void render() = 0;

    virtual ~EdificioSDL() = default;
};

#endif
