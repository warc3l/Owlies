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

		void undo_action(void);

 private:
 		Ui::MainWindow* ui;
};


#endif
