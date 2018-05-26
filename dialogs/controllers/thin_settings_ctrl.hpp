#ifndef _THIN_SETTINGS_CTRL_HPP
#define _THIN_SETTINGS_CTRL_HPP

#include <QDialog>
#include <QSettings>
#include <QWidget>

#include "../gui/ui_thin_settings.h"

class ThinSettingsCtrl : public QDialog
{
 public:
    explicit ThinSettingsCtrl(QWidget* parent=0);
    ~ThinSettingsCtrl();

    // Pre-Process
    void change_shape(int);
    void change_k_size(int);
    void change_pre_threshold_max_value(double);
    void change_pre_threshold_thresh(double);    

    // In-Process
    void change_max_intents(int);
    void change_branch_points(bool);
    void change_branch_points_color(int);

    // Post-Process
    void change_post_threshold_max_value(double);
    void change_post_threshold_thresh(double); 

 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    const QString _settings_file = "settings.ini";
    Ui::ThinDialog* ui; 
};

#endif
