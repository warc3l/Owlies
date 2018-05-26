/********************************************************************************
** Form generated from reading UI file 'scharr_filter_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHARR_FILTER_SETTINGS_H
#define UI_SCHARR_FILTER_SETTINGS_H

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

class Ui_ScharrFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lyt_scale;
    QLabel *lbl_scale_label;
    QSpinBox *spb_scale_value;
    QHBoxLayout *lyt_delta;
    QLabel *lbl_delta_label;
    QSpinBox *spb_delta_value;
    QHBoxLayout *lyt_dx;
    QLabel *lbl_dx_label;
    QSpinBox *spb_dx_value;
    QHBoxLayout *lyt_dy;
    QLabel *lbl_dy_label;
    QSpinBox *spb_dy_value;

    void setupUi(QDialog *ScharrFilterDialog)
    {
        if (ScharrFilterDialog->objectName().isEmpty())
            ScharrFilterDialog->setObjectName(QStringLiteral("ScharrFilterDialog"));
        ScharrFilterDialog->resize(400, 166);
        verticalLayout = new QVBoxLayout(ScharrFilterDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lyt_scale = new QHBoxLayout();
        lyt_scale->setObjectName(QStringLiteral("lyt_scale"));
        lbl_scale_label = new QLabel(ScharrFilterDialog);
        lbl_scale_label->setObjectName(QStringLiteral("lbl_scale_label"));

        lyt_scale->addWidget(lbl_scale_label);

        spb_scale_value = new QSpinBox(ScharrFilterDialog);
        spb_scale_value->setObjectName(QStringLiteral("spb_scale_value"));
        spb_scale_value->setMinimumSize(QSize(75, 0));
        spb_scale_value->setMaximumSize(QSize(0, 16777215));
        spb_scale_value->setMinimum(1);

        lyt_scale->addWidget(spb_scale_value);


        verticalLayout->addLayout(lyt_scale);

        lyt_delta = new QHBoxLayout();
        lyt_delta->setObjectName(QStringLiteral("lyt_delta"));
        lbl_delta_label = new QLabel(ScharrFilterDialog);
        lbl_delta_label->setObjectName(QStringLiteral("lbl_delta_label"));

        lyt_delta->addWidget(lbl_delta_label);

        spb_delta_value = new QSpinBox(ScharrFilterDialog);
        spb_delta_value->setObjectName(QStringLiteral("spb_delta_value"));
        spb_delta_value->setMinimumSize(QSize(75, 0));
        spb_delta_value->setMaximumSize(QSize(0, 16777215));
        spb_delta_value->setMinimum(0);
        spb_delta_value->setValue(0);

        lyt_delta->addWidget(spb_delta_value);


        verticalLayout->addLayout(lyt_delta);

        lyt_dx = new QHBoxLayout();
        lyt_dx->setObjectName(QStringLiteral("lyt_dx"));
        lbl_dx_label = new QLabel(ScharrFilterDialog);
        lbl_dx_label->setObjectName(QStringLiteral("lbl_dx_label"));

        lyt_dx->addWidget(lbl_dx_label);

        spb_dx_value = new QSpinBox(ScharrFilterDialog);
        spb_dx_value->setObjectName(QStringLiteral("spb_dx_value"));
        spb_dx_value->setMinimumSize(QSize(75, 0));
        spb_dx_value->setMaximumSize(QSize(0, 16777215));
        spb_dx_value->setMinimum(0);
        spb_dx_value->setValue(0);

        lyt_dx->addWidget(spb_dx_value);


        verticalLayout->addLayout(lyt_dx);

        lyt_dy = new QHBoxLayout();
        lyt_dy->setObjectName(QStringLiteral("lyt_dy"));
        lbl_dy_label = new QLabel(ScharrFilterDialog);
        lbl_dy_label->setObjectName(QStringLiteral("lbl_dy_label"));

        lyt_dy->addWidget(lbl_dy_label);

        spb_dy_value = new QSpinBox(ScharrFilterDialog);
        spb_dy_value->setObjectName(QStringLiteral("spb_dy_value"));
        spb_dy_value->setMinimumSize(QSize(75, 0));
        spb_dy_value->setMaximumSize(QSize(0, 16777215));
        spb_dy_value->setMinimum(0);
        spb_dy_value->setValue(1);

        lyt_dy->addWidget(spb_dy_value);


        verticalLayout->addLayout(lyt_dy);


        retranslateUi(ScharrFilterDialog);

        QMetaObject::connectSlotsByName(ScharrFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *ScharrFilterDialog)
    {
        ScharrFilterDialog->setWindowTitle(QApplication::translate("ScharrFilterDialog", "Dialog", nullptr));
        lbl_scale_label->setText(QApplication::translate("ScharrFilterDialog", "Scale:", nullptr));
        lbl_delta_label->setText(QApplication::translate("ScharrFilterDialog", "Delta:", nullptr));
        lbl_dx_label->setText(QApplication::translate("ScharrFilterDialog", "dx:", nullptr));
        lbl_dy_label->setText(QApplication::translate("ScharrFilterDialog", "dy:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScharrFilterDialog: public Ui_ScharrFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHARR_FILTER_SETTINGS_H
