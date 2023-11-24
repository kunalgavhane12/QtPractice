#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Statlabel = new QLabel(this);
    statProgress = new QProgressBar(this);

    ui->statusbar->addPermanentWidget(Statlabel);
    ui->statusbar->addPermanentWidget(statProgress,1);
    statProgress->setTextVisible(false);
    Statlabel->setText("Hello");
    statProgress->setValue(45);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    ui->statusbar->showMessage("Hello",1000);


}

