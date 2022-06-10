#ifndef PIX_A_COORDS_H
#define PIX_A_COORDS_H

#include <cstdint>

class PixACoords {
private:
    uint16_t x;
    uint16_t y;

public:
    PixACoords(uint16_t x, uint16_t y);
    uint16_t get_x();
    uint16_t get_y();
    ~PixACoords() = default;
};

#endif // PIX_A_COORDS_H
