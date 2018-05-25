#include "dialog_settings_creator.hpp"


QDialog* DialogSettingsCreator::create(std::string type)
{
    if (type == "draw")
        return new DrawSettingsCtrl();
    else if (type == "sature")
        return new DrawSettingsCtrl();
    else if (type == "faces")
        return new FacesSettingsCtrl();
    else if (type == "thin")
        return new DrawSettingsCtrl();
    else if (type == "recognize")
        return new DrawSettingsCtrl();
    else if (type == "blur")
        return new BlurFilterSettingsCtrl();
    else if (type == "bilateral")
        return new BilateralFilterSettingsCtrl();
    else if (type == "laplacian")
        return new LaplacianFilterSettingsCtrl();
    else if (type == "gaussian")
        return new GaussianFilterSettingsCtrl();
    else if (type == "scharr")
        return new DrawSettingsCtrl();
    else if (type == "box")
        return new BoxFilterSettingsCtrl();
    else if (type == "median")
        return new DrawSettingsCtrl();
    else if (type == "sobel")
        return new DrawSettingsCtrl();
    else if (type == "erode")
        return new ErodeFilterSettingsCtrl();
    else if (type == "dilate")
        return new DilateFilterSettingsCtrl();
    else if (type == "opening")
        return new DrawSettingsCtrl();
    else if (type == "closing")
        return new ClosingFilterSettingsCtrl();
    else    
        return new DrawSettingsCtrl();
}
