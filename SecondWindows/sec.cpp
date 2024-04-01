#include "sec.h"
#include "ui_sec.h"
#include <QMessageBox>
#include <QDebug>

Sec::Sec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sec)
{
    ui->setupUi(this);
}

Sec::~Sec()
{
    delete ui;
}


void Sec::on_btnInfo_clicked()
{
    qInfo() << "Information";
    QMessageBox::information(this,"INformation","You are mad");

}


void Sec::on_btnQues_clicked()
{
    qDebug() << "Question";
    QMessageBox::question(this,"title","do you like ...?",QMessageBox::Yes|QMessageBox::No);

}


void Sec::on_btnWarning_clicked()
{
    qDebug() << "Warning";
    QMessageBox::warning(this,"Warning", "Its seroius matter");

}


void Sec::on_btnAbout_clicked()
{

    qDebug() << "About";
    QMessageBox::about(this,"ABout","Its about me");
}


void Sec::on_btnCritical_clicked()
{
    qDebug() << "Critical";
    QMessageBox::critical(this,"Critical", "Do you want to continue",QMessageBox::Yes|QMessageBox::No);

}

