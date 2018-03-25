#ifndef TOOLBOX_HPP

#include <QWidget>

namespace Ui {
	class Toolbox;
}

class Toolbox : public QWidget
{
 private:
 		explicit Toolbox(QWidget * parent = 0);
 		~Toolbox();
 public:
 		Ui::Toolbox* ui;
};


#endif
