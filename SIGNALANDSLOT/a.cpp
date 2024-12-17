#include "a.h"
#include <QTimer>

A::A(QObject *parent)
    : QObject(parent)
{
    // Call processData after construction to simulate receiving x
    QTimer::singleShot(0, this, &A::processData);
}

void A::processData()
{
    x = getValue();      // Get or calculate the value of x
    emit MySignal(x);    // Emit the signal with the new value
}

int A::getValue()
{
    // Simulate getting the value of x (e.g., from a sensor, computation, etc.)
    return 42; // Example value, this could come from any external function
}
