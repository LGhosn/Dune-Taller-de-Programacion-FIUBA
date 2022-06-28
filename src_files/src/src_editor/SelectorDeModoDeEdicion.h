#ifndef DUNE_SELECTOR_H
#define DUNE_SELECTOR_H

#include <string>
#include <QMessageBox>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QDialog>
#include "SelectorDeModoDeEdicionUi.h"
#include "DuneEditorDeMapas.h"

class SelectorDeModoDeEdicion: public QDialog {
private:
    Ui_SelectorDeModoDeEdicion* ui;
    DuneEditorDeMapas* editor;
    std::string modo_de_edicion = "";
public:
    SelectorDeModoDeEdicion(QWidget *parent = nullptr);
    void finalizarSeleccion();
    void creacionSeleccionada();
    void edicionSeleccionada();
    bool unModoDeEdicionFueSeleccionado();
    void agregarMapasDisponibles(std::string &path);
    void pedirNombreDelMapaAlUsuario(QWidget* parent);

    void mostrarInterfazAlUsuario();
};
#endif