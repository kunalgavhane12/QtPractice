#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QDialog>
#include "loginapp.h"

namespace Ui {
class ProfilePage;
}

class ProfilePage : public QDialog
{
    Q_OBJECT

public:
    explicit ProfilePage(QWidget *parent = nullptr);
    ~ProfilePage();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_load_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_listView_activated(const QModelIndex &index);

private:
    Ui::ProfilePage *ui;
};

#endif // PROFILEPAGE_H
