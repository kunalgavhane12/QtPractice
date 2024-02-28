#include "someclass.h"
#include <QDebug>

SomeClass::SomeClass(QObject *parent) : QObject(parent),
    m_someVar("123")

{

}

void SomeClass::anotherFunction()
{
    qDebug() << "Another Function";
}

QString SomeClass::getSomeVar()
{
    return m_someVar;
}

void SomeClass::callMe()
{
    qDebug() << "Calling From Qml";
}

QString SomeClass::someVar()
{
    return m_someVar;
}

void SomeClass::setSomeVar(QString newSomeVar)
{
    if (m_someVar == newSomeVar)
        return;
    m_someVar = newSomeVar;
    emit someVarChanged();
}
