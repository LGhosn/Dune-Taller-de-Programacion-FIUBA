#include <QApplication>
#include "src_editor/SelectorDeModoDeEdicion.h"

int main (int argc, char** argv) {
    QApplication app(argc, argv);
    SelectorDeModoDeEdicion selector;
    selector.show();
    return app.exec();
}
