#ifndef SEC_H
#define SEC_H

#include <QDialog>
#include <QEvent>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTouchEvent>


namespace Ui {
class Sec;
}

class Sec : public QDialog
{
    Q_OBJECT

public:
    explicit Sec(QWidget *parent = nullptr);
    ~Sec();

protected:
    bool eventFilter(QObject *obj, QEvent *event)override{
        if(event->type() == QEvent::MouseButtonPress ||
                event->type() == QEvent::KeyPress ||
                event->type() == QEvent::TouchBegin ||
                event->type() == QEvent::TouchUpdate ||
                event->type() == QEvent::TouchEnd ||
                event->type() == QEvent::GraphicsSceneMouseMove)
        {
            inactivityTimer->start();
        }
        return QWidget::eventFilter(obj,event);
    }

private slots:

    void on_btnInfo_clicked();

    void on_btnQues_clicked();

    void on_btnWarning_clicked();

    void on_btnAbout_clicked();

    void on_btnCritical_clicked();

    void onTimeout();

private:
    Ui::Sec *ui;
    int timeoutDuration;
    QTimer *inactivityTimer;
};

#endif // SEC_H
