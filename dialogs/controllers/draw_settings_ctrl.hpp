#include <QDialog>
#include <QWidget>
#include "../gui/ui_draw_settings.h"

class DrawSettingsCtrl : public QDialog
{
 public:
    explicit DrawSettingsCtrl(QWidget * parent = 0);
    ~DrawSettingsCtrl();

 private:
    Ui::DrawDialog* ui;    
};


