#include "sender.h"
#include "ui_sender.h"

Sender::Sender(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Sender)
{
    ui->setupUi(this);
    //初始化
    sender = new QUdpSocket(this);
    ui->communication_window->setReadOnly(true);
}

Sender::~Sender()
{
    delete ui;
}


void Sender::on_broadcast_clicked()
{
    QByteArray data = ui->send_window->toPlainText().toUtf8();
    //广播到8888端口
    sender->writeDatagram(data,QHostAddress::Broadcast,8888);
    QString msg = QString("Sender: %1 \n").arg(ui->send_window->toPlainText());
    ui->communication_window->append(msg);
    ui->send_window->clear();
}

void Sender::on_exit_clicked()
{
    this->close();
}
