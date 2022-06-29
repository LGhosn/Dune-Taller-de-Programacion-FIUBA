#ifndef FORM_UNION_H
#define FORM_UNION_H

#include "../src_common/common_DTO/Status.h"
#include "../src_common/common_DTO/dto_sol_unirse_a_partida.h"
#include "../src_cliente/client_protocolo.h"
#include "../src_cliente/client_client.h"
#include "../src_common/common_serializador.h"
#include "ui_FormUnionUi.h"
#include <set>
#include <syslog.h>
#include <QWidget>
#include <QScreen>
#include <QMessageBox>
#include <QCloseEvent>

class Ui_FormUnir;

class FormUnion : public QWidget {
public:
    /*
     * Constructor de la clase, toma por paŕametro el protocolo del cliente
     * asociado para el envío de solicitudes de unión y su posterior informe
     * de estado.
     * */
    explicit FormUnion(Client& cliente, QWidget* parent);

    /* Toma y valida los campos rellenados por el usuario para la unión a
     * una partida, la cual puede ser o no existente, el usuario será
     * notificado si hubo algún error al rellenar dichos campos y/o
     * la unión se dio con o sin éxito.
     * */
    void solicitudDeUnion();

    /* Devuelve true si el nombre de partida ingresado o la casa elegida
     * no son válidos, falso en caso contrario.
     * */
    bool algunParametroNoEsValido(std::string& casa, std::string& nombre_partida);

    /* Devuelve true si no se eligio una casa para utilizar al unirse
     * o false en caso contrario.
     * */
    bool laCasaNoEsValida(std::string& casa);

    /* Devuelve true si el nombre de partida ingresado no es válido
     * es decir que está vacío o false en caso de haber sido completado.
     * */
    static bool elNombreDePartidaNoEsValido(std::string& nombre_partida);

    /* Muestra un QMessageBox indicando si la union solicitada fue
     * completada con o sin éxito.
     * */
    void unirseNotificacion(ProtocoloCliente& protocolo, Status& status);

    /* Establece la casa elegida por el usuario como Atreides.
     * */
    void elegirCasaAtreides();

    /* Establece la casa elegida por el usuario como Harkonnen.
     * */
    void elegirCasaHarkonnen();

    /* Establece la casa elegida por el usuario como Ordos.
     * */
    void elegirCasaOrdos();

    ~FormUnion() override;

    /*
     * No tiene sentido copiar un cliente y tampoco moverlo (al menos por ahora).
     * */
    FormUnion(const FormUnion&) = delete;
    FormUnion& operator=(const FormUnion&) = delete;
    FormUnion(FormUnion&&) = delete;
    FormUnion& operator=(FormUnion&&) = delete;
private:
    Client& cliente;
    Ui_FormUnir* ui;
    std::set<std::string> casas_elegibles = {"Atreides", "Harkonnen", "Ordos"};
};
#endif //FORM_UNION_H
