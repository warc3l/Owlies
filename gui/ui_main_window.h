/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_image;
    QAction *actionSave_image;
    QAction *actionQuit;
    QAction *actionUndo_action;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 514);
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
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
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

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_image->setText(QApplication::translate("MainWindow", "Open image...", nullptr));
        actionSave_image->setText(QApplication::translate("MainWindow", "Save image...", nullptr));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        actionUndo_action->setText(QApplication::translate("MainWindow", "Undo action", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H