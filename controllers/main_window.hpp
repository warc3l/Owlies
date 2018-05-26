#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QAction>
#include "../gui/ui_main_window.h"
#include <iostream>
#include <QFileDialog>
#include <QPixmap>
#include <QLayout>
#include <QShortcut>
#include <string>


class MainWindow : public QMainWindow
{
 Q_OBJECT

 public:
 		explicit MainWindow(QWidget * parent = 0);
 		~MainWindow();

		void open_image(int);
		void save_image(void);
		void refresh_image(void);

		void add_statusbar_widget(QWidget* wdg=nullptr);
		void delete_statusbar_widgets(void);

		void undo_action(void);

 private:
 		Ui::MainWindow* ui;
};


#endif
