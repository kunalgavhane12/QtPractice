#include "ProfilePage.h"
#include "ui_profilepage.h"
#include "loginpage.h"

ProfilePage::ProfilePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfilePage)
{
    ui->setupUi(this);

    ui->label_Username->setText(LoginPage::username);
    ui->lineEdit_FromAccountNo->setValidator(new QIntValidator(0, 1000000000, ui->lineEdit_FromAccountNo));
    ui->lineEdit_ToAccountNo->setValidator(new QIntValidator(0, 1000000000, ui->lineEdit_ToAccountNo));
    ui->lineEdit_Transfer->setValidator(new QDoubleValidator(0, 1000000000,2, ui->lineEdit_Transfer));
    setUp();

    LoginPage conn;

    if (conn.USE_File)
    {
        QFile file;
        file.setFileName("D:/QtPractice/MyApp/user_credential.txt");

        if (file.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&file);

            QStringList headers = {"Account Number", "Name", "Email", "Balance"};
            QStandardItemModel *model = new QStandardItemModel(0, headers.length(), this);
            model->setHorizontalHeaderLabels(headers);

            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList fields = line.split(',');
                fields = fields.mid(0, 4);

                QList<QStandardItem *> items;
                for (const QString &field : fields)
                {
                    items.append(new QStandardItem(field));
                }
                model->appendRow(items);
            }

            file.close();

            ui->tableView->setModel(model);
        }
    }

}

ProfilePage::~ProfilePage()
{
    delete ui;
}

void ProfilePage::setUp()
{
    QStringList headers = {"Account Number", "Name", "Email", "Balance"};
    QStandardItemModel *model = new QStandardItemModel(0, headers.length(), this);
    model->setHorizontalHeaderLabels(headers);
    ui->tableView->setModel(model);

    LoginPage conn;

    if (conn.USE_DB)
    {
        //Detail in TableView tab
        QSqlQueryModel *model = new QSqlQueryModel();

        QSqlQuery* qry = new QSqlQuery(conn.mydb);

        qry->prepare("select accountnumber,name,email,balance from BankAccountDetails where Username ='"+LoginPage::username+"'");
        qry->exec();

        model->setQuery(*qry);

        ui->tableView->setModel(model);

        qDebug() << (model->rowCount());

    }

    //Detail in Account Details tab
    QSqlQuery query(conn.mydb);
    query.prepare("select accountnumber,name,email,balance from BankAccountDetails where Username ='"+LoginPage::username+"'");

    if (query.exec())
    {
        if (query.next())
        {
            accountNumber = query.value(0).toInt();
            name = query.value(1).toString();
            email = query.value(2).toString();
            balance = query.value(3).toString();

            qDebug() << accountNumber << name << email << balance;

            ui->label_AccountNumber->setText("Account Number : " + QString::number(accountNumber));
            ui->label_Name->setText("Name : " + name);
            ui->label_Email->setText("Email : " + email);
            ui->label_Balance->setText("Balance : " + balance);
            //                ui->lineEdit_FromAccountNo->setText(QString::number(accountNumber));
        }
        else
        {
            qDebug() << "No data found for Username: " << LoginPage::username;
        }
    }
    else
    {
        qDebug() << "Error executing query: " << query.lastError().text();
    }

}

void ProfilePage::allclear()
{
    ui->lineEdit_FromAccountNo->clear();
    ui->lineEdit_ToAccountNo->clear();
    ui->lineEdit_Transfer->clear();
}

void ProfilePage::on_btn_Logout_clicked()
{
    hide();
    LoginPage *loginPage = new LoginPage();
    if(loginPage)
    {
        loginPage->show();
    }
}


void ProfilePage::on_pushButton_TransferAmount_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Quick Transfer","Do you Want to Transfer?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No)
    {
        allclear();
        return;
    }

    QString FromAccountNo = ui->lineEdit_FromAccountNo->text();
    QString ToAccountNo = ui->lineEdit_ToAccountNo->text();
    QString Amount = ui->lineEdit_Transfer->text();

    LoginPage conn;
    double sBalance = 0, rBalance = 0;

    if(conn.USE_DB)
    {
        QSqlQuery* qry = new QSqlQuery(conn.mydb);

        if(qry->exec("select * from BankAccountDetails where AccountNumber = '"+FromAccountNo+"'"))
        {
            if(!qry->next())
            {
                QMessageBox::information(this, "Quick Transfer", "Invalid From Account Number");
                return;
            }

            sBalance = qry->value("Balance").toDouble();
            if(sBalance >= Amount.toDouble())
            {
                sBalance -= Amount.toDouble();
                qry->prepare("update BankAccountDetails SET Balance = '"+QString::number(sBalance)+"' where AccountNumber = '"+FromAccountNo+"'");
                qry->exec();

                if(qry->exec("select * from BankAccountDetails where AccountNumber = '"+ToAccountNo+"'"))
                {
                    if(!qry->next())
                    {
                        QMessageBox::information(this, "Quick Transfer", "Invalid To Account Number");
                        return;
                    }

                    rBalance = qry->value("Balance").toDouble();
                    rBalance += Amount.toDouble();
                    qry->prepare("update BankAccountDetails SET Balance = '"+QString::number(rBalance)+"' where AccountNumber = '"+ToAccountNo+"'");
                    qry->exec();

                    QMessageBox::information(this,"Quick Transfer","Transfer Sucess");
                }
                else
                {
                    sBalance += Amount.toDouble();
                    qry->prepare("update BankAccountDetails SET Balance = '"+QString::number(sBalance)+"' where AccountNumber = '"+FromAccountNo+"'");
                    qry->exec();
                }
            }
            else
            {
                QMessageBox::information(this,"Quick Transfer","Insufficient Balance");
                qDebug() << "Insufficient Balance";
                return;
            }
        }
    }

    //    qDebug() <<FromAccountNo << " "<< ToAccountNo <<" "<<Amount;
    setUp();
    allclear();
}

