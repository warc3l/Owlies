#include "color_label.hpp"


ColorLabel::ColorLabel(QWidget* parent)
{
    setAutoFillBackground(true);

    QColor init_color(0, 0, 0);
    QPalette palette;
    palette.setBrush(QPalette::Window, init_color);
    this->setPalette(palette);
}

void ColorLabel::set_settings_value_color(QString value)
{
    _settings_value = value;

    QSettings settings (_settings_file, QSettings::NativeFormat);
    QColor init_color(  settings.value(value + "_r_color",0).toInt(),
                        settings.value(value + "_g_color",0).toInt(),
                        settings.value(value + "_b_color",0).toInt());
    QPalette palette;
    palette.setBrush(QPalette::Window, init_color);
    this->setPalette(palette);
}

void ColorLabel::mouseDoubleClickEvent(QMouseEvent* event)
{
    QColorDialog* dlg_color = new QColorDialog(this);
    QColor color = dlg_color->getColor();
    QSettings settings(_settings_file, QSettings::NativeFormat);

    if (color.isValid())
    {
        QPalette palette(color);
        palette.setBrush(QPalette::Window, color);
        this->setPalette(palette);

        _r_color = color.red();
        _g_color = color.green();
        _b_color = color.blue();

        if (_settings_value != "")
        {
            settings.setValue(_settings_value + "_r_color", _r_color);
            settings.setValue(_settings_value + "_g_color", _g_color);
            settings.setValue(_settings_value + "_b_color", _b_color);
        }
    }
}

std::vector<int> ColorLabel::rgb()
{
    std::vector<int> v_rgb {_r_color, _g_color, _b_color};
    return v_rgb;
}


