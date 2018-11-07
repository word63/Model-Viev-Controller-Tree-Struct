#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

#include <QObject>
#include <QMessageBox>
#include <QTime>

class TcpServer : public QObject
{
    Q_OBJECT

private:
    QTcpServer* tcpServer;
    QList<QTcpSocket*> connectedDevices;
    int deviceCount = 0;

private slots:
    virtual void slotNewConnection();
    void slotReadClient();

public slots:
    void addDevice(QTcpSocket* socket);
    void deleteDevice();

public:
    explicit TcpServer(int port, QObject *parent = nullptr);
    void sendToClient(QTcpSocket* pSocket, const QString &strPrint);

signals:
    void requestedMessage(QString data);
    void deviceCountChanged(int count);

public Q_SLOTS:
    void slotSendData(QString data);



};

#endif // TCPSERVER_H
