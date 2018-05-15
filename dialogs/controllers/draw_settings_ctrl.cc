#include "draw_settings_ctrl.hpp"


DrawSettingsCtrl::DrawSettingsCtrl(QWidget * parent) : QDialog(parent), ui(new Ui::DrawDialog)
{
    ui->setupUi(this);

    QSettings settings(_settings_file, QSettings::NativeFormat);

    ui->spb_size_value->setValue(settings.value("draw_settings_size", 10).toInt());

    connect(ui->spb_size_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &DrawSettingsCtrl::change_size);
}

void DrawSettingsCtrl::change_size(int size)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("draw_settings_size", size);
}

DrawSettingsCtrl::~DrawSettingsCtrl()
{
    delete ui;
}


