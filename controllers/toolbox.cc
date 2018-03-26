#include "toolbox.hpp"


Toolbox::Toolbox(QWidget* parent) : QWidget(parent), ui(new Ui::Toolbox)
{
	ui->setupUi(this);

	/* Create all the necessary connections */
}

Toolbox::~Toolbox()
{
	delete ui;
}

