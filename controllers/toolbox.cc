#include "toolbox.hpp"


Toolbox::Toolbox(QWidget* parent, MainWindow* w) : QWidget(parent), ui(new Ui::Toolbox)
{
	ui->setupUi(this);
	setWindowFlags(Qt::Tool);
	setEnabled(false); // No image loaded

	main_window = w;

	connect(main_window, &MainWindow::newImageLoaded, this, &Toolbox::loaded_image);

	// Basic
	ui->btn_crop->setCheckable(true);

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
	connect(ui->btn_thin, &QToolButton::clicked, this, &Toolbox::thin);
	connect(ui->btn_recognize, &QToolButton::clicked, this, &Toolbox::recognize);

	// Filters
	Image* img = Image::instance();

	filters["blur"] = std::make_pair(QString(":/icons/ic_blur_on_black_24px.svg"), [=]() { img->blur_filter(); });
	filters["bilateral"] = std::make_pair(QString(":/icons/ic_call_split_black_24px.svg"), [=]() { img->bilateral_filter(); });
	filters["laplacian"] = std::make_pair(QString(":/icons/ic_swap_calls_black_24px"), [=]() { img->laplacian_filter(); });
	filters["gaussian"] = std::make_pair(QString(":/icons/ic_blur_circular_black_24px.svg"), [=]() { img->gaussian_filter(); });
	filters["scharr"] = std::make_pair(QString(":/icons/ic_polymer_black_24px.svg"), [=]() { img->scharr_filter(); });
	filters["box"] = std::make_pair(QString(":/icons/ic_inbox_icon_24px.svg"), [=]() { img->box_filter(); });
	filters["median"] = std::make_pair(QString(":/icons/ic_select_all_black_24px.svg"), [=]() { img->median_filter(); });
	filters["sobel"] = std::make_pair(QString(":/icons/ic_access_time_black_24px.svg"), [=]() { img->sobel_filter(); });

	filters["erode"] = std::make_pair(QString(":/icons/ic_dashboard_black_24px.svg"), [=]() { img->erode(); });
	filters["dilate"] = std::make_pair(QString(":/icons/ic_surround_sound_black_24px.svg"), [=]() { img->dilate(); });
	filters["opening"] = std::make_pair(QString(":/icons/ic_lock_open_black_24px.svg"), [=]() { img->opening(); });
	filters["closing"] = std::make_pair(QString(":/icons/ic_lock_black_24px.svg"), [=]() { img->closing(); });

	common_filters.push_back("blur");
	common_filters.push_back("bilateral");
	common_filters.push_back("laplacian");

	ui->btn_filter_1->setToolTip("Blur");
	ui->btn_filter_2->setToolTip("Bilateral");
	ui->btn_filter_3->setToolTip("Laplacian");
}

Toolbox::~Toolbox()
{
	delete ui;
}

void Toolbox::loaded_image(void)
{
	setEnabled(true);
}

void Toolbox::uncheck_all(QToolButton* btn_non_uncheck)
{
	bool actual_state = false;
	main_window->delete_statusbar_widgets(); // Delete all additional childs, except base...

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
	ui->btn_filter_3->setChecked(false);
	ui->btn_faces->setChecked(false);
	ui->btn_thin->setChecked(false);
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
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{
		uncheck_all();
		std::cout << "Control button is pressed" << std::endl;
	}
	else
	{
		Image* img = Image::instance();
		img->set_actual_action(NONE);
		img->zoom_in();
		main_window->refresh_image();		
	}
}

void Toolbox::zoom_out(void)
{
	uncheck_all(ui->btn_zoom_out);
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{
		uncheck_all();
		std::cout << "Control button is pressed" << std::endl;
	}
	else
	{
		Image* img = Image::instance();
		img->set_actual_action(NONE);
		img->zoom_out();
		main_window->refresh_image();		
	}
}

void Toolbox::draw(void)
{
	uncheck_all(ui->btn_draw);
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{
		uncheck_all();
		DialogSettingsCreator dlg_settings_creator;
		QDialog* dlg = dlg_settings_creator.create("draw");
		dlg->show();
	}
	else
	{
		Image* img = Image::instance();

		if ( ui->btn_draw->isChecked() )
		{
			img->set_actual_action(DRAW);
			QSettings settings(_settings_file, QSettings::NativeFormat);

			QLabel* color_label = new QLabel();
			color_label->setMinimumSize(QSize(15,15));
			color_label->setAutoFillBackground(true);
			QColor init_color(  settings.value("draw_settings_r_color",0).toInt(),
								settings.value("draw_settings_g_color",0).toInt(),
								settings.value("draw_settings_b_color",0).toInt());
			QPalette palette;
			palette.setBrush(QPalette::Window, init_color);
			color_label->setPalette(palette);

			main_window->add_statusbar_widget(color_label);
		}
		else
			img->set_actual_action(NONE);
	}
}

void Toolbox::scale(void)
{
	uncheck_all(ui->btn_scale);
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{
		uncheck_all();

	}
	else
	{	
		Image* img = Image::instance();

		if ( ui->btn_scale->isChecked() )
			img->set_actual_action(SCALE);
		else
			img->set_actual_action(NONE);
	}
}

void Toolbox::invert_image(void)
{
	uncheck_all();
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{

	}
	else
	{	
		Image* img = Image::instance();
		img->set_actual_action(NONE);
		img->invert_image();
		main_window->refresh_image();
	}
}

void Toolbox::pick(void)
{
	uncheck_all(ui->btn_pick);
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{
		uncheck_all();
	}
	else
	{
		Image* img = Image::instance();
		if ( ui->btn_pick->isChecked() )
			img->set_actual_action(PICK);
		else
			img->set_actual_action(NONE);	
	}
}

void Toolbox::invert_colors(void)
{
	uncheck_all();
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{

	}
	else
	{
		Image* img = Image::instance();
		img->set_actual_action(NONE);
		img->invert_colors();
		main_window->refresh_image();
	}
}

void Toolbox::sature(void)
{
	uncheck_all();
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{
		DialogSettingsCreator dlg_settings_creator;
		QDialog* dlg = dlg_settings_creator.create("sature");
		dlg->show();
	}
	else
	{
		Image* img = Image::instance();
		img->set_actual_action(NONE);
		img->sature();
		main_window->refresh_image();
	}
}

void Toolbox::filter_1(void)
{
	uncheck_all();
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{
		DialogSettingsCreator dlg_settings_creator;
		QDialog* dlg = dlg_settings_creator.create(common_filters[0]);
		dlg->show();
	}
	else
	{
		Image* img = Image::instance();
		img->set_actual_action(NONE);
		filters[common_filters[0]].second();
		main_window->refresh_image();
	}
}

void Toolbox::filter_2(void)
{
	uncheck_all();
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{
		DialogSettingsCreator dlg_settings_creator;
		QDialog* dlg = dlg_settings_creator.create(common_filters[1]);
		dlg->show();
	} 
	else
	{
		Image* img = Image::instance();
		img->set_actual_action(NONE);
		filters[common_filters[1]].second();
		main_window->refresh_image();
	}
}

void Toolbox::filter_3(void)
{
	uncheck_all();
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{
		DialogSettingsCreator dlg_settings_creator;
		QDialog* dlg = dlg_settings_creator.create(common_filters[2]);
		dlg->show();
	}
	else
	{
		Image* img = Image::instance();
		img->set_actual_action(NONE);
		filters[common_filters[2]].second();
		main_window->refresh_image();
	}
}

void Toolbox::filter_menu(void)
{
	QMenu menu(this);
	Image* img = Image::instance();
	img->set_actual_action(NONE);


	// Fill menu with filters
	for (const auto imap: filters)
	{
		std::string identifier = imap.first;
		if ( !std::any_of(common_filters.begin(), common_filters.end(), [=](std::string x) { return identifier == x; } ))
		{
			identifier[0] = ::toupper(identifier[0]);
			menu.addAction(QString::fromStdString(identifier));
		}
	}

	QAction* action = menu.exec(QCursor::pos());
	if (action != 0)
	{
		std::string data = action->text().toUtf8().constData();
		std::transform(data.begin(), data.end(), data.begin(), ::tolower);

		// Call that filter
		filters[data].second();
		main_window->refresh_image();

		// Reorder common filters
		common_filters[2] = common_filters[1];
		common_filters[1] = common_filters[0];
		common_filters[0] = data;

		// Change the icons
		ui->btn_filter_1->setIcon(QIcon(filters[common_filters[0]].first));
		ui->btn_filter_2->setIcon(QIcon(filters[common_filters[1]].first));
		ui->btn_filter_3->setIcon(QIcon(filters[common_filters[2]].first));

		// Set new Tooltips
		std::string first = common_filters[0], second = common_filters[1], third = common_filters[2];
		first[0] = ::toupper(first[0]); second[0] = ::toupper(second[0]); third[0] = ::toupper(third[0]);

		ui->btn_filter_1->setToolTip(QString::fromStdString(first));
		ui->btn_filter_2->setToolTip(QString::fromStdString(second));
		ui->btn_filter_3->setToolTip(QString::fromStdString(third));
	}
}

void Toolbox::faces(void)
{
	uncheck_all();
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{
		DialogSettingsCreator dlg_settings_creator;
		QDialog* dlg = dlg_settings_creator.create("faces");
		dlg->show();
	}
	else
	{
		Image* img = Image::instance();
		img->set_actual_action(NONE);
		img->faces();
		main_window->refresh_image();
	}
}

void Toolbox::thin(void)
{
	uncheck_all();
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{
		DialogSettingsCreator dlg_settings_creator;
		QDialog* dlg = dlg_settings_creator.create("thin");
		dlg->show();
	}
	else
	{
		Image* img = Image::instance();
		img->set_actual_action(NONE);
		img->thin();
		main_window->refresh_image();
	}

}

void Toolbox::recognize(void)
{
	uncheck_all();
	if ( QGuiApplication::keyboardModifiers() & Qt::ControlModifier )
	{
	}
	else
	{
		Image* img = Image::instance();
		img->set_actual_action(NONE);

		DialogSettingsCreator dlg_settings_creator;
		QDialog* dlg = dlg_settings_creator.create("recognize");
		int ret = dlg->exec();
		
		main_window->refresh_image();
	}
}
