#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn_option1, &QPushButton::clicked, this, &MainWindow::option1_called);
    connect(ui->btn_option2, &QPushButton::clicked, this, &MainWindow::option2_called);
    connect(ui->btn_option3, &QPushButton::clicked, this, &MainWindow::option3_called);
    connect(ui->btn_option4, &QPushButton::clicked, this, &MainWindow::option4_called);
}

void MainWindow::option1_called(void)
{
    /*
        std::unique_ptr<QWidget> push_button = std::make_unique<QPushButton>();

        this->centralWidget()->layout()->addWidget(push_button);
    */

    QWidget* pushbutton = new QPushButton("Hello!");
    ui->stackedWidget->currentWidget()->layout()->addWidget(pushbutton);
}

void MainWindow::option2_called(void)
{
}

void MainWindow::option3_called(void)
{
}

void MainWindow::option4_called(void)
{
}

void MainWindow::change_page(int index)
{
}

MainWindow::~MainWindow()
{
    delete ui;
}
