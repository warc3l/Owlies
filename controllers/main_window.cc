#include "main_window.hpp"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	/* Create all the necessary connections */
}

MainWindow::~MainWindow()
{
	delete ui;
}

