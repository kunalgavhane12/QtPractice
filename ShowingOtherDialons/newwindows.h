#ifndef NEWWINDOWS_H
#define NEWWINDOWS_H

#include <QDialog>

namespace Ui {
class NewWindows;
}

class NewWindows : public QDialog
{
    Q_OBJECT

public:
    explicit NewWindows(QWidget *parent = nullptr);
    ~NewWindows();

private:
    Ui::NewWindows *ui;
};

#endif // NEWWINDOWS_H
