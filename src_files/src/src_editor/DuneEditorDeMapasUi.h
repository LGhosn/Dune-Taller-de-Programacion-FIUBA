/********************************************************************************
** Form generated from reading UI file 'DuneEditorDeMapasUi.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUNEEDITORDEMAPASUI_H
#define UI_DUNEEDITORDEMAPASUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DuneEditorDeMapas
{
public:
    QWidget *centralwidget;
    QListWidget *EditorList;
    QLabel *EditonModeLabel;
    QLabel *RequiredPlayersLabel;
    QLabel *DimentiosLabel;
    QPushButton *SaveButton;
    QLabel *TerrainTypeLabel;
    QComboBox *TerrainTypeComboBox;
    QLabel *TerrainTextureLabel;
    QComboBox *TerrainTextureComboBox;
    QFrame *DividingLine;
    QFrame *DividingLine_2;
    QFrame *DividingLine_3;
    QFrame *DividingLine_4;
    QFrame *DividingLine_5;
    QFrame *DividingLine_6;
    QLabel *xLabel;
    QLabel *CantFilasLabel;
    QLabel *CantColumnasLabel;
    QLabel *CantJugadoresLabel;
    QLabel *MostradorTexturaLabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QMainWindow *DuneEditorDeMapas)
    {
        if (DuneEditorDeMapas->objectName().isEmpty())
            DuneEditorDeMapas->setObjectName(QString::fromUtf8("DuneEditorDeMapas"));
        DuneEditorDeMapas->resize(1280, 720);
        DuneEditorDeMapas->setMinimumSize(QSize(1280, 720));
        DuneEditorDeMapas->setMaximumSize(QSize(1280, 720));
        centralwidget = new QWidget(DuneEditorDeMapas);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        EditorList = new QListWidget(centralwidget);
        EditorList->setObjectName(QString::fromUtf8("EditorList"));
        EditorList->setGeometry(QRect(1000, 0, 291, 721));
        EditorList->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        EditonModeLabel = new QLabel(centralwidget);
        EditonModeLabel->setObjectName(QString::fromUtf8("EditonModeLabel"));
        EditonModeLabel->setGeometry(QRect(1020, 10, 241, 31));
        EditonModeLabel->setStyleSheet(QString::fromUtf8(""));
        RequiredPlayersLabel = new QLabel(centralwidget);
        RequiredPlayersLabel->setObjectName(QString::fromUtf8("RequiredPlayersLabel"));
        RequiredPlayersLabel->setGeometry(QRect(1020, 60, 161, 21));
        DimentiosLabel = new QLabel(centralwidget);
        DimentiosLabel->setObjectName(QString::fromUtf8("DimentiosLabel"));
        DimentiosLabel->setGeometry(QRect(1020, 110, 241, 21));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(1070, 680, 141, 25));
        SaveButton->setCursor(QCursor(Qt::PointingHandCursor));
        SaveButton->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));
        TerrainTypeLabel = new QLabel(centralwidget);
        TerrainTypeLabel->setObjectName(QString::fromUtf8("TerrainTypeLabel"));
        TerrainTypeLabel->setGeometry(QRect(1020, 180, 121, 21));
        TerrainTypeComboBox = new QComboBox(centralwidget);
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->setObjectName(QString::fromUtf8("TerrainTypeComboBox"));
        TerrainTypeComboBox->setGeometry(QRect(1020, 210, 251, 25));
        TerrainTypeComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        TerrainTextureLabel = new QLabel(centralwidget);
        TerrainTextureLabel->setObjectName(QString::fromUtf8("TerrainTextureLabel"));
        TerrainTextureLabel->setGeometry(QRect(1020, 260, 131, 21));
        TerrainTextureComboBox = new QComboBox(centralwidget);
        TerrainTextureComboBox->addItem(QString());
        TerrainTextureComboBox->setObjectName(QString::fromUtf8("TerrainTextureComboBox"));
        TerrainTextureComboBox->setGeometry(QRect(1020, 290, 251, 25));
        TerrainTextureComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        TerrainTextureComboBox->setMaxVisibleItems(5);
        DividingLine = new QFrame(centralwidget);
        DividingLine->setObjectName(QString::fromUtf8("DividingLine"));
        DividingLine->setGeometry(QRect(1010, 40, 261, 16));
        DividingLine->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        DividingLine->setFrameShape(QFrame::HLine);
        DividingLine->setFrameShadow(QFrame::Sunken);
        DividingLine_2 = new QFrame(centralwidget);
        DividingLine_2->setObjectName(QString::fromUtf8("DividingLine_2"));
        DividingLine_2->setGeometry(QRect(1010, 90, 261, 16));
        DividingLine_2->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        DividingLine_2->setFrameShape(QFrame::HLine);
        DividingLine_2->setFrameShadow(QFrame::Sunken);
        DividingLine_3 = new QFrame(centralwidget);
        DividingLine_3->setObjectName(QString::fromUtf8("DividingLine_3"));
        DividingLine_3->setGeometry(QRect(1010, 160, 261, 16));
        DividingLine_3->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        DividingLine_3->setFrameShape(QFrame::HLine);
        DividingLine_3->setFrameShadow(QFrame::Sunken);
        DividingLine_4 = new QFrame(centralwidget);
        DividingLine_4->setObjectName(QString::fromUtf8("DividingLine_4"));
        DividingLine_4->setGeometry(QRect(1010, 240, 261, 16));
        DividingLine_4->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        DividingLine_4->setFrameShape(QFrame::HLine);
        DividingLine_4->setFrameShadow(QFrame::Sunken);
        DividingLine_5 = new QFrame(centralwidget);
        DividingLine_5->setObjectName(QString::fromUtf8("DividingLine_5"));
        DividingLine_5->setGeometry(QRect(1010, 400, 261, 16));
        DividingLine_5->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        DividingLine_5->setFrameShape(QFrame::HLine);
        DividingLine_5->setFrameShadow(QFrame::Sunken);
        DividingLine_6 = new QFrame(centralwidget);
        DividingLine_6->setObjectName(QString::fromUtf8("DividingLine_6"));
        DividingLine_6->setGeometry(QRect(1010, 660, 261, 16));
        DividingLine_6->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        DividingLine_6->setFrameShape(QFrame::HLine);
        DividingLine_6->setFrameShadow(QFrame::Sunken);
        xLabel = new QLabel(centralwidget);
        xLabel->setObjectName(QString::fromUtf8("xLabel"));
        xLabel->setGeometry(QRect(1160, 140, 16, 17));
        CantFilasLabel = new QLabel(centralwidget);
        CantFilasLabel->setObjectName(QString::fromUtf8("CantFilasLabel"));
        CantFilasLabel->setGeometry(QRect(1100, 140, 51, 17));
        CantColumnasLabel = new QLabel(centralwidget);
        CantColumnasLabel->setObjectName(QString::fromUtf8("CantColumnasLabel"));
        CantColumnasLabel->setGeometry(QRect(1180, 140, 81, 17));
        CantJugadoresLabel = new QLabel(centralwidget);
        CantJugadoresLabel->setObjectName(QString::fromUtf8("CantJugadoresLabel"));
        CantJugadoresLabel->setGeometry(QRect(1190, 60, 67, 21));
        MostradorTexturaLabel = new QLabel(centralwidget);
        MostradorTexturaLabel->setObjectName(QString::fromUtf8("MostradorTexturaLabel"));
        MostradorTexturaLabel->setGeometry(QRect(1120, 340, 50, 50));
        MostradorTexturaLabel->setFrameShape(QFrame::Box);
        MostradorTexturaLabel->setFrameShadow(QFrame::Plain);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 1001, 721));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 999, 719));
        scrollArea->setWidget(scrollAreaWidgetContents);
        DuneEditorDeMapas->setCentralWidget(centralwidget);

        retranslateUi(DuneEditorDeMapas);

        QMetaObject::connectSlotsByName(DuneEditorDeMapas);
    } // setupUi

    void retranslateUi(QMainWindow *DuneEditorDeMapas)
    {
        DuneEditorDeMapas->setWindowTitle(QApplication::translate("DuneEditorDeMapas", "Dune2000 Editor de Mapas", nullptr));
        EditonModeLabel->setText(QString());
        RequiredPlayersLabel->setText(QApplication::translate("DuneEditorDeMapas", "Jugadores requeridos:", nullptr));
        DimentiosLabel->setText(QApplication::translate("DuneEditorDeMapas", "Dimensiones <filas> x <columnas>:", nullptr));
        SaveButton->setText(QApplication::translate("DuneEditorDeMapas", "Guardar", nullptr));
        TerrainTypeLabel->setText(QApplication::translate("DuneEditorDeMapas", "Tipo de terreno:", nullptr));
        TerrainTypeComboBox->setItemText(0, QApplication::translate("DuneEditorDeMapas", "-", nullptr));
        TerrainTypeComboBox->setItemText(1, QApplication::translate("DuneEditorDeMapas", "Arena", nullptr));
        TerrainTypeComboBox->setItemText(2, QApplication::translate("DuneEditorDeMapas", "Duna", nullptr));
        TerrainTypeComboBox->setItemText(3, QApplication::translate("DuneEditorDeMapas", "Roca", nullptr));
        TerrainTypeComboBox->setItemText(4, QApplication::translate("DuneEditorDeMapas", "Cima", nullptr));
        TerrainTypeComboBox->setItemText(5, QApplication::translate("DuneEditorDeMapas", "Precipicio", nullptr));
        TerrainTypeComboBox->setItemText(6, QApplication::translate("DuneEditorDeMapas", "Especia", nullptr));

        TerrainTextureLabel->setText(QApplication::translate("DuneEditorDeMapas", "Textura de terreno:", nullptr));
        TerrainTextureComboBox->setItemText(0, QApplication::translate("DuneEditorDeMapas", "-", nullptr));

        xLabel->setText(QApplication::translate("DuneEditorDeMapas", "x", nullptr));
        CantFilasLabel->setText(QString());
        CantColumnasLabel->setText(QString());
        CantJugadoresLabel->setText(QString());
        MostradorTexturaLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DuneEditorDeMapas: public Ui_DuneEditorDeMapas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUNEEDITORDEMAPASUI_H
