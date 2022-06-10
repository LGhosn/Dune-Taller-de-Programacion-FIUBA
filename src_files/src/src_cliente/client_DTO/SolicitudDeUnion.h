#ifndef CLIENT_SOLICITUD_DE_UNION_H
#define CLIENT_SOLICITUD_DE_UNION_H

#include <string>

struct SolicitudDeUnion {
    const std::string nombre_partida;
    const std::string casa;

    SolicitudDeUnion(std::string& nombre_partida, std::string& casa) :
            nombre_partida(std::move(nombre_partida)),
            casa(std::move(casa)) {}
};


#endif //CLIENT_SOLICITUD_DE_UNION_H
