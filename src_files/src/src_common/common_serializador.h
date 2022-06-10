#ifndef COMMON_SERIALIZADOR_H
#define COMMON_SERIALIZADOR_H

#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <arpa/inet.h>
#include <sstream>

class Serializador {
private:
    std::map<std::string, uint8_t> operaciones = {{"unirse", 1}, {"listar", 2}, {"crear", 3}, {"mover", 4}, {"crear_edificio", 5}};
    std::map<std::string, uint8_t> casas = {{"Harkonnen", 0}, {"Atreides", 1}, {"Ordos", 2}};
public:
    Serializador() = default;

    static uint16_t uint16_ntoh(uint16_t src);

    uint16_t uint16_hton(uint16_t src);

    static std::vector<char> buffer_char(uint16_t tamanio);

    static std::string buffer_to_string(std::vector<char> buffer);

    static std::vector<char> string_to_buffer(std::string string);

    static std::tuple<std::string, uint8_t, uint16_t, std::string> serializar_creacion(std::string& argumento);

    static std::tuple<std::string, uint16_t, std::string> serializar_union(std::string& argumento);

    uint8_t obtenerCodigoOperacion(std::string& operacion);

    uint8_t obtenerCodigoCasa(std::string& casa);

    ~Serializador() = default;
};

#endif //COMMON_SERIALIZADOR_H
