#include "accountopen.h"
#include "ui_accountopen.h"

AccountOpen::AccountOpen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountOpen)
{
    ui->setupUi(this);
}

AccountOpen::~AccountOpen()
{
    delete ui;
}
