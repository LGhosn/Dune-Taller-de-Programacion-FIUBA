#ifndef SERVER_UNIDADES_H
#define SERVER_UNIDADES_H

#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

#include "yaml-cpp/yaml.h"
#include "../../server_DTO/dto_unidad_info.h"
#include "../server_jugador/jugador.h"
#include "../server_mapa/server_mapa.h"
#include "../../../src_common/common_colas/cola_bloqueante.h"
#include "../../server_comandos/server_comando.h"
#include "server_armas/arma.h"
#include "server_armas/arma_factory.h"
#include "../entidad_server.h"
#include "comportamiento/unidad_comportamiento.h"

class Arma;
class UnidadComportamiento;

class Unidad : public EntidadServer{
    friend class UnidadComportamiento;
    friend class UnidadModoAtaque;
    friend class UnidadModoPasivo;

    static uint8_t contador_ids;
protected:
    Jugador& duenio;
    const uint8_t tipo_unidad;
    uint8_t id;
    Coordenadas ubicacion_actual;
    std::shared_ptr<Arma> arma;
    std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos;

    // Atributos
    uint8_t rango;
    uint16_t velocidad;
    uint16_t tiempo_entrenamiento;
    uint16_t vida;
    uint16_t costo;
    std::vector<float> penalizacion_terreno;
    std::vector<uint8_t> terrenos_no_accesibles;
    Mapa& mapa;
    std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades;
    const uint16_t ticks;
    const uint16_t multiplicador_tiempo_mov;
    std::unique_ptr<UnidadComportamiento> comportamiento;

    void enviarComandoEmpezarEntrenamiento();

public:
    Unidad(Jugador& duenio,
            uint8_t tipo_unidad,
            Mapa& mapa,
            YAML::Node& constantes,
            std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comando,
            uint8_t rango,
            uint16_t velocidad,
            uint16_t tiempo_entrenamiento,
            uint16_t vida,
            uint16_t costo,
            std::vector<float> penalizacion_terreno,
            std::vector<uint8_t> terrenos_no_accesibles,
            ArmaFactory& arma_factory,
            std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades);

    Coordenadas& ubicacion();
    bool sigueViva();
    uint8_t obtenerIdJugador();
    uint8_t obtenerId() const;
    void recibirDmg(uint8_t dmg_entrante, uint8_t id_unidad_atacante);
    void moverA(const Coordenadas& destino);
    virtual void update(long ticks_transcurridos);
    void atacar(std::shared_ptr<EntidadServer> unidad_a_atacar);
    virtual uint8_t obtenerTipoDeUnidad() = 0;
    virtual ~Unidad() = default;
};

#endif // SERVER_UNIDADES_H
