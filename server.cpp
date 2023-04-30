#include "server.h"

#include <QDebug>
Server::Server(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Server"));

    slider1 -> setRange(2,5);
    slider2 -> setRange(-10,10);
    slider3 -> setRange(-10,10);

    slider1 -> setValue(slider1->minimum());
    slider2 -> setValue(slider2->minimum());
    slider3 -> setValue(slider3->minimum());

    label4 -> setText(QString::number(slider1->value()));
    label5 -> setText(QString::number(slider2->value()/10.0,'f',2));
    label6 -> setText(QString::number(slider3->value()/10.0,'f',2));

    connect(slider1, SIGNAL(valueChanged(int)), this, SLOT(slider1VChanged(int)));
    connect(slider2, SIGNAL(valueChanged(int)), this, SLOT(slider2VChanged(int)));
    connect(slider3, SIGNAL(valueChanged(int)), this, SLOT(slider3VChanged(int)));

    MyVBox -> addLayout(MyGrid);
    MyGrid -> addWidget(label1, 0, 0);
    MyGrid -> addWidget(label2, 1, 0);
    MyGrid -> addWidget(label3, 2, 0);

    MyGrid -> addWidget(slider1, 0, 1);
    MyGrid -> addWidget(slider2, 1, 1);
    MyGrid -> addWidget(slider3, 2, 1);

    MyGrid -> addWidget(label4, 0, 2);
    MyGrid -> addWidget(label5, 1, 2);
    MyGrid -> addWidget(label6, 2, 2);

    MyVBox -> addWidget(button);

    connect(button, SIGNAL(released()), this, SLOT(buttonClicked()));
}

Server::~Server()
{

}
void Server::buttonClicked()
{
    sender_1.messege = label4 -> text() + " " + label5 -> text() + " " + label6 -> text();
    //Отправка данных клиенту
    connect(&thread_1, &QThread::started, &sender_1, &SendData::send);
    connect(&sender_1, &SendData::finished, &thread_1, &QThread::terminate);
    sender_1.moveToThread(&thread_1);
    thread_1.start();

}

void Server::slider1VChanged(int value)
{
    //Изменение угла камеры
    label4 -> setText(QString::number(value));
}

void Server::slider2VChanged(int value)
{
    //Изменени смещения по горизонтали
    label5 -> setText(QString::number(value/10.0,'f',2));
}

void Server::slider3VChanged(int value)
{
    //Изменени смещения по вертикали
    label6 -> setText(QString::number(value/10.0,'f',2));
}


