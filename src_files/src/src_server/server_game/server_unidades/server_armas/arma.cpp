#include "arma.h"

Arma::Arma(uint8_t dmg,
        uint16_t frecuencia_disparo, std::vector<uint8_t> bonificaciones,
        uint16_t ticks):
        dmg(dmg),
        ticks_frecuencia_disparo(ticks / frecuencia_disparo),
        bonificaciones(bonificaciones) {}


void Arma::disparar(std::shared_ptr<Unidad> unidad_a_disparar){
    if (!en_cooldown) {
        uint8_t bonificacion = unidad_a_disparar->obtenerTipoDeUnidad();
        uint8_t dmg_total = dmg + bonificaciones[bonificacion];
        unidad_a_disparar->recibirDmg(dmg_total);
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
