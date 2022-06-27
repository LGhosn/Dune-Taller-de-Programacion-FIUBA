//
// Implementación tomada de https://wiki.qt.io/Clickable_QLabel
//
#ifndef CLICKABLE_LABEL_H
#define CLICKABLE_LABEL_H

#include <iostream>
#include <QMouseEvent>
#include <QLabel>
#include <QWidget>
#include <Qt>
#include "DuneEditorDeMapas.h"

class ClickableLabel : public QLabel {
Q_OBJECT
private:
    std::vector<std::vector<char>>* grilla_terrenos = nullptr;
    std::vector<std::vector<uint8_t>>* grilla_texturas = nullptr;
    char* terreno_seleccionado = nullptr;
    uint8_t* textura_seleccionada = nullptr;
    QString* path_textura_seleccionada = nullptr;

    //int obtenerCoordenadaX();
    //int obtenerCoordenadaY();

public:
    ClickableLabel(std::vector<std::vector<char>>* grilla_terrenos,
                   std::vector<std::vector<uint8_t>>* grilla_texturas,
                   char* terreno_seleccionado,
                   uint8_t* textura_seleccionada,
                   QString* path_textura,
                   QWidget* parent = Q_NULLPTR,
                   Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel() override;

    void establecerTextura();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event) override;
};
#endif //CLICKABLE_LABEL_H
