#ifndef UNIDAD_COSECHADORA_H
#define UNIDAD_COSECHADORA_H

#include "unidades.h"

class Cosechadora : public Unidad {
    int capacidad_especia;
    int especia_cosechada = 0;
    int capacidad_maxima_extraccion_por_cosecha = 200;
    uint16_t tiempo_extraer;
    uint16_t tiempo_depositar;
    Coordenadas coords_refinamiento;
    Coordenadas coords_cosecha;
    
public:
    Cosechadora(uint8_t id,
                Jugador& duenio,
                Mapa& mapa,
                YAML::Node& atributos_unidad,
                Coordenadas& coords_spawn,
                YAML::Node& constantes,
                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos);
    void cargarCosecha();
    int vaciarCosecha();
    void empezarProcesoDeCosecha(Coordenadas coords_cosecha);
    void volverACosechar();
    void volverARefinar();
    bool estaEnLasCoordenadasDeCosecha();
    virtual ~Cosechadora() = default;
    void update(long ticks_transcurridos) override;
};

#endif
