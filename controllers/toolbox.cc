#include "toolbox.hpp"


Toolbox::Toolbox(QWidget* parent) : QWidget(parent), ui(new Ui::Toolbox)
{
	ui->setupUi(this);
	setWindowFlags(Qt::Tool);

	/* Create all the necessary connections */
	ui->toolButton_2->setIcon(QIcon(":/icons/ic_done_black_24px.svg"));
	
}


Toolbox::~Toolbox()
{
	delete ui;
}

