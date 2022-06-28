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
            mostrarInterfazAlUsuario();
        } else {
            pedirNombreDelMapaAlUsuario(this);
        }
    } else {
        QMessageBox::information(this, "No se selecciono el modo de edicion", "Recuerda elegir uno entre crear un nuevo mapa y editar uno existente.");
    }
}

void SelectorDeModoDeEdicion::mostrarInterfazAlUsuario() {
    editor = new DuneEditorDeMapas(nullptr, ui->FilasSpinBox->value(), ui->ColumnasSpinBox->value(), ui->JugadoresSpinBox->value());
    editor->show();
    close();
}

void SelectorDeModoDeEdicion::pedirNombreDelMapaAlUsuario(QWidget* parent) {
    bool ok;
    QString map_name = QInputDialog::getText(parent, tr("Ingresar nombre del mapa a editar"),
                                             tr("Nombre del archivo (sin .yaml):"), QLineEdit::Normal,
                                             "", &ok);
    if (ok && map_name.isEmpty()) {
        QMessageBox::information(parent, "Error al editar", "Recuerda elegir el nombre del archivo a editar.");
    } else if (ok && !map_name.isEmpty()) {
        if (!std::filesystem::exists(RESOURCE_PATH"/maps/" + map_name.toStdString() + ".yaml")) {
            QMessageBox::information(this, "Error al editar", "No existe un archivo con ese nombre, por favor, elegir uno existente.");
        } else {
            std::string path = RESOURCE_PATH"/maps/" + map_name.toStdString() + ".yaml";
            editor = new DuneEditorDeMapas(nullptr, path);
            editor->show();
            close();
        }
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

/*void SelectorDeModoDeEdicion::agregarMapasDisponibles(std::string &path) {
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
}*/