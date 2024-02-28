#include "test.h"

test::test(QObject *parent) : QObject(parent)
{
    number = 0;
    timer.setInterval(1000);
    connect(&timer, &QTimer::timeout,this, &test::timeout);

}

void test::timeout()
{
    number++;
    qInfo() << QTime::currentTime().toString(Qt::DateFormat::SystemLocaleDate);
    if(number== 5){
        timer.stop();
        qInfo() << "Complete";
    }

}

void test::doStuff()
{
    timer.start();
}

