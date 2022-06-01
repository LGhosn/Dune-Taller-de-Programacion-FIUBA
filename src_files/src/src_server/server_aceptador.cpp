#include "server_aceptador.h"

HiloAceptador::HiloAceptador(Socket& skt_aceptador,
                    Lobby& lobby,
                    std::atomic<bool> &hay_que_seguir):
                    skt_aceptador(skt_aceptador),
                    lobby(lobby),
                    hay_que_seguir(hay_que_seguir) {}

void HiloAceptador::atenderClientes() {
    try {
        while (this->hayQueSeguir()) {
            Socket aceptado = skt_aceptador.accept();
            this->lanzarHandlerCliente(aceptado);
            this->limpiarHandlersClientesFinalizados();
        }
    } catch (const SocketError &e){
        this->esperarHandlersCliente();
        syslog(LOG_CRIT, "Un error: %s", e.what());
    } catch (...) {
        syslog(LOG_CRIT, "Error desconocido.\n");
    }
}

void HiloAceptador::lanzarHandlerCliente(Socket& aceptado) {
    HandlerCliente* nuevo_cliente = new HandlerCliente(aceptado, lobby);
    // Guardo los Manejadores para poder esperarlos.
    clientes.push_back(nuevo_cliente);
    nuevo_cliente->iniciarComunicacion();
}

bool HiloAceptador::hayQueSeguir() {
    return hay_que_seguir;
}

void HiloAceptador::limpiarHandlersClientesFinalizados() {
    clientes.erase(std::remove_if(clientes.begin(),
                                  clientes.end(),
                                  esperarSiHaFinalizado),
                   clientes.end());
}

bool HiloAceptador::esperarSiHaFinalizado(HandlerCliente* cliente) {
    if (cliente->haFinalizado()) {
        cliente->cerrar_hilo();
        delete cliente;
        return true;
    } else {
        return false;
    }
}

void HiloAceptador::esperarHandlersCliente() {
    for (auto itr = clientes.begin(); itr != clientes.end(); itr++) {
        HandlerCliente* actual = *itr;
        actual->cerrar_conexion();
        actual->cerrar_hilo();
        delete actual;
    }
}
