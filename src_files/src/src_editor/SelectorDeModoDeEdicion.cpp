#include "SelectorDeModoDeEdicion.h"

SelectorDeModoDeEdicion::SelectorDeModoDeEdicion(QWidget* parent) : ui(new Ui_SelectorDeModoDeEdicion) {
    ui->setupUi(this);
    editor = nullptr;
    ui->SeleccionDeJugadoresLabel->hide();
    ui->JugadoresSpinBox->hide();
    ui->SeleccionDeDimensionesLabel->hide();
    ui->FilasLabel->hide();
    ui->FilasSpinBox->hide();
    ui->ColumnasLabel->hide();
    ui->ColumnasSpinBox->hide();
    connect(ui->CrearButton, &QPushButton::clicked, this, &SelectorDeModoDeEdicion::creacionSeleccionada);
    connect(ui->EditarButton, &QPushButton::clicked, this, &SelectorDeModoDeEdicion::edicionSeleccionada);
    connect(ui->ContinuarButton, &QPushButton::clicked, this, &SelectorDeModoDeEdicion::finalizarSeleccion);
}

void SelectorDeModoDeEdicion::finalizarSeleccion() {
    if (unModoDeEdicionFueSeleccionado()) {
        if (modo_de_edicion == "crear") {
            editor = new DuneEditorDeMapas(nullptr, ui->FilasSpinBox->value(), ui->ColumnasSpinBox->value(), ui->JugadoresSpinBox->value());
        } else {
            editor = new DuneEditorDeMapas(nullptr, RESOURCE_PATH"/maps/hola.yaml");
        }
        editor->show();
        close();
    } else {
        QMessageBox::information(this, "No se selecciono el modo de edicion", "Recuerda elegir uno entre crear un nuevo mapa y editar uno existente.");
    }
}

void SelectorDeModoDeEdicion::creacionSeleccionada() {
    modo_de_edicion = "crear";
    ui->SeleccionDeJugadoresLabel->setVisible(true);
    ui->JugadoresSpinBox->setVisible(true);
    ui->SeleccionDeDimensionesLabel->setVisible(true);
    ui->FilasLabel->setVisible(true);
    ui->FilasSpinBox->setVisible(true);
    ui->ColumnasLabel->setVisible(true);
    ui->ColumnasSpinBox->setVisible(true);
}

void SelectorDeModoDeEdicion::edicionSeleccionada() {
    modo_de_edicion = "editar";
    ui->SeleccionDeJugadoresLabel->hide();
    ui->JugadoresSpinBox->hide();
    ui->SeleccionDeDimensionesLabel->hide();
    ui->FilasLabel->hide();
    ui->FilasSpinBox->hide();
    ui->ColumnasLabel->hide();
    ui->ColumnasSpinBox->hide();
}

bool SelectorDeModoDeEdicion::unModoDeEdicionFueSeleccionado() {
    return modo_de_edicion != "";
}

void SelectorDeModoDeEdicion::agregarMapasDisponibles(std::string &path) {
    std::vector<std::string> mapas_encontrados;
    for (auto &file: std::filesystem::directory_iterator(path)) {
        std::string mapa_path = file.path();
        std::string mapa = mapa_path.substr(mapa_path.find_last_of('/') + 1);
        mapas_encontrados.push_back(mapa);
    }
    std::sort(mapas_encontrados.begin(), mapas_encontrados.end());
    for (auto &mapa: mapas_encontrados) {
        //ui->MapasEncontradosComboBox->addItem(QString::fromStdString(mapa));
    }
}