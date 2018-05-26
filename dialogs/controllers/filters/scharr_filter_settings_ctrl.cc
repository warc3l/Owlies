#include "scharr_filter_settings_ctrl.hpp"

ScharrFilterSettingsCtrl::ScharrFilterSettingsCtrl(QWidget* parent) : QDialog(parent), ui(new Ui::ScharrFilterDialog)
{
    ui->setupUi(this);
    QSettings settings(_settings_file, QSettings::NativeFormat);

    ui->spb_scale_value->setValue( settings.value("scharr_filter_settings_scale", 1).toInt() );
    ui->spb_delta_value->setValue( settings.value("scharr_filter_settings_delta", 0).toInt() );
    ui->spb_dx_value->setValue( settings.value("scharr_filter_settings_dx", 0).toInt() );
    ui->spb_dy_value->setValue( settings.value("scharr_filter_settings_dy", 1).toInt() );

    connect(ui->spb_scale_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &ScharrFilterSettingsCtrl::change_scale);
    connect(ui->spb_delta_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &ScharrFilterSettingsCtrl::change_delta);
    connect(ui->spb_dx_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &ScharrFilterSettingsCtrl::change_dx);
    connect(ui->spb_dy_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &ScharrFilterSettingsCtrl::change_dy);
}

void ScharrFilterSettingsCtrl::change_scale(int scale)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("scharr_filter_settings_scale", scale);
}

void ScharrFilterSettingsCtrl::change_delta(int delta)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("scharr_filter_settings_delta", delta);
}

void ScharrFilterSettingsCtrl::change_dx(int dx)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("scharr_filter_settings_dx", dx);
}

void ScharrFilterSettingsCtrl::change_dy(int dy)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("scharr_filter_settings_dy", dy);
}

ScharrFilterSettingsCtrl::~ScharrFilterSettingsCtrl()
{
    delete ui;
}
