#include "socketdevice.h"

void SocketDevice::makeConnects()
{
    connect(pbtnSend, &QPushButton::clicked, this, &SocketDevice::on_pbtnSend_clicked);
    connect(pbtnConnect, &QPushButton::clicked, this, &SocketDevice::on_pbtnConnect_clicked);
    connect(socket, SIGNAL(readyRead()), this, SLOT(dataFromSocket()));

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
        return;
    }

    QString data = lWriteData->text();

    sendData(data);
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


void SocketDevice::dataFromSocket()
{
    socket->waitForReadyRead(30);
    lReadData->setText(QString::fromLocal8Bit(socket->readAll()));
}


void SocketDevice::sendData(QString datas)
{
    socket->write(datas.toLocal8Bit());

}

void SocketDevice::on_pbtnClose_clicked()
{
    socket->disconnectFromHost();
    socket->deleteLater();
    emit deviceDestroyed(this);
    this->deleteLater();
}
