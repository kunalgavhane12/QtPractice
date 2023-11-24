#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

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


void Dialog::on_pushButton_clicked()
{
    QMessageBox::information(this,"Title","Hello World!");
}


void Dialog::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Title","Do you like Dogs?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
       QMessageBox::information(this,"title","You Love Dogs");
    }
}


void Dialog::on_pushButton_3_clicked()
{
    QMessageBox::warning(this,"Title","This is Warning");
}


void Dialog::on_pushButton_4_clicked()
{
    QMessageBox::question(this,"Title","My Test here",QMessageBox::YesToAll | QMessageBox::Yes | QMessageBox::NoToAll | QMessageBox::No);
}

