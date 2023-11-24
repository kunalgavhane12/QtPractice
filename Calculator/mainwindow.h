#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void numberPress();
    void operatorButtonPress();
    void on_Clear_clicked();
    void on_Delete_clicked();
    void on_Equalto_clicked();
    void on_Point_clicked();
};
#endif // MAINWINDOW_H
