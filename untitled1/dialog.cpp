#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QMessageBox::information(this,"Information","This is info");

}


void Dialog::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply= QMessageBox::question(this,"Question","This is Ques?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
        QApplication::quit();
    else
        QMessageBox::information(this,"INFO","Press NO");
}


void Dialog::on_pushButton_3_clicked()
{
    QMessageBox::critical(this,"Critical","This is critical info");

}


void Dialog::on_pushButton_4_clicked()
{
    QMessageBox::warning(this,"Warning","This is Warning info");

}

