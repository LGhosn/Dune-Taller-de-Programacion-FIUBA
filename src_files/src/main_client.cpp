#include "src_cliente/client_client.h"
#include "src_menu/MenuDune.h"
#include "src_cliente/client_thread_reciever/client_hilo_reciever.h"
#include "src_cliente/client_thread_sender/client_hilo_sender.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Client cliente(argv[1], argv[2]);
    MenuDune menu(cliente);
    menu.show();
    int resultado = QApplication::exec();
    if (resultado == 0) {
        cliente.empezarPartida();
    }
    return 0;
}
