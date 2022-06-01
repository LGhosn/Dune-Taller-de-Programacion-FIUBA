#ifndef SERVER_MANEJADOR_H_
#define SERVER_MANEJADOR_H_

#include "../src_common/common_socket_error.h"
#include "server_lobby.h"
#include "server_protocolo.h"
#include "../src_common/common_DTOs.h"
#include <utility>
#include <thread>
#include <atomic>
#include <syslog.h>

class HandlerCliente {
    std::thread hilo;
    bool fue_cerrado = false;
    std::atomic<bool> flag_sigue_conectado;
    std::atomic<bool> flag_ha_finalizado;
    Socket skt_comunicador;
    Protocolo_servidor protocolo;
    Lobby& lobby;

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
    HandlerCliente(Socket& comunicador, Lobby& lobby);

    /*
    * En funcion de la operacion solicitada, se utilizara
    * al protocolo para llevar a cabo una de las mismas
    * y alterar al Lobby (utilizando DTOs).
     * */
    void evaluarOperacion(uint8_t operacion);
    void unirsePartida();
    void crearPartida();
    void listarPartidas();


    /*
     * Lanza un hilo llamando al método
     * */
    void iniciarComunicacion();

    /*
     * Lanza un hilo el cual se comunica con un cliente.
     * */
    void comunicarseConCliente();

    /*
     * Devuelve un booleano indicando si el hilo
     * termino su ejecucion.
     * */
    bool haFinalizado();
    
    /*
     * Cierra el socket del HandlerCliente.
     * */
    void cerrar_conexion();
    
    /*
     * Hace join al hilo que maneja HandlerCliente.
     * */
    void cerrar_hilo();

    /*
     * No tiene sentido copiar un handler y tampoco moverlo (al menos por ahora).
     * */
    HandlerCliente(const HandlerCliente&) = delete;
    HandlerCliente& operator=(const HandlerCliente&) = delete;
    HandlerCliente(HandlerCliente&&) = delete;
    HandlerCliente& operator=(HandlerCliente&&) = delete;
};
#endif  // SERVER_MANEJADOR_H_
