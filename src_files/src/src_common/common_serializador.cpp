#include "common_serializador.h"

uint16_t Serializador::uint16_ntoh(uint16_t src){
    return ntohs(src);
}

uint16_t Serializador::uint16_hton(uint16_t src){
    return htons(src);
}

std::vector<char> Serializador::buffer_char(uint16_t tamanio){
    return std::vector<char>(tamanio);
}

std::string Serializador::buffer_to_string(std::vector<char> buffer){
    return std::string(buffer.begin(), buffer.end());
}

std::vector<char> Serializador::string_to_buffer(std::string string){
    return std::vector<char>(string.begin(), string.end());
}

std::tuple<std::string, uint8_t, uint16_t, std::string> Serializador::serializar_creacion(std::string& argumento){
    std::stringstream parseo(argumento);
    std::string casa, requeridos, nombre_partida;
    parseo >> casa >> requeridos >> std::ws;
    std::getline(parseo, nombre_partida);

    uint8_t requeridos_num = std::stoul(requeridos);
    uint16_t largo_nombre = nombre_partida.length();

    return std::make_tuple(casa, requeridos_num, largo_nombre, nombre_partida);
}

std::tuple<std::string, uint16_t, std::string> Serializador::serializar_union(std::string& argumento){
    std::stringstream parseo(argumento);
    std::string casa, nombre_partida;
    parseo >> casa >> std::ws;
    std::getline(parseo, nombre_partida);

    uint16_t largo_nombre = nombre_partida.length();

    return std::make_tuple(casa, largo_nombre, nombre_partida);
}

uint8_t Serializador::obtenerCodigoOperacion(std::string& operacion) {
    return operaciones.at(operacion);
}

uint8_t Serializador::obtenerCodigoCasa(std::string& casa) {
    return casas.at(casa);
}