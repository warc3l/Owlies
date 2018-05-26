#include "median_filter_settings_ctrl.hpp"


MedianFilterSettingsCtrl::MedianFilterSettingsCtrl(QWidget * parent) : QDialog(parent), ui(new Ui::MedianFilterDialog)
{
    ui->setupUi(this);
    QSettings settings(_settings_file, QSettings::NativeFormat);

    ui->spb_k_size_value->setValue( settings.value("median_filter_settings_k_size", 3).toInt() );

    connect(ui->spb_k_size_value, &QSpinBox::editingFinished, this, &MedianFilterSettingsCtrl::change_k_size);
}

void MedianFilterSettingsCtrl::change_k_size()
{
    int k_size = ui->spb_k_size_value->value();
    if ((k_size % 3) == 0)
    {
        old_k_size = k_size;
        QSettings settings(_settings_file, QSettings::NativeFormat);
        settings.setValue("median_filter_settings_k_size", k_size);
    }
    else
        ui->spb_k_size_value->setValue(old_k_size);
}

MedianFilterSettingsCtrl::~MedianFilterSettingsCtrl()
{
    delete ui;
}

