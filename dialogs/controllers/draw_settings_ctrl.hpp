#include <QDialog>
#include <QWidget>
#include <QSettings>
#include "../gui/ui_draw_settings.h"


template<typename... Args> struct SELECT 
{ 
    template<typename C, typename R> 
    static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
};

class DrawSettingsCtrl : public QDialog
{
 public:
    explicit DrawSettingsCtrl(QWidget * parent = 0);
    ~DrawSettingsCtrl();

    void change_size(int);

 private:
    const QString _settings_file = "settings.ini";
    Ui::DrawDialog* ui;

};


