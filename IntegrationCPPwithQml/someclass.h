#ifndef SOMECLASS_H
#define SOMECLASS_H

#include <QObject>

class SomeClass : public QObject
{
    Q_OBJECT
    QString m_someVar;

public:
    explicit SomeClass(QObject *parent = nullptr);

    Q_PROPERTY(QString someVar READ someVar WRITE setSomeVar NOTIFY someVarChanged)

    Q_INVOKABLE void anotherFunction();
    Q_INVOKABLE QString getSomeVar();

    QString someVar() ;

signals:

    void someVarChanged();

public slots:
    void setSomeVar(QString newSomeVar);
    void callMe();

};

#endif // SOMECLASS_H
