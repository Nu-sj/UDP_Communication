#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);
    udpsocket = new QUdpSocket(this);
    udpsocket->bind(8888,QUdpSocket::ShareAddress);
    connect(udpsocket,&QUdpSocket::readyRead,this,&Server::receivedata);
}

Server::~Server()
{
    delete ui;
}

void Server::receivedata()
{
    while (udpsocket->hasPendingDatagrams()) {
        QByteArray data;
        data.resize(udpsocket->pendingDatagramSize());
        udpsocket->readDatagram(data.data(),data.size());
        QString msg = QString("Sender: %1 \n").arg(data.data());
        ui->textEdit->append(msg);
    }
}
