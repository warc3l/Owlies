#include "thin_settings_ctrl.hpp"

ThinSettingsCtrl::ThinSettingsCtrl(QWidget* parent) : QDialog(parent), ui(new Ui::ThinDialog)
{
    ui->setupUi(this);
    QSettings settings(_settings_file, QSettings::NativeFormat);

    // Pre-Process
    ui->cmb_shape_value->addItem("MORPH RECT");
    ui->cmb_shape_value->addItem("MORPH CROSS");
    ui->cmb_shape_value->addItem("MORPH ELLIPSE");

    ui->cmb_shape_value->setCurrentIndex(settings.value("thin_settings_shape", 1).toInt()); // per default, MORPH CROSS
    ui->spb_k_size_value->setValue(settings.value("thin_settings_k_size", 5).toInt());
    ui->spb_pre_threshold_thresh_value->setValue(settings.value("thin_settings_pre_threshold_thresh", 0.5).toDouble());
    ui->spb_pre_threshold_max_value_value->setValue(settings.value("thin_settings_pre_threshold_max_value", 255).toDouble());

    // In-Process
    ui->spb_max_intents_value->setValue( settings.value("thin_settings_max_intents", 100).toInt() );
    ui->chb_branch_points_value->setChecked( settings.value("thin_settings_detect_branch_points", false).toBool() );
    ui->lbl_branch_points_color_value->set_settings_value_color("thin_settings");

    // Post-Process
    ui->spb_post_threshold_thresh_value->setValue( settings.value("thin_settings_post_threshold_thresh", 0.5).toDouble() );
    ui->spb_post_threshold_max_value_value->setValue( settings.value("thin_settings_post_threshold_max_value", 10).toDouble() );

    // Pre-process
    connect(ui->cmb_shape_value, SELECT<int>::OVERLOAD_OF(&QComboBox::currentIndexChanged), this, &ThinSettingsCtrl::change_shape);
    connect(ui->spb_k_size_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &ThinSettingsCtrl::change_k_size);
    connect(ui->spb_pre_threshold_thresh_value, SELECT<double>::OVERLOAD_OF(&QDoubleSpinBox::valueChanged), this, &ThinSettingsCtrl::change_pre_threshold_thresh);
    connect(ui->spb_pre_threshold_max_value_value, SELECT<double>::OVERLOAD_OF(&QDoubleSpinBox::valueChanged), this, &ThinSettingsCtrl::change_pre_threshold_max_value);

    // In-process
    connect(ui->spb_max_intents_value, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), this, &ThinSettingsCtrl::change_max_intents);
    connect(ui->chb_branch_points_value, &QCheckBox::stateChanged, this, &ThinSettingsCtrl::change_branch_points);

    // Post-process
    connect(ui->spb_post_threshold_thresh_value, SELECT<double>::OVERLOAD_OF(&QDoubleSpinBox::valueChanged), this, &ThinSettingsCtrl::change_post_threshold_thresh);
    connect(ui->spb_post_threshold_max_value_value, SELECT<double>::OVERLOAD_OF(&QDoubleSpinBox::valueChanged), this, &ThinSettingsCtrl::change_post_threshold_max_value);
} 

// Pre-Process
void ThinSettingsCtrl::change_shape(int index_shape)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("thin_settings_shape", index_shape);
}

void ThinSettingsCtrl::change_k_size(int k_size)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("thin_settings_k_size", k_size);
}

void ThinSettingsCtrl::change_pre_threshold_thresh(double thresh)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("thin_settings_pre_threshold_thresh", thresh);
}    

void ThinSettingsCtrl::change_pre_threshold_max_value(double max_value)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("thin_settings_pre_threshold_max_value", max_value);
}

// In-Process
void ThinSettingsCtrl::change_max_intents(int max_intents)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("thin_settings_max_intents", max_intents);
}

void ThinSettingsCtrl::change_branch_points(bool detect_branch_points)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("thin_settings_detect_branch_points", detect_branch_points);
}

// Post-Process
void ThinSettingsCtrl::change_post_threshold_thresh(double thresh)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("thin_settings_post_threshold_thresh", thresh);
}

void ThinSettingsCtrl::change_post_threshold_max_value(double max_value)
{
    QSettings settings(_settings_file, QSettings::NativeFormat);
    settings.setValue("thin_settings_post_threshold_max_value", max_value);
}

ThinSettingsCtrl::~ThinSettingsCtrl()
{
    delete ui;
}

