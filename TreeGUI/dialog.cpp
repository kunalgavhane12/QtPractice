#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(2);
    AddRoot("1 Hello","World");
    AddRoot("2 Hello","World");
    AddRoot("3 Hello","World");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::AddRoot(QString name, QString Description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0,name);
    itm->setText(1,Description);
    ui->treeWidget->addTopLevelItem(itm);
    AddChild(itm,"One","Hello");
    AddChild(itm,"Two","World");
}

void Dialog::AddChild(QTreeWidgetItem *parent,QString name, QString Description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,name);
    itm->setText(1,Description);
    parent->addChild(itm);

}

