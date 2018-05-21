#include "closing_filter_settings_ctrl.hpp"

ClosingFilterSettingsCtrl::ClosingFilterSettingsCtrl(QWidget* parent) : QDialog(parent), ui(new Ui::ClosingFilterDialog)
{
    ui->setupUi(this);
    QSettings settings(_settings_file, QSettings::NativeFormat);

    ui->cmb_shape_value->addItem("MORPH RECT");
    ui->cmb_shape_value->addItem("MORPH CROSS");
    ui->cmb_shape_value->addItem("MORPH ELLIPSE");

    ui->cmb_shape_value->setCurrentIndex( settings.value("closing_filter_settings_shape", 0).toInt() );
    ui->spb_k_size_value->setValue( settings.value("closing_filter_settings_k_size", 3).toInt() );

    connect(ui->cmb_shape_value, SELECT<int>::OVERLOAD_OF(&QComboBox::currentIndexChanged), this, &ClosingFilterSettingsCtrl::change_shape);
    connect(ui->spb_k_size_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &ClosingFilterSettingsCtrl::change_k_size);
}

void ClosingFilterSettingsCtrl::change_shape(int shape_index)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("closing_filter_settings_shape", shape_index);
}

void ClosingFilterSettingsCtrl::change_k_size(int k_size)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("closing_filter_settings_k_size", k_size);
}

ClosingFilterSettingsCtrl::~ClosingFilterSettingsCtrl()
{
    delete ui;
}


