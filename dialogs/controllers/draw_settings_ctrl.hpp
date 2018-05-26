#ifndef _DRAW_SETTINGS_CTRL_HPP
#define _DRAW_SETTINGS_CTRL_HPP

#include <QDialog>
#include <QWidget>
#include <QSettings>
#include "../gui/ui_draw_settings.h"


class DrawSettingsCtrl : public QDialog
{
 public:
    explicit DrawSettingsCtrl(QWidget * parent = 0);
    ~DrawSettingsCtrl();

    void change_size(int);
    void change_form(bool);

 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    enum { CIRCLE, TRIANGLE };

    const QString _settings_file = "settings.ini";
    Ui::DrawDialog* ui;
};

#endif
