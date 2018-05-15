#include "draw_settings_ctrl.hpp"


DrawSettingsCtrl::DrawSettingsCtrl(QWidget * parent) : QDialog(parent), ui(new Ui::DrawDialog)
{
    ui->setupUi(this);

    QSettings settings(_settings_file, QSettings::NativeFormat);

    ui->spb_size_value->setValue(settings.value("draw_settings_size", 10).toInt());

    ui->rdp_circle->setChecked(true);

    connect(ui->spb_size_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &DrawSettingsCtrl::change_size);
    connect(ui->rdp_circle, SELECT<bool>::OVERLOAD_OF(&QRadioButton::toggled), this, &DrawSettingsCtrl::change_form);
    connect(ui->rdp_triangle, SELECT<bool>::OVERLOAD_OF(&QRadioButton::toggled), this, &DrawSettingsCtrl::change_form);

    if (settings.value("draw_settings_form", 0).toInt() == CIRCLE)
        ui->rdp_circle->setChecked(true);
    else if (settings.value("draw_settings_form").toInt() == TRIANGLE)
        ui->rdp_triangle->setChecked(true);
}

void DrawSettingsCtrl::change_size(int size)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("draw_settings_size", size);
}

void DrawSettingsCtrl::change_form(bool toggled)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    if (ui->rdp_circle->isChecked())
        settings.setValue("draw_settings_form", CIRCLE);
    else if (ui->rdp_triangle->isChecked())
        settings.setValue("draw_settings_form", TRIANGLE);
}

DrawSettingsCtrl::~DrawSettingsCtrl()
{
    delete ui;
}


