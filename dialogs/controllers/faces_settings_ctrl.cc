#include "faces_settings_ctrl.hpp"


FacesSettingsCtrl::FacesSettingsCtrl(QWidget* parent) : QDialog(parent), ui(new Ui::FacesDialog)
{
    ui->setupUi(this);

    QSettings settings(_settings_file, QSettings::NativeFormat);

    ui->spb_size_value->setValue(settings.value("faces_settings_size", 1).toInt());
    ui->spb_neighbours_value->setValue(settings.value("faces_settings_neighbours", 3).toInt());

    connect(ui->spb_scale_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &FacesSettingsCtrl::change_scale);
    connect(ui->spb_neighbours_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &FacesSettingsCtrl::change_min_neighbours);
}

void FacesSettingsCtrl::change_scale(int new_size)
{

}

void FacesSettingsCtrl::change_min_neighbours(int new_neighbours)
{

}

