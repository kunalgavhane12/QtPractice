#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(myFunction()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myFunction()
{
    QDate date = QDate::currentDate();
    QString date_text = date.toString("dd/MM/yyyy");

    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    if((time.second()%2)==0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui->label_date->setText(date_text);
    ui->label_time->setText(time_text);
}

