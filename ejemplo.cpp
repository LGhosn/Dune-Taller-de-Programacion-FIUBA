//
// Created by sruizs on 18/05/22.
//

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    // Clase que contiene el loop principal
    QApplication app(argc, argv);
    // Instancio un componente grafico para salida de texto
    // Llamo a QLabel(const QString &text, QWidget *parent=0, Qt::WindowFlags f=0);
    QLabel label("Hello QT");
    // Muestro el elemento
    label.show();
    // Arranca el loop de la UI
    return app.exec();
}