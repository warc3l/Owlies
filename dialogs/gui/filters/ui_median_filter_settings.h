/********************************************************************************
** Form generated from reading UI file 'median_filter_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAN_FILTER_SETTINGS_H
#define UI_MEDIAN_FILTER_SETTINGS_H

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

class Ui_MedianFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lyt_k_size;
    QLabel *lbl_k_size_label;
    QSpinBox *spb_k_size_value;

    void setupUi(QDialog *MedianFilterDialog)
    {
        if (MedianFilterDialog->objectName().isEmpty())
            MedianFilterDialog->setObjectName(QStringLiteral("MedianFilterDialog"));
        MedianFilterDialog->resize(400, 166);
        verticalLayout = new QVBoxLayout(MedianFilterDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lyt_k_size = new QHBoxLayout();
        lyt_k_size->setObjectName(QStringLiteral("lyt_k_size"));
        lbl_k_size_label = new QLabel(MedianFilterDialog);
        lbl_k_size_label->setObjectName(QStringLiteral("lbl_k_size_label"));

        lyt_k_size->addWidget(lbl_k_size_label);

        spb_k_size_value = new QSpinBox(MedianFilterDialog);
        spb_k_size_value->setObjectName(QStringLiteral("spb_k_size_value"));
        spb_k_size_value->setMinimumSize(QSize(75, 0));
        spb_k_size_value->setMaximumSize(QSize(0, 16777215));
        spb_k_size_value->setMinimum(1);

        lyt_k_size->addWidget(spb_k_size_value);


        verticalLayout->addLayout(lyt_k_size);


        retranslateUi(MedianFilterDialog);

        QMetaObject::connectSlotsByName(MedianFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *MedianFilterDialog)
    {
        MedianFilterDialog->setWindowTitle(QApplication::translate("MedianFilterDialog", "Dialog", nullptr));
        lbl_k_size_label->setText(QApplication::translate("MedianFilterDialog", "K-Size (M, M):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MedianFilterDialog: public Ui_MedianFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAN_FILTER_SETTINGS_H
