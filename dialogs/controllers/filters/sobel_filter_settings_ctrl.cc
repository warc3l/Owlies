#include "sobel_filter_settings_ctrl.hpp"

SobelFilterSettingsCtrl::SobelFilterSettingsCtrl(QWidget* parent) : QDialog(parent), ui(new Ui::SobelFilterDialog)
{
    ui->setupUi(this);
    QSettings settings(_settings_file, QSettings::NativeFormat);


    ui->spb_scale_value->setValue( settings.value("sobel_filter_settings_scale", 1).toInt() );
    ui->spb_k_size_value->setValue( settings.value("sobel_filter_settings_k_size", 3).toInt() );
    ui->spb_delta_value->setValue( settings.value("sobel_filter_settings_delta", 0).toInt() );
    ui->spb_dx_value->setValue( settings.value("sobel_filter_settings_dx", 0).toInt() );
    ui->spb_dy_value->setValue( settings.value("sobel_filter_settings_dy", 1).toInt() );

    connect(ui->spb_k_size_value, &QSpinBox::editingFinished, this, &SobelFilterSettingsCtrl::change_k_size);
    connect(ui->spb_scale_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &SobelFilterSettingsCtrl::change_scale);
    connect(ui->spb_delta_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &SobelFilterSettingsCtrl::change_delta);
    connect(ui->spb_dx_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &SobelFilterSettingsCtrl::change_dx);
    connect(ui->spb_dy_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &SobelFilterSettingsCtrl::change_dy);
}

void SobelFilterSettingsCtrl::change_k_size()
{
    int k_size = ui->spb_k_size_value->value();
    if ((k_size % 3) == 0)
    {
        old_k_size = k_size;
        QSettings settings(_settings_file, QSettings::NativeFormat);
        settings.setValue("sobel_filter_settings_k_size", k_size);
    }
    else
        ui->spb_k_size_value->setValue(old_k_size);
}

void SobelFilterSettingsCtrl::change_scale(int scale)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("sobel_filter_settings_scale", scale);
}

void SobelFilterSettingsCtrl::change_delta(int delta)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("sobel_filter_settings_delta", delta);
}

void SobelFilterSettingsCtrl::change_dx(int dx)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("sobel_filter_settings_dx", dx);
}

void SobelFilterSettingsCtrl::change_dy(int dy)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("sobel_filter_settings_dy", dy);
}

SobelFilterSettingsCtrl::~SobelFilterSettingsCtrl()
{
    delete ui;
}
