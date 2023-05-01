#include "senddata.h"
#include <QDebug>
SendData::SendData(QObject *parent) :
    QObject(parent)
{
    qDebug() << "hello";
}

void SendData::send()
{
    udpSocket -> writeDatagram(messege.toLatin1(), QHostAddress::LocalHost, 5555);
    emit finished();
}
