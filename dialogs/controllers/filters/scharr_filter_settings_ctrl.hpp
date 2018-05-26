#ifndef _SCHARR_FILTER_SETTINGS_CTRL_HPP
#define _SCHARR_FILTER_SETTINGS_CTRL_HPP

#include <QWidget>
#include <QDialog>
#include <QSettings>

#include "../../gui/filters/ui_scharr_filter_settings.h"

class ScharrFilterSettingsCtrl : public QDialog
{
 public:
    explicit ScharrFilterSettingsCtrl(QWidget * parent=0);
    ~ScharrFilterSettingsCtrl();

    void change_dx(int);
    void change_dy(int);
    void change_scale(int);
    void change_delta(int);

 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    const QString _settings_file = "settings.ini";
    Ui::ScharrFilterDialog* ui;

};

#endif

