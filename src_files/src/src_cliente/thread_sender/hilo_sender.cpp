#include "hilo_sender.h"

HiloSender::HiloSender(ColaBloqueante<ComandoAEnviar> &cola_comandos, ProtocoloCliente &protocolo) : cola_comandos(cola_comandos), protocolo(protocolo) {
    this->thread = std::thread(&HiloSender::run, this);
}

void HiloSender::run() {
    // try: // como pingo hacer esto
    while (this->hay_que_seguir) {
        std::unique_ptr<ComandoAEnviar> comando = this->cola_comandos.wait_and_pop();
        this->enviar(comando);
    }
    // } catch (std::exception &e) {}
}

void HiloSender::enviar(ComandoAEnviar &comando) {
    comando->enviar_instruccion(this->protocolo);
}

void HiloSender::stop() {
    this->hay_que_seguir = false;
}

HiloSender::~HiloSender() {
    this->thread.join();
}
