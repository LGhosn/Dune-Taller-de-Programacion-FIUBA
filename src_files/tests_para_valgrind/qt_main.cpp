#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QPushButton button ("Hola mundo");
    button.show();

    return a.exec();
}
