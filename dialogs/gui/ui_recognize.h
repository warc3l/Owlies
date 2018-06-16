/********************************************************************************
** Form generated from reading UI file 'recognize.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOGNIZE_H
#define UI_RECOGNIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecognizeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *cmb_select_option;
    QStackedWidget *stk_train_recognize;
    QWidget *page_train;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *gpb_train;
    QHBoxLayout *horizontalLayout;
    QWidget *wdg_local_cloud;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *rdb_train_local;
    QRadioButton *rdb_train_cloud;
    QStackedWidget *stk_local_cloud;
    QWidget *page_local;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_input_path_local_label;
    QLineEdit *lie_input_path_local_value;
    QWidget *page_cloud;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *lyt_h_cloud_user;
    QLabel *lbl_cloud_user_label;
    QLineEdit *lie_cloud_user_value;
    QHBoxLayout *lyt_h_cloud_password;
    QLabel *lbl_cloud_password_label;
    QLineEdit *lie_cloud_password_value;
    QHBoxLayout *lyt_h_cloud_token;
    QLabel *lbl_cloud_token_label;
    QLineEdit *lie_cloud_token_value;
    QWidget *page_recognize;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *gpb_recognize;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_trained_file_label;
    QLineEdit *lie_trained_file_value;

    void setupUi(QDialog *RecognizeDialog)
    {
        if (RecognizeDialog->objectName().isEmpty())
            RecognizeDialog->setObjectName(QStringLiteral("RecognizeDialog"));
        RecognizeDialog->resize(450, 231);
        verticalLayout = new QVBoxLayout(RecognizeDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        cmb_select_option = new QComboBox(RecognizeDialog);
        cmb_select_option->setObjectName(QStringLiteral("cmb_select_option"));

        verticalLayout->addWidget(cmb_select_option);

        stk_train_recognize = new QStackedWidget(RecognizeDialog);
        stk_train_recognize->setObjectName(QStringLiteral("stk_train_recognize"));
        page_train = new QWidget();
        page_train->setObjectName(QStringLiteral("page_train"));
        verticalLayout_2 = new QVBoxLayout(page_train);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gpb_train = new QGroupBox(page_train);
        gpb_train->setObjectName(QStringLiteral("gpb_train"));
        horizontalLayout = new QHBoxLayout(gpb_train);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        wdg_local_cloud = new QWidget(gpb_train);
        wdg_local_cloud->setObjectName(QStringLiteral("wdg_local_cloud"));
        verticalLayout_4 = new QVBoxLayout(wdg_local_cloud);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        rdb_train_local = new QRadioButton(wdg_local_cloud);
        rdb_train_local->setObjectName(QStringLiteral("rdb_train_local"));

        verticalLayout_4->addWidget(rdb_train_local);

        rdb_train_cloud = new QRadioButton(wdg_local_cloud);
        rdb_train_cloud->setObjectName(QStringLiteral("rdb_train_cloud"));

        verticalLayout_4->addWidget(rdb_train_cloud);


        horizontalLayout->addWidget(wdg_local_cloud);

        stk_local_cloud = new QStackedWidget(gpb_train);
        stk_local_cloud->setObjectName(QStringLiteral("stk_local_cloud"));
        page_local = new QWidget();
        page_local->setObjectName(QStringLiteral("page_local"));
        horizontalLayout_2 = new QHBoxLayout(page_local);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbl_input_path_local_label = new QLabel(page_local);
        lbl_input_path_local_label->setObjectName(QStringLiteral("lbl_input_path_local_label"));

        horizontalLayout_2->addWidget(lbl_input_path_local_label);

        lie_input_path_local_value = new QLineEdit(page_local);
        lie_input_path_local_value->setObjectName(QStringLiteral("lie_input_path_local_value"));

        horizontalLayout_2->addWidget(lie_input_path_local_value);

        stk_local_cloud->addWidget(page_local);
        page_cloud = new QWidget();
        page_cloud->setObjectName(QStringLiteral("page_cloud"));
        verticalLayout_5 = new QVBoxLayout(page_cloud);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lyt_h_cloud_user = new QHBoxLayout();
        lyt_h_cloud_user->setObjectName(QStringLiteral("lyt_h_cloud_user"));
        lbl_cloud_user_label = new QLabel(page_cloud);
        lbl_cloud_user_label->setObjectName(QStringLiteral("lbl_cloud_user_label"));

        lyt_h_cloud_user->addWidget(lbl_cloud_user_label);

        lie_cloud_user_value = new QLineEdit(page_cloud);
        lie_cloud_user_value->setObjectName(QStringLiteral("lie_cloud_user_value"));

        lyt_h_cloud_user->addWidget(lie_cloud_user_value);


        verticalLayout_5->addLayout(lyt_h_cloud_user);

        lyt_h_cloud_password = new QHBoxLayout();
        lyt_h_cloud_password->setObjectName(QStringLiteral("lyt_h_cloud_password"));
        lbl_cloud_password_label = new QLabel(page_cloud);
        lbl_cloud_password_label->setObjectName(QStringLiteral("lbl_cloud_password_label"));

        lyt_h_cloud_password->addWidget(lbl_cloud_password_label);

        lie_cloud_password_value = new QLineEdit(page_cloud);
        lie_cloud_password_value->setObjectName(QStringLiteral("lie_cloud_password_value"));

        lyt_h_cloud_password->addWidget(lie_cloud_password_value);


        verticalLayout_5->addLayout(lyt_h_cloud_password);

        lyt_h_cloud_token = new QHBoxLayout();
        lyt_h_cloud_token->setObjectName(QStringLiteral("lyt_h_cloud_token"));
        lbl_cloud_token_label = new QLabel(page_cloud);
        lbl_cloud_token_label->setObjectName(QStringLiteral("lbl_cloud_token_label"));

        lyt_h_cloud_token->addWidget(lbl_cloud_token_label);

        lie_cloud_token_value = new QLineEdit(page_cloud);
        lie_cloud_token_value->setObjectName(QStringLiteral("lie_cloud_token_value"));

        lyt_h_cloud_token->addWidget(lie_cloud_token_value);


        verticalLayout_5->addLayout(lyt_h_cloud_token);

        stk_local_cloud->addWidget(page_cloud);

        horizontalLayout->addWidget(stk_local_cloud);


        verticalLayout_2->addWidget(gpb_train);

        stk_train_recognize->addWidget(page_train);
        page_recognize = new QWidget();
        page_recognize->setObjectName(QStringLiteral("page_recognize"));
        verticalLayout_3 = new QVBoxLayout(page_recognize);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gpb_recognize = new QGroupBox(page_recognize);
        gpb_recognize->setObjectName(QStringLiteral("gpb_recognize"));
        horizontalLayout_3 = new QHBoxLayout(gpb_recognize);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbl_trained_file_label = new QLabel(gpb_recognize);
        lbl_trained_file_label->setObjectName(QStringLiteral("lbl_trained_file_label"));

        horizontalLayout_3->addWidget(lbl_trained_file_label);

        lie_trained_file_value = new QLineEdit(gpb_recognize);
        lie_trained_file_value->setObjectName(QStringLiteral("lie_trained_file_value"));

        horizontalLayout_3->addWidget(lie_trained_file_value);


        verticalLayout_3->addWidget(gpb_recognize);

        stk_train_recognize->addWidget(page_recognize);

        verticalLayout->addWidget(stk_train_recognize);


        retranslateUi(RecognizeDialog);

        stk_train_recognize->setCurrentIndex(1);
        stk_local_cloud->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(RecognizeDialog);
    } // setupUi

    void retranslateUi(QDialog *RecognizeDialog)
    {
        RecognizeDialog->setWindowTitle(QApplication::translate("RecognizeDialog", "Dialog", 0));
        cmb_select_option->clear();
        cmb_select_option->insertItems(0, QStringList()
         << QApplication::translate("RecognizeDialog", "Train", 0)
         << QApplication::translate("RecognizeDialog", "Recognize", 0)
        );
        gpb_train->setTitle(QApplication::translate("RecognizeDialog", "Train", 0));
        rdb_train_local->setText(QApplication::translate("RecognizeDialog", "Local", 0));
        rdb_train_cloud->setText(QApplication::translate("RecognizeDialog", "Cloud", 0));
        lbl_input_path_local_label->setText(QApplication::translate("RecognizeDialog", "Input path:", 0));
        lbl_cloud_user_label->setText(QApplication::translate("RecognizeDialog", "User:", 0));
        lbl_cloud_password_label->setText(QApplication::translate("RecognizeDialog", "Password:", 0));
        lbl_cloud_token_label->setText(QApplication::translate("RecognizeDialog", "Token:", 0));
        gpb_recognize->setTitle(QApplication::translate("RecognizeDialog", "Recognize", 0));
        lbl_trained_file_label->setText(QApplication::translate("RecognizeDialog", "Trained file:", 0));
    } // retranslateUi

};

namespace Ui {
    class RecognizeDialog: public Ui_RecognizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOGNIZE_H
