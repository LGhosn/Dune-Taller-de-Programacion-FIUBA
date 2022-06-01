#include "gtest/gtest.h"
#include "../../src_common/common_serializador.h"

TEST(Serializador, convierte_host_to_network){
    Serializador serializador;
    uint16_t numero = 0x1234;
    uint16_t numero_convertido = serializador.uint16_hton(numero);
    EXPECT_EQ(numero_convertido, 0x3412);
}

TEST(Serializador, convierte_network_to_host){
    Serializador serializador;
    uint16_t numero = 0x3412;
    uint16_t numero_convertido = serializador.uint16_ntoh(numero);
    EXPECT_EQ(numero_convertido, 0x1234);
}

TEST(Serializador, crea_buffer_de_tamanio_correcto){
    Serializador serializador;
    uint16_t tamanio = 10;
    std::vector<char> buffer = serializador.buffer_char(tamanio);
    EXPECT_EQ(buffer.size(), tamanio);
}

TEST(Serializador, convierte_string_a_buffer){
    Serializador serializador;
    std::string string = "hola";
    std::vector<char> buffer = serializador.string_to_buffer(string);
    int tamanio = (int)string.length();
    for (int i = 0; i < tamanio; i++) {
        EXPECT_EQ(buffer[i], string[i]);
    }
}

TEST(Serializador, convierte_buffer_a_string){
    Serializador serializador;
    std::string string = "hola";
    std::vector<char> buffer = serializador.string_to_buffer(string);
    std::string string_convertida = serializador.buffer_to_string(buffer);
    EXPECT_EQ(string_convertida, string);
}

TEST(Serializador, serializa_creacion_correctamente){
    Serializador serializador;
    std::string argumento = "casa_1 requeridos_1 nombre_partida_1";
    std::tuple<std::string, uint8_t, uint16_t, std::string> tupla = serializador.serializar_creacion(argumento);
    EXPECT_EQ(std::get<0>(tupla), "casa_1");
    EXPECT_EQ(std::get<1>(tupla), 1);
    EXPECT_EQ(std::get<2>(tupla), 10);
    EXPECT_EQ(std::get<3>(tupla), "nombre_partida_1");
}

TEST(Serializador, serializa_union_correctamente){
    Serializador serializador;
    std::string argumento = "casa_1 nombre_partida_1";
    std::tuple<std::string, uint16_t, std::string> tupla = serializador.serializar_union(argumento);
    EXPECT_EQ(std::get<0>(tupla), "casa_1");
    EXPECT_EQ(std::get<1>(tupla), 10);
    EXPECT_EQ(std::get<2>(tupla), "nombre_partida_1");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
