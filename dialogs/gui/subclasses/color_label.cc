#include "color_label.hpp"


ColorLabel::ColorLabel(QWidget* parent)
{
    setAutoFillBackground(true);

    QSettings settings(_settings_file, QSettings::NativeFormat);
    QColor init_color(  settings.value("draw_settings_r_color",0).toInt(),
                        settings.value("draw_settings_g_color",0).toInt(),
                        settings.value("draw_settings_b_color",0).toInt());

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

        settings.setValue("draw_settings_r_color", _r_color);
        settings.setValue("draw_settings_g_color", _g_color);
        settings.setValue("draw_settings_b_color", _b_color);
    }
}

std::vector<int> ColorLabel::rgb()
{
    std::vector<int> v_rgb {_r_color, _g_color, _b_color};
    return v_rgb;
}


