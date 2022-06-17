#ifndef FORM_CREACION_H
#define FORM_CREACION_H

#include "../src_common/common_DTO/Status.h"
#include "../src_common/common_DTO/dto_sol_crear_partida.h"
#include "../src_cliente/client_protocolo.h"
#include "../src_cliente/client_client.h"
#include "ui_FormCreacionUi.h"
#include <syslog.h>
#include <set>
#include <string>
#include <QWidget>
#include <QScreen>
#include <QMessageBox>

class Ui_FromCrear;

class FormCreacion : public QWidget {
public:
    /*
     * Constructor de la clase, toma por paŕametro el protocolo del cliente
     * asociado para el envío de solicitudes de creación y su posterior informe
     * de estado.
     * */
    explicit FormCreacion(Client& cliente, QWidget* parent);

    /* Toma y valida los campos rellenados por el usuario para la creación
     * de una partida, la cual puede ser o no existente, el usuario será
     * notificado si hubo algún error al rellenar dichos campos y/o
     * la creación se dio con o sin éxito.
     * */
    void solicitudDeCreacion();

    /* Muestra un QMessageBox indicando si la union solicitada fue
     * completada con o sin éxito.
     * */
    void crearNotificacion(Status& status);

    /* Devuelve true si el nombre de partida, mapa, jugadores requeridos
     * la casa elegida no son válidos, falso en caso contrario.
     * */
    bool algunParametroNoEsValido(std::string& nombre_partida,
                                  std::string& mapa,
                                  std::string& casa,
                                  uint8_t& jugadores_requeridos);

    /* Devuelve true si el nombre de partida ingresado no es válido
     * es decir que está vacío o false en caso de haber sido completado.
     * */
    static bool elNombreDePartidaNoEsValido(std::string& nombre_partida);

    /* Devuelve true si el mapa ingresado no es válido es decir que está
     * vacío o false en caso de haber sido completado.
     * */
    static bool elMapaNoEsValido(std::string& mapa);

    /* Devuelve true si no se eligio una casa para utilizar al unirse
     * o false en caso contrario.
     * */
    bool laCasaNoEsValida(std::string &casa);

    /* Establece la casa elegida por el usuario como Atreides.
     * */
    void elegirCasaAtreides();

    /* Establece la casa elegida por el usuario como Harkonnen.
     * */
    void elegirCasaHarkonnen();

    /* Establece la casa elegida por el usuario como Ordos.
     * */
    void elegirCasaOrdos();

    ~FormCreacion() override;

    /*
     * No tiene sentido copiar un cliente y tampoco moverlo (al menos por ahora).
     * */
    FormCreacion(const FormCreacion&) = delete;
    FormCreacion& operator=(const FormCreacion&) = delete;
    FormCreacion(FormCreacion&&) = delete;
    FormCreacion& operator=(FormCreacion&&) = delete;
private:
    Client& cliente;
    Ui_FromCrear* ui;
    std::set<std::string> casas_elegibles = {"Atreides", "Harkonnen", "Ordos"};
};
#endif // FORM_CREACION_H
