#ifndef SERVER_EDIFICIOS_SERVER_H
#define SERVER_EDIFICIOS_SERVER_H

#include <cstdint>
#include "yaml-cpp/yaml.h"
#include "../server_jugador/jugador.h"
#include "../server_mapa/server_mapa.h"
#include "../entidad_server.h"

class EdificioServer : public EntidadServer {
    static uint8_t contador_ids;

    void enviarVidaActualizada(uint8_t id_unidad_atacante);
protected:
    Jugador& duenio;
    Mapa& mapa;
    const uint8_t tipo_edificio;
    uint8_t id_edificio;
    Coordenadas& coords;
    std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos;
    std::unordered_map<uint8_t, std::shared_ptr<EdificioServer> >& edificios;
    bool es_centro;

    // Atributos
    uint16_t vida;
    // uint16_t costo;
    
    void enviarComandoCrearEdificio();

public:
    EdificioServer(Jugador& duenio,
                   Mapa& mapa,
                   uint8_t tipo_edificio,
                   Coordenadas& coords,
                   YAML::Node& constantes,
                   std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                   std::unordered_map<uint8_t, std::shared_ptr<EdificioServer> >& edificios);
    virtual uint8_t obtenerId();
    bool esCentro() const;
    virtual void recibirDmg(uint8_t dmg_entrante, uint8_t id_unidad_atacante);
    virtual const Coordenadas& ubicacion() const;
    virtual bool sigueViva();
    virtual ~EdificioServer() = default;
};

#endif // SERVER_EDIFICIOS_SERVER_H
