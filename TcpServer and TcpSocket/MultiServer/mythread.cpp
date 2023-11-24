#include "mythread.h"
#include <QThread>

MyThread::MyThread(int ID, QObject *parent) : QObject(parent)
{
    this->socketDescriptor = ID;
}

void MyThread::run()
{
    //thread starts here
    qDebug() << socketDescriptor <<"Starting thread";
    socket = new QTcpSocket();

    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this, SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this, SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << "Client Connected";

//    exec();

}


void MyThread::readyRead()
{
    QByteArray Data = socket->readAll();

    qDebug() << socketDescriptor << "Data in : " << Data;

    socket->write(Data);
}

void MyThread::disconnected()
{

    qDebug() << socketDescriptor << "Disconnceted";

    socket->deleteLater();
    exit(0);
}
