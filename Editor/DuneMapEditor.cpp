#include <iostream>
#include "DuneMapEditor.h"

DuneMapEditor::DuneMapEditor(QWidget* parent) : ui(new Ui_DuneMapEditor),
                                                grid_map(grid_map_rows, std::vector<char>(grid_map_columns, 'A')) {
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    connect(ui->SaveButton, &QPushButton::clicked, this, &DuneMapEditor::saveMap);
    connect(ui->ResetButton, &QPushButton::clicked, this, &DuneMapEditor::reset);
    //showGridMap();
}

/* *****************************************************************
 *             METODOS REFERIDOS A EDITAR MAPAS
 * *****************************************************************/
void DuneMapEditor::showGridMap() {
    for (int i = 0; i < grid_map_rows; i++) {
        for (int j = 0; j < grid_map_columns; j++) {
            QLabel* label = new QLabel();
            label->setGeometry(QRect(130, 40, 200, 200));
            label->setMinimumSize(QSize(200, 200));
            label->setMaximumSize(QSize(200, 200));
            label->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207)"));
            //std::cout << grid_map[i][j];
        }
    }
}

/* *****************************************************************
 *             METODOS REFERIDOS A REINICIAR CAMPOS
 * *****************************************************************/

void DuneMapEditor::reset() {
    resetEditionMode();
    resetRequiredPlayers();
    resetDimensions();
    resetTerrainType();
    resetTerrainTexture();
}

void DuneMapEditor::resetTerrainTexture() {
    terrain_type = "-";
    ui->TerrainTextureComboBox->setCurrentText("-");
}

void DuneMapEditor::resetTerrainType() {
    terrain_type = "-";
    ui->TerrainTypeComboBox->setCurrentText("-");
}

void DuneMapEditor::resetDimensions() {
    grid_map_rows = 250;
    grid_map_columns = 250;
    ui->RowsSpinBox->setValue(250);
    ui->ColumnsSpinBox->setValue(250);
}

void DuneMapEditor::resetRequiredPlayers() {
    required_players = 0;
    ui->RequiredPlayersComboBox->setCurrentText("-");
}

void DuneMapEditor::resetEditionMode() {
    edition_mode = "-";
    ui->EditionModeComboBox->setCurrentText("-");
}

/* *****************************************************************
 *             METODOS REFERIDOS AL GUARDADO DE MAPAS
 * *****************************************************************/

void DuneMapEditor::saveMap() {
    setFields();
    checkIfSomeFieldIsNotCompleted();
}

void DuneMapEditor::setFields() {
    edition_mode = ui->EditionModeComboBox->currentText().toStdString();
    required_players = ui->RequiredPlayersComboBox->currentText().toInt();
}

void DuneMapEditor::checkIfSomeFieldIsNotCompleted() {
    if (editionModeIsNotSelected()) {
        QMessageBox::information(this, "Error al guardar",
                                 "Recuerda elegir un modo de edición.");
    } else if (requiredPlayersIsNotSelected()) {
        QMessageBox::information(this, "Error al guardar",
                                 "Recuerda elegir una cantidad de jugadores requeridos.");
    } else {
        // pedimos el nombre del mapa
        // escribimos el archivo y lo guardamos
    }
}

bool DuneMapEditor::editionModeIsNotSelected() {
    return edition_mode == "-";
}

bool DuneMapEditor::requiredPlayersIsNotSelected() {
    return required_players == 0;
}