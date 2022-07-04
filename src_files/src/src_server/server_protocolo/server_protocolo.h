#ifndef SERVER_PROTOCOLO_H_
#define SERVER_PROTOCOLO_H_

#include "../server_DTO/partida_DTO.h"
#include "../../src_common/common_socket.h"
#include "../../src_common/common_coords.h"
#include "../../src_common/common_DTO/dto_sol_crear_partida.h"
#include "../../src_common/common_DTO/dto_sol_unirse_a_partida.h"
#include "../server_DTO/dto_sol_comprar_edificio.h"
#include "../../src_common/common_DTO/Status.h"
#include "../server_DTO/dto_sol_crear_edificio.h"
#include "../server_DTO/dto_sol_comprar_unidad.h"
#include "../server_DTO/dto_sol_mover_unidad.h"
#include "../server_DTO/dto_sol_atacar_unidad.h"
#include "../../src_common/common_DTO/dto_info_partida.h"
#include "server_serializador.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <netinet/in.h>
#include "yaml-cpp/yaml.h"

class PartidaDTO;
class Status;

class ProtocoloServidor {
    Socket& skt_comunicador;
    SerializadorServer serializador;
    enum class Operaciones : uint8_t {unirse = 1, listar = 2, crear = 3};

/* *****************************************************************
 *                      METODOS AUXILIARES
 * *****************************************************************/

    /*
     * Envia un vector de bytes al cliente.
    */
    void enviarBuffer(const std::vector<uint8_t>& buffer) const;

    /*
     * Recibe el largo del nombre que el cliente quiere enviar, en formato de 2 bytes,
     * y luego recibe cada caracter del nombre de la partida/el mapa.
    */
    std::string recibirNombre() const;

public:
    /*
     * Construye la clase, estableciendo un socket
     * válido como su atributo.
     * */
    explicit ProtocoloServidor(Socket& comunicador, YAML::Node& codigos);

    void cerrarSocket();

    /*
     * Recibe el codigo de operacion solicitado
     * por el cliente.
     * */
    void recibirOperacion(uint8_t& codigo_operacion);

    void enviarId(uint8_t id_cliente);

/* *****************************************************************
 *             METODOS REFERIDOS A UNIRSE A PARTIDAS
 * *****************************************************************/

    /*
     * Recibe la casa a utilizar por el jugador y
     * el nombre de la partida a la cual quiere unirse,
     * luego en función de si la partida fue o no creada,
     * y está o no completa, envía un status al cliente.
     * Si la partida se completa, el servidor lo informa
     * con un mensaje.
     * */
    SolicitudUnirseAPartidaDTO recibirSolicitudUnirseAPartida();
    void enviarStatusDeUnion(Status &status_de_union);
    void enviarComienzoDePartida(const InfoPartidaDTO& info_partida);

/* *****************************************************************
 *             METODOS REFERIDOS A CREAR PARTIDAS
 * *****************************************************************/

    /*
     * Recibe la casa a utilizar por el jugador, los
     * jugadores requeridos para iniciar la partida
     * y el nombre de dicha partida, luego en función
     * de si la partida fue o no creada, envía un status
     * al cliente
     * */
    SolicitudCrearPartidaDTO recibirSolicitudCrearPartida();
    void enviarStatusDeCreacion(Status &status_de_creacion);

    uint8_t recibirCodigoDeSolicitud();

/* *****************************************************************
 *             METODOS REFERIDOS A MOVER UNIDADES
 * *****************************************************************/

    void enviarComandoMoverUnidad(uint8_t id_unidad, uint8_t direccion, uint16_t tiempo);

    SolicitudMoverUnidadDTO recibirSolicitudMoverUnidad();

/* *****************************************************************
 *             METODOS REFERIDOS A CREAR EDIFICIOS
 * *****************************************************************/

    void enviarComandoEmpezarConstruccionEdificio(uint8_t tipo_edificio,
                                                uint16_t tiempo_construccion);
    SolComprarEdificioDTO recibirSolicitudComprarEdificio();

    void enviarComandoCrearEdificio(uint8_t id_jugador, uint8_t id_edificio, uint8_t tipo,
                                    const Coordenadas& coords, uint8_t casa) const;
    SolicitudCrearEdificioDTO recibirSolicitudCrearEdificio();

    void enviarComandoConstruccionInvalida();

/* *****************************************************************
 *             METODOS REFERIDOS A COMPRAS
 * *****************************************************************/

    SolicitudComprarUnidadDTO recibirSolicitudComprarUnidad();

    void enviarComandoEmpezarEntrenamientoUnidad(uint8_t id_unidad, uint8_t tipo_unidad, uint16_t tiempo, Coordenadas& coords);

    void enviarComandoEnemigoDespliegaUnidad(uint8_t id_unidad, uint8_t id_jugador, uint8_t tipo_unidad, uint16_t tiempo, Coordenadas& coords);

/* *****************************************************************
 *             METODOS REFERIDOS A ACTUALIZAR ESPECIA
 * *****************************************************************/

    void enviarComandoModificarEspecia(uint16_t cantidad_especia);

    void enviarComandoModificarEnergia(int16_t cantidad_energia);

/* *****************************************************************
 * METODOS REFERIDOS A ACTUALIZAR ESTADO COMPRA EDIFICIOS Y UNIDADES
 * *****************************************************************/

    void enviarComandoActualizarTiendaEdificios(const std::vector<bool>& edificios_comprables);

    void enviarComandoActualizarTiendaUnidades(const std::vector<bool>& unidades_comprables);

    void enviarComandoEmpezarEntrenamientoUnidad(uint8_t tipo_unidad, uint16_t tiempo_construccion, Coordenadas& coords_spawn);

/* *****************************************************************
 *                  METODOS REFERIDOS A PUNTAJE
 * *****************************************************************/

    void enviarComandoActualizarPuntaje(uint8_t id_jugador, uint16_t nuevo_puntaje);

/* *****************************************************************
 *                  METODOS REFERIDOS A ATAQUES
 * *****************************************************************/
    SolicitudAtacarUnidadDTO recibirSolicitudAtacarUnidad();

/* *****************************************************************
 *                  MOVE SEMANTICS
 * *****************************************************************/
    /*
     * No tiene sentido copiar un ProtocoloServidor.
     * */
    ProtocoloServidor(const ProtocoloServidor&) = delete;
    ProtocoloServidor& operator=(const ProtocoloServidor&) = delete;
    ProtocoloServidor(ProtocoloServidor&&) = delete;
    ProtocoloServidor& operator=(ProtocoloServidor&&) = delete;
};
#endif  // SERVER_PROTOCOLO_H_
