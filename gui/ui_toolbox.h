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
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QFrame *line;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton_9;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QToolButton *toolButton_12;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Toolbox)
    {
        if (Toolbox->objectName().isEmpty())
            Toolbox->setObjectName(QStringLiteral("Toolbox"));
        Toolbox->setWindowModality(Qt::NonModal);
        Toolbox->resize(159, 445);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Toolbox->sizePolicy().hasHeightForWidth());
        Toolbox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Toolbox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        groupBox = new QGroupBox(Toolbox);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(toolButton, 0, 0, 1, 1);

        toolButton_2 = new QToolButton(groupBox);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(toolButton_2, 0, 1, 1, 1);

        toolButton_3 = new QToolButton(groupBox);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(toolButton_3, 0, 2, 1, 1);

        toolButton_4 = new QToolButton(groupBox);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(toolButton_4, 1, 0, 1, 1);

        toolButton_5 = new QToolButton(groupBox);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(toolButton_5, 1, 1, 1, 1);

        toolButton_6 = new QToolButton(groupBox);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(toolButton_6, 1, 2, 1, 1);


        verticalLayout->addWidget(groupBox);

        line = new QFrame(Toolbox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        groupBox_2 = new QGroupBox(Toolbox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        toolButton_9 = new QToolButton(groupBox_2);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        toolButton_9->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(toolButton_9, 0, 2, 1, 1);

        toolButton_7 = new QToolButton(groupBox_2);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(toolButton_7, 0, 0, 1, 1);

        toolButton_8 = new QToolButton(groupBox_2);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(toolButton_8, 0, 1, 1, 1);

        toolButton_10 = new QToolButton(groupBox_2);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        toolButton_10->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(toolButton_10, 1, 0, 1, 1);

        toolButton_11 = new QToolButton(groupBox_2);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        toolButton_11->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(toolButton_11, 1, 1, 1, 1);

        toolButton_12 = new QToolButton(groupBox_2);
        toolButton_12->setObjectName(QStringLiteral("toolButton_12"));
        toolButton_12->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(toolButton_12, 1, 2, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Toolbox);

        QMetaObject::connectSlotsByName(Toolbox);
    } // setupUi

    void retranslateUi(QWidget *Toolbox)
    {
        Toolbox->setWindowTitle(QApplication::translate("Toolbox", "Form", 0));
        groupBox->setTitle(QApplication::translate("Toolbox", " Basic Operations", 0));
        toolButton->setText(QApplication::translate("Toolbox", "...", 0));
        toolButton_2->setText(QApplication::translate("Toolbox", "...", 0));
        toolButton_3->setText(QApplication::translate("Toolbox", "...", 0));
        toolButton_4->setText(QApplication::translate("Toolbox", "...", 0));
        toolButton_5->setText(QApplication::translate("Toolbox", "...", 0));
        toolButton_6->setText(QApplication::translate("Toolbox", "...", 0));
        groupBox_2->setTitle(QApplication::translate("Toolbox", "GroupBox", 0));
        toolButton_9->setText(QApplication::translate("Toolbox", "...", 0));
        toolButton_7->setText(QApplication::translate("Toolbox", "...", 0));
        toolButton_8->setText(QApplication::translate("Toolbox", "...", 0));
        toolButton_10->setText(QApplication::translate("Toolbox", "...", 0));
        toolButton_11->setText(QApplication::translate("Toolbox", "...", 0));
        toolButton_12->setText(QApplication::translate("Toolbox", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class Toolbox: public Ui_Toolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBOX_H
