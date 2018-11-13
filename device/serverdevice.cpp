#include "serverdevice.h"

void ServerDevice::on_pbtnServer_clicked()
{
    server = new TcpServer(portStr->text().toInt());
    pbtnServer->setEnabled(false);
    portStr->setEnabled(false);

    connect(server, &TcpServer::deviceCountChanged, this, &ServerDevice::updateOpenStatus);
    connect(server, &TcpServer::requestedMessage, this, &ServerDevice::setRequestedData);
    connect(this, &ServerDevice::receiveData, server, &TcpServer::slotSendData);
    updateOpenStatus(0);
}

void ServerDevice::checkPortStr()
{
    // Максимальное значение для порта 65355 - 16 полных разрядов
    int port = portStr->text().toInt();
    if( port <65355 && port > 0)
        pbtnServer->setEnabled(true);
    else
        pbtnServer->setEnabled(false);
}

ServerDevice::ServerDevice(QString description) : AbstractIODevice (description)
{
    Initialization();

    portStr = new QLineEdit();
    createLineWidget("port:", portStr);

    pbtnServer = new QPushButton("Start Server");
    pbtnServer->setEnabled(false);
    createLineWidget(pbtnServer);

    connect(pbtnSend, &QPushButton::clicked, this, &ServerDevice::on_pbtnSend_clicked);
    connect(pbtnServer, &QPushButton::clicked, this, &ServerDevice::on_pbtnServer_clicked);
    connect(portStr, &QLineEdit::textChanged, this, &ServerDevice::checkPortStr);

}

void ServerDevice::setRequestedData(QString data)
{
    lReadData->setText(data);
}



void ServerDevice::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.setBrush(QBrush(Qt::white));
    p.setPen(QPen(QColor(Qt::red)));
    p.setRenderHint(QPainter::Antialiasing, true);
    p.drawRoundedRect(1, 1, width() - 2, height() - 2,3,3, Qt::AbsoluteSize);
}


void ServerDevice::on_pbtnSend_clicked()
{
    sendData(lWriteData->text());

    lWriteData->clear();
}

void ServerDevice::updateOpenStatus(int count)
{
    lOpenStatus->setText(count>0?"Connected: "+ QString::number(count) :"isListening");
}


void ServerDevice::on_pbtnClose_clicked()
{
    emit deviceDestroyed(this);
    server->deleteLater();
    this->~ServerDevice();

}


void ServerDevice::sendData(QString datas)
{
    emit receiveData(datas);
}
