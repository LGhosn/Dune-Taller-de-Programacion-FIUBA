#include "DuneMapEditor.h"

DuneMapEditor::DuneMapEditor(QWidget* parent) : ui(new Ui_DuneMapEditor) {
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}