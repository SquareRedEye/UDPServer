#ifndef SENDDATA_H
#define SENDDATA_H

#include <QObject>
#include <QUdpSocket>
class SendData : public QObject
{
    Q_OBJECT

public:
    explicit SendData(QObject *parent = nullptr);

signals:
    void finished();

public slots:
    void send(QString m);
private:
    QUdpSocket *udpSocket = new QUdpSocket(this);
};

#endif // SENDDATA_H
