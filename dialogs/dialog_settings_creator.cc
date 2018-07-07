#include "dialog_settings_creator.hpp"


QDialog* DialogSettingsCreator::create(std::string type)
{
    if (type == "bilateral")
        return new BilateralFilterSettingsCtrl();
    else if (type == "blur")
        return new BlurFilterSettingsCtrl();
    else if (type == "box")
        return new BoxFilterSettingsCtrl();
    else if (type == "closing")
        return new ClosingFilterSettingsCtrl();
    else if (type == "dilate")
        return new DilateFilterSettingsCtrl();
    else if (type == "draw")
        return new DrawSettingsCtrl();
    else if (type == "erode")
        return new ErodeFilterSettingsCtrl();
    else if (type == "faces")
        return new FacesSettingsCtrl();
    else if (type == "gaussian")
        return new GaussianFilterSettingCtrl();
    else if (type == "recognize")
        return new RecognizeDialogCtrl();
    else if (type == "laplacian")
        return new LaplacianFilterSettingsCtrl();
    else if (type == "median")
        return new MedianFilterSettingsCtrl();
    else if (type == "opening")
        return new OpeningFilterSettingsCtrl();
    else if (type == "scharr")
        return new ScharrFilterSettingsCtrl();
    else if (type == "sobel")
        return new SobelFilterSettingsCtrl();
    else if (type == "thin")
        return new ThinSettingsCtrl();
    else    
        return new DrawSettingsCtrl();
}
