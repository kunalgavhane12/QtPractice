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

private slots:
    void on_btn_Logout_clicked();

private:
    Ui::ProfilePage *ui;
};

#endif // PROFILEPAGE_H
