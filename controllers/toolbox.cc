#include "toolbox.hpp"
#include "ui_toolbox.h"

Toolbox::Toolbox(QWidget* parent) : QWidget(parent), ui(new Ui::Toolbox)
{
	ui->setupUi(this);

	/* Create all the necessary connections */
}

Toolbox::~Toolbox()
{
	delete ui;
}

