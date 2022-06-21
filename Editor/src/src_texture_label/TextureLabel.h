/********************************************************************************
** Form generated from reading UI file 'label.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTURE_LABEL_H
#define UI_TEXTURE_LABEL_H

#include "../src_editor/DuneEditorDeMapasUi.h"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

class TextureLabel: public QLabel {
    public:
    QLabel *label;

    {
        label = new QLabel();
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 50, 50));
        label->setMinimumSize(QSize(50, 50));
        label->setMaximumSize(QSize(50, 50));
        label->setPixmap(QPixmap(QString::fromUtf8(":/prefijoNuevo/resources/Arena.png")));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};
#endif // UI_TEXTURE_LABEL_H
