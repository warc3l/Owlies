/********************************************************************************
** Form generated from reading UI file 'gaussian_filter_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUSSIAN_FILTER_SETTINGS_H
#define UI_GAUSSIAN_FILTER_SETTINGS_H

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

class Ui_GaussianFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lyt_k_size;
    QLabel *lbl_k_size_label;
    QSpinBox *spb_k_size_value;
    QHBoxLayout *lyt_sigma_x;
    QLabel *lbl_sigma_x_label;
    QDoubleSpinBox *spb_sigma_x_value;
    QHBoxLayout *lyt_sigma_y;
    QLabel *lbl_sigma_y_label;
    QDoubleSpinBox *spb_sigma_y_value;

    void setupUi(QDialog *GaussianFilterDialog)
    {
        if (GaussianFilterDialog->objectName().isEmpty())
            GaussianFilterDialog->setObjectName(QStringLiteral("GaussianFilterDialog"));
        GaussianFilterDialog->resize(400, 166);
        verticalLayout = new QVBoxLayout(GaussianFilterDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lyt_k_size = new QHBoxLayout();
        lyt_k_size->setObjectName(QStringLiteral("lyt_k_size"));
        lbl_k_size_label = new QLabel(GaussianFilterDialog);
        lbl_k_size_label->setObjectName(QStringLiteral("lbl_k_size_label"));

        lyt_k_size->addWidget(lbl_k_size_label);

        spb_k_size_value = new QSpinBox(GaussianFilterDialog);
        spb_k_size_value->setObjectName(QStringLiteral("spb_k_size_value"));
        spb_k_size_value->setMinimumSize(QSize(75, 0));
        spb_k_size_value->setMaximumSize(QSize(0, 16777215));
        spb_k_size_value->setMinimum(1);

        lyt_k_size->addWidget(spb_k_size_value);


        verticalLayout->addLayout(lyt_k_size);

        lyt_sigma_x = new QHBoxLayout();
        lyt_sigma_x->setObjectName(QStringLiteral("lyt_sigma_x"));
        lbl_sigma_x_label = new QLabel(GaussianFilterDialog);
        lbl_sigma_x_label->setObjectName(QStringLiteral("lbl_sigma_x_label"));

        lyt_sigma_x->addWidget(lbl_sigma_x_label);

        spb_sigma_x_value = new QDoubleSpinBox(GaussianFilterDialog);
        spb_sigma_x_value->setObjectName(QStringLiteral("spb_sigma_x_value"));
        spb_sigma_x_value->setMinimumSize(QSize(75, 0));
        spb_sigma_x_value->setMaximumSize(QSize(0, 16777215));
        spb_sigma_x_value->setMinimum(1);

        lyt_sigma_x->addWidget(spb_sigma_x_value);


        verticalLayout->addLayout(lyt_sigma_x);

        lyt_sigma_y = new QHBoxLayout();
        lyt_sigma_y->setObjectName(QStringLiteral("lyt_sigma_y"));
        lbl_sigma_y_label = new QLabel(GaussianFilterDialog);
        lbl_sigma_y_label->setObjectName(QStringLiteral("lbl_sigma_y_label"));

        lyt_sigma_y->addWidget(lbl_sigma_y_label);

        spb_sigma_y_value = new QDoubleSpinBox(GaussianFilterDialog);
        spb_sigma_y_value->setObjectName(QStringLiteral("spb_sigma_y_value"));
        spb_sigma_y_value->setMinimumSize(QSize(75, 0));
        spb_sigma_y_value->setMaximumSize(QSize(0, 16777215));

        lyt_sigma_y->addWidget(spb_sigma_y_value);


        verticalLayout->addLayout(lyt_sigma_y);


        retranslateUi(GaussianFilterDialog);

        QMetaObject::connectSlotsByName(GaussianFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *GaussianFilterDialog)
    {
        GaussianFilterDialog->setWindowTitle(QApplication::translate("GaussianFilterDialog", "Dialog", nullptr));
        lbl_k_size_label->setText(QApplication::translate("GaussianFilterDialog", "K-Size (M, M):", nullptr));
        lbl_sigma_x_label->setText(QApplication::translate("GaussianFilterDialog", "Sigma X", nullptr));
        lbl_sigma_y_label->setText(QApplication::translate("GaussianFilterDialog", "Sigma Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GaussianFilterDialog: public Ui_GaussianFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUSSIAN_FILTER_SETTINGS_H
