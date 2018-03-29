#include "toolbox.hpp"


Toolbox::Toolbox(QWidget* parent, MainWindow* w) : QWidget(parent), ui(new Ui::Toolbox)
{
	ui->setupUi(this);
	setWindowFlags(Qt::Tool);

	main_window = w;

	// Basic
	connect(ui->btn_crop, &QToolButton::clicked, this, &Toolbox::crop);
	connect(ui->btn_zoom_in, &QToolButton::clicked, this, &Toolbox::zoom_in);
	connect(ui->btn_zoom_out, &QToolButton::clicked, this, &Toolbox::zoom_out);

	// Manipulation
	connect(ui->btn_draw, &QToolButton::clicked, this, &Toolbox::draw);
	connect(ui->btn_scale, &QToolButton::clicked, this, &Toolbox::scale);
	connect(ui->btn_invert_image, &QToolButton::clicked, this, &Toolbox::invert_image);

	// Colors
	connect(ui->btn_pick, &QToolButton::clicked, this, &Toolbox::pick);
	connect(ui->btn_invert_colors, &QToolButton::clicked, this, &Toolbox::invert_colors);
	connect(ui->btn_sature, &QToolButton::clicked, this, &Toolbox::sature);

	// Filters
	connect(ui->btn_filter_1, &QToolButton::clicked, this, &Toolbox::filter_1);
	connect(ui->btn_filter_2, &QToolButton::clicked, this, &Toolbox::filter_2);
	connect(ui->btn_filter_3, &QToolButton::clicked, this, &Toolbox::filter_3);

	// Recognition
	connect(ui->btn_faces, &QToolButton::clicked, this, &Toolbox::faces);
	connect(ui->btn_points, &QToolButton::clicked, this, &Toolbox::points);
	connect(ui->btn_recognize, &QToolButton::clicked, this, &Toolbox::recognize);

}

Toolbox::~Toolbox()
{
	delete ui;
}

void Toolbox::crop(void)
{
	Image* img = Image::instance();
	img->set_actual_action(CROP);
}

void Toolbox::zoom_in(void)
{

}

void Toolbox::zoom_out(void)
{

}

void Toolbox::draw(void)
{

}

void Toolbox::scale(void)
{

}

void Toolbox::invert_image(void)
{
	Image* img = Image::instance();
	img->invert_image();
	main_window->refresh_image();
}

void Toolbox::pick(void)
{
	Image* img = Image::instance();
	img->set_actual_action(PICK);
}

void Toolbox::invert_colors(void)
{
	Image* img = Image::instance();
	img->invert_colors();
	main_window->refresh_image();
}

void Toolbox::sature(void)
{

}

void Toolbox::filter_1(void)
{

}

void Toolbox::filter_2(void)
{

}

void Toolbox::filter_3(void)
{

}

void Toolbox::faces(void)
{

}

void Toolbox::points(void)
{

}

void Toolbox::recognize(void)
{

}
