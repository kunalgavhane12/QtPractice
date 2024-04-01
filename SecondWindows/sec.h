#ifndef SEC_H
#define SEC_H

#include <QDialog>

namespace Ui {
class Sec;
}

class Sec : public QDialog
{
    Q_OBJECT

public:
    explicit Sec(QWidget *parent = nullptr);
    ~Sec();

private slots:

    void on_btnInfo_clicked();

    void on_btnQues_clicked();

    void on_btnWarning_clicked();

    void on_btnAbout_clicked();

    void on_btnCritical_clicked();

private:
    Ui::Sec *ui;
};

#endif // SEC_H
