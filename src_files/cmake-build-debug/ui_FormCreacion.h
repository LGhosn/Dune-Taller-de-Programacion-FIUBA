/********************************************************************************
** Form generated from reading UI file 'FormCreacion.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCREACION_H
#define UI_FORMCREACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FromCrear
{
public:
    QLabel *CasaLabel;
    QLabel *CantLabel;
    QLabel *NombreLabel;
    QLineEdit *CasaLine;
    QLineEdit *NombreLine;
    QLineEdit *CantLine;
    QPushButton *CrearButton;
    QLabel *MapaLabel;
    QLineEdit *MapaLine;

    void setupUi(QWidget *FromCrear)
    {
        if (FromCrear->objectName().isEmpty())
            FromCrear->setObjectName(QString::fromUtf8("FromCrear"));
        FromCrear->resize(560, 225);
        FromCrear->setMinimumSize(QSize(560, 225));
        FromCrear->setMaximumSize(QSize(560, 225));
        FromCrear->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));
        CasaLabel = new QLabel(FromCrear);
        CasaLabel->setObjectName(QString::fromUtf8("CasaLabel"));
        CasaLabel->setGeometry(QRect(30, 20, 151, 21));
        CasaLabel->setStyleSheet(QString::fromUtf8(""));
        CantLabel = new QLabel(FromCrear);
        CantLabel->setObjectName(QString::fromUtf8("CantLabel"));
        CantLabel->setGeometry(QRect(30, 140, 341, 31));
        CantLabel->setStyleSheet(QString::fromUtf8(""));
        NombreLabel = new QLabel(FromCrear);
        NombreLabel->setObjectName(QString::fromUtf8("NombreLabel"));
        NombreLabel->setGeometry(QRect(30, 60, 191, 21));
        NombreLabel->setStyleSheet(QString::fromUtf8(""));
        CasaLine = new QLineEdit(FromCrear);
        CasaLine->setObjectName(QString::fromUtf8("CasaLine"));
        CasaLine->setGeometry(QRect(390, 20, 151, 25));
        CasaLine->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        NombreLine = new QLineEdit(FromCrear);
        NombreLine->setObjectName(QString::fromUtf8("NombreLine"));
        NombreLine->setGeometry(QRect(390, 60, 151, 25));
        NombreLine->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        CantLine = new QLineEdit(FromCrear);
        CantLine->setObjectName(QString::fromUtf8("CantLine"));
        CantLine->setGeometry(QRect(390, 140, 41, 25));
        CantLine->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        CrearButton = new QPushButton(FromCrear);
        CrearButton->setObjectName(QString::fromUtf8("CrearButton"));
        CrearButton->setGeometry(QRect(240, 190, 89, 25));
        CrearButton->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));
        MapaLabel = new QLabel(FromCrear);
        MapaLabel->setObjectName(QString::fromUtf8("MapaLabel"));
        MapaLabel->setGeometry(QRect(30, 100, 191, 31));
        MapaLabel->setStyleSheet(QString::fromUtf8(""));
        MapaLine = new QLineEdit(FromCrear);
        MapaLine->setObjectName(QString::fromUtf8("MapaLine"));
        MapaLine->setGeometry(QRect(390, 100, 151, 25));
        MapaLine->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(FromCrear);

        QMetaObject::connectSlotsByName(FromCrear);
    } // setupUi

    void retranslateUi(QWidget *FromCrear)
    {
        FromCrear->setWindowTitle(QApplication::translate("FromCrear", "Formulario de Creacion de Partida", nullptr));
        CasaLabel->setText(QApplication::translate("FromCrear", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#eeeeec;\">Casa a utilizar:</span></p></body></html>", nullptr));
        CantLabel->setText(QApplication::translate("FromCrear", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#eeeeec;\">Cantidad de jugadores requeridos:</span></p></body></html>", nullptr));
        NombreLabel->setText(QApplication::translate("FromCrear", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#eeeeec;\">Nombre de Partida:</span></p></body></html>", nullptr));
        CrearButton->setText(QApplication::translate("FromCrear", "Crear", nullptr));
        MapaLabel->setText(QApplication::translate("FromCrear", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#eeeeec;\">Mapa:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FromCrear: public Ui_FromCrear {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCREACION_H
