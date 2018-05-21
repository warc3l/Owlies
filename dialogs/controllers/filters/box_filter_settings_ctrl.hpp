#ifndef _BOX_FILTER_SETTINGS_CTRL_HPP
#define _BOX_FILTER_SETTINGS_CTRL_HPP

#include <QDialog>
#include <QWidget>
#include <QSettings>
#include "../../gui/filters/ui_box_filter_settings.h"

class BoxFilterSettingsCtrl : public QDialog
{
 public:
    explicit BoxFilterSettingsCtrl(QWidget * parent = 0);
    ~BoxFilterSettingsCtrl();

    void change_depth(int);
    void change_k_size(int);
    void change_normalized(bool);

 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    const QString _settings_file = "settings.ini";

    Ui::BoxFilterDialog* ui;
};



#endif



