#ifndef _ERODE_FILTER_SETTINGS_CTRL_HPP
#define _ERODE_FILTER_SETTINGS_CTRL_HPP

#include <QWidget>
#include <QDialog>
#include <QSettings>

#include "../../gui/filters/ui_erode_filter_settings.h"


class ErodeFilterSettingsCtrl : public QDialog
{
 public:
    explicit ErodeFilterSettingsCtrl(QWidget * parent = 0);
    ~ErodeFilterSettingsCtrl();

    void change_shape(int);
    void change_k_size(int);

 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    const QString _settings_file = "settings.ini";
    Ui::ErodeFilterDialog* ui;
};


#endif


