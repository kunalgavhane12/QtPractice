#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

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

    QFile file("D:/qt practice program/MyQFileClass/myfile.txt");//Static Path
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this,"title","File not Open..");
    }

    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;

    file.flush();
    file.close();

}


void MainWindow::on_pushButton_2_clicked()
{
    QString filter = "All File(*.*) ;; Text File (*.*) ;; XML File (*.xml) ";
    QString file_name = QFileDialog::getOpenFileName(this,"Open a File","D://",filter);
    QFile file(file_name);

    //QFile file("D:/qt practice program/MyQFileClass/myfile.txt");//static path

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this,"title","File not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

