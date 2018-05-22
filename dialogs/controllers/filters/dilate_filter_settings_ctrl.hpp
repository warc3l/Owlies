#ifndef _DILATE_FILTER_SETTINGS_CTRL_HPP
#define _DILATE_FILTER_SETTINGS_CTRL_HPP

#include <QWidget>
#include <QDialog>
#include <QSettings>

#include "../../gui/filters/ui_dilate_filter_settings.h"

class DilateFilterSettingsCtrl : public QDialog
{
 public:
    explicit DilateFilterSettingsCtrl(QWidget * parent = 0);
    ~DilateFilterSettingsCtrl();

    void change_shape(int);
    void change_k_size(int);

 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    const QString _settings_file = "settings.ini";
    Ui::DilateFilterDialog* ui;
};


#endif


