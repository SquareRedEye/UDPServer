#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QPushButton>
#include <QUdpSocket>

class Server : public QWidget
{
    Q_OBJECT
public:
    Server(QWidget *parent = nullptr);
    ~Server();
private slots:
    void slider1VChanged(int value);
    void slider2VChanged(int value);
    void slider3VChanged(int value);
    void buttonClicked();
private:
    QVBoxLayout *MyVBox = new QVBoxLayout(this);

    QGridLayout *MyGrid = new QGridLayout;

    QLabel *label1 = new QLabel("Угол камеры по горизонтали, град.");
    QLabel *label2 = new QLabel("Отступ по горизонтали");
    QLabel *label3 = new QLabel("Отступ по вертикали");
    QLabel *label4 = new QLabel;
    QLabel *label5 = new QLabel;
    QLabel *label6 = new QLabel;

    QSlider *slider1 = new QSlider(Qt::Horizontal);
    QSlider *slider2 = new QSlider(Qt::Horizontal);
    QSlider *slider3 = new QSlider(Qt::Horizontal);

    QPushButton *button = new QPushButton("Отправить");

    QUdpSocket *udpSocket = new QUdpSocket;
};
