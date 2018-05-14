#include "dialog_settings_creator.hpp"
#include "controllers/draw_settings_ctrl.hpp"


QDialog* DialogSettingsCreator::create(std::string type)
{
    if (type == "draw")
    {
        std::cout << "Creating draw settings" << std::endl;
        return new DrawSettingsCtrl();
    }
    else if (type == "")
    {

    }
    else if (type == "")
    {

    }
    else
    {

    }
}


