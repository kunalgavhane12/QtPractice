#include "dialog.h"
#include "ui_dialog.h"
#include "newwindows.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_btnWithParent_clicked()
{
    NewWindows *secW = new NewWindows(this);
    secW->show();
}


void Dialog::on_btnWithoutParent_clicked()
{
    NewWindows *secW = new NewWindows(nullptr);
    secW->show();

//    NewWindows secWin;
//    secWin.setModal(true);
//    secWin.exec();
}

