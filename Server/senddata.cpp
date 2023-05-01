#include "senddata.h"
#include <QDebug>
SendData::SendData(QObject *parent) :
    QObject(parent)
{

}

void SendData::send(QString m)
{
    udpSocket -> writeDatagram(m.toLatin1(), QHostAddress::LocalHost, 5555);
    emit finished();
}
