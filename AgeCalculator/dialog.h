#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnCalculate_clicked();
    bool isLeapYear(int year);
    int dayOfMonth(int month, int year);
    void calculateAge(int pd, int pm, int py, int bd, int bm, int by);
    int calculateTotalDays(int by, int py);

private:
    Ui::Dialog *ui;
    int py,pm,pd,by,bm,bd;
    int y,m,d;
    static int cnt;

};
#endif // DIALOG_H
