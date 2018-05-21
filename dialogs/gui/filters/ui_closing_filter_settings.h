/********************************************************************************
** Form generated from reading UI file 'closing_filter_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOSING_FILTER_SETTINGS_H
#define UI_CLOSING_FILTER_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClosingFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lyt_depth;
    QLabel *lbl_shape_label;
    QComboBox *cmb_shape_value;
    QHBoxLayout *lyt_k_size;
    QLabel *lbl_k_size_label;
    QSpinBox *spb_k_size_value;

    void setupUi(QDialog *ClosingFilterDialog)
    {
        if (ClosingFilterDialog->objectName().isEmpty())
            ClosingFilterDialog->setObjectName(QStringLiteral("ClosingFilterDialog"));
        ClosingFilterDialog->resize(400, 166);
        verticalLayout = new QVBoxLayout(ClosingFilterDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lyt_depth = new QHBoxLayout();
        lyt_depth->setObjectName(QStringLiteral("lyt_depth"));
        lbl_shape_label = new QLabel(ClosingFilterDialog);
        lbl_shape_label->setObjectName(QStringLiteral("lbl_shape_label"));

        lyt_depth->addWidget(lbl_shape_label);

        cmb_shape_value = new QComboBox(ClosingFilterDialog);
        cmb_shape_value->setObjectName(QStringLiteral("cmb_shape_value"));

        lyt_depth->addWidget(cmb_shape_value);


        verticalLayout->addLayout(lyt_depth);

        lyt_k_size = new QHBoxLayout();
        lyt_k_size->setObjectName(QStringLiteral("lyt_k_size"));
        lbl_k_size_label = new QLabel(ClosingFilterDialog);
        lbl_k_size_label->setObjectName(QStringLiteral("lbl_k_size_label"));

        lyt_k_size->addWidget(lbl_k_size_label);

        spb_k_size_value = new QSpinBox(ClosingFilterDialog);
        spb_k_size_value->setObjectName(QStringLiteral("spb_k_size_value"));
        spb_k_size_value->setMinimumSize(QSize(75, 0));
        spb_k_size_value->setMaximumSize(QSize(0, 16777215));
        spb_k_size_value->setMinimum(1);

        lyt_k_size->addWidget(spb_k_size_value);


        verticalLayout->addLayout(lyt_k_size);


        retranslateUi(ClosingFilterDialog);

        QMetaObject::connectSlotsByName(ClosingFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *ClosingFilterDialog)
    {
        ClosingFilterDialog->setWindowTitle(QApplication::translate("ClosingFilterDialog", "Dialog", nullptr));
        lbl_shape_label->setText(QApplication::translate("ClosingFilterDialog", "Morphological Shape:", nullptr));
        lbl_k_size_label->setText(QApplication::translate("ClosingFilterDialog", "K-Size (M, M):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClosingFilterDialog: public Ui_ClosingFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOSING_FILTER_SETTINGS_H
