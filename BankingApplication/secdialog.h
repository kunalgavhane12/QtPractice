#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private slots:
    void on_pushButton_account_clicked();

    void on_pushButton_transfer_clicked();

    void on_pushButton_balance_clicked();

    void on_pushButton_Logout_clicked();

    void deposit(float);
    bool balanceTransfer(float);
    void balanceEnquiry();

private:
    Ui::SecDialog *ui;
    int accNo;
    QString name;
    float balance;
    static int count;

};

#endif // SECDIALOG_H
