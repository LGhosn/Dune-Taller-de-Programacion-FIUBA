#include "arma.h"

Arma::Arma(uint8_t dmg,
        uint16_t frecuencia_disparo, std::vector<uint8_t> bonificaciones,
        uint16_t ticks,
        uint8_t id_unidad_portador) :
        dmg(dmg),
        ticks_frecuencia_disparo(ticks / frecuencia_disparo),
        bonificaciones(bonificaciones),
        id_unidad_portador(id_unidad_portador) {}


void Arma::disparar(std::shared_ptr<EntidadServer> edificio_a_disparar) {
    if (!en_cooldown) {
        uint8_t dmg_total = dmg + bonificaciones[2];
        edificio_a_disparar->recibirDmg(dmg_total, id_unidad_portador);
        ticks_restantes = ticks_frecuencia_disparo;
        en_cooldown = true;
    }
}

void Arma::update(long frames_transcurridos) {
    if (en_cooldown) {
        if (frames_transcurridos > ticks_restantes) {
            en_cooldown = false;
        } else {
            ticks_restantes -= frames_transcurridos;
        }
    }
}
