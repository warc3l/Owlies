#include "recognize_dialog_ctrl.hpp"

RecognizeDialogCtrl::RecognizeDialogCtrl(QWidget* parent) : QDialog(parent), ui(new Ui::RecognizeDialog)
{
    ui->setupUi(this);
    ui->cmb_select_option->setCurrentIndex(RECOGNIZE_MODE); // TODO: Add Train Index to ComboBox to able this option.
    ui->stk_train_recognize->setCurrentIndex(RECOGNIZE_MODE);
    ui->rdb_train_local->setChecked(true);

    connect(ui->cmb_select_option, SELECT<int>::OVERLOAD_OF(&QComboBox::currentIndexChanged), this, &RecognizeDialogCtrl::changeModeFunctionality);

    connect(ui->rdb_train_local, &QRadioButton::toggled, this, &RecognizeDialogCtrl::changeTrainMode);
    connect(ui->rdb_train_cloud, &QRadioButton::toggled, this, &RecognizeDialogCtrl::changeTrainMode);

    connect(ui->btn_go_recognize, &QPushButton::clicked, this, &RecognizeDialogCtrl::recognize);
    connect(ui->btn_go_train, &QPushButton::clicked, this, &RecognizeDialogCtrl::train);

    ui->lie_trained_file_value->setEnabled(false);
    ui->lie_trained_file_value->setText("resources/input/MobileNetSSD_deploy.txt");
}

void RecognizeDialogCtrl::recognize()
{
    Image* img = Image::instance();
    img->recognize();
    accept();
}

void RecognizeDialogCtrl::train()
{

}

void RecognizeDialogCtrl::changeModeFunctionality(int index)
{    
    if (index == TRAIN_MODE)
        ui->stk_train_recognize->setCurrentIndex(TRAIN_MODE);
    else if (index == RECOGNIZE_MODE)
        ui->stk_train_recognize->setCurrentIndex(RECOGNIZE_MODE);
}

void RecognizeDialogCtrl::changeTrainMode(void)
{
    QRadioButton* rdb = static_cast<QRadioButton*>(this->sender());
    if ( rdb->isChecked() )
    {
        if ( rdb == ui->rdb_train_local ){
            ui->stk_local_cloud->setCurrentIndex(LOCAL);
        }
        else if ( rdb == ui->rdb_train_cloud ){
            ui->stk_local_cloud->setCurrentIndex(CLOUD);
        }
    }
}




