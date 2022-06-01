#include "src_cliente/client_client.h"
#include "src_menu/MenuDune.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Client cliente(argv[1], argv[2]);
    MenuDune menu(cliente.protocoloAsociado());
    menu.show();
    return QApplication::exec();
}