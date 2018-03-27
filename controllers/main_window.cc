#include "main_window.hpp"
#include "../model/image.hpp"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	/* Create all the necessary connections */
	connect(ui->actionOpen_image, &QAction::triggered, this, &MainWindow::open_image);
	connect(ui->actionSave_image, &QAction::triggered, this, &MainWindow::save_image);
}

void MainWindow::open_image(int a)
{
	std::cout << "Hello, world" << std::endl;
	
	// Open a file
	std::string file_name = QFileDialog::getOpenFileName(this, "Open image", "/home/marcel").toUtf8().constData();

	std::cout << file_name << std::endl;

	try
	{
		Image* img = Image::instance(file_name);
		ui->main_window_image->setPixmap(img->get_modified_pixmap());
		adjustSize();
		this->layout()->setSizeConstraint(QLayout::SetFixedSize); // Freeze QMainWindow to resize. TODO: It would be a problem for high resolution images.
	}
	catch(...)
	{
		std::cout << "The file entered is not an image" << std::endl;
	}
}

void MainWindow::save_image(void)
{
	std::cout << "Save, world" << std::endl;
}

MainWindow::~MainWindow()
{
	delete ui;
}

