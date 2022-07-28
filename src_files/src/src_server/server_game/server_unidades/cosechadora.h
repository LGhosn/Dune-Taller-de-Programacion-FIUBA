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
    Cosechadora(Jugador& duenio,
                Mapa& mapa,
                YAML::Node& atributos_unidad,
                YAML::Node& constantes,
                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                ArmaFactory& arma_factory,
                std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades);
    void cargarCosecha();
    int vaciarCosecha();
    void empezarProcesoDeCosecha(Coordenadas coords_cosecha);
    void volverACosechar();
    void volverARefinar();
    bool estaEnLasCoordenadasDeCosecha();
    virtual ~Cosechadora() = default;
    virtual void update(long ticks_transcurridos) override;
    virtual uint8_t obtenerTipoDeUnidad();
};

#endif
