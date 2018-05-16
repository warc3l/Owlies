#include <QDialog>
#include <string>
#include <iostream>


#include "controllers/draw_settings_ctrl.hpp"
#include "controllers/faces_settings_ctrl.hpp"

class DialogSettingsCreator
{
 public:
    DialogSettingsCreator() {}
    QDialog* create(std::string type);
};

