#ifndef TOOLBOX_HPP

#include "../gui/ui_toolbox.h"
#include "../model/image.hpp"
#include "../controllers/main_window.hpp"

#include <QWidget>
#include <iostream>
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

		// Recognition
		void faces(void);
		void points(void);
		void recognize(void);

 private:
 		Ui::Toolbox* ui;
		MainWindow* main_window;
};


#endif
