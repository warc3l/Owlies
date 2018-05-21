#include "faces_settings_ctrl.hpp"


FacesSettingsCtrl::FacesSettingsCtrl(QWidget* parent) : QDialog(parent), ui(new Ui::FacesDialog)
{
    ui->setupUi(this);

    QSettings settings(_settings_file, QSettings::NativeFormat);

    ui->spb_scale_value->setValue(settings.value("faces_settings_scale", 1.1).toDouble());
    ui->spb_neighbours_value->setValue(settings.value("faces_settings_neighbours", 3).toInt());
    ui->lbl_color_value->set_settings_value_color("faces_settings");

    connect(ui->spb_scale_value, SELECT<double>::OVERLOAD_OF(&QDoubleSpinBox::valueChanged), this, &FacesSettingsCtrl::change_scale);
    connect(ui->spb_neighbours_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &FacesSettingsCtrl::change_min_neighbours);
}

void FacesSettingsCtrl::change_scale(double size)
{
    QSettings settings(_settings_file, QSettings::NativeFormat); 
    settings.setValue("faces_settings_scale", size);   
}

void FacesSettingsCtrl::change_min_neighbours(int neighbours)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("faces_settings_neighbours", neighbours);
}

