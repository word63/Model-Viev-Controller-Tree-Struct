#include "socketdevice.h"

void SocketDevice::makeConnects()
{
    connect(pbtnSend, &QPushButton::clicked, this, &SocketDevice::on_pbtnSend_clicked);
    connect(pbtnConnect, &QPushButton::clicked, this, &SocketDevice::on_pbtnConnect_clicked);
    connect(socket, SIGNAL(readyRead()), this, SLOT(slotTransmitData()));

}

SocketDevice::SocketDevice(QString description) : AbstractIODevice (description)
{
    Initialization();
    ipLine = new QLineEdit();
    createLineWidget("ip", ipLine);

    pbtnConnect = new QPushButton("Connect");
    createLineWidget(pbtnConnect);

    socket = new QTcpSocket();

    makeConnects();
}


void SocketDevice::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.setRenderHint(QPainter::Antialiasing, true);
    p.setBrush(QBrush(Qt::white));
    p.setPen(QPen(QColor(Qt::yellow)));
    p.drawRoundedRect(1, 1, width() - 2, height() - 2,3,3, Qt::AbsoluteSize);
}

void SocketDevice::on_pbtnSend_clicked()
{
    if(!socket->isOpen())
    {
        qDebug() << "socket is closed!";
        return;
    }

    qDebug() << "data transmitted";
    QString data = lWriteData->text();
    socket->write(data.toLocal8Bit());

    lWriteData->clear();
}

void SocketDevice::on_pbtnConnect_clicked()
{
    if(!socket->isOpen())
    {

        socket->connectToHost(ipLine->text(), 8080);

        pbtnConnect->setText("Disconnect");
        lOpenStatus->setText("Open");
    }
    else
    {
        socket->close();

        lOpenStatus->setText("Closed");
        pbtnConnect->setText("Connect");

    }
}

void SocketDevice::slotTransmitData()
{
    qDebug() << "data gotten to socket";
    socket->waitForReadyRead(30);

    QString data = QString::fromLocal8Bit(socket->readAll());
    lReadData->setText(data);
}
