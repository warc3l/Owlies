/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "subclasses/OwlyRendered.h"
#include "subclasses/image_label.hpp"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_image;
    QAction *actionSave_image;
    QAction *actionQuit;
    QAction *actionUndo_action;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_2;
    ImageLabel *main_window_image;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_3;
    OwlyRendered *openGLWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1044, 698);
        actionOpen_image = new QAction(MainWindow);
        actionOpen_image->setObjectName(QStringLiteral("actionOpen_image"));
        actionSave_image = new QAction(MainWindow);
        actionSave_image->setObjectName(QStringLiteral("actionSave_image"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionUndo_action = new QAction(MainWindow);
        actionUndo_action->setObjectName(QStringLiteral("actionUndo_action"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        sizePolicy.setHeightForWidth(tab_5->sizePolicy().hasHeightForWidth());
        tab_5->setSizePolicy(sizePolicy);
        tab_5->setMinimumSize(QSize(512, 512));
        verticalLayout_2 = new QVBoxLayout(tab_5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        main_window_image = new ImageLabel(tab_5);
        main_window_image->setObjectName(QStringLiteral("main_window_image"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(main_window_image->sizePolicy().hasHeightForWidth());
        main_window_image->setSizePolicy(sizePolicy1);
        main_window_image->setMinimumSize(QSize(512, 512));

        verticalLayout_2->addWidget(main_window_image);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        sizePolicy.setHeightForWidth(tab_6->sizePolicy().hasHeightForWidth());
        tab_6->setSizePolicy(sizePolicy);
        tab_6->setMinimumSize(QSize(512, 512));
        verticalLayout_3 = new QVBoxLayout(tab_6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        openGLWidget = new OwlyRendered(tab_6);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        sizePolicy1.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy1);
        openGLWidget->setMinimumSize(QSize(512, 512));

        verticalLayout_3->addWidget(openGLWidget);

        tabWidget->addTab(tab_6, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1044, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen_image);
        menuFile->addAction(actionSave_image);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionUndo_action);
        menuEdit->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Owlies", 0));
        actionOpen_image->setText(QApplication::translate("MainWindow", "Open image...", 0));
        actionSave_image->setText(QApplication::translate("MainWindow", "Save image...", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionUndo_action->setText(QApplication::translate("MainWindow", "Undo action", 0));
        main_window_image->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Image", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "3D Graphics", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
