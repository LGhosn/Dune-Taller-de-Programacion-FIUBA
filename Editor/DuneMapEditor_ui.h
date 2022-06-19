/********************************************************************************
** Form generated from reading UI file 'DuneMapEditor_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUNEMAPEDITOR_UI_H
#define UI_DUNEMAPEDITOR_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DuneMapEditor
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *MapCells;
    QListWidget *EditorList;
    QLabel *EditonModeLabel;
    QComboBox *EditionModeComboBox;
    QLabel *RequiredPlayersLabel;
    QComboBox *RequiredPlayersComboBox;
    QLabel *DimentiosLabel;
    QSpinBox *RowsSpinBox;
    QSpinBox *ColumnsSpinBox;
    QPushButton *PreviewButton;
    QPushButton *SaveButton;
    QPushButton *ResetButton;
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
    QLabel *label;

    void setupUi(QMainWindow *DuneMapEditor)
    {
        if (DuneMapEditor->objectName().isEmpty())
            DuneMapEditor->setObjectName(QString::fromUtf8("DuneMapEditor"));
        DuneMapEditor->resize(1280, 720);
        DuneMapEditor->setMinimumSize(QSize(1280, 720));
        DuneMapEditor->setMaximumSize(QSize(1280, 720));
        centralwidget = new QWidget(DuneMapEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 1001, 721));
        MapCells = new QGridLayout(gridLayoutWidget);
        MapCells->setSpacing(0);
        MapCells->setObjectName(QString::fromUtf8("MapCells"));
        MapCells->setSizeConstraint(QLayout::SetMinimumSize);
        MapCells->setContentsMargins(0, 0, 0, 0);
        EditorList = new QListWidget(centralwidget);
        EditorList->setObjectName(QString::fromUtf8("EditorList"));
        EditorList->setGeometry(QRect(1000, 0, 291, 721));
        EditorList->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        EditonModeLabel = new QLabel(centralwidget);
        EditonModeLabel->setObjectName(QString::fromUtf8("EditonModeLabel"));
        EditonModeLabel->setGeometry(QRect(1020, 10, 121, 31));
        EditonModeLabel->setStyleSheet(QString::fromUtf8(""));
        EditionModeComboBox = new QComboBox(centralwidget);
        EditionModeComboBox->addItem(QString());
        EditionModeComboBox->addItem(QString());
        EditionModeComboBox->addItem(QString());
        EditionModeComboBox->setObjectName(QString::fromUtf8("EditionModeComboBox"));
        EditionModeComboBox->setGeometry(QRect(1020, 40, 251, 25));
        EditionModeComboBox->setCursor(QCursor(Qt::PointingHandCursor));
        EditionModeComboBox->setInsertPolicy(QComboBox::NoInsert);
        EditionModeComboBox->setMinimumContentsLength(2);
        RequiredPlayersLabel = new QLabel(centralwidget);
        RequiredPlayersLabel->setObjectName(QString::fromUtf8("RequiredPlayersLabel"));
        RequiredPlayersLabel->setGeometry(QRect(1020, 90, 161, 21));
        RequiredPlayersComboBox = new QComboBox(centralwidget);
        RequiredPlayersComboBox->addItem(QString());
        RequiredPlayersComboBox->addItem(QString());
        RequiredPlayersComboBox->addItem(QString());
        RequiredPlayersComboBox->addItem(QString());
        RequiredPlayersComboBox->addItem(QString());
        RequiredPlayersComboBox->setObjectName(QString::fromUtf8("RequiredPlayersComboBox"));
        RequiredPlayersComboBox->setGeometry(QRect(1190, 90, 51, 25));
        RequiredPlayersComboBox->setCursor(QCursor(Qt::PointingHandCursor));
        DimentiosLabel = new QLabel(centralwidget);
        DimentiosLabel->setObjectName(QString::fromUtf8("DimentiosLabel"));
        DimentiosLabel->setGeometry(QRect(1020, 140, 241, 21));
        RowsSpinBox = new QSpinBox(centralwidget);
        RowsSpinBox->setObjectName(QString::fromUtf8("RowsSpinBox"));
        RowsSpinBox->setGeometry(QRect(1080, 160, 71, 26));
        RowsSpinBox->setCursor(QCursor(Qt::PointingHandCursor));
        RowsSpinBox->setMinimum(250);
        RowsSpinBox->setMaximum(1000);
        ColumnsSpinBox = new QSpinBox(centralwidget);
        ColumnsSpinBox->setObjectName(QString::fromUtf8("ColumnsSpinBox"));
        ColumnsSpinBox->setGeometry(QRect(1180, 160, 71, 26));
        ColumnsSpinBox->setCursor(QCursor(Qt::PointingHandCursor));
        ColumnsSpinBox->setMinimum(250);
        ColumnsSpinBox->setMaximum(1000);
        PreviewButton = new QPushButton(centralwidget);
        PreviewButton->setObjectName(QString::fromUtf8("PreviewButton"));
        PreviewButton->setGeometry(QRect(1070, 640, 141, 25));
        PreviewButton->setCursor(QCursor(Qt::PointingHandCursor));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(1070, 680, 141, 25));
        SaveButton->setCursor(QCursor(Qt::PointingHandCursor));
        ResetButton = new QPushButton(centralwidget);
        ResetButton->setObjectName(QString::fromUtf8("ResetButton"));
        ResetButton->setGeometry(QRect(1070, 600, 141, 25));
        ResetButton->setCursor(QCursor(Qt::PointingHandCursor));
        TerrainTypeLabel = new QLabel(centralwidget);
        TerrainTypeLabel->setObjectName(QString::fromUtf8("TerrainTypeLabel"));
        TerrainTypeLabel->setGeometry(QRect(1020, 210, 121, 21));
        TerrainTypeComboBox = new QComboBox(centralwidget);
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->addItem(QString());
        TerrainTypeComboBox->setObjectName(QString::fromUtf8("TerrainTypeComboBox"));
        TerrainTypeComboBox->setGeometry(QRect(1020, 230, 251, 25));
        TerrainTextureLabel = new QLabel(centralwidget);
        TerrainTextureLabel->setObjectName(QString::fromUtf8("TerrainTextureLabel"));
        TerrainTextureLabel->setGeometry(QRect(1020, 280, 131, 21));
        TerrainTextureComboBox = new QComboBox(centralwidget);
        TerrainTextureComboBox->addItem(QString());
        TerrainTextureComboBox->setObjectName(QString::fromUtf8("TerrainTextureComboBox"));
        TerrainTextureComboBox->setGeometry(QRect(1020, 300, 251, 25));
        DividingLine = new QFrame(centralwidget);
        DividingLine->setObjectName(QString::fromUtf8("DividingLine"));
        DividingLine->setGeometry(QRect(1010, 70, 261, 16));
        DividingLine->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        DividingLine->setFrameShape(QFrame::HLine);
        DividingLine->setFrameShadow(QFrame::Sunken);
        DividingLine_2 = new QFrame(centralwidget);
        DividingLine_2->setObjectName(QString::fromUtf8("DividingLine_2"));
        DividingLine_2->setGeometry(QRect(1010, 120, 261, 16));
        DividingLine_2->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        DividingLine_2->setFrameShape(QFrame::HLine);
        DividingLine_2->setFrameShadow(QFrame::Sunken);
        DividingLine_3 = new QFrame(centralwidget);
        DividingLine_3->setObjectName(QString::fromUtf8("DividingLine_3"));
        DividingLine_3->setGeometry(QRect(1010, 190, 261, 16));
        DividingLine_3->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        DividingLine_3->setFrameShape(QFrame::HLine);
        DividingLine_3->setFrameShadow(QFrame::Sunken);
        DividingLine_4 = new QFrame(centralwidget);
        DividingLine_4->setObjectName(QString::fromUtf8("DividingLine_4"));
        DividingLine_4->setGeometry(QRect(1010, 260, 261, 16));
        DividingLine_4->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        DividingLine_4->setFrameShape(QFrame::HLine);
        DividingLine_4->setFrameShadow(QFrame::Sunken);
        DividingLine_5 = new QFrame(centralwidget);
        DividingLine_5->setObjectName(QString::fromUtf8("DividingLine_5"));
        DividingLine_5->setGeometry(QRect(1010, 340, 261, 16));
        DividingLine_5->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        DividingLine_5->setFrameShape(QFrame::HLine);
        DividingLine_5->setFrameShadow(QFrame::Sunken);
        DividingLine_6 = new QFrame(centralwidget);
        DividingLine_6->setObjectName(QString::fromUtf8("DividingLine_6"));
        DividingLine_6->setGeometry(QRect(1010, 580, 261, 16));
        DividingLine_6->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        DividingLine_6->setFrameShape(QFrame::HLine);
        DividingLine_6->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1160, 170, 16, 17));
        DuneMapEditor->setCentralWidget(centralwidget);

        retranslateUi(DuneMapEditor);

        QMetaObject::connectSlotsByName(DuneMapEditor);
    } // setupUi

    void retranslateUi(QMainWindow *DuneMapEditor)
    {
        DuneMapEditor->setWindowTitle(QApplication::translate("DuneMapEditor", "Dune2000 Editor de Mapas", nullptr));
        EditonModeLabel->setText(QApplication::translate("DuneMapEditor", "Modo de edici\303\263n:", nullptr));
        EditionModeComboBox->setItemText(0, QApplication::translate("DuneMapEditor", "-", nullptr));
        EditionModeComboBox->setItemText(1, QApplication::translate("DuneMapEditor", "Crear un nuevo mapa", nullptr));
        EditionModeComboBox->setItemText(2, QApplication::translate("DuneMapEditor", "Editar un mapa existente", nullptr));

        RequiredPlayersLabel->setText(QApplication::translate("DuneMapEditor", "Jugadores requeridos", nullptr));
        RequiredPlayersComboBox->setItemText(0, QApplication::translate("DuneMapEditor", "-", nullptr));
        RequiredPlayersComboBox->setItemText(1, QApplication::translate("DuneMapEditor", "2", nullptr));
        RequiredPlayersComboBox->setItemText(2, QApplication::translate("DuneMapEditor", "3", nullptr));
        RequiredPlayersComboBox->setItemText(3, QApplication::translate("DuneMapEditor", "4", nullptr));
        RequiredPlayersComboBox->setItemText(4, QApplication::translate("DuneMapEditor", "5", nullptr));

        DimentiosLabel->setText(QApplication::translate("DuneMapEditor", "Dimensiones <filas> x <columnas>:", nullptr));
        PreviewButton->setText(QApplication::translate("DuneMapEditor", "Previsualizar", nullptr));
        SaveButton->setText(QApplication::translate("DuneMapEditor", "Guardar", nullptr));
        ResetButton->setText(QApplication::translate("DuneMapEditor", "Reestablecer", nullptr));
        TerrainTypeLabel->setText(QApplication::translate("DuneMapEditor", "Tipo de terreno:", nullptr));
        TerrainTypeComboBox->setItemText(0, QApplication::translate("DuneMapEditor", "-", nullptr));
        TerrainTypeComboBox->setItemText(1, QApplication::translate("DuneMapEditor", "Arena", nullptr));
        TerrainTypeComboBox->setItemText(2, QApplication::translate("DuneMapEditor", "Duna", nullptr));
        TerrainTypeComboBox->setItemText(3, QApplication::translate("DuneMapEditor", "Roca", nullptr));
        TerrainTypeComboBox->setItemText(4, QApplication::translate("DuneMapEditor", "Cima", nullptr));
        TerrainTypeComboBox->setItemText(5, QApplication::translate("DuneMapEditor", "Precipicio", nullptr));

        TerrainTextureLabel->setText(QApplication::translate("DuneMapEditor", "Textura de terreno:", nullptr));
        TerrainTextureComboBox->setItemText(0, QApplication::translate("DuneMapEditor", "-", nullptr));

        label->setText(QApplication::translate("DuneMapEditor", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DuneMapEditor: public Ui_DuneMapEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUNEMAPEDITOR_UI_H
