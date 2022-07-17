/********************************************************************************
** Form generated from reading UI file 'toolbox.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBOX_H
#define UI_TOOLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Toolbox
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *group_basic;
    QGridLayout *gridLayout;
    QToolButton *btn_zoom_in;
    QToolButton *btn_zoom_out;
    QToolButton *btn_crop;
    QFrame *line;
    QGroupBox *group_manipulation;
    QGridLayout *gridLayout_2;
    QToolButton *btn_scale;
    QToolButton *btn_invert_image;
    QToolButton *btn_draw;
    QFrame *line_2;
    QGroupBox *group_colors;
    QGridLayout *gridLayout_4;
    QToolButton *btn_sature;
    QToolButton *btn_invert_colors;
    QToolButton *btn_pick;
    QFrame *line_3;
    QGroupBox *group_filters;
    QGridLayout *gridLayout_3;
    QToolButton *btn_filter_2;
    QToolButton *btn_filter_3;
    QToolButton *btn_filter_1;
    QToolButton *btn_filter_menu;
    QFrame *line_4;
    QGroupBox *group_recognition;
    QGridLayout *gridLayout_5;
    QToolButton *btn_thin;
    QToolButton *btn_recognize;
    QToolButton *btn_faces;
    QFrame *line_5;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Toolbox)
    {
        if (Toolbox->objectName().isEmpty())
            Toolbox->setObjectName(QStringLiteral("Toolbox"));
        Toolbox->setWindowModality(Qt::NonModal);
        Toolbox->resize(164, 433);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Toolbox->sizePolicy().hasHeightForWidth());
        Toolbox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Toolbox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        group_basic = new QGroupBox(Toolbox);
        group_basic->setObjectName(QStringLiteral("group_basic"));
        gridLayout = new QGridLayout(group_basic);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_zoom_in = new QToolButton(group_basic);
        btn_zoom_in->setObjectName(QStringLiteral("btn_zoom_in"));
        btn_zoom_in->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/ic_zoom_in_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_zoom_in->setIcon(icon);

        gridLayout->addWidget(btn_zoom_in, 0, 1, 1, 1);

        btn_zoom_out = new QToolButton(group_basic);
        btn_zoom_out->setObjectName(QStringLiteral("btn_zoom_out"));
        btn_zoom_out->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/ic_zoom_out_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_zoom_out->setIcon(icon1);

        gridLayout->addWidget(btn_zoom_out, 0, 2, 1, 1);

        btn_crop = new QToolButton(group_basic);
        btn_crop->setObjectName(QStringLiteral("btn_crop"));
        btn_crop->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/ic_crop_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_crop->setIcon(icon2);

        gridLayout->addWidget(btn_crop, 0, 0, 1, 1);


        verticalLayout->addWidget(group_basic);

        line = new QFrame(Toolbox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        group_manipulation = new QGroupBox(Toolbox);
        group_manipulation->setObjectName(QStringLiteral("group_manipulation"));
        gridLayout_2 = new QGridLayout(group_manipulation);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btn_scale = new QToolButton(group_manipulation);
        btn_scale->setObjectName(QStringLiteral("btn_scale"));
        btn_scale->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/ic_photo_size_select_large_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_scale->setIcon(icon3);

        gridLayout_2->addWidget(btn_scale, 0, 2, 1, 1);

        btn_invert_image = new QToolButton(group_manipulation);
        btn_invert_image->setObjectName(QStringLiteral("btn_invert_image"));
        btn_invert_image->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/ic_compare_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_invert_image->setIcon(icon4);

        gridLayout_2->addWidget(btn_invert_image, 0, 3, 1, 1);

        btn_draw = new QToolButton(group_manipulation);
        btn_draw->setObjectName(QStringLiteral("btn_draw"));
        btn_draw->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/ic_brush_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_draw->setIcon(icon5);

        gridLayout_2->addWidget(btn_draw, 0, 1, 1, 1);


        verticalLayout->addWidget(group_manipulation);

        line_2 = new QFrame(Toolbox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        group_colors = new QGroupBox(Toolbox);
        group_colors->setObjectName(QStringLiteral("group_colors"));
        gridLayout_4 = new QGridLayout(group_colors);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        btn_sature = new QToolButton(group_colors);
        btn_sature->setObjectName(QStringLiteral("btn_sature"));
        btn_sature->setFocusPolicy(Qt::NoFocus);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/ic_whatshot_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_sature->setIcon(icon6);

        gridLayout_4->addWidget(btn_sature, 0, 2, 1, 1);

        btn_invert_colors = new QToolButton(group_colors);
        btn_invert_colors->setObjectName(QStringLiteral("btn_invert_colors"));
        btn_invert_colors->setFocusPolicy(Qt::NoFocus);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/ic_invert_colors_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_invert_colors->setIcon(icon7);

        gridLayout_4->addWidget(btn_invert_colors, 0, 1, 1, 1);

        btn_pick = new QToolButton(group_colors);
        btn_pick->setObjectName(QStringLiteral("btn_pick"));
        btn_pick->setFocusPolicy(Qt::NoFocus);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/ic_colorize_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_pick->setIcon(icon8);

        gridLayout_4->addWidget(btn_pick, 0, 0, 1, 1);


        verticalLayout->addWidget(group_colors);

        line_3 = new QFrame(Toolbox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        group_filters = new QGroupBox(Toolbox);
        group_filters->setObjectName(QStringLiteral("group_filters"));
        gridLayout_3 = new QGridLayout(group_filters);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        btn_filter_2 = new QToolButton(group_filters);
        btn_filter_2->setObjectName(QStringLiteral("btn_filter_2"));
        btn_filter_2->setFocusPolicy(Qt::NoFocus);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/ic_call_split_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_filter_2->setIcon(icon9);

        gridLayout_3->addWidget(btn_filter_2, 0, 1, 1, 1);

        btn_filter_3 = new QToolButton(group_filters);
        btn_filter_3->setObjectName(QStringLiteral("btn_filter_3"));
        btn_filter_3->setFocusPolicy(Qt::NoFocus);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icons/ic_swap_calls_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_filter_3->setIcon(icon10);

        gridLayout_3->addWidget(btn_filter_3, 0, 2, 1, 1);

        btn_filter_1 = new QToolButton(group_filters);
        btn_filter_1->setObjectName(QStringLiteral("btn_filter_1"));
        btn_filter_1->setFocusPolicy(Qt::NoFocus);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icons/ic_blur_on_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_filter_1->setIcon(icon11);

        gridLayout_3->addWidget(btn_filter_1, 0, 0, 1, 1);

        btn_filter_menu = new QToolButton(group_filters);
        btn_filter_menu->setObjectName(QStringLiteral("btn_filter_menu"));
        btn_filter_menu->setFocusPolicy(Qt::NoFocus);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icons/ic_list_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_filter_menu->setIcon(icon12);

        gridLayout_3->addWidget(btn_filter_menu, 0, 3, 1, 1);


        verticalLayout->addWidget(group_filters);

        line_4 = new QFrame(Toolbox);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        group_recognition = new QGroupBox(Toolbox);
        group_recognition->setObjectName(QStringLiteral("group_recognition"));
        gridLayout_5 = new QGridLayout(group_recognition);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        btn_thin = new QToolButton(group_recognition);
        btn_thin->setObjectName(QStringLiteral("btn_thin"));
        btn_thin->setFocusPolicy(Qt::NoFocus);
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/icons/ic_fingerprint_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_thin->setIcon(icon13);

        gridLayout_5->addWidget(btn_thin, 0, 1, 1, 1);

        btn_recognize = new QToolButton(group_recognition);
        btn_recognize->setObjectName(QStringLiteral("btn_recognize"));
        btn_recognize->setFocusPolicy(Qt::NoFocus);
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/icons/ic_record_voice_over_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_recognize->setIcon(icon14);

        gridLayout_5->addWidget(btn_recognize, 0, 2, 1, 1);

        btn_faces = new QToolButton(group_recognition);
        btn_faces->setObjectName(QStringLiteral("btn_faces"));
        btn_faces->setFocusPolicy(Qt::NoFocus);
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/icons/ic_tag_faces_black_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_faces->setIcon(icon15);

        gridLayout_5->addWidget(btn_faces, 0, 0, 1, 1);


        verticalLayout->addWidget(group_recognition);

        line_5 = new QFrame(Toolbox);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Toolbox);

        QMetaObject::connectSlotsByName(Toolbox);
    } // setupUi

    void retranslateUi(QWidget *Toolbox)
    {
        Toolbox->setWindowTitle(QApplication::translate("Toolbox", "Toolbox", 0));
        group_basic->setTitle(QApplication::translate("Toolbox", " Basic", 0));
        btn_zoom_in->setText(QApplication::translate("Toolbox", "...", 0));
        btn_zoom_out->setText(QApplication::translate("Toolbox", "...", 0));
        btn_crop->setText(QString());
        group_manipulation->setTitle(QApplication::translate("Toolbox", "Manipulation", 0));
        btn_scale->setText(QApplication::translate("Toolbox", "...", 0));
        btn_invert_image->setText(QApplication::translate("Toolbox", "...", 0));
        btn_draw->setText(QApplication::translate("Toolbox", "...", 0));
        group_colors->setTitle(QApplication::translate("Toolbox", "Colors", 0));
        btn_sature->setText(QApplication::translate("Toolbox", "...", 0));
        btn_invert_colors->setText(QApplication::translate("Toolbox", "...", 0));
        btn_pick->setText(QApplication::translate("Toolbox", "...", 0));
        group_filters->setTitle(QApplication::translate("Toolbox", "FIlters", 0));
        btn_filter_2->setText(QApplication::translate("Toolbox", "...", 0));
        btn_filter_3->setText(QApplication::translate("Toolbox", "...", 0));
        btn_filter_1->setText(QApplication::translate("Toolbox", "...", 0));
        btn_filter_menu->setText(QApplication::translate("Toolbox", "...", 0));
        group_recognition->setTitle(QApplication::translate("Toolbox", "Recognition", 0));
        btn_thin->setText(QApplication::translate("Toolbox", "...", 0));
        btn_recognize->setText(QApplication::translate("Toolbox", "...", 0));
        btn_faces->setText(QApplication::translate("Toolbox", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class Toolbox: public Ui_Toolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBOX_H
