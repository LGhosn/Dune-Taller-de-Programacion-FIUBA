#include <QApplication>
#include "src_editor/DuneEditorDeMapas.h"

int main (int argc, char** argv) {
    QApplication app(argc, argv);
    DuneEditorDeMapas editor;
    editor.show();
    return app.exec();
}
