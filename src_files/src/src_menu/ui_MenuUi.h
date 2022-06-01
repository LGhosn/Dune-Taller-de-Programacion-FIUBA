/********************************************************************************
** Form generated from reading UI file 'MenuUi.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUUI_H
#define UI_MENUUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QLabel *BackgroundImage;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *CrearLabel;
    QPushButton *UnirseLabel;
    QLabel *DuneLogoLabel;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Menu->sizePolicy().hasHeightForWidth());
        Menu->setSizePolicy(sizePolicy);
        Menu->setMinimumSize(QSize(1280, 720));
        Menu->setMaximumSize(QSize(1280, 720));
        Menu->setSizeIncrement(QSize(1280, 720));
        Menu->setBaseSize(QSize(1280, 720));
        BackgroundImage = new QLabel(Menu);
        BackgroundImage->setObjectName(QString::fromUtf8("BackgroundImage"));
        BackgroundImage->setGeometry(QRect(-10, 0, 1291, 721));
        sizePolicy.setHeightForWidth(BackgroundImage->sizePolicy().hasHeightForWidth());
        BackgroundImage->setSizePolicy(sizePolicy);
        BackgroundImage->setAutoFillBackground(false);
        BackgroundImage->setTextFormat(Qt::PlainText);
        BackgroundImage->setPixmap(QPixmap(QString::fromUtf8(":/Background/dune_space_wars.jpg")));
        BackgroundImage->setScaledContents(true);
        verticalWidget = new QWidget(Menu);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalWidget->setGeometry(QRect(520, 280, 221, 81));
        verticalWidget->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        CrearLabel = new QPushButton(verticalWidget);
        CrearLabel->setObjectName(QString::fromUtf8("CrearLabel"));
        CrearLabel->setCursor(QCursor(Qt::PointingHandCursor));
        CrearLabel->setStyleSheet(QString::fromUtf8("border-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(255, 255, 255, 255), stop:0.373979 rgba(255, 255, 255, 255), stop:0.373991 rgba(33, 30, 255, 255), stop:0.624018 rgba(33, 30, 255, 255), stop:0.624043 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));\n"
"background-color: rgb(193, 125, 17);\n"
""));

        verticalLayout->addWidget(CrearLabel);

        UnirseLabel = new QPushButton(verticalWidget);
        UnirseLabel->setObjectName(QString::fromUtf8("UnirseLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(UnirseLabel->sizePolicy().hasHeightForWidth());
        UnirseLabel->setSizePolicy(sizePolicy1);
        UnirseLabel->setCursor(QCursor(Qt::PointingHandCursor));
        UnirseLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));

        verticalLayout->addWidget(UnirseLabel);

        DuneLogoLabel = new QLabel(Menu);
        DuneLogoLabel->setObjectName(QString::fromUtf8("DuneLogoLabel"));
        DuneLogoLabel->setGeometry(QRect(380, 60, 501, 121));
        DuneLogoLabel->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/Logo/logo.jpg);\n"
""));
        DuneLogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/Logo/dune_logo.png")));
        DuneLogoLabel->setScaledContents(true);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Dune 2000", nullptr));
        BackgroundImage->setText(QString());
        CrearLabel->setText(QApplication::translate("Menu", "Crear una partida", nullptr));
        UnirseLabel->setText(QApplication::translate("Menu", "Unirse a una partida", nullptr));
        DuneLogoLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUUI_H
