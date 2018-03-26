#include "controllers/main_window.hpp"
#include "controllers/toolbox.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Toolbox t;

    w.show();
    t.show();

    return a.exec();
}
