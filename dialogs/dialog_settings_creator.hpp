#include <QDialog>
#include <string>
#include <iostream>


#include "controllers/draw_settings_ctrl.hpp"
#include "controllers/faces_settings_ctrl.hpp"
#include "controllers/thin_settings_ctrl.hpp"

#include "controllers/filters/bilateral_filter_settings_ctrl.hpp"
#include "controllers/filters/blur_filter_settings_ctrl.hpp"
#include "controllers/filters/box_filter_settings_ctrl.hpp"
#include "controllers/filters/closing_filter_settings_ctrl.hpp"
#include "controllers/filters/dilate_filter_settings_ctrl.hpp"
#include "controllers/filters/erode_filter_settings_ctrl.hpp"
#include "controllers/filters/gaussian_filter_settings_ctrl.hpp"
#include "controllers/filters/laplacian_filter_settings_ctrl.hpp"
#include "controllers/filters/median_filter_settings_ctrl.hpp"
#include "controllers/filters/opening_filter_settings_ctrl.hpp"
#include "controllers/filters/scharr_filter_settings_ctrl.hpp"
#include "controllers/filters/sobel_filter_settings_ctrl.hpp"


class DialogSettingsCreator
{
 public:
    DialogSettingsCreator() {}
    QDialog* create(std::string type);
};

