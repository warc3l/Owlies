#ifndef _TOOLBOX_HPP
#define _TOOLBOX_HPP

#include "../gui/ui_toolbox.h"
#include "../model/image.hpp"
#include "../controllers/main_window.hpp"
#include "../dialogs/dialog_settings_creator.hpp"

#include <QWidget>
#include <iostream>
#include <map>
#include <utility>
#include <functional>
#include <vector>
#include <algorithm>
#include <QShortcut>
#include <QKeySequence>
#include <QIcon>


class Toolbox : public QWidget
{
 public:
 		explicit Toolbox(QWidget * parent = 0, MainWindow* mw = 0 );
 		~Toolbox();

		// Uncheck all toolbox
		void uncheck_all(QToolButton* btn_non_uncheck = nullptr);

		// Basic
		void crop(void);
		void zoom_in(void);
		void zoom_out(void);

		// Manipulation
		void draw(void);
		void scale(void);
		void invert_image(void);

		// Colors
		void pick(void);
		void invert_colors(void);
		void sature(void);

		// Filters
		void filter_1(void);
		void filter_2(void);
		void filter_3(void);
		void filter_menu(void);

		// Recognition
		void faces(void);
		void thin(void);
		void recognize(void);

		// Slots
		void loaded_image(void);

		// Implemented filters.
		// @ key: identificator
		// @ pair<path_icon, lambda_function_image>
		std::map<std::string, std::pair<QString, std::function<void()>>> filters;
		std::vector<std::string> common_filters;

 private:
		const QString _settings_file = "settings.ini";
 		Ui::Toolbox* ui;
		MainWindow* main_window;
};


#endif
