#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Bottle");
    setUp();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUp()
{
    QStringList headers = {"Name", "Surname", "Contact"};
    QStandardItemModel *model = new QStandardItemModel(3, headers.length(), this);
    model->setHorizontalHeaderLabels(headers);
    ui->tableView->setModel(model);

    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            QString labelText = QString("Label");
            QStandardItem *item = new QStandardItem(labelText);
            model->setItem(row, column, item);
        }
    }

    int columnWidth = 400 / headers.length();
    int rowHeight = 250 / 3;
    for(int column = 0; column < headers.length(); column++)
    {
        ui->tableView->setColumnWidth(column, columnWidth);
    }
    for(int row = 0; row < 3; row++)
    {
        ui->tableView->setRowHeight(row, rowHeight);
    }
}



void MainWindow::on_pushButton_clicked()
{
    //    //model approch
    //    Sec seWd;
    //    seWd.setModal(true);
    //    seWd.exec();

    //model less approvch
    secWind = new Sec(this);
    secWind->show();
}

