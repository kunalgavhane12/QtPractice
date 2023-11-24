#include "mainwindow.h"
#include "ui_mainwindow.h"

double result = 0.0;
int operatorBtn = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText(QString::number(result));

    setWindowTitle("Calculator");
    QPushButton *numberButton[10];
    for(int i=0; i<10; i++)
    {
        QString btnName = "pushButton" + QString::number(i);
        numberButton[i] = MainWindow::findChild<QPushButton*> (btnName);
        connect(numberButton[i], SIGNAL(clicked()), this, SLOT(numberPress()));
    }

    connect(ui->Addition, SIGNAL(clicked()), this, SLOT(operatorButtonPress()));
    connect(ui->Substract, SIGNAL(clicked()), this, SLOT(operatorButtonPress()));
    connect(ui->Multiply, SIGNAL(clicked()), this, SLOT(operatorButtonPress()));
    connect(ui->Modules, SIGNAL(clicked()), this, SLOT(operatorButtonPress()));
    connect(ui->Divide, SIGNAL(clicked()), this, SLOT(operatorButtonPress()));

    connect(ui->Equals, SIGNAL(clicked()), this, SLOT(on_Equalto_clicked()));
    connect(ui->Clear, SIGNAL(clicked()), this, SLOT(on_Clear_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberPress()
{
    QPushButton *button =(QPushButton*) sender();
    QString btnVal = button->text();
    QString DisplayVal = ui->lineEdit->text();

    QString newVal = DisplayVal + btnVal;
    ui->lineEdit->setText(newVal);
}

void MainWindow::operatorButtonPress()
{
    QString displayVal = ui->lineEdit->text();
    result = displayVal.toDouble();
    QPushButton *button = (QPushButton *) sender();
    QString btnVal = button->text();

    if(0 == QString::compare(btnVal, "+", Qt::CaseInsensitive))
    {
        operatorBtn = 1;
    }
    else if(0 == QString::compare(btnVal, "-", Qt::CaseInsensitive))
    {
        operatorBtn = 2;
    }
    else if(0 == QString::compare(btnVal, "/", Qt::CaseInsensitive))
    {
        operatorBtn = 3;
    }
    else if(0 == QString::compare(btnVal, "*", Qt::CaseInsensitive))
    {
        operatorBtn = 4;
    }
//    else  if(0 == QString::compare(btnVal, "(", Qt::CaseInsensitive))
//    {
//        operatorBtn = 5;
//    }
//    else  if(0 == QString::compare(btnVal, ")", Qt::CaseInsensitive))
//    {
//        operatorBtn = 6;
//    }
    else
    {
        operatorBtn = 5;
    }
//    ui->lineEdit->setText(displayVal+btnVal);
    //ui->lineEdit->setText("");
}


void MainWindow::on_Clear_clicked()
{
    ui->lineEdit->setText("0");
}


void MainWindow::on_Delete_clicked()
{
    QString str = ui->lineEdit->text();
    ui->lineEdit->setText("");
    for(int i=0; i<str.length()-1; i++)
    {
        ui->lineEdit->setText(ui->lineEdit->text()+str[i]);
    }
}


void MainWindow::on_Equalto_clicked()
{
    double ans = 0.0;
    QString displayVal = ui->lineEdit->text();
    double val = displayVal.toDouble();

    switch (operatorBtn)
    {
        case 1:
            ans = result + val;
        break;
        case 2:
            ans = result - val;
        break;
        case 3:
            ans = result / val;
        break;
        case 4:
            ans = result * val;
        break;
        case 5:
            val = 100;
            ans = result / val;
        break;
    default:
        ans = 0.0;
    }
    ui->lineEdit->setText(QString::number(ans));
}


void MainWindow::on_Point_clicked()
{
    QPushButton *button =(QPushButton*) sender();
    QString btnVal = button->text();
    QString DisplayVal = ui->lineEdit->text();

    ui->lineEdit->setText(DisplayVal+btnVal);
}

