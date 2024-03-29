#include "dialog.h"
#include "ui_dialog.h"

int Dialog::cnt = 0;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnCalculate_clicked()
{
    pd = ui->lineEditEndDate->text().toInt();
    pm = ui->lineEditEndMonth->text().toInt();
    py = ui->lineEditEndYear->text().toInt();

    bd = ui->lineEditStartDate->text().toInt();
    bm = ui->lineEditStartMonth->text().toInt();
    by = ui->lineEditStartYear->text().toInt();


    qDebug() <<"Present Date: " << pd << "/" << pm << "/" << py;
    qDebug() <<"Birthday Date: " << bd << "/" << bm << "/" << by;

    calculateAge(pd,pm,py,bd,bm,by);

    int Total_days = calculateTotalDays(by,py);
//    qDebug() << Total_days;

    int birthMonthDay = 0;
    int presentMonthDay = 0;
    if(bm <= 12)
    {
        for(int i=bm; i<=12; i++)
        {
            birthMonthDay += dayOfMonth(i,by);
        }
        if(isLeapYear(by))
            birthMonthDay += 1;
    }
    if(pm <= 12)
    {
        for(int i=pm; i<=12; i++)
        {
            presentMonthDay += dayOfMonth(i,py);
        }
        if(isLeapYear(py))
        {

            presentMonthDay = 366 - presentMonthDay;
        }
        else
        {

            presentMonthDay = 365 - presentMonthDay;
        }
    }

    int result =(birthMonthDay - bd) + (presentMonthDay + pd);

    qDebug() << "Total Days: " << Total_days + result;

}

bool Dialog::isLeapYear(int year)
{
    if(year%400 == 0 || (year%4==0 && year%100 !=0))
        return true;
    return false;
}

int Dialog::dayOfMonth(int month, int year)
{
    if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if(month ==2)
        return isLeapYear(year)? 29 : 28;
    else
        return 31;
}

void Dialog::calculateAge(int pd, int pm, int py, int bd, int bm, int by)
{
    y = py - by;
    if(pm < bm)
    {
        y--;
        m = 12 - (bm - pm);
    }
    else
    {
        m = pm - bm;
    }

    if(pd < bd)
    {
        m--;
        d = dayOfMonth(m,py) - (bd - pd);
    }
    else
    {
        d = pd - bd;
    }
    qDebug() <<"Age: "<< y << " Month: " << m << " Day: " <<d;

    QMessageBox::information(this, "Age Info", "Your age: "+QString::number(y)+"\nMonth: "+QString::number(m)+"\nDay: "+QString::number(d));
}

int Dialog::calculateTotalDays(int by, int py)
{
    cnt = 0;
    for(int i = by + 1; i<py; i++)
    {
        if(!isLeapYear(i))
            cnt += 365;
        else
            cnt += 366;
    }
//    qDebug() <<"Count: " <<cnt;
    return cnt;
}

