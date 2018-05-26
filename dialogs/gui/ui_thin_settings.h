/********************************************************************************
** Form generated from reading UI file 'thin_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIN_SETTINGS_H
#define UI_THIN_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "subclasses/color_label.hpp"

QT_BEGIN_NAMESPACE

class Ui_ThinDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *grp_pre_process;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lyt_shape;
    QLabel *lbl_shape_label;
    QComboBox *cmb_shape_value;
    QHBoxLayout *lyt_k_size;
    QLabel *lbl_k_size_label;
    QSpinBox *spb_k_size_value;
    QFrame *line;
    QHBoxLayout *lyt_pre_threshold_thresh;
    QLabel *lbl_pre_threshold_thresh_label;
    QDoubleSpinBox *spb_pre_threshold_thresh_value;
    QHBoxLayout *lyt_pre_threshold_max_value;
    QLabel *lbl_pre_threshold_max_value_label;
    QDoubleSpinBox *spb_pre_threshold_max_value_value;
    QGroupBox *grp_in_process;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *lyt_max_intents;
    QLabel *lbl_max_intents_label;
    QSpinBox *spb_max_intents_value;
    QHBoxLayout *lyt_branch_points;
    QLabel *lbl_branch_points_label;
    QCheckBox *chb_branch_points_value;
    QHBoxLayout *lyt_branch_points_color;
    QLabel *lbl_branch_points_color_label;
    ColorLabel *lbl_branch_points_color_value;
    QGroupBox *grp_post_process;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *lyt_post_threshold_thresh;
    QLabel *lbl_post_threshold_thresh_label;
    QDoubleSpinBox *spb_post_threshold_thresh_value;
    QHBoxLayout *lyt_post_threshold_max_value;
    QLabel *lbl_post_threshold_max_value_label;
    QDoubleSpinBox *spb_post_threshold_max_value_value;

    void setupUi(QDialog *ThinDialog)
    {
        if (ThinDialog->objectName().isEmpty())
            ThinDialog->setObjectName(QStringLiteral("ThinDialog"));
        ThinDialog->resize(819, 241);
        horizontalLayout = new QHBoxLayout(ThinDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        grp_pre_process = new QGroupBox(ThinDialog);
        grp_pre_process->setObjectName(QStringLiteral("grp_pre_process"));
        verticalLayout = new QVBoxLayout(grp_pre_process);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lyt_shape = new QHBoxLayout();
        lyt_shape->setObjectName(QStringLiteral("lyt_shape"));
        lbl_shape_label = new QLabel(grp_pre_process);
        lbl_shape_label->setObjectName(QStringLiteral("lbl_shape_label"));

        lyt_shape->addWidget(lbl_shape_label);

        cmb_shape_value = new QComboBox(grp_pre_process);
        cmb_shape_value->setObjectName(QStringLiteral("cmb_shape_value"));

        lyt_shape->addWidget(cmb_shape_value);


        verticalLayout->addLayout(lyt_shape);

        lyt_k_size = new QHBoxLayout();
        lyt_k_size->setObjectName(QStringLiteral("lyt_k_size"));
        lbl_k_size_label = new QLabel(grp_pre_process);
        lbl_k_size_label->setObjectName(QStringLiteral("lbl_k_size_label"));

        lyt_k_size->addWidget(lbl_k_size_label);

        spb_k_size_value = new QSpinBox(grp_pre_process);
        spb_k_size_value->setObjectName(QStringLiteral("spb_k_size_value"));
        spb_k_size_value->setMinimumSize(QSize(75, 0));
        spb_k_size_value->setMaximumSize(QSize(0, 16777215));
        spb_k_size_value->setMinimum(1);

        lyt_k_size->addWidget(spb_k_size_value);


        verticalLayout->addLayout(lyt_k_size);

        line = new QFrame(grp_pre_process);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        lyt_pre_threshold_thresh = new QHBoxLayout();
        lyt_pre_threshold_thresh->setObjectName(QStringLiteral("lyt_pre_threshold_thresh"));
        lbl_pre_threshold_thresh_label = new QLabel(grp_pre_process);
        lbl_pre_threshold_thresh_label->setObjectName(QStringLiteral("lbl_pre_threshold_thresh_label"));

        lyt_pre_threshold_thresh->addWidget(lbl_pre_threshold_thresh_label);

        spb_pre_threshold_thresh_value = new QDoubleSpinBox(grp_pre_process);
        spb_pre_threshold_thresh_value->setObjectName(QStringLiteral("spb_pre_threshold_thresh_value"));
        spb_pre_threshold_thresh_value->setMinimumSize(QSize(75, 0));
        spb_pre_threshold_thresh_value->setMaximumSize(QSize(0, 16777215));
        spb_pre_threshold_thresh_value->setMaximum(100000);

        lyt_pre_threshold_thresh->addWidget(spb_pre_threshold_thresh_value);


        verticalLayout->addLayout(lyt_pre_threshold_thresh);

        lyt_pre_threshold_max_value = new QHBoxLayout();
        lyt_pre_threshold_max_value->setObjectName(QStringLiteral("lyt_pre_threshold_max_value"));
        lbl_pre_threshold_max_value_label = new QLabel(grp_pre_process);
        lbl_pre_threshold_max_value_label->setObjectName(QStringLiteral("lbl_pre_threshold_max_value_label"));

        lyt_pre_threshold_max_value->addWidget(lbl_pre_threshold_max_value_label);

        spb_pre_threshold_max_value_value = new QDoubleSpinBox(grp_pre_process);
        spb_pre_threshold_max_value_value->setObjectName(QStringLiteral("spb_pre_threshold_max_value_value"));
        spb_pre_threshold_max_value_value->setMinimumSize(QSize(75, 0));
        spb_pre_threshold_max_value_value->setMaximumSize(QSize(0, 16777215));
        spb_pre_threshold_max_value_value->setMaximum(100000);

        lyt_pre_threshold_max_value->addWidget(spb_pre_threshold_max_value_value);


        verticalLayout->addLayout(lyt_pre_threshold_max_value);


        horizontalLayout->addWidget(grp_pre_process);

        grp_in_process = new QGroupBox(ThinDialog);
        grp_in_process->setObjectName(QStringLiteral("grp_in_process"));
        verticalLayout_2 = new QVBoxLayout(grp_in_process);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lyt_max_intents = new QHBoxLayout();
        lyt_max_intents->setObjectName(QStringLiteral("lyt_max_intents"));
        lbl_max_intents_label = new QLabel(grp_in_process);
        lbl_max_intents_label->setObjectName(QStringLiteral("lbl_max_intents_label"));

        lyt_max_intents->addWidget(lbl_max_intents_label);

        spb_max_intents_value = new QSpinBox(grp_in_process);
        spb_max_intents_value->setObjectName(QStringLiteral("spb_max_intents_value"));
        spb_max_intents_value->setMinimumSize(QSize(75, 0));
        spb_max_intents_value->setMaximumSize(QSize(0, 16777215));
        spb_max_intents_value->setMinimum(100);
        spb_max_intents_value->setMaximum(100000);

        lyt_max_intents->addWidget(spb_max_intents_value);


        verticalLayout_2->addLayout(lyt_max_intents);

        lyt_branch_points = new QHBoxLayout();
        lyt_branch_points->setObjectName(QStringLiteral("lyt_branch_points"));
        lbl_branch_points_label = new QLabel(grp_in_process);
        lbl_branch_points_label->setObjectName(QStringLiteral("lbl_branch_points_label"));

        lyt_branch_points->addWidget(lbl_branch_points_label);

        chb_branch_points_value = new QCheckBox(grp_in_process);
        chb_branch_points_value->setObjectName(QStringLiteral("chb_branch_points_value"));

        lyt_branch_points->addWidget(chb_branch_points_value);


        verticalLayout_2->addLayout(lyt_branch_points);

        lyt_branch_points_color = new QHBoxLayout();
        lyt_branch_points_color->setObjectName(QStringLiteral("lyt_branch_points_color"));
        lyt_branch_points_color->setContentsMargins(-1, -1, 10, -1);
        lbl_branch_points_color_label = new QLabel(grp_in_process);
        lbl_branch_points_color_label->setObjectName(QStringLiteral("lbl_branch_points_color_label"));

        lyt_branch_points_color->addWidget(lbl_branch_points_color_label);

        lbl_branch_points_color_value = new ColorLabel(grp_in_process);
        lbl_branch_points_color_value->setObjectName(QStringLiteral("lbl_branch_points_color_value"));
        lbl_branch_points_color_value->setMinimumSize(QSize(15, 15));
        lbl_branch_points_color_value->setMaximumSize(QSize(15, 15));
        lbl_branch_points_color_value->setStyleSheet(QStringLiteral(""));

        lyt_branch_points_color->addWidget(lbl_branch_points_color_value);


        verticalLayout_2->addLayout(lyt_branch_points_color);


        horizontalLayout->addWidget(grp_in_process);

        grp_post_process = new QGroupBox(ThinDialog);
        grp_post_process->setObjectName(QStringLiteral("grp_post_process"));
        verticalLayout_3 = new QVBoxLayout(grp_post_process);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lyt_post_threshold_thresh = new QHBoxLayout();
        lyt_post_threshold_thresh->setObjectName(QStringLiteral("lyt_post_threshold_thresh"));
        lbl_post_threshold_thresh_label = new QLabel(grp_post_process);
        lbl_post_threshold_thresh_label->setObjectName(QStringLiteral("lbl_post_threshold_thresh_label"));

        lyt_post_threshold_thresh->addWidget(lbl_post_threshold_thresh_label);

        spb_post_threshold_thresh_value = new QDoubleSpinBox(grp_post_process);
        spb_post_threshold_thresh_value->setObjectName(QStringLiteral("spb_post_threshold_thresh_value"));
        spb_post_threshold_thresh_value->setMinimumSize(QSize(75, 0));
        spb_post_threshold_thresh_value->setMaximumSize(QSize(0, 16777215));
        spb_post_threshold_thresh_value->setMaximum(100000);

        lyt_post_threshold_thresh->addWidget(spb_post_threshold_thresh_value);


        verticalLayout_3->addLayout(lyt_post_threshold_thresh);

        lyt_post_threshold_max_value = new QHBoxLayout();
        lyt_post_threshold_max_value->setObjectName(QStringLiteral("lyt_post_threshold_max_value"));
        lbl_post_threshold_max_value_label = new QLabel(grp_post_process);
        lbl_post_threshold_max_value_label->setObjectName(QStringLiteral("lbl_post_threshold_max_value_label"));

        lyt_post_threshold_max_value->addWidget(lbl_post_threshold_max_value_label);

        spb_post_threshold_max_value_value = new QDoubleSpinBox(grp_post_process);
        spb_post_threshold_max_value_value->setObjectName(QStringLiteral("spb_post_threshold_max_value_value"));
        spb_post_threshold_max_value_value->setMinimumSize(QSize(75, 0));
        spb_post_threshold_max_value_value->setMaximumSize(QSize(0, 16777215));
        spb_post_threshold_max_value_value->setMaximum(100000);

        lyt_post_threshold_max_value->addWidget(spb_post_threshold_max_value_value);


        verticalLayout_3->addLayout(lyt_post_threshold_max_value);


        horizontalLayout->addWidget(grp_post_process);


        retranslateUi(ThinDialog);

        QMetaObject::connectSlotsByName(ThinDialog);
    } // setupUi

    void retranslateUi(QDialog *ThinDialog)
    {
        ThinDialog->setWindowTitle(QApplication::translate("ThinDialog", "Dialog", nullptr));
        grp_pre_process->setTitle(QApplication::translate("ThinDialog", "Pre-process", nullptr));
        lbl_shape_label->setText(QApplication::translate("ThinDialog", "Morphological Shape:", nullptr));
        lbl_k_size_label->setText(QApplication::translate("ThinDialog", "K-Size (M, M):", nullptr));
        lbl_pre_threshold_thresh_label->setText(QApplication::translate("ThinDialog", "Threshold - thresh:", nullptr));
        lbl_pre_threshold_max_value_label->setText(QApplication::translate("ThinDialog", "Threshold - maxValue:", nullptr));
        grp_in_process->setTitle(QApplication::translate("ThinDialog", "In process", nullptr));
        lbl_max_intents_label->setText(QApplication::translate("ThinDialog", "Max intents:", nullptr));
        lbl_branch_points_label->setText(QApplication::translate("ThinDialog", "Detect Branch-Points:", nullptr));
        chb_branch_points_value->setText(QApplication::translate("ThinDialog", "Yes", nullptr));
        lbl_branch_points_color_label->setText(QApplication::translate("ThinDialog", "Branch-Points color:", nullptr));
        lbl_branch_points_color_value->setText(QString());
        grp_post_process->setTitle(QApplication::translate("ThinDialog", "Post-process", nullptr));
        lbl_post_threshold_thresh_label->setText(QApplication::translate("ThinDialog", "Threshold - thresh:", nullptr));
        lbl_post_threshold_max_value_label->setText(QApplication::translate("ThinDialog", "Threshold - maxValue:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThinDialog: public Ui_ThinDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIN_SETTINGS_H
