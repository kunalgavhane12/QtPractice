#include "loginpage.h"
#include "ui_loginpage.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

int LoginPage::Count = 0;

LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    ui->lineEdit_Username->setPlaceholderText("Username");
    ui->lineEdit_Password->setPlaceholderText("Password");

    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                          QRegularExpression::CaseInsensitiveOption);
    ui->lineEdit_Username->setValidator(new QRegularExpressionValidator(rx, this));
    ui->lineEdit_Password->setValidator(new QRegularExpressionValidator(rx, this));

    if(USE_DB)
    {
        if(!connectionOpen())
        {
            ui->label_Status->setText("Failed to open database");
        }
        else
        {
            ui->label_Status->setText("Connected USE_DB...");
        }

    }

    if(USE_File)
    {
        if(!fileOpen())
        {
            ui->label_Status->setText("Failed to open database");
        }
        else
        {
            ui->label_Status->setText("Connected USE_FILE...");
        }

    }

}

LoginPage::~LoginPage()
{
    delete ui;
}


void LoginPage::on_btnLogin_clicked()
{
    LoginLib Check;

    username = ui->lineEdit_Username->text();
    password = ui->lineEdit_Password->text();

    if(username.isEmpty() || password.isEmpty())
    {
        QMessageBox::information(this, "Login", "Please fill in all fields");
        return;
    }

    if(!Check.isValidEmail(username))
    {
        QMessageBox::information(this, "Login", "Invalid Username");
        return;
    }

    if(!Check.isValidPassword(password))
    {
        QMessageBox::warning(this, "Login", "Password must have at least one digit,"
                                            " one lowercase, one uppercase, one special character and has to be at least of 8 characters");
        ui->lineEdit_Password->clear();
        return;
    }


    hide();
    profilePage = new ProfilePage(this);
    profilePage->show();
}


void LoginPage::on_btnReset_clicked()
{
    ui->lineEdit_Username->clear();
    ui->lineEdit_Password->clear();
}

void LoginPage::on_btnSignUp_clicked()
{
    hide();
    CreateAccount *createAccount = new CreateAccount(this);
    createAccount->show();
}

void LoginPage::loadAccountNumberFromDatabase()
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

void LoginPage::saveAccountNumberToDatabase()
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

void LoginPage::saveAccountNumberToFile()
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

void LoginPage::loadAccountNumberFromFile()
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

