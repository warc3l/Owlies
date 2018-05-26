#ifndef _SOBEL_FILTER_SETTINGS_CTRL_HPP
#define _SOBEL_FILTER_SETTINGS_CTRL_HPP

#include <QWidget>
#include <QDialog>
#include <QSettings>

#include "../../gui/filters/ui_sobel_filter_settings.h"

class SobelFilterSettingsCtrl : public QDialog
{
 public:
    explicit SobelFilterSettingsCtrl(QWidget * parent=0);
    ~SobelFilterSettingsCtrl();

    void change_k_size(void);
    void change_dx(int);
    void change_dy(int);
    void change_scale(int);
    void change_delta(int);

 private:
    int old_k_size = 3;

    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    const QString _settings_file = "settings.ini";
    Ui::SobelFilterDialog* ui;

};

#endif

