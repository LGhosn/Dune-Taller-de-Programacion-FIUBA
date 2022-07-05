#include "arma.h"

void Arma::disparar(std::shared_ptr<Unidad> unidad_a_disparar) {
    uint8_t bonificacion = unidad_a_disparar->obtenerTipoDeUnidad();
    uint8_t dmg_total = dmg * frecuencia_disparo + dmg * bonificaciones[bonificacion];
    unidad_a_disparar->recibirDmg(dmg_total);
}