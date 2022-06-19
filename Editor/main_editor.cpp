#include <QApplication>
#include "DuneMapEditor.h"

int main (int argc, char** argv) {
    QApplication app(argc, argv);
    DuneMapEditor editor;
    editor.show();
    return app.exec();
}
