#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->comboBox->addItem(QIcon(":/img/new.jpeg"),"New");
//    ui->comboBox->addItem(QIcon(":/img/open.png"),"Feb");
//    ui->comboBox->addItem(QIcon(":/img/close.png"),"March");

    for (int i = 0; i < 10 ; i++ )
    {
        ui->comboBox->addItem(QIcon(":/img/new.jpeg"),QString::number(i) + " name");
    }
    ui->comboBox->insertItem(3,QIcon(":/img/close.png"),"close");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "Title", QString::number(ui->comboBox->currentIndex()));
}

