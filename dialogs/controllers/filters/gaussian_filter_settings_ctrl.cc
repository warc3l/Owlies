
#include "gaussian_filter_settings_ctrl.hpp"

GaussianFilterSettingsCtrl::GaussianFilterSettingsCtrl(QWidget* parent) : QDialog(parent), ui(new Ui::GaussianFilterDialog)
{
    ui->setupUi(this);

    QSettings settings(_settings_file, QSettings::NativeFormat);

    ui->spb_k_size_value->setValue( settings.value("gaussian_filter_settings_k_size", 3).toInt() );
    ui->spb_sigma_x_value->setValue( settings.value("gaussian_filter_settings_sigma_x", 1).toDouble() );
    ui->spb_sigma_y_value->setValue( settings.value("gaussian_filter_settings_sigma_y", 0).toDouble() );

    connect(ui->spb_k_size_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &GaussianFilterSettingsCtrl::change_k_size);
    connect(ui->spb_sigma_x_value,  SELECT<double>::OVERLOAD_OF(&QDoubleSpinBox::valueChanged), this, &GaussianFilterSettingsCtrl::change_sigma_x);
    connect(ui->spb_sigma_y_value, SELECT<double>::OVERLOAD_OF(&QDoubleSpinBox::valueChanged), this, &GaussianFilterSettingsCtrl::change_sigma_y);
}

void GaussianFilterSettingsCtrl::change_k_size(int k_size)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("gaussian_filter_settings_k_size", k_size);
}

void GaussianFilterSettingsCtrl::change_sigma_x(double sigma_x)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("gaussian_filter_settings_sigma_x", sigma_x);
}

void GaussianFilterSettingsCtrl::change_sigma_y(double sigma_y)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("gaussian_filter_settings_sigma_y", sigma_y);
}

GaussianFilterSettingsCtrl::~GaussianFilterSettingsCtrl()
{
    delete ui;
}

