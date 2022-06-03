#include "hilo_reciever.h"

HiloReceiver::HiloReciever(ColaNoBloqueante<Comando>& cola_eventos) : cola_eventos(cola_eventos) {}

void HiloReceiver::manejarHilo() {
    try {
        receiveInfoAndPushCommands();
    } catch (const std::exception& e) {
        std::cerr << "Excepción encontrada en hilo reciever: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida en hilo reciever" << std::endl;
    }
}

void HiloReceiver::recibirInfoYPushearComandos() {
    while (hayQueSeguirRecibiendo) {
        // Recibimos la info del server
        // Luego la traducimos a un comando
        // Finalmente encolamos el comando
    }
}

void HiloReceiver::push(Comando& comando_creado) {
    cola_eventos.push(comando_creado);
}