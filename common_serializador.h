#ifndef SERIALIZADOR_H
#define SERIALIZADOR_H

#include <string>
#include <vector>
#include <tuple>

class Serializador {
public:
    Serializador() = default;

    uint16_t uint16_ntoh(uint16_t src);

    uint16_t uint16_hton(uint16_t src);

    std::vector<char> buffer_char(uint16_t tamanio);

    std::string buffer_to_string(std::vector<char> buffer);

    std::vector<char> string_to_buffer(std::string string);

    std::tuple<std::string, uint8_t, uint16_t, std::string> serializar_creacion(std::string argumento);

    std::tuple<std::string, uint16_t, std::string> serializar_union(std::string argumento);

    ~Serializador() = default;
};

#endif // SERIALIZADOR_H
