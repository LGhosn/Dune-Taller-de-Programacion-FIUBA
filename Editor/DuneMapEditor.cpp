#include "DuneMapEditor.h"

DuneMapEditor::DuneMapEditor(QWidget* parent) : ui(new Ui_DuneMapEditor) {
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    connect(ui->SaveButton, &QPushButton::clicked, this, &DuneMapEditor::saveMap);
    connect(ui->ResetButton, &QPushButton::clicked, this, &DuneMapEditor::reset);
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
    map_rows = 250;
    map_columns = 250;
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
    }
}

bool DuneMapEditor::editionModeIsNotSelected() {
    return edition_mode == "-";
}

bool DuneMapEditor::requiredPlayersIsNotSelected() {
    return required_players == 0;
}