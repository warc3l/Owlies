#include "draw_settings_ctrl.hpp"


DrawSettingsCtrl::DrawSettingsCtrl(QWidget * parent) : QDialog(parent), ui(new Ui::DrawDialog)
{
    ui->setupUi(this);    
}

DrawSettingsCtrl::~DrawSettingsCtrl()
{
    delete ui;
}


