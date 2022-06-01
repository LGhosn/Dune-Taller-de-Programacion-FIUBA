#include "ui_MenuUi.h"
#include "MenuDune.h"

MenuDune::MenuDune(ProtocoloCliente& protocolo_asociado, QWidget *parent) :
                                        QWidget(parent),
                                        ui(new Ui_Menu),
                                        formulario_creacion(new FormCreacion(protocolo_asociado)),
                                        formulario_union(new FormUnion(protocolo_asociado)) {
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    connect(ui->CrearLabel, &QPushButton::clicked, this, &MenuDune::mostrarVentanaDeCreacion);
    connect(ui->UnirseLabel, &QPushButton::clicked, this, &MenuDune::mostrarVentanaDeUnion);
}

void MenuDune::mostrarVentanaDeCreacion() {
    formulario_creacion->show();
}

void MenuDune::mostrarVentanaDeUnion() {
    formulario_union->show();
}

MenuDune::~MenuDune() {
    delete ui;
    delete formulario_creacion;
    delete formulario_union;
}
