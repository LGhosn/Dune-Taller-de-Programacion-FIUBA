#ifndef SERVER_MANEJADOR_H_
#define SERVER_MANEJADOR_H_

#include "../server_lobby.h"
#include "../server_DTO/partida_DTO.h"
#include "../../src_common/common_socket_error.h"
#include "../../src_common/common_socket.h"
#include "../server_protocolo.h"
#include <utility>
#include <thread>
#include <atomic>
#include <syslog.h>

class Lobby;

class HiloClienteLobby {
    std::thread hilo;
    bool fue_cerrado = false;
    std::atomic<bool> flag_ha_finalizado;
    // Socket skt_comunicador;
    ProtocoloServidor& protocolo;
    Lobby* lobby;

    enum class Operaciones : uint8_t {
        unirse = 1, listar = 2, crear = 3, fin = 4
    };

    public:
    /*
     * Constructor de la clase, toma un Socket y una
     * ListaDePartidas por referencia para su interaccion
     * con las operaciones solicitadas por un Cliente, por
     * medio del ProtocoloServidor.
     */
    HiloClienteLobby(ProtocoloServidor& protocolo, Lobby* lobby);

    /*
    * En funcion de la operacion solicitada, se utilizara
    * al protocolo para llevar a cabo una de las mismas
    * y alterar al Lobby (utilizando DTOs).
     * */
    void evaluarOperacion(uint8_t operacion);
    void unirsePartida();
    void crearPartida();
    void listarPartidas();

    void comenzarPartida();

    /*
     * Lanza un hilo llamando al método
     * */
    void iniciarComunicacion();

    /*
     * Lanza un hilo el cual se comunica con un cliente.
     * */
    void comunicarseConCliente();

    
    /*
     * Hace join al hilo que maneja HiloClienteLobby.
     * */
    void cerrar_hilo();

    /*
     * No tiene sentido copiar un handler y tampoco moverlo (al menos por ahora).
     * */
    HiloClienteLobby(const HiloClienteLobby&) = delete;
    HiloClienteLobby& operator=(const HiloClienteLobby&) = delete;
    HiloClienteLobby(HiloClienteLobby&&) = delete;
    HiloClienteLobby& operator=(HiloClienteLobby&&) = delete;
};
#endif  // SERVER_MANEJADOR_H_
