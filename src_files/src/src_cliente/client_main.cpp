#include "istream"
#include "common_socket.h"
#include "client_client.h"
#include <syslog.h>

#define SUCCESS 0
#define FAILURE 1

int main(int argc, char* argv[]) {
    try {
        Client cliente(argv[1], argv[2]);
        cliente.parsearEntrada();
        return SUCCESS;
    } catch (const std::exception &e) {
        syslog(LOG_CRIT, "Un error: %s", e.what());
    } catch (...) {
        syslog(LOG_CRIT, "Error desconocido.\n");
    }
    return FAILURE;
}
