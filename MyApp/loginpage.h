#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include "loginlib.h"
#include "ProfilePage.h"
#include "CreateAccount.h"
#include <QtSql>
#include <QMessageBox>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
    bool USE_DB = true;
    bool USE_File = false;

    QSqlDatabase mydb;
    QFile file;

    void connectionClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connectionOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("D:/QtPractice/MyApp/user_credential.db");

        if(!mydb.open())
        {
            qDebug() << "Failed to open the database";
            return false;
        }
        else
        {
            qDebug() << "Connected..";
            loadAccountNumberFromDatabase();
            return true;
        }
    }

    void fileClose()
    {
        file.flush();
        file.close();
    }

    bool fileOpen()
    {
        file.setFileName("D:/QtPractice/MyApp/user_credential.txt");
        if(!file.open(QFile::Append | QFile::Text))
        {
            QMessageBox::information(this, "Login", "file not open");
            return false;
        }
        else
        {
            qDebug() << "Connected..";
            return true;
        }
    }



private slots:

    void on_btnLogin_clicked();

    void on_btnReset_clicked();

    void on_btnSignUp_clicked();

    void loadAccountNumberFromDatabase();

    void saveAccountNumberToDatabase();

    void saveAccountNumberToFile();

    void loadAccountNumberFromFile();


private:
    Ui::LoginPage *ui;
    ProfilePage *profilePage;
    static int Count;
    QString username, password;

};
#endif // LOGINPAGE_H
