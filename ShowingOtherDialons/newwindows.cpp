#include "newwindows.h"
#include "ui_newwindows.h"

NewWindows::NewWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewWindows)
{
    ui->setupUi(this);
}

NewWindows::~NewWindows()
{
    delete ui;
}
