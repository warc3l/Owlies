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

	// Scroll area
	scroll_area = new QScrollArea(this);
	scroll_area->setWidget(ui->centralwidget);
	scroll_area->setWidgetResizable(true);
	setCentralWidget(scroll_area);

	// Shortcuts
	QShortcut* undo_shortcut = new QShortcut(this); 
	undo_shortcut->setKey(Qt::CTRL + Qt::Key_Z);
	connect(undo_shortcut, &QShortcut::activated, this, &MainWindow::undo_action);
}

void MainWindow::undo_action(void)
{
	std::cout << "Undo activated" << std::endl;
	Image* img = Image::instance();
	img->load_saved_state();
	refresh_image();
}

void MainWindow::add_statusbar_widget(QWidget* wdg)
{
	Image* img = Image::instance();
	QString img_pointer = "";
	QString img_size = "";
	while (QLabel* statusbar_wdg = ui->statusbar->findChild<QLabel*>())
	{
		if (statusbar_wdg->objectName() == "lbl_image_pointer")
			img_pointer = statusbar_wdg->text();
		else if (statusbar_wdg->objectName() == "lbl_image_size")
			img_size = statusbar_wdg->text();

		delete statusbar_wdg;
	}

	if (wdg != nullptr)
		ui->statusbar->addWidget(wdg);

	QLabel* lbl_image_name = new QLabel("");
	ui->statusbar->addWidget(lbl_image_name, 1);

	if (img_pointer != "")
	{
		QLabel* lbl_image_pointer = new QLabel(img_pointer);
		lbl_image_pointer->setObjectName("lbl_image_pointer");
		ui->statusbar->addWidget(lbl_image_pointer);
	}
	
	if (img_size != "")
	{
		QLabel* lbl_image_size = new QLabel(img_size);
		lbl_image_size->setObjectName("lbl_image_size");
		ui->statusbar->addWidget(lbl_image_size);
	}
}

void MainWindow::delete_statusbar_widgets(void)
{
	add_statusbar_widget(nullptr);
}

void MainWindow::open_image(int a)
{
	
	// Open a file
	std::string file_name = QFileDialog::getOpenFileName(this, "Open image", "/home/marcel").toUtf8().constData();

	std::cout << file_name << std::endl;

	try
	{
		Image* img = Image::instance(file_name);
		ui->main_window_image->setPixmap(img->get_modified_pixmap());
		adjustSize();
//		this->layout()->setSizeConstraint(QLayout::SetFixedSize); // Freeze QMainWindow to resize. TODO: It would be a problem for high resolution images.

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

		emit newImageLoaded();
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
//	adjustSize();
}

MainWindow::~MainWindow()
{
	delete ui;
}

