#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //Model approch
//    SecDialog secDialog;
//    secDialog.setModal(true);//only one windows can access
//    secDialog.exec();
    //hide();// hide main windows

    secDialog = new SecDialog(this);
    secDialog->show();//Modelless approch
}

