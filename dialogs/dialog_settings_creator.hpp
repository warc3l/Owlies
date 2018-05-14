#include <QDialog>
#include <string>
#include <iostream>

class DialogSettingsCreator
{
 public:
    DialogSettingsCreator() {}
    QDialog* create(std::string type);
};

