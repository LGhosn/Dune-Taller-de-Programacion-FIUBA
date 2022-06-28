#include "client_hilo_reciever.h"
#include "../client_comandos/cmd_salir.h"
#include "../client_comandos/cmd_modificar_especia.h"
#include "../client_comandos/cmd_actualizar_tienda_edificios.h"
#include "../client_comandos/cmd_empezar_construccion_edificio.h"
#include "../client_DTO/dto_cmd_empezar_construccion_edificio.h"

ClientHiloReciever::ClientHiloReciever(ColaNoBloqueante<ComandoCliente>& cola_eventos, Client* cliente) :
                                        cliente(cliente),
                                        protocolo(cliente->protocoloAsociado()),
                                        cola_eventos(cola_eventos) {}

void ClientHiloReciever::handleThread() {
    try {
        this->run();
    } catch (const SocketError& e) {
        std::cerr << "Se cerro el Receiver" << std::endl;
        cola_eventos.push(new ComandoSalir());
    } catch (const std::exception& e) {
        std::cerr << "Excepción encontrada en ClientHiloReceiver: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida en ClientHiloReceiver: " << std::endl;
    }
}

void ClientHiloReciever::run() {
    while (this->hay_que_seguir) {
        uint8_t codigo_comando;
        protocolo.recibirCodigoDeComando(codigo_comando);
        ComandoCliente* comando = this->crearComandoSegunCodigo(codigo_comando);
        cola_eventos.push(comando);
    }
}

ComandoCliente* ClientHiloReciever::crearComandoSegunCodigo(uint8_t codigo) {
    switch (codigo) {
        // Solicitan crear un edificio
        case 5:{
            ComandoCrearEdificioDTO comandoDTO = protocolo.recibirComandoCrearEdificio();
            return new ComandoCrearEdificio(comandoDTO);
        }
        case 20: {
            uint16_t cantidad_especia = protocolo.recibirComandoModificarEspecia();
            return new CmdModificarEspeciaServer(cantidad_especia);
        }
        case 21: {
            std::vector<bool> edificios_construidos = protocolo.recibirComandoActualizarTiendaEdificios();
            return new CmdActualizarTiendaEdificiosCliente(edificios_construidos);
        }
        case 25: {
            CmdEmpezarConstruccionEdificioDTO comando_dto = protocolo.recibirComandoEmpezarConstruccionEdificio();
            return new CmdEmpezarConstruccionEdificioCliente(comando_dto.tipo,
                                                            comando_dto.tiempo_construccion);
        }
        default:
            throw std::runtime_error("ClientHiloReciever: Codigo de comando desconocido");
    }
}


void ClientHiloReciever::start() {
    this->thread = std::thread(&ClientHiloReciever::handleThread, this);
}

void ClientHiloReciever::push(ComandoCliente* comando_creado) {
    this->cola_eventos.push(comando_creado);
}

ClientHiloReciever::~ClientHiloReciever() {
    this->hay_que_seguir = false;
    if (this->thread.joinable()) {
        this->thread.join();
    }
    std::cerr << "Destruyendo HiloReceiver\n";
}