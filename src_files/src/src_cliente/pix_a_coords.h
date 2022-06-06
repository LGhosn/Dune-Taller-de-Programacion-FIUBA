#ifndef PIX_A_COORDS_H
#define PIX_A_COORDS_H

#include <cstdint>

class PixACoords {
private:
    uint16_t x;
    uint16_t y;

public:
    PixACoords(uint16_t x, uint16_t y);
    virtual ~PixACoords();
    virtual uint16_t get_x();
    virtual uint16_t get_y();
};

#endif // PIX_A_COORDS_H
