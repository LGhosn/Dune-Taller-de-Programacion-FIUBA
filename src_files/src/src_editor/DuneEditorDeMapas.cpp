#include <iostream>
#include <QDir>
#include "DuneEditorDeMapas.h"

DuneEditorDeMapas::DuneEditorDeMapas(QWidget* parent) : ui(new Ui_DuneMapEditor),
                                                        mapa(cantidad_filas_mapa, std::vector<char>(cantidad_columnas_mapa, 'A')) {
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    connect(ui->SaveButton, &QPushButton::clicked, this, &DuneEditorDeMapas::guardarMapa);
    connect(ui->ResetButton, &QPushButton::clicked, this, &DuneEditorDeMapas::reestablecer);
    connect(ui->TerrainTypeComboBox, &QComboBox::currentTextChanged, this, &DuneEditorDeMapas::ofrecerTexturasSegunTipoDeTerreno);
    //mostrarMapa();
}

/* *****************************************************************
 *             METODOS REFERIDOS A EDITAR MAPAS
 * *****************************************************************/

void DuneEditorDeMapas::ofrecerTexturasSegunTipoDeTerreno() {
    QString terreno = ui->TerrainTypeComboBox->currentText();
    if (terreno == "-") {
        ui->TerrainTextureComboBox->clear();
    } else if (terreno == "Arena") {
        mostrarTexturasDeArena();
    } else if (terreno == "Duna") {
        mostrarTexturasDeDuna();
    } else if (terreno == "Roca") {
        mostrarTexturasDeRoca();
    } else if (terreno == "Cima") {
        mostrarTexturasDeCima();
    } else if (terreno == "Precipicio") {
        mostrarTexturasDePrecipicio();
    }
}

void DuneEditorDeMapas::mostrarTexturasDePrecipicio() {
    ui->TerrainTextureComboBox->clear();
    ui->TerrainTextureComboBox->addItem("-");
    ui->TerrainTextureComboBox->addItem("Precipicio01");
    ui->TerrainTextureComboBox->addItem("Precipicio02");
    ui->TerrainTextureComboBox->addItem("Precipicio03");
}

void DuneEditorDeMapas::mostrarTexturasDeCima() {
    ui->TerrainTextureComboBox->clear();
    ui->TerrainTextureComboBox->addItem("-");
    ui->TerrainTextureComboBox->addItem("Cima01");
    ui->TerrainTextureComboBox->addItem("Cima02");
    ui->TerrainTextureComboBox->addItem("Cima03");
}

void DuneEditorDeMapas::mostrarTexturasDeRoca() {
    ui->TerrainTextureComboBox->clear();
    ui->TerrainTextureComboBox->addItem("-");
    ui->TerrainTextureComboBox->addItem("Roca01");
    ui->TerrainTextureComboBox->addItem("Roca02");
    ui->TerrainTextureComboBox->addItem("Roca03");
}

void DuneEditorDeMapas::mostrarTexturasDeDuna() {
    ui->TerrainTextureComboBox->clear();
    ui->TerrainTextureComboBox->addItem("-");
    ui->TerrainTextureComboBox->addItem("Duna01");
    ui->TerrainTextureComboBox->addItem("Duna02");
    ui->TerrainTextureComboBox->addItem("Duna03");
}

void DuneEditorDeMapas::mostrarTexturasDeArena() {
    ui->TerrainTextureComboBox->clear();
    ui->TerrainTextureComboBox->addItem("-");
    ui->TerrainTextureComboBox->addItem("Arena01");
    ui->TerrainTextureComboBox->addItem("Arena02");
    ui->TerrainTextureComboBox->addItem("Arena03");
}

void DuneEditorDeMapas::mostrarMapa() {
    for (int i = 0; i < cantidad_filas_mapa; i++) {
        for (int j = 0; j < cantidad_columnas_mapa; j++) {
            QLabel* label = new QLabel();
            label->setGeometry(QRect(130, 40, 200, 200));
            label->setMinimumSize(QSize(50, 50));
            label->setMaximumSize(QSize(50, 50));
            label->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207)"));
            ui->MapCells->addWidget(label, i, j);
        }
    }
}

/* *****************************************************************
 *             METODOS REFERIDOS A REINICIAR CAMPOS
 * *****************************************************************/

void DuneEditorDeMapas::reestablecer() {
    reestablecerModoDeEdicion();
    reestablecerJugadoresRequeridos();
    reestablecerDimensiones();
    reestablecerTipoDeTerreno();
    reestablecerTexturaDelTerreno();
}

void DuneEditorDeMapas::reestablecerTexturaDelTerreno() {
    tipo_de_terreno = "-";
    ui->TerrainTextureComboBox->setCurrentText("-");
}

void DuneEditorDeMapas::reestablecerTipoDeTerreno() {
    tipo_de_terreno = "-";
    ui->TerrainTypeComboBox->setCurrentText("-");
}

void DuneEditorDeMapas::reestablecerDimensiones() {
    cantidad_filas_mapa = CANTIDAD_INICIAL_DE_FILAS;
    cantidad_columnas_mapa = CANTIDAD_INICIAL_DE_COLUMNAS;
    ui->RowsSpinBox->setValue(250);
    ui->ColumnsSpinBox->setValue(250);
}

void DuneEditorDeMapas::reestablecerJugadoresRequeridos() {
    jugadores_requeridos = 0;
    ui->RequiredPlayersComboBox->setCurrentText("-");
}

void DuneEditorDeMapas::reestablecerModoDeEdicion() {
    modo_de_edicion = "-";
    ui->EditionModeComboBox->setCurrentText("-");
}

/* *****************************************************************
 *             METODOS REFERIDOS AL GUARDADO DE MAPAS
 * *****************************************************************/

void DuneEditorDeMapas::guardarMapa() {
    establecerCampos();
    chequearSiAlgunCampoNoEstaCompleto();
}

void DuneEditorDeMapas::establecerCampos() {
    modo_de_edicion = ui->EditionModeComboBox->currentText().toStdString();
    jugadores_requeridos = ui->RequiredPlayersComboBox->currentText().toInt();
    cantidad_filas_mapa = ui->RowsSpinBox->value();
    cantidad_columnas_mapa = ui->RowsSpinBox->value();
}

void DuneEditorDeMapas::chequearSiAlgunCampoNoEstaCompleto() {
    if (elModoDeEdicionNoFueSeleccionado()) {
        QMessageBox::information(this, "Error al guardar",
                                 "Recuerda elegir un modo de edición.");
    } else if (losJugadoresRequeridosNoFueronSeleccionados()) {
        QMessageBox::information(this, "Error al guardar",
                                 "Recuerda elegir una cantidad de jugadores requeridos.");
    } else {
        // pedimos el nombre del mapa
        pedirNombreDelMapaAlUsuario(this);
    }
}

void DuneEditorDeMapas::pedirNombreDelMapaAlUsuario(QWidget* parent) {
    bool ok;
    QString map_name = QInputDialog::getText(parent, tr("Ingresar nombre del mapa"),
                                         tr("Nombre del Mapa:"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && map_name.isEmpty()) {
        QMessageBox::information(parent, "Error al guardar", "Recuerda elegir un nombre para el mapa creado.");
    } else if (ok && !map_name.isEmpty()) {
        // escribimor el YAML
        QMessageBox::information(parent, "Exito al guardar", "El mapa fue guardado con éxito en la carpeta <INGRESAR DIRECTORIO>.");
    }
}

bool DuneEditorDeMapas::elModoDeEdicionNoFueSeleccionado() {
    return modo_de_edicion == "-";
}

bool DuneEditorDeMapas::losJugadoresRequeridosNoFueronSeleccionados() {
    return jugadores_requeridos == 0;
}