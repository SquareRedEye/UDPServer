#ifndef SENDDATA_H
#define SENDDATA_H

#include <QObject>
#include <QUdpSocket>
class SendData : public QObject
{
    Q_OBJECT

public:
    explicit SendData(QObject *parent = nullptr);
    QString messege;

signals:
    void finished();

public slots:
    void send();
private:
    QUdpSocket *udpSocket = new QUdpSocket;
};

#endif // SENDDATA_H
