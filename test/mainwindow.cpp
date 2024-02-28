#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(QProgressBar,SIGNAL,this,SLOT(on_horizontalSlider_valueChanged()));
        connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
//        connect(ui->horizontalSlider,SIGNAL(setValue(int)),ui->progressBar,SLOT(changeValue));
}

MainWindow::~MainWindow()
{
    delete ui;
}



