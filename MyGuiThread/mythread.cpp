#include "mythread.h"

class MyThreadData : public QSharedData
{
public:

};

MyThread::MyThread() : data(new MyThreadData)
{

}

MyThread::MyThread(const MyThread &rhs) : data(rhs.data)
{

}

MyThread &MyThread::operator=(const MyThread &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

MyThread::~MyThread()
{

}
