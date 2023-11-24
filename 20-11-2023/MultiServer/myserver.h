#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include "mythread.h"
#include <QThread>
#include <QTcpSocket>

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr);

    void StartServer();

signals:

public slots:

protected:

    void incomingConnection(int socketDescriptor);

};

#endif // MYSERVER_H
