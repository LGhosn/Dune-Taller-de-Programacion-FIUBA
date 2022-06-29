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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QPushButton *CrearButton;
    QLabel *MapaLabel;
    QPushButton *AtreidesButton;
    QPushButton *HarkonnenButton;
    QPushButton *OrdosButton;
    QSpinBox *JugadoresSpinBox;
    QComboBox *MapaComboBox;

    void setupUi(QWidget *FromCrear)
    {
        if (FromCrear->objectName().isEmpty())
            FromCrear->setObjectName(QString::fromUtf8("FromCrear"));
        FromCrear->resize(560, 320);
        FromCrear->setMinimumSize(QSize(560, 320));
        FromCrear->setMaximumSize(QSize(560, 320));
        FromCrear->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 101, 164)"));
        CasaLabel = new QLabel(FromCrear);
        CasaLabel->setObjectName(QString::fromUtf8("CasaLabel"));
        CasaLabel->setGeometry(QRect(20, 20, 151, 21));
        CasaLabel->setStyleSheet(QString::fromUtf8(""));
        CantLabel = new QLabel(FromCrear);
        CantLabel->setObjectName(QString::fromUtf8("CantLabel"));
        CantLabel->setGeometry(QRect(20, 230, 341, 31));
        CantLabel->setStyleSheet(QString::fromUtf8(""));
        NombreLabel = new QLabel(FromCrear);
        NombreLabel->setObjectName(QString::fromUtf8("NombreLabel"));
        NombreLabel->setGeometry(QRect(20, 170, 191, 21));
        NombreLabel->setStyleSheet(QString::fromUtf8(""));
        CasaLine = new QLineEdit(FromCrear);
        CasaLine->setObjectName(QString::fromUtf8("CasaLine"));
        CasaLine->setGeometry(QRect(380, 120, 161, 25));
        CasaLine->setCursor(QCursor(Qt::ArrowCursor));
        CasaLine->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17)"));
        NombreLine = new QLineEdit(FromCrear);
        NombreLine->setObjectName(QString::fromUtf8("NombreLine"));
        NombreLine->setGeometry(QRect(380, 170, 161, 25));
        NombreLine->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        CrearButton = new QPushButton(FromCrear);
        CrearButton->setObjectName(QString::fromUtf8("CrearButton"));
        CrearButton->setGeometry(QRect(240, 280, 89, 25));
        CrearButton->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));
        MapaLabel = new QLabel(FromCrear);
        MapaLabel->setObjectName(QString::fromUtf8("MapaLabel"));
        MapaLabel->setGeometry(QRect(20, 200, 191, 31));
        MapaLabel->setStyleSheet(QString::fromUtf8(""));
        AtreidesButton = new QPushButton(FromCrear);
        AtreidesButton->setObjectName(QString::fromUtf8("AtreidesButton"));
        AtreidesButton->setGeometry(QRect(220, 10, 91, 101));
        AtreidesButton->setCursor(QCursor(Qt::PointingHandCursor));
        AtreidesButton->setStyleSheet(QString::fromUtf8("border-image: url(:/Logo/AtreidesIcon.png);"));
        HarkonnenButton = new QPushButton(FromCrear);
        HarkonnenButton->setObjectName(QString::fromUtf8("HarkonnenButton"));
        HarkonnenButton->setGeometry(QRect(340, 10, 89, 101));
        HarkonnenButton->setCursor(QCursor(Qt::PointingHandCursor));
        HarkonnenButton->setStyleSheet(QString::fromUtf8("border-image: url(:/Logo/HarkonnenIcon.png);"));
        OrdosButton = new QPushButton(FromCrear);
        OrdosButton->setObjectName(QString::fromUtf8("OrdosButton"));
        OrdosButton->setGeometry(QRect(450, 10, 89, 101));
        OrdosButton->setCursor(QCursor(Qt::PointingHandCursor));
        OrdosButton->setStyleSheet(QString::fromUtf8("border-image: url(:/Logo/OrdosIcon.png)"));
        JugadoresSpinBox = new QSpinBox(FromCrear);
        JugadoresSpinBox->setObjectName(QString::fromUtf8("JugadoresSpinBox"));
        JugadoresSpinBox->setGeometry(QRect(380, 230, 48, 26));
        JugadoresSpinBox->setMinimum(2);
        MapaComboBox = new QComboBox(FromCrear);
        MapaComboBox->addItem(QString());
        MapaComboBox->setObjectName(QString::fromUtf8("MapaComboBox"));
        MapaComboBox->setGeometry(QRect(380, 200, 161, 25));

        retranslateUi(FromCrear);

        QMetaObject::connectSlotsByName(FromCrear);
    } // setupUi

    void retranslateUi(QWidget *FromCrear)
    {
        FromCrear->setWindowTitle(QApplication::translate("FromCrear", "Formulario de Creacion de Partida", nullptr));
        CasaLabel->setText(QApplication::translate("FromCrear", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#eeeeec;\">Casa a utilizar:</span></p></body></html>", nullptr));
        CantLabel->setText(QApplication::translate("FromCrear", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#eeeeec;\">Cantidad de jugadores requeridos:</span></p></body></html>", nullptr));
        NombreLabel->setText(QApplication::translate("FromCrear", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#eeeeec;\">Nombre de Partida:</span></p></body></html>", nullptr));
        CasaLine->setPlaceholderText(QApplication::translate("FromCrear", "Casa elegida", nullptr));
        NombreLine->setPlaceholderText(QApplication::translate("FromCrear", "Nombre de partida", nullptr));
        CrearButton->setText(QApplication::translate("FromCrear", "Crear", nullptr));
        MapaLabel->setText(QApplication::translate("FromCrear", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#eeeeec;\">Mapa:</span></p></body></html>", nullptr));
        AtreidesButton->setText(QString());
        HarkonnenButton->setText(QString());
        OrdosButton->setText(QString());
        MapaComboBox->setItemText(0, QApplication::translate("FromCrear", "-", nullptr));

    } // retranslateUi

};

namespace Ui {
    class FromCrear: public Ui_FromCrear {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCREACION_H
