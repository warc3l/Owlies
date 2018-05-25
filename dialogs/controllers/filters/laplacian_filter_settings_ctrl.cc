#include "laplacian_filter_settings_ctrl.hpp"


LaplacianFilterSettingsCtrl::LaplacianFilterSettingsCtrl(QWidget * parent) : QDialog(parent), ui(new Ui::LaplacianFilterDialog)
{
    ui->setupUi(this);
    QSettings settings(_settings_file, QSettings::NativeFormat);

    ui->spb_k_size_value->setValue( settings.value("laplacian_filter_settings_k_size", 3).toInt() );
    ui->spb_scale_value->setValue( settings.value("laplacian_filter_settings_scale", 1).toInt() );
    ui->spb_delta_value->setValue( settings.value("laplacian_filter_settings_delta", 1).toInt() );

    connect(ui->spb_k_size_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &LaplacianFilterSettingsCtrl::change_k_size);
    connect(ui->spb_scale_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &LaplacianFilterSettingsCtrl::change_scale);
    connect(ui->spb_delta_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &LaplacianFilterSettingsCtrl::change_delta);
}

void LaplacianFilterSettingsCtrl::change_k_size(int k_size)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("laplacian_filter_settings_k_size", k_size);
}

void LaplacianFilterSettingsCtrl::change_scale(int scale)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("laplacian_filter_settings_scale", scale);
}

void LaplacianFilterSettingsCtrl::change_delta(int delta)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("laplacian_filter_settings_delta", delta);
}

LaplacianFilterSettingsCtrl::~LaplacianFilterSettingsCtrl()
{
    delete ui;
}
