#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secdialog.h"
#include "accountopen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PushButton_Login_clicked();

    void on_pushButton_Reset_clicked();

    bool isValidEmail(const QString& email);

    bool isValidPassword(const QString& password);

    void on_pushButton_createaccount_clicked();

private:
    Ui::MainWindow *ui;
    SecDialog *secDialog;
    AccountOpen *accountopen;
};
#endif // MAINWINDOW_H
