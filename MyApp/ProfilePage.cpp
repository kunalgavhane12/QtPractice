#include "ProfilePage.h"
#include "ui_profilepage.h"
#include "loginpage.h"

ProfilePage::ProfilePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfilePage)
{
    ui->setupUi(this);

    ui->label_Username->setText(LoginPage::username);
    setUp();

}

ProfilePage::~ProfilePage()
{
    delete ui;
}

void ProfilePage::setUp()
{
    LoginPage conn;

    QStringList headers = {"Account Number", "Name", "Email", "Balance"};
    QStandardItemModel *model = new QStandardItemModel(0, headers.length(), this);
    model->setHorizontalHeaderLabels(headers);

    if(conn.USE_DB)
    {
        QSqlQueryModel *model = new QSqlQueryModel();

        QSqlQuery* qry = new QSqlQuery(conn.mydb);

        qry->prepare("select accountnumber,name,email,balance from BankAccountDetails where Username ='"+LoginPage::username+"'");
        qry->exec();

        model->setQuery(*qry);

        ui->tableView->setModel(model);

        qDebug() << (model->rowCount());
    }

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

    ui->tableView->setModel(model);
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

