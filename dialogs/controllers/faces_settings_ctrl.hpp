#ifndef _FACES_SETTINGS_CTRL_HPP
#define _FACES_SETTINGS_CTRL_HPP

#include <QDialog>
#include <QSettings>
#include <QWidget>
#include "../gui/ui_faces_settings.h"


class FacesSettingsCtrl : public QDialog
{
 public:
    explicit FacesSettingsCtrl(QWidget* parent=0);

    void change_scale(int);
    void change_min_neighbours(int);

 private:
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    const QString _settings_file = "settings.ini";
    Ui::FacesDialog* ui;
};

#endif
