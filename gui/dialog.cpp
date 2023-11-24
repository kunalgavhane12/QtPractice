#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    for(int i = 0; i< 9; i++)
    {
        ui->listWidget->addItem(QString::number(i) + "Item");
    }

//    ui->comboBox->addItem("Kunal");
//    ui->comboBox->addItem("Gavhane");

    ui->checkBox->setChecked(true);
    for(int i = 0; i < 9; i++)
    {
        ui->comboBox->addItem(QString::number(i) + " item");
    }
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    //QMessageBox::information(this,"Title here","Hello World");
    if(ui->checkBox->isChecked())
    {
        QMessageBox::information(this,"Dog","You like dogs");
    }
    else
    {
               QMessageBox::information(this,"Dog","You don't like dogs");
    }
}


void Dialog::on_pushButton_2_clicked()
{
    if(ui->radioButton->isChecked())
    {
        QMessageBox::information(this,"Title", ui->radioButton->text());
    }
    if(ui->radioButton_2->isChecked())
    {
          QMessageBox::information(this,"Title", ui->radioButton_2->text());
    }
}


void Dialog::on_pushButton_3_clicked()
{
    QMessageBox::information(this,"Title",ui->comboBox->currentText());
}


void Dialog::on_pushButton_4_clicked()
{
    //ui->listWidget->currentItem()->setText("xyz");
    QListWidgetItem *itm = ui->listWidget->currentItem();
    itm->setText("Doing Well");
    itm->setTextColor(Qt::red);
    itm->setBackgroundColor(Qt::black);
}

