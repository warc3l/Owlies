#include "blur_filter_settings_ctrl.hpp"

BlurFilterSettingsCtrl::BlurFilterSettingsCtrl(QWidget * parent) : QDialog(parent), ui(new Ui::BlurFilterDialog)
{
    ui->setupUi(this);
    QSettings settings(_settings_file, QSettings::NativeFormat);

    ui->spb_k_size_value->setValue(settings.value("blur_filter_settings_k_size", 3).toInt());

    connect(ui->spb_k_size_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &BlurFilterSettingsCtrl::change_k_size);
}

void BlurFilterSettingsCtrl::change_k_size(int k_size)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("blur_filter_settings_k_size", k_size);
}

BlurFilterSettingsCtrl::~BlurFilterSettingsCtrl()
{
    delete ui;
}


