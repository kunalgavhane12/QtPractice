#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_Login_clicked();

    bool isValidEmail(const QString&);

    bool isValidPassword(const QString&);

    bool authenticate(const QString& username, const QString&);


private:
    Ui::login *ui;
    QFile file_DB;
};
#endif // LOGIN_H
