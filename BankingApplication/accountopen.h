#ifndef ACCOUNTOPEN_H
#define ACCOUNTOPEN_H

#include <QDialog>

namespace Ui {
class AccountOpen;
}

class AccountOpen : public QDialog
{
    Q_OBJECT

public:
    explicit AccountOpen(QWidget *parent = nullptr);
    ~AccountOpen();

private:
    Ui::AccountOpen *ui;
};

#endif // ACCOUNTOPEN_H
