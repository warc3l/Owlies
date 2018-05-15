#include <QLabel>
#include <QColorDialog>
#include <QSettings>

#include <iostream>
#include <vector>

class ColorLabel : public QLabel
{
 private:
    int _r_color;
    int _g_color;
    int _b_color;

    const QString _settings_file = "settings.ini";

 protected:
    virtual void mouseDoubleClickEvent(QMouseEvent* event);

 public:
    ColorLabel(QWidget* parent);
    std::vector<int> rgb();
};


