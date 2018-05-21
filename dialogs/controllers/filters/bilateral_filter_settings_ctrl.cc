#include "bilateral_filter_settings_ctrl.hpp"

BilateralFilterSettingsCtrl::BilateralFilterSettingsCtrl(QWidget* parent) : QDialog(parent), ui(new Ui::BilateralFilterDialog)
{
    ui->setupUi(this);

    QSettings settings(_settings_file, QSettings::NativeFormat);

    ui->spb_diameter_value->setValue( settings.value("bilateral_filter_settings_diameter", 15).toInt() );
    ui->spb_sigma_color_value->setValue( settings.value("bilateral_filter_settings_sigma_color", 80.0).toDouble() );
    ui->spb_sigma_space_value->setValue( settings.value("bilateral_filter_settings_sigma_space", 80.0).toDouble() );

    connect(ui->spb_diameter_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &BilateralFilterSettingsCtrl::change_diameter);
    connect(ui->spb_sigma_color_value, SELECT<double>::OVERLOAD_OF(&QDoubleSpinBox::valueChanged), this, &BilateralFilterSettingsCtrl::change_sigma_color);
    connect(ui->spb_sigma_space_value, SELECT<double>::OVERLOAD_OF(&QDoubleSpinBox::valueChanged), this, &BilateralFilterSettingsCtrl::change_sigma_space);
}

void BilateralFilterSettingsCtrl::change_diameter(int diameter)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("bilateral_filter_settings_diameter", diameter);
}

void BilateralFilterSettingsCtrl::change_sigma_color(double sigma_color)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("bilateral_filter_settings_sigma_color", sigma_color);
}

void BilateralFilterSettingsCtrl::change_sigma_space(double sigma_space)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("bilateral_filter_settings_sigma_space", sigma_space);
}

BilateralFilterSettingsCtrl::~BilateralFilterSettingsCtrl()
{
    delete ui;
}


