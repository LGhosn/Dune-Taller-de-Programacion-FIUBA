//
// Implementación tomada de https://wiki.qt.io/Clickable_QLabel
//
#ifndef CLICKABLE_LABEL_H
#define CLICKABLE_LABEL_H

#include <QMessageBox>
#include <iostream>
#include <string>
#include <QMouseEvent>
#include <QLabel>
#include <QWidget>
#include <Qt>

#define TIPO_TEXTURA_DEFAULT 9
#define TERRENO_ROCA 5
#define TIPO_TERRENO_DEFAULT 0
#define PIXELES_COORDENADA 50

class ClickableLabel : public QLabel {
Q_OBJECT
private:
    std::vector<std::vector<int>>* grilla_terrenos = nullptr;
    std::vector<std::vector<int>>* grilla_texturas = nullptr;
    std::vector<std::tuple<int, int>>& centros_ubicados;
    int &cant_jugadores;
    int &cant_filas_grillas;
    int &cant_columnas_grillas;
    int* terreno_seleccionado = nullptr;
    int* textura_seleccionada = nullptr;
    QString* path_textura_seleccionada;

public:
    ClickableLabel(std::vector<std::vector<int>>* grilla_terrenos,
                   std::vector<std::vector<int>>* grilla_texturas,
                   std::vector<std::tuple<int, int>>& centros_ubicados,
                   int &cant_jugadores,
                   int &cant_filas_grillas,
                   int &cant_columnas_grillas,
                   int* terreno_seleccionado,
                   int* textura_seleccionada,
                   QString* path_textura,
                   QWidget* parent = Q_NULLPTR,
                   Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel() override;

    void establecerTextura();

    int obtenerCoordenadaX();

    int obtenerCoordenadaY();

    /*
     * Devuelve un bool indicando si el centro puede ser o no ubicado en la coordenadas pasadas por parámetro.
     */
    bool laPosicionParaUnCentroEsValida(int& coord_x, int& coord_y);

    /*
     * Devuelve un bool indicando si el usuario busca establecer un centro de construccion en el mapa.
     */
    bool seQuiereEstablecerUnCentro();

    /*
     * Devuelve un bool indicando si faltan establecer centros de construccion en el mapa.
     */
    bool faltanEstablecerCentros();

    bool seQuiereEstablecerTexturaSobreUnCentro(int& coord_x, int& coord_y);

    /*
     * Ubica 'X' en el mapa señalando que hay un centro de construcción en esas coordenadas.
     * Esto es simplemente simbólico para que los demás metodos complementarios puedan decidir
     * si se puede o no establecer otro centro o terreno en dichas coordenadas.
     */
    void marcarUbicacionDelCentro(int& coord_x, int& coord_y);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event) override;

    bool lasCoordenadasDelCentroPermanecenEnElMapa(const int &coord_x, const int &coord_y) const;

    bool lasCoordenadasNoCoincidenConLasDeOtroCentro(const int &coord_x, const int &coord_y) const;

    bool seClickeoSobreElOrigenDelCentro(int& coord_x, int& coord_y) const;

    void eliminarCentro(int& coord_x, int& coord_y);

    void establecerTexturaEnLaGrilla(int coord_x, int coord_y);
};
#endif //CLICKABLE_LABEL_H
