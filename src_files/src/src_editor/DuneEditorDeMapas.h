#ifndef DUNE_EDITOR_H
#define DUNE_EDITOR_H

#include <tuple>
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
#include <string>
#include "DuneEditorDeMapasUi.h"
#include "ClickableLabel.h"
#include "yaml-cpp/yaml.h"

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
    int textura_seleccionada = TIPO_TEXTURA_DEFAULT;
    std::vector<std::vector<char>>* grilla_terrenos = nullptr;
    std::vector<std::vector<int>>* grilla_texturas = nullptr;
    std::vector<std::tuple<int, int>> centros_ubicados;

/* *****************************************************************
 *             METODOS REFERIDOS AL GUARDADO DE MAPAS
 * *****************************************************************/

    /*
     * El primer método es el principal a la hora de guardar un mapa,
     * los que le siguen complementan dicho código.
     */
    void guardarMapa();
    void pedirNombreDelMapaAlUsuario(QWidget* parent);
    void escribirDatosDeMapa(YAML::Emitter &out);
    void escribirTiposDeTerreno(YAML::Emitter &out);
    void escribirTiposDeTexturas(YAML::Emitter &out);
    void escribirCentrosDeConstruccion(YAML::Emitter &out);
    void guardarArchivoMapa(const QString &nombre_archivo, const YAML::Emitter &out);
    bool faltanEstablecerCentros();
    int obtenerCantidadDeCentrosUbicados();
    int obtenerCantidadDeCentrosNecesarios();
    void establecerRocaBajoCuarteles();
    void escribirArchivoMapa(QString &nombre_archivo);

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
    void mostrarCentroDeConstruccionSeleccionado();
    void agregarTexturas(std::string &path);
    void seleccionarTextura(const char* path, const char &tipo_terreno, const uint8_t &tipo_textura);


    void cargarMapaDefault();
    void establecerDatosDeCreacionDeMapa(int cant_jugadores, int cant_filas, int cant_columnas);
    void establecerDatosDeEdicionDeMapa(std::string &path_mapa);
public:
    DuneEditorDeMapas(QWidget *parent, int cant_filas, int cant_columnas, int cant_jugadores);
    DuneEditorDeMapas(QWidget* parent, std::string &path_mapa);

    void establecerGrillaEstandar();
    static std::string obtenerPathSegunInfo(const char &terreno_editado, std::string &textura_editada);

    DuneEditorDeMapas(const DuneEditorDeMapas&) = delete;
    DuneEditorDeMapas& operator=(const DuneEditorDeMapas&) = delete;
    DuneEditorDeMapas(DuneEditorDeMapas&&) = delete;
    DuneEditorDeMapas& operator=(DuneEditorDeMapas&&) = delete;
};
#endif