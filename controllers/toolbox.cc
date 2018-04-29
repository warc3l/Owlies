#include "toolbox.hpp"


Toolbox::Toolbox(QWidget* parent, MainWindow* w) : QWidget(parent), ui(new Ui::Toolbox)
{
	ui->setupUi(this);
	setWindowFlags(Qt::Tool);

	main_window = w;

	// Basic
	ui->btn_crop->setCheckable(true);
	ui->btn_zoom_in->setCheckable(true);
	ui->btn_zoom_out->setCheckable(true);

	connect(ui->btn_crop, &QToolButton::clicked, this, &Toolbox::crop);
	connect(ui->btn_zoom_in, &QToolButton::clicked, this, &Toolbox::zoom_in);
	connect(ui->btn_zoom_out, &QToolButton::clicked, this, &Toolbox::zoom_out);

	// Manipulation
	ui->btn_draw->setCheckable(true);
	ui->btn_scale->setCheckable(true);

	connect(ui->btn_draw, &QToolButton::clicked, this, &Toolbox::draw);
	connect(ui->btn_scale, &QToolButton::clicked, this, &Toolbox::scale);
	connect(ui->btn_invert_image, &QToolButton::clicked, this, &Toolbox::invert_image);

	// Colors
	ui->btn_pick->setCheckable(true);

	connect(ui->btn_pick, &QToolButton::clicked, this, &Toolbox::pick);
	connect(ui->btn_invert_colors, &QToolButton::clicked, this, &Toolbox::invert_colors);
	connect(ui->btn_sature, &QToolButton::clicked, this, &Toolbox::sature);

	// Filters
	connect(ui->btn_filter_1, &QToolButton::clicked, this, &Toolbox::filter_1);
	connect(ui->btn_filter_2, &QToolButton::clicked, this, &Toolbox::filter_2);
	connect(ui->btn_filter_3, &QToolButton::clicked, this, &Toolbox::filter_3);
	connect(ui->btn_filter_menu, &QToolButton::clicked, this, &Toolbox::filter_menu);

	// Recognition
	connect(ui->btn_faces, &QToolButton::clicked, this, &Toolbox::faces);
	connect(ui->btn_points, &QToolButton::clicked, this, &Toolbox::points);
	connect(ui->btn_recognize, &QToolButton::clicked, this, &Toolbox::recognize);

}

Toolbox::~Toolbox()
{
	delete ui;
}

void Toolbox::uncheck_all(QToolButton* btn_non_uncheck)
{
	bool actual_state = false;

	if (btn_non_uncheck != nullptr)
		actual_state = btn_non_uncheck->isChecked();

	ui->btn_crop->setChecked(false);
	ui->btn_zoom_in->setChecked(false);
	ui->btn_zoom_out->setChecked(false);
	ui->btn_draw->setChecked(false);
	ui->btn_scale->setChecked(false);
	ui->btn_invert_image->setChecked(false);
	ui->btn_pick->setChecked(false);
	ui->btn_invert_colors->setChecked(false);
	ui->btn_sature->setChecked(false);
	ui->btn_filter_1->setChecked(false);
	ui->btn_filter_2->setChecked(false);
	ui->btn_faces->setChecked(false);
	ui->btn_points->setChecked(false);
	ui->btn_recognize->setChecked(false);

	if (btn_non_uncheck != nullptr)
		btn_non_uncheck->setChecked(actual_state);
}

void Toolbox::crop(void)
{
	uncheck_all(ui->btn_crop);
	
	Image* img = Image::instance();
	if ( ui->btn_crop->isChecked() )
		img->set_actual_action(CROP);
	else
		img->set_actual_action(NONE);
}

void Toolbox::zoom_in(void)
{
	uncheck_all(ui->btn_zoom_in);

}

void Toolbox::zoom_out(void)
{
	uncheck_all(ui->btn_zoom_out);

}

void Toolbox::draw(void)
{
	uncheck_all(ui->btn_draw);
	Image* img = Image::instance();

	if ( ui->btn_draw->isChecked() )
		img->set_actual_action(DRAW);
	else
		img->set_actual_action(NONE);
}

void Toolbox::scale(void)
{
	uncheck_all(ui->btn_scale);
	Image* img = Image::instance();

	if ( ui->btn_scale->isChecked() )
		img->set_actual_action(SCALE);
	else
		img->set_actual_action(NONE);
}

void Toolbox::invert_image(void)
{
	uncheck_all();
	Image* img = Image::instance();
	img->set_actual_action(NONE);
	img->invert_image();
	main_window->refresh_image();
}

void Toolbox::pick(void)
{
	uncheck_all(ui->btn_pick);

	Image* img = Image::instance();

	if ( ui->btn_pick->isChecked() )
		img->set_actual_action(PICK);
	else
		img->set_actual_action(NONE);	
}

void Toolbox::invert_colors(void)
{
	uncheck_all();

	Image* img = Image::instance();
	img->set_actual_action(NONE);
	img->invert_colors();
	main_window->refresh_image();
}

void Toolbox::sature(void)
{
	uncheck_all();

}

void Toolbox::filter_1(void)
{
	uncheck_all();
	Image* img = Image::instance();

	img->blur_filter(); // Needs to be changed by dynamically lambda
	main_window->refresh_image();
}

void Toolbox::filter_2(void)
{
	uncheck_all();
	Image* img = Image::instance();

	img->bilateral_filter(); // Needs to be changed by dynamically lambda
	main_window->refresh_image();
}

void Toolbox::filter_3(void)
{
	uncheck_all();
	Image* img = Image::instance();

	img->laplacian_filter(); // Needs to be changed by dynamically lambda
	main_window->refresh_image();
}

void Toolbox::filter_menu(void)
{
	QMenu menu(this);
	menu.addAction("Hello");
	// ... list of all actual filters
	menu.exec(QCursor::pos());
}

void Toolbox::faces(void)
{
	uncheck_all();

	Image* img = Image::instance();
	img->faces();
	main_window->refresh_image();
}

void Toolbox::points(void)
{
	uncheck_all();

}

void Toolbox::recognize(void)
{
	uncheck_all();

}
