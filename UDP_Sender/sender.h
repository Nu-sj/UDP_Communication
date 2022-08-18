#ifndef SENDER_H
#define SENDER_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Sender; }
QT_END_NAMESPACE

class Sender : public QMainWindow
{
    Q_OBJECT

public:
    Sender(QWidget *parent = nullptr);
    ~Sender();

private slots:
    void on_broadcast_clicked();

    void on_exit_clicked();

private:
    Ui::Sender *ui;
    QUdpSocket *sender;
};
#endif // SENDER_H
