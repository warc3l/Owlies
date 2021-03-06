/********************************************************************************
** Form generated from reading UI file 'draw_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAW_SETTINGS_H
#define UI_DRAW_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "subclasses/color_label.hpp"

QT_BEGIN_NAMESPACE

class Ui_DrawDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *lyt_color;
    QLabel *lbl_color_label;
    ColorLabel *lbl_color_value;
    QGroupBox *gpb_form;
    QVBoxLayout *verticalLayout;
    QRadioButton *rdp_circle;
    QRadioButton *rdp_triangle;
    QHBoxLayout *lyt_size;
    QLabel *lbl_size_label;
    QSpinBox *spb_size_value;

    void setupUi(QDialog *DrawDialog)
    {
        if (DrawDialog->objectName().isEmpty())
            DrawDialog->setObjectName(QStringLiteral("DrawDialog"));
        DrawDialog->resize(365, 114);
        horizontalLayout = new QHBoxLayout(DrawDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        lyt_color = new QHBoxLayout();
        lyt_color->setObjectName(QStringLiteral("lyt_color"));
        lyt_color->setContentsMargins(-1, -1, 10, -1);
        lbl_color_label = new QLabel(DrawDialog);
        lbl_color_label->setObjectName(QStringLiteral("lbl_color_label"));

        lyt_color->addWidget(lbl_color_label);

        lbl_color_value = new ColorLabel(DrawDialog);
        lbl_color_value->setObjectName(QStringLiteral("lbl_color_value"));
        lbl_color_value->setMinimumSize(QSize(15, 15));
        lbl_color_value->setMaximumSize(QSize(15, 15));
        lbl_color_value->setStyleSheet(QStringLiteral(""));

        lyt_color->addWidget(lbl_color_value);


        horizontalLayout->addLayout(lyt_color);

        gpb_form = new QGroupBox(DrawDialog);
        gpb_form->setObjectName(QStringLiteral("gpb_form"));
        gpb_form->setFlat(false);
        gpb_form->setCheckable(false);
        verticalLayout = new QVBoxLayout(gpb_form);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rdp_circle = new QRadioButton(gpb_form);
        rdp_circle->setObjectName(QStringLiteral("rdp_circle"));

        verticalLayout->addWidget(rdp_circle);

        rdp_triangle = new QRadioButton(gpb_form);
        rdp_triangle->setObjectName(QStringLiteral("rdp_triangle"));

        verticalLayout->addWidget(rdp_triangle);


        horizontalLayout->addWidget(gpb_form);

        lyt_size = new QHBoxLayout();
        lyt_size->setObjectName(QStringLiteral("lyt_size"));
        lbl_size_label = new QLabel(DrawDialog);
        lbl_size_label->setObjectName(QStringLiteral("lbl_size_label"));

        lyt_size->addWidget(lbl_size_label);

        spb_size_value = new QSpinBox(DrawDialog);
        spb_size_value->setObjectName(QStringLiteral("spb_size_value"));
        spb_size_value->setMinimumSize(QSize(75, 0));
        spb_size_value->setMaximumSize(QSize(0, 16777215));

        lyt_size->addWidget(spb_size_value);

        lyt_size->setStretch(1, 1);

        horizontalLayout->addLayout(lyt_size);


        retranslateUi(DrawDialog);

        QMetaObject::connectSlotsByName(DrawDialog);
    } // setupUi

    void retranslateUi(QDialog *DrawDialog)
    {
        DrawDialog->setWindowTitle(QApplication::translate("DrawDialog", "Dialog", nullptr));
        lbl_color_label->setText(QApplication::translate("DrawDialog", "Color:", nullptr));
        lbl_color_value->setText(QString());
        gpb_form->setTitle(QString());
        rdp_circle->setText(QApplication::translate("DrawDialog", "Circle", nullptr));
        rdp_triangle->setText(QApplication::translate("DrawDialog", "Triangle", nullptr));
        lbl_size_label->setText(QApplication::translate("DrawDialog", "Size:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawDialog: public Ui_DrawDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAW_SETTINGS_H
