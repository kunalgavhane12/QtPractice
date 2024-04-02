#include "loginpage.h"
#include "ui_loginpage.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

QString LoginPage::username=" ";
QString LoginPage::password = "";

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

    if(USE_DB)
    {
        //finding
        QSqlQuery qry;

        qry.prepare("select Username,Password from BankAccountDetails where Username ='"+username+"' and Password='"+password+"'");

        if(qry.exec())
        {
            int count=0;

            while(qry.next())
            {
                count++;
            }
            if(count == 1)
            {
                ui->label_Status->setText("username and password is correct");
                QMessageBox::information(this, "Login", "Login Sucess");

                hide();
                profilePage = new ProfilePage(this);
                profilePage->show();
            }
            if(count < 1)
            {
                ui->label_Status->setText("username and password is not correct");
                QMessageBox::warning(this, "Login", "Invalid username or password");
                ui->lineEdit_Username->clear();
                ui->lineEdit_Password->clear();
            }
        }
    }

    if(USE_File)
    {
        if(authenticate(username,password))
        {
            QMessageBox::information(this, "Login", "Login Success");

            hide();
            profilePage = new ProfilePage(this);
            profilePage->show();
        }
        else
        {
            QMessageBox::warning(this, "Login", "Invalid username or password");
            ui->lineEdit_Username->clear();
            ui->lineEdit_Password->clear();
        }

    }

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

bool LoginPage::authenticate(const QString &, const QString &)
{

    QFile file;
    file.setFileName("D:/QtPractice/MyApp/user_credential.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Login", "File not open");
        return false;
    }


    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList parts = line.split(",");

        if (parts.size() >= 6 && parts[4] == username && parts[5] == password)
        {
            fileClose();
            return true;
        }
    }

    fileClose();
    return false;

}
