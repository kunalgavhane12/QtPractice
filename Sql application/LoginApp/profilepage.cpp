#include "profilepage.h"
#include "ui_profilepage.h"
#include <QMessageBox>

ProfilePage::ProfilePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfilePage)
{
    ui->setupUi(this);


    LoginApp conn;
    if(!conn.connectionOpen())
    {
        ui->label_Profilepage_Status->setText("Failed to open the database");
    }
    else
    {
        ui->label_Profilepage_Status->setText("Connected..");
    }
}

ProfilePage::~ProfilePage()
{
    delete ui;
}

void ProfilePage::on_pushButton_save_clicked()
{
    LoginApp conn;

    QString name, surname,emailid,balance, password;
    name = ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    emailid = ui->lineEdit_email->text();
    balance = ui->lineEdit_balance->text();
    password = ui->lineEdit_password->text();

    if(!conn.connectionOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    conn.connectionOpen();//this function open your connection only one time

    QSqlQuery qry;

    //insert
    qry.prepare("insert into bankaccount (Name,Surname,Email,Balance,Username,Password)"
                " values ('"+name+"','"+surname+"', '"+emailid+"','"+balance+"','"+emailid+"','"+password+"')");

    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Save"),tr("Saved"));

        conn.connectionClose();//close the connection with databse when query exxute successfuly
    }
    else
    {
        QMessageBox::critical(this, tr("Error"),qry.lastError().text());
    }

}


void ProfilePage::on_pushButton_update_clicked()
{
    LoginApp conn;

    QString name, surname, emailid, balance, username, password;
    name = ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    balance = ui->lineEdit_balance->text();
    emailid = ui->lineEdit_email->text();
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(!conn.connectionOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    conn.connectionOpen();//this function open your connection only one time

    QSqlQuery qry;

//update

    qry.prepare("update bankaccount set Name='"+name+"',Surname='"+surname+"',Email='"+emailid+"',Username='"+username+"' where Email='"+emailid+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Edit"),tr("Updated"));

        conn.connectionClose();//close the connection with databse when query excute successfuly
    }
    else
    {
        QMessageBox::critical(this, tr("Error"),qry.lastError().text());
    }

}


void ProfilePage::on_pushButton_delete_clicked()
{
    LoginApp conn;

    QString emailid;
    emailid = ui->lineEdit_email->text();

    if(!conn.connectionOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    conn.connectionOpen();//this function open your connection only one time

    QSqlQuery qry;

//Delete
    qry.prepare("Delete from bankaccount where username='"+emailid+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Delete"),tr("Deleted"));

        conn.connectionClose();//close the connection with databse when query excute successfuly
    }
    else
    {
        QMessageBox::critical(this, tr("Error"),qry.lastError().text());
    }

}

//load .db file data in tableView, listView, comboBox
void ProfilePage::on_pushButton_load_clicked()
{
    LoginApp conn;
    QSqlQueryModel *model = new QSqlQueryModel();

    conn.connectionOpen();

    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from bankaccount");
    qry->exec();

    model->setQuery(*qry);

    ui->listView->setModel(model);

    ui->comboBox->setModel(model);

    ui->tableView->setModel(model);

    conn.connectionClose();
    qDebug() << (model->rowCount());
}

void ProfilePage::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString name = ui->comboBox->currentText();

    LoginApp conn;

    if(!conn.connectionOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    conn.connectionOpen();//this function open your connection only one time

    QSqlQuery qry;

    //show corresponding data using combobox in line Edit
    qry.prepare("select * from bankaccount where username='"+name+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_name->setText(qry.value(0).toString());
            ui->lineEdit_surname->setText(qry.value(1).toString());
            ui->lineEdit_email->setText(qry.value(2).toString());
            ui->lineEdit_balance->setText(qry.value(3).toString());
            ui->lineEdit_username->setText(qry.value(4).toString());
            ui->lineEdit_password->setText(qry.value(5).toString());
        }

        conn.connectionClose();//close the connection with databse when query excute successfuly
    }
    else
    {
        QMessageBox::critical(this, tr("error"),qry.lastError().text());
    }

}


void ProfilePage::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();

    LoginApp conn;

    if(!conn.connectionOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    conn.connectionOpen();//this function open your connection only one time

    QSqlQuery qry;

    //show corresponding data using tableView in line Edit
    qry.prepare("select * from bankaccount where username='"+val+"' or password='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_name->setText(qry.value(0).toString());
            ui->lineEdit_surname->setText(qry.value(1).toString());
            ui->lineEdit_email->setText(qry.value(2).toString());
            ui->lineEdit_balance->setText(qry.value(3).toString());
            ui->lineEdit_username->setText(qry.value(4).toString());
            ui->lineEdit_password->setText(qry.value(5).toString());
        }

        conn.connectionClose();//close the connection with databse when query excute successfuly
    }
    else
    {
        QMessageBox::critical(this, tr("error"),qry.lastError().text());
    }

}


void ProfilePage::on_listView_activated(const QModelIndex &index)
{
    QString val = ui->listView->model()->data(index).toString();

    LoginApp conn;

    if(!conn.connectionOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    conn.connectionOpen();//this function open your connection only one time

    QSqlQuery qry;

    //show corresponding data using tableView in line Edit
    qry.prepare("select * from bankaccount where username='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_name->setText(qry.value(0).toString());
            ui->lineEdit_surname->setText(qry.value(1).toString());
            ui->lineEdit_email->setText(qry.value(2).toString());
            ui->lineEdit_balance->setText(qry.value(3).toString());
            ui->lineEdit_username->setText(qry.value(4).toString());
            ui->lineEdit_password->setText(qry.value(5).toString());
        }

        conn.connectionClose();//close the connection with databse when query excute successfuly
    }
    else
    {
        QMessageBox::critical(this, tr("error"),qry.lastError().text());
    }


}

