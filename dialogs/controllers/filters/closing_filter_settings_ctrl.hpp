#ifndef _CLOSING_FILTER_SETTINGS_CTRL
#define _CLOSING_FILTER_SETTINGS_CTRL

#include <QDialog>
#include <QWidget>
#include <QSettings>

#include "../../gui/filters/ui_closing_filter_settings.h"


class ClosingFilterSettingsCtrl : public QDialog
{
 public:
    explicit ClosingFilterSettingsCtrl(QWidget* parent=0);
    ~ClosingFilterSettingsCtrl();

    void change_shape(int);
    void change_k_size(int);

 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    const QString _settings_file = "settings.ini";
    Ui::ClosingFilterDialog* ui;
};

#endif

