#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>

enum Operation {
    NoOperation,
    Addition,
    Subtraction,
    Multiply,
    Division
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDigitButtonClicked(int digit);
    void keyPressEvent(QKeyEvent *event);
    void onOperationButtonClicked(const QString &operation);
    void onEqualButtonClicked();
    void updateDisplay();

private:
    Ui::MainWindow *ui;
    QLabel *label;
    QPushButton *buttons[10];
    int currentValue;
    int secondValue;
    Operation currentOperation;
};

#endif // MAINWINDOW_H

