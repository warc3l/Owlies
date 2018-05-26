#ifndef _MEDIAN_FILTER_SETTINGS_CTRL_HPP
#define _MEDIAN_FILTER_SETTINGS_CTRL_HPP

#include <QDialog>
#include <QWidget>
#include <QSettings>

#include "../../gui/filters/ui_median_filter_settings.h"

class MedianFilterSettingsCtrl : public QDialog
{
 public:
    explicit MedianFilterSettingsCtrl(QWidget* parent = 0);
    ~MedianFilterSettingsCtrl();

    void change_k_size();

 private:
    int old_k_size = 3;
    const QString _settings_file = "settings.ini";

    Ui::MedianFilterDialog* ui;

};

#endif

