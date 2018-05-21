#ifndef _BILATERAL_FILTER_SETTINGS_CTRL
#define _BILATERAL_FILTER_SETTINGS_CTRL

#include <QDialog>
#include <QWidget>
#include <QSettings>

#include "../../gui/filters/ui_bilateral_filter_settings.h"

class BilateralFilterSettingsCtrl : public QDialog
{
 public:
    explicit BilateralFilterSettingsCtrl(QWidget * parent = 0);
    ~BilateralFilterSettingsCtrl();

    void change_diameter(int);
    void change_sigma_color(double);
    void change_sigma_space(double);

 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };
    
    const QString _settings_file = "settings.ini";

    Ui::BilateralFilterDialog* ui;
};

#endif





