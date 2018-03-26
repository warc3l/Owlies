#ifndef MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QAction>
#include "../gui/ui_main_window.h"
#include <iostream>
#include <QFileDialog>
#include <QPixmap>
#include <string>


class MainWindow : public QMainWindow
{
 Q_OBJECT

 public:
 		explicit MainWindow(QWidget * parent = 0);
 		~MainWindow();

		void open_image(int);
		void save_image(void);

 private:
 		Ui::MainWindow* ui;
};


#endif