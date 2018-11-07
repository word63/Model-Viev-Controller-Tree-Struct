#include "tcpserver.h"

TcpServer::TcpServer(int port, QObject *parent) : QObject(parent)
{
    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen(QHostAddress::Any, quint16(port)))
    {
        qDebug()<< "listening";
        QMessageBox::critical(nullptr,
                              "Fatal Error",
                              "Server is unable to start: "
                              + tcpServer->errorString()
                              );
    }
    connect(tcpServer, &QTcpServer::newConnection, this, &TcpServer::slotNewConnection);
}

void TcpServer::slotNewConnection()
{
    qDebug() << " new connection";
    QTcpSocket* pSocket = tcpServer->nextPendingConnection();

    addDevice(pSocket);

    connect(pSocket, SIGNAL(disconnected()), pSocket, SLOT(deleteLater()));
    connect(pSocket, SIGNAL(disconnected()), this, SLOT(deleteDevice()));
    connect(pSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));

}

void TcpServer::slotReadClient()
{
    qDebug()<<"message readed";

    QTcpSocket* clientSocket = static_cast<QTcpSocket*>(sender());
    clientSocket->waitForReadyRead(30);

    QByteArray bData = clientSocket->readAll();

    QString strMessage = QString::fromLocal8Bit(bData);

    emit requestedMessage(strMessage);
}

void TcpServer::slotSendData(QString data)
{
    foreach(QTcpSocket* socket, connectedDevices )
    {
        sendToClient(socket, data);
    }
}



void TcpServer::sendToClient(QTcpSocket *pSocket,const QString &strPrint)
{
    QByteArray arrBlock;
    arrBlock = strPrint.toLocal8Bit();

    pSocket->write(arrBlock);
}

void TcpServer::addDevice(QTcpSocket *socket)
{
    connectedDevices.append(socket);

    deviceCount++;
    emit deviceCountChanged(deviceCount);
}

void TcpServer::deleteDevice()
{
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
    connectedDevices.removeOne(socket);

    deviceCount--;
    emit deviceCountChanged(deviceCount);
}
