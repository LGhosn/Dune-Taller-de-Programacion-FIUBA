/********************************************************************************
** Form generated from reading UI file 'FormUnion.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMUNION_H
#define UI_FORMUNION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormUnir
{
public:
    QLabel *CasaLabel;
    QLabel *NombreLabel;
    QLineEdit *CasaLine;
    QLineEdit *NombreLine;
    QPushButton *UnirseButton;

    void setupUi(QWidget *FormUnir)
    {
        if (FormUnir->objectName().isEmpty())
            FormUnir->setObjectName(QString::fromUtf8("FormUnir"));
        FormUnir->resize(400, 137);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormUnir->sizePolicy().hasHeightForWidth());
        FormUnir->setSizePolicy(sizePolicy);
        FormUnir->setMinimumSize(QSize(400, 137));
        FormUnir->setMaximumSize(QSize(400, 137));
        FormUnir->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));
        CasaLabel = new QLabel(FormUnir);
        CasaLabel->setObjectName(QString::fromUtf8("CasaLabel"));
        CasaLabel->setGeometry(QRect(30, 20, 151, 21));
        CasaLabel->setStyleSheet(QString::fromUtf8(""));
        NombreLabel = new QLabel(FormUnir);
        NombreLabel->setObjectName(QString::fromUtf8("NombreLabel"));
        NombreLabel->setGeometry(QRect(30, 60, 191, 21));
        NombreLabel->setStyleSheet(QString::fromUtf8(""));
        CasaLine = new QLineEdit(FormUnir);
        CasaLine->setObjectName(QString::fromUtf8("CasaLine"));
        CasaLine->setGeometry(QRect(230, 20, 151, 25));
        CasaLine->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        NombreLine = new QLineEdit(FormUnir);
        NombreLine->setObjectName(QString::fromUtf8("NombreLine"));
        NombreLine->setGeometry(QRect(230, 60, 151, 25));
        NombreLine->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        UnirseButton = new QPushButton(FormUnir);
        UnirseButton->setObjectName(QString::fromUtf8("UnirseButton"));
        UnirseButton->setGeometry(QRect(160, 100, 89, 25));
        UnirseButton->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));

        retranslateUi(FormUnir);

        QMetaObject::connectSlotsByName(FormUnir);
    } // setupUi

    void retranslateUi(QWidget *FormUnir)
    {
        FormUnir->setWindowTitle(QApplication::translate("FormUnir", "Formulario de Union a Partida", nullptr));
        CasaLabel->setText(QApplication::translate("FormUnir", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#eeeeec;\">Casa a utilizar:</span></p></body></html>", nullptr));
        NombreLabel->setText(QApplication::translate("FormUnir", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#eeeeec;\">Nombre de Partida:</span></p></body></html>", nullptr));
        UnirseButton->setText(QApplication::translate("FormUnir", "Unirse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormUnir: public Ui_FormUnir {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMUNION_H
