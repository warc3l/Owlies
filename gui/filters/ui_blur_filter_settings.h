/********************************************************************************
** Form generated from reading UI file 'blur_filter_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUR_FILTER_SETTINGS_H
#define UI_BLUR_FILTER_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BlurFilterDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_k_size_label;
    QSpinBox *spb_k_size_value;

    void setupUi(QDialog *BlurFilterDialog)
    {
        if (BlurFilterDialog->objectName().isEmpty())
            BlurFilterDialog->setObjectName(QStringLiteral("BlurFilterDialog"));
        BlurFilterDialog->resize(292, 71);
        horizontalLayout = new QHBoxLayout(BlurFilterDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        lbl_k_size_label = new QLabel(BlurFilterDialog);
        lbl_k_size_label->setObjectName(QStringLiteral("lbl_k_size_label"));

        horizontalLayout->addWidget(lbl_k_size_label);

        spb_k_size_value = new QSpinBox(BlurFilterDialog);
        spb_k_size_value->setObjectName(QStringLiteral("spb_k_size_value"));
        spb_k_size_value->setMinimumSize(QSize(75, 0));
        spb_k_size_value->setMaximumSize(QSize(0, 16777215));
        spb_k_size_value->setMinimum(1);

        horizontalLayout->addWidget(spb_k_size_value);


        retranslateUi(BlurFilterDialog);

        QMetaObject::connectSlotsByName(BlurFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *BlurFilterDialog)
    {
        BlurFilterDialog->setWindowTitle(QApplication::translate("BlurFilterDialog", "Dialog", 0));
        lbl_k_size_label->setText(QApplication::translate("BlurFilterDialog", "K-Size (M, M):", 0));
    } // retranslateUi

};

namespace Ui {
    class BlurFilterDialog: public Ui_BlurFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUR_FILTER_SETTINGS_H
