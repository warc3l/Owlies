/********************************************************************************
** Form generated from reading UI file 'sobel_filter_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOBEL_FILTER_SETTINGS_H
#define UI_SOBEL_FILTER_SETTINGS_H

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

QT_BEGIN_NAMESPACE

class Ui_SobelFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lyt_scale;
    QLabel *lbl_scale_label;
    QSpinBox *spb_scale_value;
    QHBoxLayout *lyt_k_size;
    QLabel *lbl_k_size_label;
    QSpinBox *spb_k_size_value;
    QHBoxLayout *lyt_delta;
    QLabel *lbl_delta_label;
    QSpinBox *spb_delta_value;
    QHBoxLayout *lyt_dx;
    QLabel *lbl_dx_label;
    QSpinBox *spb_dx_value;
    QHBoxLayout *lyt_dy;
    QLabel *lbl_dy_label;
    QSpinBox *spb_dy_value;

    void setupUi(QDialog *SobelFilterDialog)
    {
        if (SobelFilterDialog->objectName().isEmpty())
            SobelFilterDialog->setObjectName(QStringLiteral("SobelFilterDialog"));
        SobelFilterDialog->resize(400, 182);
        verticalLayout = new QVBoxLayout(SobelFilterDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lyt_scale = new QHBoxLayout();
        lyt_scale->setObjectName(QStringLiteral("lyt_scale"));
        lbl_scale_label = new QLabel(SobelFilterDialog);
        lbl_scale_label->setObjectName(QStringLiteral("lbl_scale_label"));

        lyt_scale->addWidget(lbl_scale_label);

        spb_scale_value = new QSpinBox(SobelFilterDialog);
        spb_scale_value->setObjectName(QStringLiteral("spb_scale_value"));
        spb_scale_value->setMinimumSize(QSize(75, 0));
        spb_scale_value->setMaximumSize(QSize(0, 16777215));
        spb_scale_value->setMinimum(1);

        lyt_scale->addWidget(spb_scale_value);


        verticalLayout->addLayout(lyt_scale);

        lyt_k_size = new QHBoxLayout();
        lyt_k_size->setObjectName(QStringLiteral("lyt_k_size"));
        lbl_k_size_label = new QLabel(SobelFilterDialog);
        lbl_k_size_label->setObjectName(QStringLiteral("lbl_k_size_label"));

        lyt_k_size->addWidget(lbl_k_size_label);

        spb_k_size_value = new QSpinBox(SobelFilterDialog);
        spb_k_size_value->setObjectName(QStringLiteral("spb_k_size_value"));
        spb_k_size_value->setMinimumSize(QSize(75, 0));
        spb_k_size_value->setMaximumSize(QSize(0, 16777215));
        spb_k_size_value->setMinimum(1);

        lyt_k_size->addWidget(spb_k_size_value);


        verticalLayout->addLayout(lyt_k_size);

        lyt_delta = new QHBoxLayout();
        lyt_delta->setObjectName(QStringLiteral("lyt_delta"));
        lbl_delta_label = new QLabel(SobelFilterDialog);
        lbl_delta_label->setObjectName(QStringLiteral("lbl_delta_label"));

        lyt_delta->addWidget(lbl_delta_label);

        spb_delta_value = new QSpinBox(SobelFilterDialog);
        spb_delta_value->setObjectName(QStringLiteral("spb_delta_value"));
        spb_delta_value->setMinimumSize(QSize(75, 0));
        spb_delta_value->setMaximumSize(QSize(0, 16777215));
        spb_delta_value->setMinimum(0);
        spb_delta_value->setValue(0);

        lyt_delta->addWidget(spb_delta_value);


        verticalLayout->addLayout(lyt_delta);

        lyt_dx = new QHBoxLayout();
        lyt_dx->setObjectName(QStringLiteral("lyt_dx"));
        lbl_dx_label = new QLabel(SobelFilterDialog);
        lbl_dx_label->setObjectName(QStringLiteral("lbl_dx_label"));

        lyt_dx->addWidget(lbl_dx_label);

        spb_dx_value = new QSpinBox(SobelFilterDialog);
        spb_dx_value->setObjectName(QStringLiteral("spb_dx_value"));
        spb_dx_value->setMinimumSize(QSize(75, 0));
        spb_dx_value->setMaximumSize(QSize(0, 16777215));
        spb_dx_value->setMinimum(0);
        spb_dx_value->setValue(0);

        lyt_dx->addWidget(spb_dx_value);


        verticalLayout->addLayout(lyt_dx);

        lyt_dy = new QHBoxLayout();
        lyt_dy->setObjectName(QStringLiteral("lyt_dy"));
        lbl_dy_label = new QLabel(SobelFilterDialog);
        lbl_dy_label->setObjectName(QStringLiteral("lbl_dy_label"));

        lyt_dy->addWidget(lbl_dy_label);

        spb_dy_value = new QSpinBox(SobelFilterDialog);
        spb_dy_value->setObjectName(QStringLiteral("spb_dy_value"));
        spb_dy_value->setMinimumSize(QSize(75, 0));
        spb_dy_value->setMaximumSize(QSize(0, 16777215));
        spb_dy_value->setMinimum(0);
        spb_dy_value->setValue(1);

        lyt_dy->addWidget(spb_dy_value);


        verticalLayout->addLayout(lyt_dy);


        retranslateUi(SobelFilterDialog);

        QMetaObject::connectSlotsByName(SobelFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *SobelFilterDialog)
    {
        SobelFilterDialog->setWindowTitle(QApplication::translate("SobelFilterDialog", "Dialog", nullptr));
        lbl_scale_label->setText(QApplication::translate("SobelFilterDialog", "Scale:", nullptr));
        lbl_k_size_label->setText(QApplication::translate("SobelFilterDialog", "K-Size (M, M)", nullptr));
        lbl_delta_label->setText(QApplication::translate("SobelFilterDialog", "Delta:", nullptr));
        lbl_dx_label->setText(QApplication::translate("SobelFilterDialog", "dx:", nullptr));
        lbl_dy_label->setText(QApplication::translate("SobelFilterDialog", "dy:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SobelFilterDialog: public Ui_SobelFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOBEL_FILTER_SETTINGS_H
