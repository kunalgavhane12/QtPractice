#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class MyThreadData;

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    MyThread(const MyThread &);
    MyThread &operator=(const MyThread &);
    ~MyThread();

private:
    QSharedDataPointer<MyThreadData> data;
};

#endif // MYTHREAD_H
