#ifndef DUNE_EDITOR_H
#define DUNE_EDITOR_H

#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <QPixmap>
#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QScreen>
#include <filesystem>
#include <iostream>
#include <QDir>
#include <QScrollArea>
#include <QGridLayout>
#include "DuneEditorDeMapasUi.h"
#include "ClickableLabel.h"
#include "yaml-cpp/yaml.h"

#define TIPO_TEXTURA_DEFAULT 9
#define TIPO_TERRENO_DEFAULT 'A'

class DuneEditorDeMapas: public QMainWindow {
private:
    Ui_DuneEditorDeMapas* ui;
    QGridLayout* grilla;
    QString modo_de_edicion = "-";
    QString path_textura_seleccionada = RESOURCE_PATH"/terrenos/arena/mostrador/arena9.bmp"; // Textura default utilizada a la hora de crear un mapa desde cero.
    std::string tipo_de_terreno = "-";
    std::string tipo_de_textura = "-";
    int cantidad_jugadores;
    int cantidad_filas_mapa;
    int cantidad_columnas_mapa;
    char terreno_seleccionado = TIPO_TERRENO_DEFAULT;
    uint8_t textura_seleccionada = TIPO_TEXTURA_DEFAULT;
    std::vector<std::vector<char>>* grilla_terrenos = nullptr;
    std::vector<std::vector<uint8_t>>* grilla_texturas = nullptr;

/* *****************************************************************
 *             METODOS REFERIDOS AL GUARDADO DE MAPAS
 * *****************************************************************/

    /*
     * Guarda el mapa creado/editado.
     */
    void guardarMapa();
    void pedirNombreDelMapaAlUsuario(QWidget* parent);

/* *****************************************************************
*         METODOS REFERIDOS A LA PREVISUALIZACIÓN DE MAPAS
* *****************************************************************/
    /*
     * Según el tipo de terreno obtenido por el QComboBox de los tipos de terreno
     * se mostrarán las opciones a elegir en el QComboBox de las texturas del terreno.
     */
    void ofrecerTexturasSegunTipoDeTerreno();
    void ofrecerTexturasDeArena();
    void ofrecerTexturasDeDuna();
    void ofrecerTexturasDeRoca();
    void ofrecerTexturasDeCima();
    void ofrecerTexturasDePrecipicio();
    void ofrecerTexturasDeEspecia();

    /*
     * Según la textura obtenida por el QComboBox de los tipos de textura
     * se mostrará la textura seleccinada.
     */
    void mostrarTexturaSegunTipoDeTerreno();
    void mostrarArenaSeleccionada();
    void mostrarDunaSeleccionada();
    void mostrarRocaSeleccionada();
    void mostrarCimaSeleccionada();
    void mostrarPrecipicioSeleccionada();
    void mostrarEspeciaSeleccionada();
    void mostrarCuartelSeleccionado();

    void cargarMapaDefault();
    void establecerDatosDeCreacionDeMapa(int cant_jugadores, int cant_filas, int cant_columnas);
    void establecerDatosDeEdicionDeMapa(std::string &path_mapa);
public:
    DuneEditorDeMapas(QWidget *parent, int cant_filas, int cant_columnas, int cant_jugadores);
    DuneEditorDeMapas(QWidget* parent, const char *path_mapa);
    void agregarTexturas(std::string &path);
    void seleccionarTextura(const char* path, const char &tipo_terreno, const uint8_t &tipo_textura);

    void establecerGrillaEstandar();
    void escribirArchivoMapa(QString &nombre_archivo);

    DuneEditorDeMapas(const DuneEditorDeMapas&) = delete;
    DuneEditorDeMapas& operator=(const DuneEditorDeMapas&) = delete;
    DuneEditorDeMapas(DuneEditorDeMapas&&) = delete;
    DuneEditorDeMapas& operator=(DuneEditorDeMapas&&) = delete;
};
#endif