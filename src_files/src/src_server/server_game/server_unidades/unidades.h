#ifndef SERVER_UNIDADES_H
#define SERVER_UNIDADES_H

#define DISTANCIA_A_MOVER 16

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
#include "../entidad_server.h"

class Arma;

class Unidad : public EntidadServer{
    static uint8_t contador_ids;
protected:
    Jugador& duenio;
    const uint8_t tipo_unidad;
    Mapa& mapa;
    Coordenadas origen;
    Coordenadas destino;
    uint8_t id;
    std::unique_ptr<Arma> arma;
    bool moviendose = false;
    bool atacando = false;
    bool esta_viva = true;
    bool persiguiendo = false;
    std::stack<Coordenadas> camino;
    long ticks_para_sig_movimiento = 0;
    long ticks_restantes = 0;
    std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos;
    std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades;
    std::shared_ptr<EntidadServer> unidad_a_atacar = nullptr;

    // Atributos
    uint8_t rango;
    int16_t velocidad;
    uint16_t tiempo_entrenamiento;
    uint16_t vida;
    uint16_t costo;
    std::vector<float> penalizacion_terreno;
    std::vector<uint8_t> terrenos_no_accesibles;

    // Constantes
    const uint16_t ticks;

    virtual void setTicksParaSigMovimiento(uint16_t tiempo_para_moverse);

    uint16_t obtenerTiempoParaMoverse();

    void updateMovimiento(long ticks_transcurridos);
    void updateAtaque(long ticks_transcurridos);

    void setearNuevoMovimiento();

    bool estaEnRango(Coordenadas& coords) const;

    void atacarUnidadEnRango();
    void enviarComando();

    void enviarComandoEmpezarEntrenamiento();
    void setearNuevoCamino();

public:
    Unidad(Jugador& duenio,
            uint8_t tipo_unidad,
            Mapa& mapa,
            YAML::Node& constantes,
            std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comando,
            std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades);

    virtual Coordenadas& ubicacion();
    virtual bool sigueViva();
    virtual uint8_t obtenerIdJugador();
    virtual uint8_t obtenerId() const;
    virtual void recibirDmg(uint8_t dmg_entrante, uint8_t id_unidad_atacante);
    virtual void empezarMovimiento(const Coordenadas& destino);
    virtual bool update(long ticks_transcurridos);
    virtual void atacar(std::shared_ptr<EntidadServer> unidad_a_atacar);
    virtual uint8_t obtenerTipoDeUnidad() = 0;
    virtual ~Unidad() = default;
};

#endif // SERVER_UNIDADES_H
