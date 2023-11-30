#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DB_Connection = QSqlDatabase::addDatabase("QODBC");
    DB_Connection.setDatabaseName("D:/qt practice program/QtPractice/Sql application/QSQLite_Create_DB_File/QtWithKunal.db");

    if(DB_Connection.open())
    {
        qDebug() << "Opened!";
        DB_Connection.close();
    }
    else
    {
        qDebug() << "Error: " <<DB_Connection.lastError().text();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

