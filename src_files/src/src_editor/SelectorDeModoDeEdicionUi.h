/********************************************************************************
** Form generated from reading UI file 'SelectorDeModoDeEdicionUi.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTORDEMODODEEDICIONUI_H
#define UI_SELECTORDEMODODEEDICIONUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SelectorDeModoDeEdicion
{
public:
    QLabel *SeleccionDeModoLabel;
    QPushButton *CrearButton;
    QPushButton *EditarButton;
    QPushButton *ContinuarButton;
    QLabel *SeleccionDeDimensionesLabel;
    QSpinBox *ColumnasSpinBox;
    QSpinBox *FilasSpinBox;
    QLabel *FilasLabel;
    QLabel *ColumnasLabel;
    QLabel *SeleccionDeJugadoresLabel;
    QSpinBox *JugadoresSpinBox;

    void setupUi(QDialog *SelectorDeModoDeEdicion)
    {
        if (SelectorDeModoDeEdicion->objectName().isEmpty())
            SelectorDeModoDeEdicion->setObjectName(QString::fromUtf8("SelectorDeModoDeEdicion"));
        SelectorDeModoDeEdicion->resize(525, 328);
        SelectorDeModoDeEdicion->setMinimumSize(QSize(525, 232));
        SelectorDeModoDeEdicion->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        SeleccionDeModoLabel = new QLabel(SelectorDeModoDeEdicion);
        SeleccionDeModoLabel->setObjectName(QString::fromUtf8("SeleccionDeModoLabel"));
        SeleccionDeModoLabel->setGeometry(QRect(20, 20, 221, 17));
        CrearButton = new QPushButton(SelectorDeModoDeEdicion);
        CrearButton->setObjectName(QString::fromUtf8("CrearButton"));
        CrearButton->setGeometry(QRect(270, 20, 221, 25));
        CrearButton->setCursor(QCursor(Qt::PointingHandCursor));
        CrearButton->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        EditarButton = new QPushButton(SelectorDeModoDeEdicion);
        EditarButton->setObjectName(QString::fromUtf8("EditarButton"));
        EditarButton->setGeometry(QRect(270, 50, 221, 25));
        EditarButton->setCursor(QCursor(Qt::PointingHandCursor));
        EditarButton->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        ContinuarButton = new QPushButton(SelectorDeModoDeEdicion);
        ContinuarButton->setObjectName(QString::fromUtf8("ContinuarButton"));
        ContinuarButton->setGeometry(QRect(200, 290, 89, 25));
        ContinuarButton->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));
        SeleccionDeDimensionesLabel = new QLabel(SelectorDeModoDeEdicion);
        SeleccionDeDimensionesLabel->setObjectName(QString::fromUtf8("SeleccionDeDimensionesLabel"));
        SeleccionDeDimensionesLabel->setGeometry(QRect(20, 190, 421, 17));
        ColumnasSpinBox = new QSpinBox(SelectorDeModoDeEdicion);
        ColumnasSpinBox->setObjectName(QString::fromUtf8("ColumnasSpinBox"));
        ColumnasSpinBox->setGeometry(QRect(380, 260, 111, 26));
        ColumnasSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        ColumnasSpinBox->setMinimum(25);
        ColumnasSpinBox->setMaximum(250);
        ColumnasSpinBox->setValue(25);
        FilasSpinBox = new QSpinBox(SelectorDeModoDeEdicion);
        FilasSpinBox->setObjectName(QString::fromUtf8("FilasSpinBox"));
        FilasSpinBox->setGeometry(QRect(380, 220, 111, 26));
        FilasSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        FilasSpinBox->setMinimum(25);
        FilasSpinBox->setMaximum(250);
        FilasSpinBox->setValue(25);
        FilasLabel = new QLabel(SelectorDeModoDeEdicion);
        FilasLabel->setObjectName(QString::fromUtf8("FilasLabel"));
        FilasLabel->setGeometry(QRect(340, 220, 41, 31));
        ColumnasLabel = new QLabel(SelectorDeModoDeEdicion);
        ColumnasLabel->setObjectName(QString::fromUtf8("ColumnasLabel"));
        ColumnasLabel->setGeometry(QRect(300, 260, 71, 31));
        SeleccionDeJugadoresLabel = new QLabel(SelectorDeModoDeEdicion);
        SeleccionDeJugadoresLabel->setObjectName(QString::fromUtf8("SeleccionDeJugadoresLabel"));
        SeleccionDeJugadoresLabel->setGeometry(QRect(20, 120, 351, 17));
        JugadoresSpinBox = new QSpinBox(SelectorDeModoDeEdicion);
        JugadoresSpinBox->setObjectName(QString::fromUtf8("JugadoresSpinBox"));
        JugadoresSpinBox->setGeometry(QRect(440, 120, 51, 26));
        JugadoresSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        JugadoresSpinBox->setMinimum(2);
        JugadoresSpinBox->setMaximum(4);

        retranslateUi(SelectorDeModoDeEdicion);

        QMetaObject::connectSlotsByName(SelectorDeModoDeEdicion);
    } // setupUi

    void retranslateUi(QDialog *SelectorDeModoDeEdicion)
    {
        SelectorDeModoDeEdicion->setWindowTitle(QApplication::translate("SelectorDeModoDeEdicion", "Selector de modo de edici\303\263n", nullptr));
        SeleccionDeModoLabel->setText(QApplication::translate("SelectorDeModoDeEdicion", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">Seleccione el modo de edici\303\263n:</span></p></body></html>", nullptr));
        CrearButton->setText(QApplication::translate("SelectorDeModoDeEdicion", "Crear un nuevo mapa", nullptr));
        EditarButton->setText(QApplication::translate("SelectorDeModoDeEdicion", "Editar un mapa existente", nullptr));
        ContinuarButton->setText(QApplication::translate("SelectorDeModoDeEdicion", "Continuar", nullptr));
        SeleccionDeDimensionesLabel->setText(QApplication::translate("SelectorDeModoDeEdicion", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">Seleccione las dimensiones que desea para su nuevo mapa:</span></p></body></html>", nullptr));
        FilasLabel->setText(QApplication::translate("SelectorDeModoDeEdicion", "Filas:", nullptr));
        ColumnasLabel->setText(QApplication::translate("SelectorDeModoDeEdicion", "Columnas:", nullptr));
        SeleccionDeJugadoresLabel->setText(QApplication::translate("SelectorDeModoDeEdicion", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">Seleccione la cantidad de jugadores requeridos:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectorDeModoDeEdicion: public Ui_SelectorDeModoDeEdicion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTORDEMODODEEDICIONUI_H
