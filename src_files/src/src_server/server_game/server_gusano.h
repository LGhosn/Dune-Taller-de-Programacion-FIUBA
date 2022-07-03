#ifndef GUSANO_GAME_H
#define GUSANO_GAME_H

#include "yaml-cpp/yaml.h"
#include "server_mapa/server_mapa.h"

class Gusano {
    int victimas_a_devorar;
    uint16_t tiempo_entre_victimas;
    uint16_t ticks_para_sig_ataque;
    uint16_t ticks_restantes;
    Mapa& mapa;
    
public:
    Gusano(int victimas_a_devorar, uint16_t tiempo_entre_victimas, Mapa& mapa);
    void empezarAAsechar();
    bool tieneHambre();
    bool devorar(uint16_t ticks_transcurridos, uint8_t *id_victima);
};
#endif
