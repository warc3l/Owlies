/********************************************************************************
** Form generated from reading UI file 'bilateral_filter_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILATERAL_FILTER_SETTINGS_H
#define UI_BILATERAL_FILTER_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BilateralFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lyt_diameter;
    QLabel *lbl_diameter_label;
    QSpinBox *spb_diameter_value;
    QHBoxLayout *lyt_sigma_color;
    QLabel *lbl_sigma_color_label;
    QDoubleSpinBox *spb_sigma_color_value;
    QHBoxLayout *lyt_sigma_space;
    QLabel *lbl_sigma_space_label;
    QDoubleSpinBox *spb_sigma_space_value;

    void setupUi(QDialog *BilateralFilterDialog)
    {
        if (BilateralFilterDialog->objectName().isEmpty())
            BilateralFilterDialog->setObjectName(QStringLiteral("BilateralFilterDialog"));
        BilateralFilterDialog->resize(316, 145);
        verticalLayout = new QVBoxLayout(BilateralFilterDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        lyt_diameter = new QHBoxLayout();
        lyt_diameter->setObjectName(QStringLiteral("lyt_diameter"));
        lbl_diameter_label = new QLabel(BilateralFilterDialog);
        lbl_diameter_label->setObjectName(QStringLiteral("lbl_diameter_label"));

        lyt_diameter->addWidget(lbl_diameter_label);

        spb_diameter_value = new QSpinBox(BilateralFilterDialog);
        spb_diameter_value->setObjectName(QStringLiteral("spb_diameter_value"));
        spb_diameter_value->setMinimumSize(QSize(75, 0));
        spb_diameter_value->setMaximumSize(QSize(0, 16777215));

        lyt_diameter->addWidget(spb_diameter_value);


        verticalLayout->addLayout(lyt_diameter);

        lyt_sigma_color = new QHBoxLayout();
        lyt_sigma_color->setObjectName(QStringLiteral("lyt_sigma_color"));
        lbl_sigma_color_label = new QLabel(BilateralFilterDialog);
        lbl_sigma_color_label->setObjectName(QStringLiteral("lbl_sigma_color_label"));

        lyt_sigma_color->addWidget(lbl_sigma_color_label);

        spb_sigma_color_value = new QDoubleSpinBox(BilateralFilterDialog);
        spb_sigma_color_value->setObjectName(QStringLiteral("spb_sigma_color_value"));
        spb_sigma_color_value->setMinimumSize(QSize(75, 0));
        spb_sigma_color_value->setMaximumSize(QSize(0, 16777215));
        spb_sigma_color_value->setDecimals(1);
        spb_sigma_color_value->setMinimum(1);
        spb_sigma_color_value->setSingleStep(0.1);

        lyt_sigma_color->addWidget(spb_sigma_color_value);


        verticalLayout->addLayout(lyt_sigma_color);

        lyt_sigma_space = new QHBoxLayout();
        lyt_sigma_space->setObjectName(QStringLiteral("lyt_sigma_space"));
        lbl_sigma_space_label = new QLabel(BilateralFilterDialog);
        lbl_sigma_space_label->setObjectName(QStringLiteral("lbl_sigma_space_label"));

        lyt_sigma_space->addWidget(lbl_sigma_space_label);

        spb_sigma_space_value = new QDoubleSpinBox(BilateralFilterDialog);
        spb_sigma_space_value->setObjectName(QStringLiteral("spb_sigma_space_value"));
        spb_sigma_space_value->setMinimumSize(QSize(75, 0));
        spb_sigma_space_value->setMaximumSize(QSize(0, 16777215));
        spb_sigma_space_value->setDecimals(1);
        spb_sigma_space_value->setMinimum(1);
        spb_sigma_space_value->setSingleStep(0.1);

        lyt_sigma_space->addWidget(spb_sigma_space_value);


        verticalLayout->addLayout(lyt_sigma_space);


        retranslateUi(BilateralFilterDialog);

        QMetaObject::connectSlotsByName(BilateralFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *BilateralFilterDialog)
    {
        BilateralFilterDialog->setWindowTitle(QApplication::translate("BilateralFilterDialog", "Dialog", 0));
        lbl_diameter_label->setText(QApplication::translate("BilateralFilterDialog", "Diameter of each pixel:", 0));
        lbl_sigma_color_label->setText(QApplication::translate("BilateralFilterDialog", "Sigma Color:", 0));
        lbl_sigma_space_label->setText(QApplication::translate("BilateralFilterDialog", "Sigma Space:", 0));
    } // retranslateUi

};

namespace Ui {
    class BilateralFilterDialog: public Ui_BilateralFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILATERAL_FILTER_SETTINGS_H
