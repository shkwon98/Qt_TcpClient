#include "tcpclient.h"
#include "tcpclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    TcpClient c;
    c.doConnect();

    return a.exec();
}
