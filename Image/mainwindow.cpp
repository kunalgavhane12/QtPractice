#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setUp();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUp()
{
    QPixmap pix("D:/QtPractice/Image/info-symbol.png");
    ui->label->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"title", "You click button");
}

