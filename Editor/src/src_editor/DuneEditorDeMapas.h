#ifndef DUNE_EDITOR_H
#define DUNE_EDITOR_H

#include <vector>
#include <cstdlib>
#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QScreen>
#include "DuneEditorDeMapasUi.h"

#define CANTIDAD_INICIAL_DE_FILAS 250
#define CANTIDAD_INICIAL_DE_COLUMNAS 250

class DuneEditorDeMapas: public QMainWindow {
private:
    Ui_DuneMapEditor* ui;
    std::string modo_de_edicion = "-";
    std::string tipo_de_terreno = "-";
    std::string tipo_de_textura = "-";
    int jugadores_requeridos = 0;
    int cantidad_filas_mapa = CANTIDAD_INICIAL_DE_FILAS;
    int cantidad_columnas_mapa = CANTIDAD_INICIAL_DE_COLUMNAS;
    std::vector<std::vector<char>> mapa;

    /* *****************************************************************
     *             METODOS REFERIDOS A REINICIAR CAMPOS
     * *****************************************************************/

    /*
     * Reestablece todos los campos del editor.
     */
    void reestablecer();

    /*
     * Reestablecemos el modo de edición.
     */
    void reestablecerModoDeEdicion();

    /*
     * Reestablecemos los jugadores requeridos.
     */
    void reestablecerJugadoresRequeridos();

    /*
     * Reestablecemos las dimensiones del mapa.
     */
    void reestablecerDimensiones();

    /*
     * Reestablecemos el tipo de terreno.
     */
    void reestablecerTipoDeTerreno();

    /*
     * Reestablecemos el tipo de textura del terreno.
     */
    void reestablecerTexturaDelTerreno();

/* *****************************************************************
 *             METODOS REFERIDOS AL GUARDADO DE MAPAS
 * *****************************************************************/

    /*
     * Guarda el mapa creado/editado.
     */
    void guardarMapa();

    /*
     * Establece atributos del editor en función de
     * los campos del mismo.
     */
    void establecerCampos();

    /*
     * Advierte si algún campo no fue rellenado de la manera correspondiente.
     */
    void chequearSiAlgunCampoNoEstaCompleto();

    /*
     * Devuelve un booleano indicando si se eligió algún modo de edición.
     */
    bool elModoDeEdicionNoFueSeleccionado();

    /*
     * Devuelve un booleano indicando si se eligió la cantidad de jugadores requeridos.
     */
    bool losJugadoresRequeridosNoFueronSeleccionados();

    static void pedirNombreDelMapaAlUsuario(QWidget* parent);

/* *****************************************************************
*         METODOS REFERIDOS A LA PREVISUALIZACIÓN DE MAPAS
* *****************************************************************/
    void mostrarMapa();

public:
    explicit DuneEditorDeMapas(QWidget *parent = nullptr);
};
#endif