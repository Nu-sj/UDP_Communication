#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Server; }
QT_END_NAMESPACE

class Server : public QMainWindow
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();

private slots:
    void receivedata();

private:
    Ui::Server *ui;
    QUdpSocket *udpsocket;
};
#endif // SERVER_H
