#ifndef A_H
#define A_H

#include <QObject>

class A : public QObject
{
    Q_OBJECT
public:
    explicit A(QObject *parent = nullptr);

    void processData(); // Function that processes and emits x

signals:
    void MySignal(int x);

private:
    int getValue(); // Function to retrieve or calculate x
    int x;
};

#endif // A_H
