#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("D:/Fullstacks Edureka/my pic/3.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_UserName->text();
    QString password = ui->lineEdit_password->text();
    if(username == "kunal" && password == "kunal")
    {
        QMessageBox::information(this, "Login", "Username and password is correct");
        dialog =new Dialog(this);
        dialog->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username and password is not correct");
    }
}

