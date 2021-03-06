#include "cosechadora.h"

Cosechadora::Cosechadora(Jugador& duenio,
                        Mapa& mapa,
                        YAML::Node& atributos_unidad,
                        YAML::Node& constantes,
                        std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                        ArmaFactory& arma_factory,
                        std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
                        Unidad(duenio,
                                4,
                                mapa,
                                constantes,
                                colas_comandos,
                                0,
                                atributos_unidad["Vehiculo"]["Cosechadora"]["Velocidad"].as<float>(),
                                atributos_unidad["Vehiculo"]["Cosechadora"]["TiempoEntrenamiento"].as<uint16_t>(),
                                atributos_unidad["Vehiculo"]["Cosechadora"]["Vida"].as<int16_t>(),
                                atributos_unidad["Vehiculo"]["Cosechadora"]["Costo"].as<uint16_t>(),
                                atributos_unidad["Vehiculo"]["Cosechadora"]["PenalizacionTerreno"].as<std::vector<float>>(),
                                atributos_unidad["Vehiculo"]["Cosechadora"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>(),
                                arma_factory,
                                unidades) {
    // this->capacidad_especia = atributos_unidad["CapacidadCosechadora"].as<int>();
    // this->tiempo_extraer = atributos_unidad["TiempoDeExtraccion"].as<uint16_t>();
    // this->tiempo_depositar = atributos_unidad["TiempoDeDeposito"].as<uint16_t>();

    enviarComandoEmpezarEntrenamiento();
}

void Cosechadora::empezarProcesoDeCosecha(Coordenadas coords_cosecha) {
    //this->coords_refinamiento = mapa.obtenerCoordenadasDeRefinamientoParaCosechadora();
    //this->coords_cosecha = coords_cosecha;
}

void Cosechadora::cargarCosecha() {
    this->especia_cosechada += capacidad_maxima_extraccion_por_cosecha;
}

int Cosechadora::vaciarCosecha() {
    int total_especia_cosechada = capacidad_especia;
    int fraccion_a_depositar = total_especia_cosechada / 5;
    this->especia_cosechada -= fraccion_a_depositar;
    return fraccion_a_depositar;
}

void Cosechadora::volverACosechar() {
    if (mapa.esCoordenadaValida(coords_cosecha)) {
        this->moverA(coords_cosecha);
    }
}

void Cosechadora::volverARefinar() {
    if (mapa.esCoordenadaValida(coords_refinamiento)) {
        this->moverA(coords_refinamiento);
    }
}

bool Cosechadora::estaEnLasCoordenadasDeCosecha(){
    // return origen == coords_cosecha;
    return true;
}

void Cosechadora::update(long ticks_transcurridos) {
    // updateMovimiento(ticks_transcurridos);
}

uint8_t Cosechadora::obtenerTipoDeUnidad() {
    return 1;
}
