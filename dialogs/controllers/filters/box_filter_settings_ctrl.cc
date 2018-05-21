#include "box_filter_settings_ctrl.hpp"


BoxFilterSettingsCtrl::BoxFilterSettingsCtrl(QWidget * parent) : QDialog(parent), ui(new Ui::BoxFilterDialog)
{
    ui->setupUi(this);
    QSettings settings(_settings_file, QSettings::NativeFormat);
    ui->cmb_depth_value->addItem("0", 0);
    ui->cmb_depth_value->addItem("5", 5);
    ui->cmb_depth_value->addItem("10", 10);
    ui->cmb_depth_value->addItem("50", 50);

    int index = ui->cmb_depth_value->findData( settings.value("box_filter_settings_depth", 0).toInt() );

    ui->cmb_depth_value->setCurrentIndex( (index != -1)? index : 0 );
    ui->spb_k_size_value->setValue( settings.value("box_filter_settings_k_size", 3).toInt() );
    ui->chb_normalized_value->setChecked( settings.value("box_filter_settings_normalized", true).toBool() );

    connect(ui->cmb_depth_value, SELECT<int>::OVERLOAD_OF(&QComboBox::currentIndexChanged), this, &BoxFilterSettingsCtrl::change_depth);
    connect(ui->spb_k_size_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &BoxFilterSettingsCtrl::change_k_size);
    connect(ui->chb_normalized_value, &QCheckBox::stateChanged, this, &BoxFilterSettingsCtrl::change_normalized);
}

void BoxFilterSettingsCtrl::change_depth(int index)
{
    int depth = ui->cmb_depth_value->currentData().toInt();
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("box_filter_settings_depth", depth);
}

void BoxFilterSettingsCtrl::change_k_size(int k_size)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("box_filter_settings_k_size", k_size);
}

void BoxFilterSettingsCtrl::change_normalized(bool normalized)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("box_filter_settings_normalized", normalized);
}

BoxFilterSettingsCtrl::~BoxFilterSettingsCtrl()
{
    delete ui;
}

