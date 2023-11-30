#include "secdialog.h"
#include "ui_secdialog.h"

#include <QMessageBox>
#include <QDebug>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::deposit(float amt)
{
    balance +=amt;
}

bool SecDialog::balanceTransfer(float amt)
{
    if(balance < amt)
    {
        return false;
    }
    else
    {
        balance -= amt;
        return true;
    }

}

void SecDialog::balanceEnquiry()
{
    qDebug() <<"Balance: " << balance;
}

void SecDialog::on_pushButton_account_clicked()
{
    qDebug() << "Name: " <<name;
    qDebug() << "Account Number: " <<accNo;
    qDebug() << "Balance: " <<balance;

}


void SecDialog::on_pushButton_transfer_clicked()
{
    float amt = 0.0;//ENTER TRANSFER AMOUNT
   if(balanceTransfer(amt))
   {
       qDebug() << "Transfer Successfully";
   }
   else
   {
       qDebug() << "Insufficient Balance, Transaction Failed";
   }
}


void SecDialog::on_pushButton_balance_clicked()
{
    balanceEnquiry();
}


void SecDialog::on_pushButton_Logout_clicked()
{
    exit(0);
}

