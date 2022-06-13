#include "server_aceptador.h"

HiloAceptador::HiloAceptador(const char* servicename, YAML::Node* codigos) :
                            skt_aceptador(servicename),
                            codigos(codigos),
                            hilo_prepartida(&cola_solicitudes_menu, &colas_sender) {}

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
    clientes.emplace_back(aceptado, &lobby, codigos);
    uint8_t id_cliente = clientes.back().obtenerId();
    colas_sender[id_cliente] = clientes.back().obtenerColaSender();
}

bool HiloAceptador::hayQueSeguir() {
    return hay_que_seguir;
}

void HiloAceptador::limpiarHandlersClientesFinalizados() {
    esperarSiHaFinalizado();
}

bool HiloAceptador::esperarSiHaFinalizado() {

    std::list<HandlerCliente>::iterator iter = clientes.begin();
	while (iter != clientes.end()) {
		if (iter->haFinalizado()){
            iter = clientes.erase(iter);
            uint8_t id_cliente = iter->obtenerId();
            colas_sender.erase(id_cliente);
        } else {
            ++iter;
        }
	}
}

void HiloAceptador::esperarHandlersCliente() {
    std::list<HandlerCliente>::iterator iter = clientes.begin();
	while (iter != clientes.end()) {
        iter = clientes.erase(iter);
        uint8_t id_cliente = iter->obtenerId();
        colas_sender.erase(id_cliente);
	}
}

void HiloAceptador::terminar() {
    this->hay_que_seguir = false;
    skt_aceptador.shutdown(SHUT_RDWR);
}

HiloAceptador::~HiloAceptador() {
    if (this->hilo.joinable())
        this->hilo.join();
}
