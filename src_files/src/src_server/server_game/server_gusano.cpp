#include "server_gusano.h"
#include "../../src_common/common_coords.h"
#include  <experimental/random>

Gusano::Gusano(int victimas_a_devorar, uint16_t tiempo_entre_victimas, Mapa& mapa) : 
            victimas_a_devorar(victimas_a_devorar), tiempo_entre_victimas(tiempo_entre_victimas), mapa(mapa) {}

bool Gusano::tieneHambre() {
    return victimas_a_devorar > 0;
}

void Gusano::empezarAAsechar() {
    this->ticks_para_sig_ataque = tiempo_entre_victimas * 60;
    this->ticks_restantes = this->ticks_para_sig_ataque;
}

bool Gusano::devorar(uint16_t ticks_transcurridos, uint8_t *id_victima) {
    if (tieneHambre()) {
        if (this->ticks_restantes > ticks_transcurridos) {
            this->ticks_restantes -= ticks_transcurridos;
            return false;
        } else {
            uint8_t potencia_victima;
            empezarAAsechar();
            if (mapa.obtenerUnidadRandomSobreArena(&potencia_victima)) {
                *id_victima = potencia_victima;
                victimas_a_devorar--;
                return true;
            }
        }
    }
    return false;
}
