#include <string>
#include <stdint.h>

struct SolicitudDeCreacion {
    const std::string nombre_partida;
    const std::string mapa;
    const std::string casa;
    const uint8_t jugadores_requeridos;

    SolicitudDeCreacion(std::string& nombre_partida,
                        std::string& mapa,
                        std::string& casa,
                        uint8_t& jugadores_requeridos
                        ) :
            nombre_partida(std::move(nombre_partida)),
            mapa(std::move(mapa)),
            casa(std::move(casa)),
            jugadores_requeridos(jugadores_requeridos) {};
};

struct SolicitudDeUnion {
    const std::string nombre_partida;
    const std::string casa;

    SolicitudDeUnion(std::string& nombre_partida, std::string& casa) :
            nombre_partida(std::move(nombre_partida)),
            casa(std::move(casa)) {}
};

struct StatusDTO {
    const uint8_t status;
    explicit StatusDTO(uint8_t status) : status(status) {}
};
