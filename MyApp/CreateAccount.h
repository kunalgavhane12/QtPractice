#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include "loginpage.h"

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAccount(QWidget *parent = nullptr);
    ~CreateAccount();

private slots:
    void on_pushButton_CreateAccount_clicked();

private:
    Ui::CreateAccount *ui;
    QString username, password, name, email, deposit;

};

#endif // CREATEACCOUNT_H
