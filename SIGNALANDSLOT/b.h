#ifndef B_H
#define B_H

#include "a.h"
#include <QObject>

class B : public QObject
{
    Q_OBJECT

public:
    B();

private:
    A *a1 = nullptr;
    void mydata(int x);
};

#endif // B_H
