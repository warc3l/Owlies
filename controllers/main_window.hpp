#ifndef MAIN_WINDOW_HPP

#include <QMainWindow>
#include "../gui/ui_main_window.h"

class MainWindow : public QMainWindow
{
 public:
 		explicit MainWindow(QWidget * parent = 0);
 		~MainWindow();
 private:
 		Ui::MainWindow* ui;
};


#endif
