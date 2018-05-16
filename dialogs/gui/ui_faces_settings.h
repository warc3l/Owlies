/********************************************************************************
** Form generated from reading UI file 'faces_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACES_SETTINGS_H
#define UI_FACES_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "subclasses/color_label.hpp"

QT_BEGIN_NAMESPACE

class Ui_FacesDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *lyt_color;
    QLabel *lyt_color_label;
    ColorLabel *lyt_color_value;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *lyt_scale;
    QLabel *lbl_scale_label;
    QSpinBox *spb_scale_value;
    QHBoxLayout *lyt_neighbours;
    QLabel *lbl_neighbours_label;
    QSpinBox *spb_neighbours_value;

    void setupUi(QDialog *FacesDialog)
    {
        if (FacesDialog->objectName().isEmpty())
            FacesDialog->setObjectName(QStringLiteral("FacesDialog"));
        FacesDialog->resize(465, 130);
        horizontalLayout = new QHBoxLayout(FacesDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        lyt_color = new QHBoxLayout();
        lyt_color->setObjectName(QStringLiteral("lyt_color"));
        lyt_color->setContentsMargins(-1, -1, 10, -1);
        lyt_color_label = new QLabel(FacesDialog);
        lyt_color_label->setObjectName(QStringLiteral("lyt_color_label"));

        lyt_color->addWidget(lyt_color_label);

        lyt_color_value = new ColorLabel(FacesDialog);
        lyt_color_value->setObjectName(QStringLiteral("lyt_color_value"));
        lyt_color_value->setMinimumSize(QSize(15, 15));
        lyt_color_value->setMaximumSize(QSize(15, 15));
        lyt_color_value->setStyleSheet(QStringLiteral(""));

        lyt_color->addWidget(lyt_color_value);


        horizontalLayout->addLayout(lyt_color);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lyt_scale = new QHBoxLayout();
        lyt_scale->setObjectName(QStringLiteral("lyt_scale"));
        lbl_scale_label = new QLabel(FacesDialog);
        lbl_scale_label->setObjectName(QStringLiteral("lbl_scale_label"));

        lyt_scale->addWidget(lbl_scale_label);

        spb_scale_value = new QSpinBox(FacesDialog);
        spb_scale_value->setObjectName(QStringLiteral("spb_scale_value"));
        spb_scale_value->setMinimumSize(QSize(75, 0));
        spb_scale_value->setMaximumSize(QSize(0, 16777215));
        spb_scale_value->setMinimum(1);

        lyt_scale->addWidget(spb_scale_value);

        lyt_scale->setStretch(1, 1);

        verticalLayout_2->addLayout(lyt_scale);

        lyt_neighbours = new QHBoxLayout();
        lyt_neighbours->setObjectName(QStringLiteral("lyt_neighbours"));
        lbl_neighbours_label = new QLabel(FacesDialog);
        lbl_neighbours_label->setObjectName(QStringLiteral("lbl_neighbours_label"));

        lyt_neighbours->addWidget(lbl_neighbours_label);

        spb_neighbours_value = new QSpinBox(FacesDialog);
        spb_neighbours_value->setObjectName(QStringLiteral("spb_neighbours_value"));
        spb_neighbours_value->setMinimumSize(QSize(75, 0));
        spb_neighbours_value->setMaximumSize(QSize(0, 16777215));
        spb_neighbours_value->setMinimum(0);

        lyt_neighbours->addWidget(spb_neighbours_value);

        lyt_neighbours->setStretch(1, 1);

        verticalLayout_2->addLayout(lyt_neighbours);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(FacesDialog);

        QMetaObject::connectSlotsByName(FacesDialog);
    } // setupUi

    void retranslateUi(QDialog *FacesDialog)
    {
        FacesDialog->setWindowTitle(QApplication::translate("FacesDialog", "Dialog", nullptr));
        lyt_color_label->setText(QApplication::translate("FacesDialog", "Color:", nullptr));
        lyt_color_value->setText(QString());
        lbl_scale_label->setText(QApplication::translate("FacesDialog", "Scale factor", nullptr));
        lbl_neighbours_label->setText(QApplication::translate("FacesDialog", "Min. Neighbours:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FacesDialog: public Ui_FacesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACES_SETTINGS_H
