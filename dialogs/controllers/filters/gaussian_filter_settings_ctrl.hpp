#ifndef _GAUSSIAN_FILTER_SETTINGS_CTRL
#define _GAUSSIAN_FILTER_SETTINGS_CTRL

#include <QDialog>
#include <QWidget>
#include "../../gui/filters/ui_gaussian_filter_settings.h"

class GaussianFilterSettingsCtrl : public QDialog
{
 public:
    explicit GaussianFilterSettingsCtrl(QWidget * parent = 0);
    ~GaussianFilterSettingsCtrl();

    void change_k_size(int);
    void change_sigma_x();
    void change_sigma_y();


 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    const QString _settings_file = "settings.ini";
    Ui::GaussianFilterDialog* ui;
 };

#endif


