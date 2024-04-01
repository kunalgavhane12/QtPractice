#include "CreateAccount.h"
#include "ui_createaccount.h"
#include "loginpage.h"
#include <QDoubleValidator>

CreateAccount::CreateAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateAccount)
{
    ui->setupUi(this);
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("[A-Za-z\\s]{1,40}"), this);
    ui->lineEdit_name->setValidator(validator);
    ui->lineEdit_deposit->setValidator(new QDoubleValidator(0, 1000000000,2, ui->lineEdit_deposit));
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::on_pushButton_CreateAccount_clicked()
{
    hide();
    name = ui->lineEdit_name->text();
    email = ui->lineEdit_Email->text();
    deposit = ui->lineEdit_deposit->text();
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    LoginPage *loginPage = new LoginPage();
    if(loginPage)
    {
        loginPage->show();
    }

}

