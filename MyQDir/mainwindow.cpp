#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir dir("D:/qt practice program/MyQDir");
    foreach (QFileInfo var, dir.entryInfoList())
    {
        if(var.isDir())
        ui->listWidget->addItem("Dir: " +var.absoluteFilePath());
        if(var.isFile())
        ui->listWidget->addItem("File: " +var.absoluteFilePath());

    }

//    QDir dir;
//    foreach (QFileInfo var, dir.drives())
//    {
//        ui->comboBox->addItem(var.absoluteFilePath());
//    }

//    QDir dir("D:/qt practice program/MyQDir");
//    if(dir.exists())
//    {
//        QMessageBox::information(this,"title","true");
//    }
//    else
//    {
//        QMessageBox::information(this,"title","false");
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QDir dir("D:/qt practice program/MyQDir/kunal");
    if(dir.exists())
    {
        QMessageBox::information(this,"title","Dir exists");
    }
    else
    {
        dir.mkpath("D:/qt practice program/MyQDir/kunal");
    }
}

