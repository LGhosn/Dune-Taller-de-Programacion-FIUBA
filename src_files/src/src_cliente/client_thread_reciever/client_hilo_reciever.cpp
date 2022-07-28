#include "client_hilo_reciever.h"
#include "../client_comandos/cmd_salir.h"
#include "../client_comandos/cmd_modificar_especia.h"
#include "../client_comandos/cmd_actualizar_tienda_edificios.h"
#include "../client_comandos/cmd_actualizar_tienda_unidades.h"
#include "../client_comandos/cmd_empezar_construccion_edificio.h"
#include "../client_comandos/cmd_construccion_invalida.h"
#include "../client_comandos/cmd_empezar_entrenamiento.h"
#include "../client_comandos/cmd_modificar_energia.h"
#include "../client_comandos/cmd_enemigo_despliega_unidad.h"
#include "../client_comandos/cmd_actualizar_puntaje.h"
#include "../client_comandos/cmd_modificar_vida_unidad.h"
#include "../client_comandos/cmd_modificar_vida_edificio.h"
#include "../client_comandos/cmd_terminar_partida.h"
#include "../client_DTO/dto_cmd_empezar_construccion_edificio.h"
#include "../client_DTO/dto_cmd_enemigo_despliega_unidad.h"
#include "../client_DTO/dto_cmd_actualizar_puntajes_cliente.h"
#include "../client_DTO/dto_cmd_modificar_vida_unidad_cliente.h"
#include "../client_DTO/dto_cmd_modificar_vida_edificio_cliente.h"


ClientHiloReciever::ClientHiloReciever(ColaNoBloqueante<ComandoCliente>& cola_eventos, ProtocoloCliente& protocolo_asociado) :
                                        protocolo_asociado(protocolo_asociado),
                                        cola_eventos(cola_eventos) {}

void ClientHiloReciever::handleThread() {
    try {
        this->run();
    } catch (const SocketError& e) {
        std::cerr << "Se cerro el Receiver" << std::endl;
        if (servidor_termino_partida) {
            std::cerr << "Pusheando ComandoSalir" << std::endl;
            cola_eventos.push(new ComandoSalir());
        }
    } catch (const std::exception& e) {
        std::cerr << "Excepción encontrada en ClientHiloReceiver: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida en ClientHiloReceiver: " << std::endl;
    }
}

void ClientHiloReciever::run() {
    while (this->hay_que_seguir) {
        uint8_t codigo_comando;
        protocolo_asociado.recibirCodigoDeComando(codigo_comando);
        ComandoCliente* comando = this->crearComandoSegunCodigo(codigo_comando);
        cola_eventos.push(comando);
    }
}

ComandoCliente* ClientHiloReciever::crearComandoSegunCodigo(uint8_t codigo) {
    switch (codigo) {
        // Solicitan crear un edificio
        case 5:{
            ComandoCrearEdificioDTO comandoDTO = protocolo_asociado.recibirComandoCrearEdificio();
            return new ComandoCrearEdificio(comandoDTO);
        }
        case 6: {
            return new CmdConstruccionInvalidaCliente();
        }
        case 11: {
            CmdEmpezarEntrenamientoClienteDTO comandoDTO = protocolo_asociado.recibirComandoEmpezarEntrenamientoUnidad();
            return new CmdEmpezarEntrenamientoCliente(comandoDTO);
        }
        case 12: {
            CmdMoverUnidadClienteDTO comandoDTO = protocolo_asociado.recibirComandoMoverUnidad();
            return new CmdMoverUnidadCliente(comandoDTO);
        }
        case 13: {
            CmdEnemigoDespliegaUnidadDTO comandoDTO = protocolo_asociado.recibirComandoEnemigoDespliegaUnidad();
            return new CmdEnemigoDespliegaUnidadCliente(comandoDTO);
        }
        case 20: {
            uint16_t cantidad_especia = protocolo_asociado.recibirComandoModificarEspecia();
            return new CmdModificarEspeciaServer(cantidad_especia);
        }
        case 21: {
            std::vector<bool> edificios_comprables = protocolo_asociado.recibirComandoActualizarTiendaEdificios();
            return new CmdActualizarTiendaEdificiosCliente(edificios_comprables);
        }
        case 22: {
            std::vector<bool> unidades_comprables = protocolo_asociado.recibirComandoActualizarTiendaUnidades();
            return new CmdActualizarTiendaUnidadesCliente(unidades_comprables);
        }
        case 25: {
            CmdEmpezarConstruccionEdificioDTO comando_dto = protocolo_asociado.recibirComandoEmpezarConstruccionEdificio();
            return new CmdEmpezarConstruccionEdificioCliente(comando_dto.tipo,
                                                            comando_dto.tiempo_construccion);
        }
        case 30: {
            int16_t cantidad_energia = protocolo_asociado.recibirComandoModificarEnergia();
            return new CmdModificarEnergiaCliente(cantidad_energia);
        }
        case 40: {
            CmdActualizarPuntajesClienteDTO comandoDTO = protocolo_asociado.recibirComandoActualizarPuntajes();
            return new CmdActualizarPuntajeCliente(comandoDTO.id_jugador, comandoDTO.nuevo_puntaje);
        }
        case 50: {
            CmdMoverUnidadClienteDTO comandoDTO = protocolo_asociado.recibirComandoMoverUnidad();
            return new CmdMoverUnidadCliente(comandoDTO);
        }
        case 60: {
            CmdModificarVidaUnidadClienteDTO comandoDTO = protocolo_asociado.recibirComandoModificarVidaUnidad();
            return new CmdModificarVidaUnidadCliente(comandoDTO);
        }
        case 61: {
            CmdModificarVidaEdificioClienteDTO comandoDTO = protocolo_asociado.recibirComandoModificarVidaEdificio();
            return new CmdModificarVidaEdificioCliente(comandoDTO.id_edificio, comandoDTO.unidad_atacante, comandoDTO.vida);
        }
        case 70: {
            uint8_t id_ganador = protocolo_asociado.recibirComandoTerminarPartida();
            return new CmdTerminarPartidaCliente(id_ganador);
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

void ClientHiloReciever::stop() {
    this->hay_que_seguir = false;
    servidor_termino_partida = false;
    protocolo_asociado.cerrarSocket();
    this->thread.join();
    std::cerr << "Stop en receiver" << std::endl;
}

ClientHiloReciever::~ClientHiloReciever() {
    if (this->thread.joinable()) {
        stop();
    }
    std::cerr << "Destruyendo HiloReceiver\n";
}
