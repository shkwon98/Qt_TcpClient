#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QMainWindow>
#include <QtDebug>
#include <QTcpSocket>

const int BUFSIZE = 1024;


QT_BEGIN_NAMESPACE
namespace Ui { class TcpClient; }
QT_END_NAMESPACE

class TcpClient : public QMainWindow
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();

public slots:
    void doConnect();
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);

private:
    Ui::TcpClient *ui;

    QTcpSocket *socket;
    char buf[BUFSIZE] = {0,};
};

#endif // TCPCLIENT_H
