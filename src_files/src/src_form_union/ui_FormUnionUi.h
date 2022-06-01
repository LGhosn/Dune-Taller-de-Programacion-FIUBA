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
    QLineEdit *NombreLine;
    QPushButton *UnirseButton;
    QPushButton *AtreidesButton;
    QPushButton *HarkonneButton;
    QPushButton *OrdosButton;
    QLineEdit *CasaLine;

    void setupUi(QWidget *FormUnir)
    {
        if (FormUnir->objectName().isEmpty())
            FormUnir->setObjectName(QString::fromUtf8("FormUnir"));
        FormUnir->resize(570, 230);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormUnir->sizePolicy().hasHeightForWidth());
        FormUnir->setSizePolicy(sizePolicy);
        FormUnir->setMinimumSize(QSize(570, 230));
        FormUnir->setMaximumSize(QSize(570, 230));
        FormUnir->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 74, 135);"));
        CasaLabel = new QLabel(FormUnir);
        CasaLabel->setObjectName(QString::fromUtf8("CasaLabel"));
        CasaLabel->setGeometry(QRect(10, 60, 161, 21));
        CasaLabel->setStyleSheet(QString::fromUtf8(""));
        NombreLabel = new QLabel(FormUnir);
        NombreLabel->setObjectName(QString::fromUtf8("NombreLabel"));
        NombreLabel->setGeometry(QRect(10, 150, 201, 31));
        NombreLabel->setStyleSheet(QString::fromUtf8(""));
        NombreLine = new QLineEdit(FormUnir);
        NombreLine->setObjectName(QString::fromUtf8("NombreLine"));
        NombreLine->setGeometry(QRect(220, 150, 311, 25));
        NombreLine->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        UnirseButton = new QPushButton(FormUnir);
        UnirseButton->setObjectName(QString::fromUtf8("UnirseButton"));
        UnirseButton->setGeometry(QRect(230, 190, 89, 25));
        UnirseButton->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));
        AtreidesButton = new QPushButton(FormUnir);
        AtreidesButton->setObjectName(QString::fromUtf8("AtreidesButton"));
        AtreidesButton->setGeometry(QRect(180, 20, 101, 111));
        AtreidesButton->setCursor(QCursor(Qt::PointingHandCursor));
        AtreidesButton->setStyleSheet(QString::fromUtf8("border-image: url(:/Logo/AtreidesIcon.png);\n"
"border-color: rgb(238, 238, 236);"));
        HarkonneButton = new QPushButton(FormUnir);
        HarkonneButton->setObjectName(QString::fromUtf8("HarkonneButton"));
        HarkonneButton->setGeometry(QRect(310, 20, 101, 111));
        HarkonneButton->setCursor(QCursor(Qt::PointingHandCursor));
        HarkonneButton->setStyleSheet(QString::fromUtf8("border-image: url(:/Logo/HarkonnenIcon.png);"));
        OrdosButton = new QPushButton(FormUnir);
        OrdosButton->setObjectName(QString::fromUtf8("OrdosButton"));
        OrdosButton->setGeometry(QRect(440, 20, 101, 111));
        OrdosButton->setCursor(QCursor(Qt::PointingHandCursor));
        OrdosButton->setStyleSheet(QString::fromUtf8("border-image: url(:/Logo/OrdosIcon.png);"));
        CasaLine = new QLineEdit(FormUnir);
        CasaLine->setObjectName(QString::fromUtf8("CasaLine"));
        CasaLine->setGeometry(QRect(10, 100, 151, 21));
        CasaLine->setCursor(QCursor(Qt::ArrowCursor));
        CasaLine->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));
        CasaLine->raise();
        CasaLabel->raise();
        NombreLabel->raise();
        NombreLine->raise();
        UnirseButton->raise();
        AtreidesButton->raise();
        HarkonneButton->raise();
        OrdosButton->raise();

        retranslateUi(FormUnir);

        QMetaObject::connectSlotsByName(FormUnir);
    } // setupUi

    void retranslateUi(QWidget *FormUnir)
    {
        FormUnir->setWindowTitle(QApplication::translate("FormUnir", "Formulario de Union a Partida", nullptr));
        CasaLabel->setText(QApplication::translate("FormUnir", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#eeeeec;\">Casa a utilizar:</span></p></body></html>", nullptr));
        NombreLabel->setText(QApplication::translate("FormUnir", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#eeeeec;\">Nombre de Partida:</span></p></body></html>", nullptr));
        NombreLine->setPlaceholderText(QApplication::translate("FormUnir", "Introducir nombre de partida.", nullptr));
        UnirseButton->setText(QApplication::translate("FormUnir", "Unirse", nullptr));
        AtreidesButton->setText(QString());
        HarkonneButton->setText(QString());
        OrdosButton->setText(QString());
        CasaLine->setPlaceholderText(QApplication::translate("FormUnir", "Casa elegida...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormUnir: public Ui_FormUnir {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMUNION_H
