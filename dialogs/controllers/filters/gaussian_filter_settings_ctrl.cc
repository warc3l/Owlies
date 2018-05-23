
#include "gaussian_filter_settings_ctrl.hpp"

GaussianFilterSettingsCtrl()::GaussianFilterSettingsCtrl(QWidget* parent) : QDialog(parent), ui(new GaussianFilterDialog)
{
    ui->setupUi(this);
}

GaussianFilterSettingsCtrl::~GaussianFilterSettingsCtrl()
{
    delete ui;
}

