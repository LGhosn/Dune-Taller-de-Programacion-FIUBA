#include "ui_MenuUi.h"
#include "MenuDune.h"

MenuDune::MenuDune(Client& cliente, QWidget *parent) :
                                        QWidget(parent),
                                        ui(new Ui_Menu),
                                        formulario_creacion(new FormCreacion(cliente, nullptr)),
                                        formulario_union(new FormUnion(cliente, nullptr)),
                                        cliente_asociado(cliente) {
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    connect(ui->CrearLabel, &QPushButton::clicked, this, &MenuDune::mostrarVentanaDeCreacion);
    connect(ui->UnirseLabel, &QPushButton::clicked, this, &MenuDune::mostrarVentanaDeUnion);
    //esperarInicioDePartida();
}

void MenuDune::mostrarVentanaDeCreacion() {
    formulario_creacion->show();
    close();
}

void MenuDune::mostrarVentanaDeUnion() {
    formulario_union->show();
    close();
}

MenuDune::~MenuDune() {
    delete ui;
    delete formulario_creacion;
    delete formulario_union;
}