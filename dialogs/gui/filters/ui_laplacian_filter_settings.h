/********************************************************************************
** Form generated from reading UI file 'laplacian_filter_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAPLACIAN_FILTER_SETTINGS_H
#define UI_LAPLACIAN_FILTER_SETTINGS_H

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

class Ui_LaplacianFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lyt_k_size;
    QLabel *lbl_k_size_label;
    QSpinBox *spb_k_size_value;
    QHBoxLayout *lyt_scale;
    QLabel *lbl_scale_label;
    QSpinBox *spb_scale_value;
    QHBoxLayout *lyt_delta;
    QLabel *lbl_delta_label;
    QSpinBox *spb_delta_value;

    void setupUi(QDialog *LaplacianFilterDialog)
    {
        if (LaplacianFilterDialog->objectName().isEmpty())
            LaplacianFilterDialog->setObjectName(QStringLiteral("LaplacianFilterDialog"));
        LaplacianFilterDialog->resize(400, 166);
        verticalLayout = new QVBoxLayout(LaplacianFilterDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lyt_k_size = new QHBoxLayout();
        lyt_k_size->setObjectName(QStringLiteral("lyt_k_size"));
        lbl_k_size_label = new QLabel(LaplacianFilterDialog);
        lbl_k_size_label->setObjectName(QStringLiteral("lbl_k_size_label"));

        lyt_k_size->addWidget(lbl_k_size_label);

        spb_k_size_value = new QSpinBox(LaplacianFilterDialog);
        spb_k_size_value->setObjectName(QStringLiteral("spb_k_size_value"));
        spb_k_size_value->setMinimumSize(QSize(75, 0));
        spb_k_size_value->setMaximumSize(QSize(0, 16777215));
        spb_k_size_value->setMinimum(1);

        lyt_k_size->addWidget(spb_k_size_value);


        verticalLayout->addLayout(lyt_k_size);

        lyt_scale = new QHBoxLayout();
        lyt_scale->setObjectName(QStringLiteral("lyt_scale"));
        lbl_scale_label = new QLabel(LaplacianFilterDialog);
        lbl_scale_label->setObjectName(QStringLiteral("lbl_scale_label"));

        lyt_scale->addWidget(lbl_scale_label);

        spb_scale_value = new QSpinBox(LaplacianFilterDialog);
        spb_scale_value->setObjectName(QStringLiteral("spb_scale_value"));
        spb_scale_value->setMinimumSize(QSize(75, 0));
        spb_scale_value->setMaximumSize(QSize(0, 16777215));
        spb_scale_value->setMinimum(1);

        lyt_scale->addWidget(spb_scale_value);


        verticalLayout->addLayout(lyt_scale);

        lyt_delta = new QHBoxLayout();
        lyt_delta->setObjectName(QStringLiteral("lyt_delta"));
        lbl_delta_label = new QLabel(LaplacianFilterDialog);
        lbl_delta_label->setObjectName(QStringLiteral("lbl_delta_label"));

        lyt_delta->addWidget(lbl_delta_label);

        spb_delta_value = new QSpinBox(LaplacianFilterDialog);
        spb_delta_value->setObjectName(QStringLiteral("spb_delta_value"));
        spb_delta_value->setMinimumSize(QSize(75, 0));
        spb_delta_value->setMaximumSize(QSize(0, 16777215));
        spb_delta_value->setMinimum(1);

        lyt_delta->addWidget(spb_delta_value);


        verticalLayout->addLayout(lyt_delta);


        retranslateUi(LaplacianFilterDialog);

        QMetaObject::connectSlotsByName(LaplacianFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *LaplacianFilterDialog)
    {
        LaplacianFilterDialog->setWindowTitle(QApplication::translate("LaplacianFilterDialog", "Dialog", nullptr));
        lbl_k_size_label->setText(QApplication::translate("LaplacianFilterDialog", "K-Size (M, M):", nullptr));
        lbl_scale_label->setText(QApplication::translate("LaplacianFilterDialog", "Scale:", nullptr));
        lbl_delta_label->setText(QApplication::translate("LaplacianFilterDialog", "Delta:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LaplacianFilterDialog: public Ui_LaplacianFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAPLACIAN_FILTER_SETTINGS_H
