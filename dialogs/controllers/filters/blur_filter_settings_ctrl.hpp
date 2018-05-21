#ifndef _BLUR_FILTER_SETTINGS_CTRL_HPP
#define _BLUR_FILTER_SETTINGS_CTRL_HPP

#include <QDialog>
#include <QWidget>
#include <QSettings>
#include "../../gui/filters/ui_blur_filter_settings.h"


class BlurFilterSettingsCtrl : public QDialog
{
 public:
    explicit BlurFilterSettingsCtrl(QWidget * parent = 0);
    ~BlurFilterSettingsCtrl();

    void change_k_size(int k_size);

 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    const QString _settings_file = "settings.ini";
    Ui::BlurFilterDialog* ui;

};

#endif



