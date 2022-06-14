#include "src_server/server_server.h"
#include <syslog.h>
#include <iostream>

#define SUCCESS 0
#define FAILURE 1

int main(int argc, char* argv[]) {
    try {
        Server servidor(argv[1]);
        servidor.iniciar();
        return SUCCESS;
    } catch (const std::exception &e) {
        syslog(LOG_CRIT, "Un error: %s", e.what());
    } catch (...) {
        syslog(LOG_CRIT, "Error desconocido.\n");
    }
    return FAILURE;
}