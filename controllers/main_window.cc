#include "main_window.hpp"
#include "../model/image.hpp"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	/* Create all the necessary connections */
	connect(ui->actionOpen_image, &QAction::triggered, this, &MainWindow::open_image);
	connect(ui->actionSave_image, &QAction::triggered, this, &MainWindow::save_image);

	QLabel* lbl_image_name = new QLabel("");	
	ui->statusbar->addWidget(lbl_image_name, 1);
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
		
		QString width = QString::fromStdString(std::to_string(img->get_modified_pixmap().width()));
		QString height = QString::fromStdString(std::to_string(img->get_modified_pixmap().height()));


	    QLabel* lbl_image_pointer = ui->statusbar->findChild<QLabel*>("lbl_image_pointer");
    	if (lbl_image_pointer == nullptr)
		{
			lbl_image_pointer = new QLabel("(0,0)");
			lbl_image_pointer->setObjectName("lbl_image_pointer");
			ui->statusbar->addWidget(lbl_image_pointer);
		}

		QLabel* lbl_image_size = ui->statusbar->findChild<QLabel*>("lbl_image_size");
		if (lbl_image_size == nullptr)
		{
			lbl_image_size = new QLabel("(" + width + ", " + height + ")");
			lbl_image_size->setObjectName("lbl_image_size");
			ui->statusbar->addWidget(lbl_image_size);
		}
		else
		{
			lbl_image_size->setText("(" + width + ", " + height + ")");
		}
	}
	catch(...)
	{
		std::cout << "The file entered is not an image" << std::endl;
	}
}

void MainWindow::save_image(void)
{
	std::cout << "Save, world" << std::endl;
	Image* img = Image::instance();

	if (img)
	{
		QString save_filename = QFileDialog::getSaveFileName(this, "Save modified image", "", "PNG image(*.png)");
		QFile file(save_filename);
		file.open(QIODevice::WriteOnly);
		img->get_modified_pixmap().save(&file, "PNG");
	}
}

void MainWindow::refresh_image(void)
{
	Image* img = Image::instance();
	ui->main_window_image->setPixmap(img->get_modified_pixmap());
	adjustSize();
}

MainWindow::~MainWindow()
{
	delete ui;
}

