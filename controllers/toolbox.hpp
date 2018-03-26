#ifndef TOOLBOX_HPP

#include <QWidget>
#include "../gui/ui_toolbox.h"

class Toolbox : public QWidget
{
 public:
 		explicit Toolbox(QWidget * parent = 0);
 		~Toolbox();
 private:
 		Ui::Toolbox* ui;
};


#endif
