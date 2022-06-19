#ifndef DUNE_EDITOR_H
#define DUNE_EDITOR_H

#include <cstdlib>
#include <QMessageBox>
#include <QMainWindow>
#include <QScreen>
#include "DuneMapEditor_ui.h"

class DuneMapEditor: public QMainWindow {
private:
    Ui_DuneMapEditor* ui;
    std::string edition_mode = "-";
    std::string terrain_type = "-";
    std::string terrain_texture = "-";
    uint8_t required_players = 0;
    uint32_t map_rows = 250;
    uint32_t map_columns = 250;

    /* *****************************************************************
     *             METODOS REFERIDOS A REINICIAR CAMPOS
     * *****************************************************************/

    /*
     * Reestablece todos los campos del editor.
     */
    void reset();

    /*
     * Reestablecemos el modo de edición.
     */
    void resetEditionMode();

    /*
     * Reestablecemos los jugadores requeridos.
     */
    void resetRequiredPlayers();

    /*
     * Reestablecemos las dimensiones del mapa.
     */
    void resetDimensions();

    /*
     * Reestablecemos el tipo de terreno.
     */
    void resetTerrainType();

    /*
     * Reestablecemos el tipo de textura del terreno.
     */
    void resetTerrainTexture();

/* *****************************************************************
 *             METODOS REFERIDOS AL GUARDADO DE MAPAS
 * *****************************************************************/

    /*
     * Guarda el mapa creado/editado.
     */
    void saveMap();

    /*
     * Establece atributos del editor en función de
     * los campos del mismo.
     */
    void setFields();

    /*
     * Advierte si algún campo no fue rellenado de la manera correspondiente.
     */
    void checkIfSomeFieldIsNotCompleted();

    /*
     * Devuelve un booleano indicando si se eligió algún modo de edición.
     */
    bool editionModeIsNotSelected();

    /*
     * Devuelve un booleano indicando si se eligió la cantidad de jugadores requeridos.
     */
    bool requiredPlayersIsNotSelected();

public:
    explicit DuneMapEditor(QWidget *parent = nullptr);
};
#endif