#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QDateTime>
#include <QLabel>
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUp();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::setUp()
{
    int numRows = 4;
    int numColumns = 3;

    QStringList headers = {"Type", "Widgets", "Date"};
    QStandardItemModel *model = new QStandardItemModel(numRows, numColumns, this);
    model->setHorizontalHeaderLabels(headers);

    QDateTime currentDate = QDateTime::currentDateTime();

    for (int row = 0; row < numRows; row++)
    {

        // Type column
        QString typeText = QString("string %1").arg(row + 1);
        QStandardItem *typeItem = new QStandardItem(typeText);
        model->setItem(row, 0, typeItem);

        // Widgets column
        QPixmap pix("D:/QtPractice/Image/info-symbol.png");
        QPixmap resizedPixmap = pix.scaled(50, 50, Qt::KeepAspectRatio);

        QStandardItem *item = new QStandardItem();
        item->setData(QVariant(resizedPixmap), Qt::DecorationRole);
        model->setItem(row, 1, item);

        // Date column
        QString dateText = currentDate.toString("dd-MM-yyyy");
        QStandardItem *dateItem = new QStandardItem(dateText);
        model->setItem(row, 2, dateItem);
    }

    ui->tableView->setModel(model);

    int columnWidth = 800 / numColumns;
    int rowHeight = 400 / numRows;
    for (int column = 0; column < numColumns; column++)
    {
        ui->tableView->setColumnWidth(column, columnWidth);
    }
    for (int row = 0; row < numRows; row++)
    {
        ui->tableView->setRowHeight(row, rowHeight);
    }
}
