// #ifndef SERVER_JUEGO_MAIN_H
// #define SERVER_JUEGO_MAIN_H

// #include "server_jugador.h"
// #include "server_protocolo.h"
// #include "../src_common/common_colas/cola_bloqueante.h"
// #include "../src_common/common_colas/cola_no_bloqueante.h"
// #include "../src_common/common_comandos/comando_a_enviar.h"
// #include "server_thread_reciever/server_hilo_reciever.h"
// #include "server_thread_sender/server_hilo_sender.h"
// #include "server_gameloop/server_gameloop.h"
// #include <vector>
// #include <string>
// #include <map>
// #include <thread>

// class PartidaEmpezada {
// private:
//     std::vector<Jugador>& jugadores;
//     std::string& ruta_mapa;
//     std::map<Jugador, ColaBloqueante<ComandoAEnviar> > colas_jugadores;
//     std::thread hilo;
//     Protocolo_servidor& protocolo;
    

//     void run();
//     void handleThread();
// public:
//     PartidaEmpezada(std::vector<Jugador>& jugadores, std::string& ruta_mapa, Protocolo_servidor& protocolo);
//     ~PartidaEmpezada();
// };

// #endif
