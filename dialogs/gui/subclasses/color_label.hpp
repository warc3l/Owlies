#ifndef _COLOR_LABEL_HPP
#define _COLOR_LABEL_HPP

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

    QString _settings_value;

    const QString _settings_file = "settings.ini";

 protected:
    virtual void mouseDoubleClickEvent(QMouseEvent* event);

 public:
    ColorLabel(QWidget* parent);
    std::vector<int> rgb();
    void set_settings_value_color(QString);
};

#endif
