#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

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


void MainWindow::on_PushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();


    if(!isValidEmail(username))
    {
        QMessageBox::warning(this, "Login", "Invalid email address");
        return;
    }
    if (!isValidPassword(password))
    {
        QMessageBox::warning(this, "Login", "Password must have at least one digit,"
          " one lowercase and one uppercase letter, one special character, "
             "and be at least 8 characters long");

        return;
    }

    QMessageBox::information(this, "Login", "Login Success");
    hide();
    secDialog = new SecDialog(this);
    secDialog->show();
}

bool MainWindow::isValidEmail(const QString& email)
{
    int atIndex = email.indexOf('@');
    if(atIndex == -1)
        return false;

    if(email.leftRef(atIndex).isEmpty())
        return false;

    QString domainPart = email.mid(atIndex + 1);
    QStringList domainParts = domainPart.split('.');

    if(domainPart.left(5).compare("gmail", Qt::CaseInsensitive) != 0
            && domainPart.left(5).compare("yahoo", Qt::CaseInsensitive) != 0
            && domainPart.left(10).compare("rediffmail", Qt::CaseInsensitive) != 0)
        return false;

    if (domainParts.size() < 2 || domainPart.right(4).compare(".com", Qt::CaseInsensitive) != 0 && domainPart.right(3).compare(".in", Qt::CaseInsensitive) != 0)
        return false;

    return true;
}

bool MainWindow::isValidPassword(const QString& password)
{
    bool Digit = false;
    bool Lowercase = false;
    bool Uppercase = false;
    bool SpecialChar = false;

    for (const QChar& ch : password)
    {
        if (ch.isDigit())
            Digit = true;
        else if (ch.isLower())
            Lowercase = true;
        else if (ch.isUpper())
            Uppercase = true;
        else if (ch.isPunct() || ch.isSymbol())
            SpecialChar = true;
    }

    return (Digit && Lowercase && Uppercase && SpecialChar && password.length() >= 8);
}


void MainWindow::on_pushButton_Reset_clicked()
{
    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
}


void MainWindow::on_pushButton_createaccount_clicked()
{
    hide();
    accountopen = new AccountOpen(this);
    accountopen->show();
}

