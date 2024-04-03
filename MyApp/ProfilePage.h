#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QDialog>

namespace Ui {
class ProfilePage;
}

class ProfilePage : public QDialog
{
    Q_OBJECT

public:
    explicit ProfilePage(QWidget *parent = nullptr);
    ~ProfilePage();

    void setUp();
    void allclear();

private slots:
    void on_btn_Logout_clicked();

    void on_pushButton_TransferAmount_clicked();

private:
    Ui::ProfilePage *ui;
    int accountNumber;
    QString name, email, balance;
};

#endif // PROFILEPAGE_H
