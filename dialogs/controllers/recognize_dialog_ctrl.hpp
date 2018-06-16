#ifndef _RECOGNIZE_DIALOG_CTRL
#define _RECOGNIZE_DIALOG_CTRL

#include <QDialog>
#include <iostream>
#include "../../model/image.hpp"
#include "../gui/ui_recognize.h"

class RecognizeDialogCtrl : public QDialog
{
 public:
    explicit RecognizeDialogCtrl(QWidget* parent = 0);
    void changeModeFunctionality(int index);
    void changeTrainMode(void);

    void train(void);
    void recognize(void);

 private:
    enum { TRAIN_MODE = 0, RECOGNIZE_MODE };
    enum { LOCAL = 0, CLOUD };
    template<typename... Args> struct SELECT 
    { 
        template<typename C, typename R> 
        static constexpr auto OVERLOAD_OF( R (C::*type)(Args...) ) -> decltype(type) { return type; }
    };

    Ui::RecognizeDialog* ui;
};

#endif



