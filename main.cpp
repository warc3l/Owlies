#include "controllers/main_window.hpp"
#include "controllers/toolbox.hpp"

#include <QApplication>
#include <QFile>
#include <QResource>

int main(int argc, char *argv[])
{
    QResource::registerResource("resources/resources.rcc");

    QApplication a(argc, argv);
    MainWindow w;
    Toolbox t(0, &w);

    QFile style_file(":/style/owlies_style.css");
    style_file.open(QFile::ReadOnly);
    a.setStyleSheet(style_file.readAll());

    w.show();
    t.show();

    return a.exec();
}
