#include "CreateAccount.h"
#include "ui_createaccount.h"
#include "loginpage.h"
#include <QDoubleValidator>

int CreateAccount::Count = 0;

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

void CreateAccount::allClear()
{
    ui->lineEdit_name->clear();
    ui->lineEdit_Email->clear();
    ui->lineEdit_deposit->clear();
    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();

}
/*************SQL Function***********************/
void CreateAccount::saveAccountToDatabase(int accountNumber, const QString &name, const QString &email, const QString &deposit, const QString &username, const QString &password)
{
    QSqlQuery qry;

    qry.prepare("insert into BankAccountDetails (AccountNumber, Name, Email, Balance, Username,Password)"
                " values ('"+QString::number(accountNumber)+"','"+name+"', '"+email+"', '"+QString::number(deposit.toDouble())+"', '"+username+"', '"+password+"')");

    if (!qry.exec())
    {
        qDebug() << "Error inserting account into database: " << qry.lastError().text();
    }

    saveAccountNumberToDatabase();

}

void CreateAccount::saveAccountNumberToDatabase()
{
    QSqlQuery qry;

    qry.prepare("update Count_Table set Count='"+QString::number(Count)+"' where Count=Count");

    if (qry.exec())
    {
        qDebug() << "Count Updated in the database.";
    }
    else
    {
        qDebug() << "Error updating 'Count' in the database: " << qry.lastError().text();
    }

}

void CreateAccount::loadAccountNumberFromDatabase()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM Count_Table LIMIT 1"))
    {
        if (query.next())
        {
            Count = query.value(0).toInt();
        }
    }
    else
    {
        qDebug() << "Error loading 'Count' from the databases: " << query.lastError().text();
    }

}

/*************File Function***********************/

void CreateAccount::saveAccountToFile(int accountNumber, const QString &name, const QString &email, const QString &deposit, const QString &username, const QString &password)
{
    LoginPage db;
    QTextStream out(&db.file);
    out << accountNumber << "," << name << "," << email << "," << deposit.toDouble() << "," << username << "," << password << endl;
}

void CreateAccount::saveAccountNumberToFile()
{
    QFile countFile("D:/QtPractice/MyApp/count.txt");

    if (!countFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "File not open";
        return;
    }

    QTextStream out(&countFile);
    out << Count;
    countFile.close();
}

void CreateAccount::loadAccountNumberFromFile()
{
    QFile countFile("D:/QtPractice/MyApp/count.txt");
    if (!countFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "File not open";
        return;
    }

    QTextStream in(&countFile);
    QString line = in.readLine();
    Count = line.toInt();
    countFile.close();

}

void CreateAccount::on_pushButton_CreateAccount_clicked()
{
    LoginLib check;
    LoginPage db;

    name = ui->lineEdit_name->text();
    email = ui->lineEdit_Email->text();
    deposit = ui->lineEdit_deposit->text();
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(name.isEmpty()||email.isEmpty()||deposit.isEmpty()||username.isEmpty()||password.isEmpty())
    {
        QMessageBox::warning(this, "Account Opening", "Please fill in all fields");
        return;
    }

    if(!check.isValidEmail(email))
    {
        QMessageBox::information(this, "Account Opening", "Invalid email");
        ui->lineEdit_Email->clear();
        return;
    }
    if(!check.isValidEmail(username))
    {
        QMessageBox::information(this, "Account Opening", "Invalid Username");
        ui->lineEdit_username->clear();
        return;
    }

    if(!check.isValidPassword(password))
    {
        QMessageBox::warning(this, "Login", "Password must have at least one digit,"
                                            " one lowercase, one uppercase, one special character and has to be at least of 8 characters");
        ui->lineEdit_password->clear();
        return;
    }

    if(username!=email)
    {
        QMessageBox::information(this, "Account Create", "Username and Email must be same");
        return;
    }

    if(db.USE_DB)
    {
        //finding details in database file
        QSqlQuery qry;

        qry.prepare("SELECT name,email FROM BankAccountDetails WHERE Name = '"+name+"' AND Email = '"+email+"'");

        if (qry.exec())
        {
            int count = 0;

            while (qry.next())
            {
                count++;
            }

            if (count >= 1)
            {
                QMessageBox::information(this, "Account Opening", "Account already exists");
                allClear();
                return;
            }

            if (count < 1)
            {
                loadAccountNumberFromDatabase();
                Count++;
                saveAccountToDatabase(Count, name, email, deposit, username, password);
            }
        }
        else
        {
            qDebug() << "Error loading databases: " << qry.lastError().text();
        }
    }

    if(db.USE_File)
    {
        int count = 0;
        QFile file;
        file.setFileName("D:/QtPractice/MyApp/user_credential.txt");

        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::information(this, "Account opening", "File not open");
            return;
        }

        QTextStream in(&file);

        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList data = line.split(',');

            if (data.size() >= 6 && data[1] == name && data[2] == email)
            {
                count++;
            }
        }

        if(count < 1)
        {
            loadAccountNumberFromFile();
            Count++;
            saveAccountToFile(Count, name, email, deposit, username, password);
            saveAccountNumberToFile();
        }
        else
        {
            QMessageBox::information(this, "Account Opening", "Account already exists");
            allClear();
            return;
        }

    }

    QMessageBox::information(this, "Account Opening", "Account Created");
    allClear();

}


void CreateAccount::on_pushButton_Cancel_clicked()
{
    hide();
    LoginPage *loginPage = new LoginPage();
    if(loginPage)
    {
        loginPage->show();
    }
}

