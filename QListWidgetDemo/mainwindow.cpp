#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QListWidgetItem *item = new QListWidgetItem(QIcon(":/rec/img/new.jpeg"),"New");
    ui->listWidget->addItem(item);
    QListWidgetItem *item1 = new QListWidgetItem(QIcon(":/rec/img/open.png"),"Open");
    ui->listWidget->addItem(item1);
    QListWidgetItem *item2 = new QListWidgetItem(QIcon(":/rec/img/close.png"),"Close");
    ui->listWidget->addItem(item2);
//    ui->listWidget->addItem("Feb");
//    ui->listWidget->addItem("March");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    QMessageBox::information(this,"Title",ui->listWidget->currentItem()->text());
    ui->listWidget->currentItem()->setBackgroundColor(Qt::red);
    ui->listWidget->currentItem()->setForeground(Qt::white);
}

