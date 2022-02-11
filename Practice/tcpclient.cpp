#include "tcpclient.h"
#include "ui_tcpclient.h"

TcpClient::TcpClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    
    // 정적배열
    qDebug() << "static Array :";
    int number[10];
    for (int i = 0; i < 10; i++)
    {
        number[i] = i;
        qDebug() << "i = " << number[i];
    }

    // 동적배열
    qDebug() << "dynamic Array :";
    int* num = new int[10];
    for (int i = 0; i < 10; i++)
    {
        num[i] = i;
        qDebug() << "i = " << num[i];
    }
    delete[] num;
}

TcpClient::~TcpClient()
{
    delete ui;
}


void TcpClient::doConnect()
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));

    qDebug() << "connecting...";

    socket->connectToHost("192.168.0.10", 2000);

    if(!socket->waitForConnected(5000))
    {
        qDebug() << "Error: " << socket->errorString();
    }
}

void TcpClient::connected()
{
    qDebug() << "connected...";

}

void TcpClient::disconnected()
{
    qDebug() << "disconnected...";
}

void TcpClient::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}


//종료
void TcpClient::on_pushButton_3_clicked()
{
    this->close();
}
