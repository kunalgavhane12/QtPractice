#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

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
    //void about
    //QMessageBox::about(this, "My Title", "This is my custom message");
    //void aboutQt
    //QMessageBox::aboutQt(this, "My Title");

    //StandardButton critical
    //QMessageBox::critical(this, "My Title", "This is my custom message");
    //StandardButton information
    //StandardButton question
    //StandarfButton warning
    QMessageBox::StandardButton reply = QMessageBox::question(this, "My Title",
                                "This is my custom message",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else
    {
        qDebug() << "No is clicked";
    }
}

