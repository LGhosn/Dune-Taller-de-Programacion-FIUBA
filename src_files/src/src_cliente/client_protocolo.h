#ifndef CLIENT_PROTOCOLO_H
#define CLIENT_PROTOCOLO_H

#include "../src_common/common_DTO/Status.h"
#include "../src_common/common_DTO/dto_sol_crear_partida.h"
#include "../src_common/common_DTO/dto_sol_unirse_a_partida.h"
#include "../src_common/common_DTO/dto_info_partida.h"
#include "client_DTO/dto_cmd_crear_edificio.h"
#include "client_DTO/dto_cmd_actualizar_puntajes_cliente.h"
#include "client_DTO/dto_cmd_empezar_construccion_edificio.h"
#include "client_DTO/dto_cmd_empezar_entrenamiento_unidad.h"
#include "client_DTO/dto_cmd_modificar_energia.h"
#include "client_DTO/dto_cmd_mover_unidad.h"
#include "client_DTO/dto_cmd_enemigo_despliega_unidad.h"
#include "client_serializador.h"
#include "../src_common/common_serializador.h"
#include "../src_common/common_socket.h"
#include "../src_common/common_coords.h"
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <fstream>
#include <netinet/in.h>
#include <map>

#define CODIGO_COMIENZO_PARTIDA 0

class ProtocoloCliente {
private:
    Socket& skt_cliente;
    SerializadorCliente serializador;

    void enviarBuffer(const std::vector<uint8_t>& buffer) const;
    std::string recibirNombre() const;
    Coordenadas recibirCoordenadas() const;
    std::map<uint8_t, std::pair<uint8_t, std::string>> recibirInfoJugadores();

public:
    explicit ProtocoloCliente(Socket& skt_cliente);

    void cerrarSocket();

    uint8_t obtenerId() const;

    void enviarSolicitudCrearPartida(SolicitudCrearPartidaDTO& solicitud);
    void enviarSolicitudUnirseAPartida(SolicitudUnirseAPartidaDTO& solicitud);
    void enviarSolicitudMoverUnidad(uint8_t id_jugador, uint8_t id_unidad, Coordenadas& coords_a_moverse);

    void recibirCodigoDeComando(uint8_t& codigo);
    void recibirInfoSegunCodigo(uint8_t& codigo);
    // void recibirInfoMoverUnidad();

    ComandoCrearEdificioDTO recibirComandoCrearEdificio();
    void enviarSolicitudCrearEdificio(uint8_t id_jugador, Coordenadas& coords, uint8_t tipo);
    void enviarSolicitudUnirseAPartida(std::string& casa, std::string& nombre_partida);

    uint16_t recibirComandoModificarEspecia();
    CmdActualizarPuntajesClienteDTO recibirComandoActualizarPuntajes();

    /*
     * Recibe el status de una petición de union o creacion, el mismo
     * será usado por el cliente para imprimir un mensaje.
     * */
    Status recibirStatus();
    InfoPartidaDTO recibirInfoComienzoDePartida();

/* *****************************************************************
 *          METODOS REFERIDOS A COMPRA DE EDIFICIOS
 * *****************************************************************/
    void enviarSolicitudComprarEdificio(uint8_t id_jugador, uint8_t tipo);
    std::vector<bool> recibirComandoActualizarTiendaEdificios();
    CmdEmpezarConstruccionEdificioDTO recibirComandoEmpezarConstruccionEdificio();

/* *****************************************************************
 *          METODOS REFERIDOS A COMPRA DE UNIDADES
 * *****************************************************************/
    void enviarSolicitudComprarUnidad(uint8_t id_jugador, uint8_t tipo);
    std::vector<bool> recibirComandoActualizarTiendaUnidades();
    CmdEmpezarEntrenamientoClienteDTO recibirComandoEmpezarEntrenamientoUnidad();
    CmdEnemigoDespliegaUnidadDTO recibirComandoEnemigoDespliegaUnidad();
    
/* *****************************************************************
 *          METODOS REFERIDOS A MOVER UNIDADES
 * *****************************************************************/
    CmdMoverUnidadClienteDTO recibirComandoMoverUnidad();

/* *****************************************************************
 *                  METODOS REFERIDOS A ENERGIA
 * *****************************************************************/

    int16_t recibirComandoModificarEnergia();

/* *****************************************************************
 *                  METODOS REFERIDOS A ATAQUES
 * *****************************************************************/
    void enviarSolicitudAtacarUnidad(uint8_t id_jugador_atacante, uint8_t id_unidad_atacante, uint8_t id_unidad_atacada, Coordenadas& coords);


/* *****************************************************************
 *                         MOVE SEMANTICS
 * *****************************************************************/

    /*
     * No tiene sentido copiar un ProtocoloCliente, tampoco moverlo.
     * */
    ProtocoloCliente(const ProtocoloCliente&) = delete;
    ProtocoloCliente& operator=(const ProtocoloCliente&) = delete;
    ProtocoloCliente(ProtocoloCliente&&) = delete;
    ProtocoloCliente& operator=(ProtocoloCliente&&) = delete;
};
#endif
