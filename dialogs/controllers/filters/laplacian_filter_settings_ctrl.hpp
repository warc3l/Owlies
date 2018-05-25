#ifndef _LAPLACIAN_FILTER_SETTINGS_CTRL
#define _LAPLACIAN_FILTER_SETTINGS_CTRL

#include <QDialog>
#include <QWidget>
#include <QSettings>

#include "../../gui/filters/ui_laplacian_filter_settings.h"

class LaplacianFilterSettingsCtrl : public QDialog
{
 public:
    LaplacianFilterSettingsCtrl(QWidget * parent = 0);
    ~LaplacianFilterSettingsCtrl();

    void change_k_size(int);
    void change_scale(int);
    void change_delta(int);

 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    const QString _settings_file = "settings.ini";
    Ui::LaplacianFilterDialog* ui;
};

#endif


