#ifndef SOCKETDEVICE_H
#define SOCKETDEVICE_H

#include "abstractiodevice.h"
#include <QTcpSocket>

class SocketDevice : public AbstractIODevice
{
    Q_OBJECT
private:
    QLineEdit* ipLine;
    QPushButton* pbtnConnect;
    QTcpSocket* socket;
public:
    SocketDevice(QString description);

    // QWidget interface
    void makeConnects();

protected:
    void paintEvent(QPaintEvent *event) override;


    // AbstractIODevice interface
private slots:
    void on_pbtnSend_clicked();
    void on_pbtnConnect_clicked();

    void slotTransmitData();
};

#endif // SOCKETDEVICE_H
