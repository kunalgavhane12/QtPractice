#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include "loginpage.h"
#include "loginlib.h"
#include <QFile>

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAccount(QWidget *parent = nullptr);
    ~CreateAccount();

    void allClear();

    void saveAccountToDatabase(int accountNumber, const QString &name, const QString &email, const QString &deposit, const QString &username, const QString &password);
    void saveAccountNumberToDatabase();
    void loadAccountNumberFromDatabase();


    void saveAccountToFile(int accountNumber, const QString &name, const QString &email, const QString &deposit, const QString &username, const QString &password);
    void saveAccountNumberToFile();
    void loadAccountNumberFromFile();

private slots:
    void on_pushButton_CreateAccount_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::CreateAccount *ui;
    QString username, password, name, email, deposit;
    static int Count;
};

#endif // CREATEACCOUNT_H
