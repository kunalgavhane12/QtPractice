#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Number");
    ui->lineEdit_2->setPlaceholderText("Email");
    ui->lineEdit_3->setPlaceholderText("Name");
    ui->lineEdit_4->setPlaceholderText("Double");

    //only Integer numbers
    ui->lineEdit->setValidator(new QIntValidator(0, 1000000000, ui->lineEdit));
    /*
    QValidator *validator = new QIntValidator(0, 1000000000, this);
    ui->lineEdit->setValidator(validator);*/
    //Email id restriction
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                              QRegularExpression::CaseInsensitiveOption);
     ui->lineEdit_2->setValidator(new QRegularExpressionValidator(rx, this));

     //Name restriction
     QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+\\s{1,40}"), this);
     ui->lineEdit_3->setValidator(validator);

     //Double Numbers
      ui->lineEdit_4->setValidator(new QDoubleValidator(0, 1000000000,2, ui->lineEdit_4));



}

MainWindow::~MainWindow()
{
    delete ui;
}

