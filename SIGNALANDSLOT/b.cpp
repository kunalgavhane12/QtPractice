#include "b.h"
#include <QDebug>

B::B()
{
    a1 = new A(); // Create an instance of class A
    connect(a1, &A::MySignal, this, &B::mydata);
}

void B::mydata(int x)
{
    qDebug() << "x: " << x; // Print the received value
}
