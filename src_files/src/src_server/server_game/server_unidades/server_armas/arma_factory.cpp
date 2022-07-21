#include "arma_factory.h"
#include "Canion.h"
#include "Canion22mm.h"
#include "CanionDePlasma.h"
#include "LanzaMisiles.h"
#include "OndasDeSonido.h"
#include "Rifle.h"

ArmaFactory::ArmaFactory(YAML::Node& atributos, uint16_t ticks) :
                                atributos(atributos), ticks(ticks) {}

std::shared_ptr<Arma> ArmaFactory::obtenerArma(uint8_t tipo_unidad, uint8_t id_portador) const {
    switch (tipo_unidad) {
        case 0:
            return std::shared_ptr<Arma>(new Rifle(atributos, id_portador, ticks));
        case 1:
            return std::shared_ptr<Arma>(new Rifle(atributos, id_portador, ticks));
        case 2:
            return std::shared_ptr<Arma>(new LanzaMisiles(atributos, id_portador, ticks));
        case 3:
            return std::shared_ptr<Arma>(new LanzaMisiles(atributos, id_portador, ticks));
        case 4:
            return nullptr;
        case 5:
            return std::shared_ptr<Arma>(new LanzaMisiles(atributos, id_portador, ticks));
        case 6:
            return std::shared_ptr<Arma>(new CanionDePlasma(atributos, id_portador, ticks));
        case 7:
            return std::shared_ptr<Arma>(new Canion22mm(atributos, id_portador, ticks));
        case 8:
            return std::shared_ptr<Arma>(new Canion(atributos, id_portador, ticks));
        case 9:
            return std::shared_ptr<Arma>(new OndasDeSonido(atributos, id_portador, ticks));
        case 10:
            return std::shared_ptr<Arma>(new Rifle(atributos, id_portador, ticks));
        default:
            throw std::runtime_error("Arma Factory: tipo de arma no reconocido");
    }
}
