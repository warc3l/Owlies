#ifndef _OPENING_FILTER_SETTINGS_CTRL_HPP
#define _OPENING_FILTER_SETTINGS_CTRL_HPP


#include <QDialog>
#include <QWidget>
#include <QSettings>

#include "../../gui/filters/ui_opening_filter_settings.h"

class OpeningFilterSettingsCtrl : public QDialog
{
 public:
    explicit OpeningFilterSettingsCtrl(QWidget * parent = 0);
    ~OpeningFilterSettingsCtrl();

    void change_shape(int);
    void change_k_size(int);

 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    const QString _settings_file = "settings.ini";
    Ui::OpeningFilterDialog* ui;
};

#endif


