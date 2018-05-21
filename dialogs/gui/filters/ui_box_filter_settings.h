/********************************************************************************
** Form generated from reading UI file 'box_filter_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOX_FILTER_SETTINGS_H
#define UI_BOX_FILTER_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BoxFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lyt_depth;
    QLabel *lbl_depth_label;
    QComboBox *cmb_depth_value;
    QHBoxLayout *lyt_k_size;
    QLabel *lbl_k_size_label;
    QSpinBox *spb_k_size_value;
    QHBoxLayout *lyt_normalized;
    QLabel *lbl_normalized_label;
    QCheckBox *chb_normalized_value;

    void setupUi(QDialog *BoxFilterDialog)
    {
        if (BoxFilterDialog->objectName().isEmpty())
            BoxFilterDialog->setObjectName(QStringLiteral("BoxFilterDialog"));
        BoxFilterDialog->resize(401, 161);
        verticalLayout = new QVBoxLayout(BoxFilterDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        lyt_depth = new QHBoxLayout();
        lyt_depth->setObjectName(QStringLiteral("lyt_depth"));
        lbl_depth_label = new QLabel(BoxFilterDialog);
        lbl_depth_label->setObjectName(QStringLiteral("lbl_depth_label"));

        lyt_depth->addWidget(lbl_depth_label);

        cmb_depth_value = new QComboBox(BoxFilterDialog);
        cmb_depth_value->setObjectName(QStringLiteral("cmb_depth_value"));

        lyt_depth->addWidget(cmb_depth_value);


        verticalLayout->addLayout(lyt_depth);

        lyt_k_size = new QHBoxLayout();
        lyt_k_size->setObjectName(QStringLiteral("lyt_k_size"));
        lbl_k_size_label = new QLabel(BoxFilterDialog);
        lbl_k_size_label->setObjectName(QStringLiteral("lbl_k_size_label"));

        lyt_k_size->addWidget(lbl_k_size_label);

        spb_k_size_value = new QSpinBox(BoxFilterDialog);
        spb_k_size_value->setObjectName(QStringLiteral("spb_k_size_value"));
        spb_k_size_value->setMinimumSize(QSize(75, 0));
        spb_k_size_value->setMaximumSize(QSize(0, 16777215));
        spb_k_size_value->setMinimum(1);

        lyt_k_size->addWidget(spb_k_size_value);


        verticalLayout->addLayout(lyt_k_size);

        lyt_normalized = new QHBoxLayout();
        lyt_normalized->setObjectName(QStringLiteral("lyt_normalized"));
        lbl_normalized_label = new QLabel(BoxFilterDialog);
        lbl_normalized_label->setObjectName(QStringLiteral("lbl_normalized_label"));

        lyt_normalized->addWidget(lbl_normalized_label);

        chb_normalized_value = new QCheckBox(BoxFilterDialog);
        chb_normalized_value->setObjectName(QStringLiteral("chb_normalized_value"));

        lyt_normalized->addWidget(chb_normalized_value);

        lyt_normalized->setStretch(0, 1);

        verticalLayout->addLayout(lyt_normalized);


        retranslateUi(BoxFilterDialog);

        QMetaObject::connectSlotsByName(BoxFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *BoxFilterDialog)
    {
        BoxFilterDialog->setWindowTitle(QApplication::translate("BoxFilterDialog", "Dialog", nullptr));
        lbl_depth_label->setText(QApplication::translate("BoxFilterDialog", "Desired depth:", nullptr));
        lbl_k_size_label->setText(QApplication::translate("BoxFilterDialog", "K-Size (M, M):", nullptr));
        lbl_normalized_label->setText(QApplication::translate("BoxFilterDialog", "Normalized:", nullptr));
        chb_normalized_value->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BoxFilterDialog: public Ui_BoxFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOX_FILTER_SETTINGS_H
