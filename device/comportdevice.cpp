#include "comportdevice.h"


ComPortDevice::ComPortDevice(QString description) : AbstractIODevice (description)
{
    Initialization();

    pbtnConnect = new QPushButton("connect");
    comportStr = new QLineEdit();
    baudStr = new QLineEdit();
    serPort = new QSerialPort();

    createLineWidget("comport:", comportStr);
    createLineWidget("baud:", baudStr);
    createLineWidget(pbtnConnect);

    connect(pbtnConnect, &QPushButton::clicked, this, &ComPortDevice::on_pbtnConnect_clicked);

    connect(this ,&ComPortDevice::setOpenProperty,this, &ComPortDevice::setOpen);
    connect(serPort ,&QSerialPort::errorOccurred,this, &ComPortDevice::setOpen);

    connect(pbtnSend, &QPushButton::clicked, this, &ComPortDevice::on_pbtnSend_clicked);

    this->comportStr->setText("COM3");
    this->baudStr->setText("9600");
}

void ComPortDevice::getData()
{

    QByteArray bytes = serPort->readAll();
    QString str = QString::fromLocal8Bit(bytes);
    lReadData->setText(str);

    emit sendData(str);
}

void ComPortDevice::on_pbtnConnect_clicked()
{
    if(!isConnected)
    {
        QSerialPortInfo info = QSerialPortInfo(comportStr->text());

        serPort->setPort(info);
        serPort->setBaudRate(baudStr->text().toInt());
        serPort->open(QIODevice::ReadWrite);
        if(serPort->isDataTerminalReady())
        {
            lOpenStatus->setText("Open");
//            connect(serPort, &QSerialPort::readyRead, this, &ComPortDevice::getData);
        }
    }
    else
    {
        serPort->close();
        lOpenStatus->setText("Closed");
    }
    emit setOpenProperty();

}

void ComPortDevice::setOpen()
{
    QString str;
    if(serPort->isOpen())
    {
        str = "Open";
        pbtnConnect->setText("connect");
        isConnected = true;
    }
    else
    {
        str = "Closed";
        pbtnConnect->setText("disconnect");
        isConnected = false;
    }

    lOpenStatus->setText(str);
}

void ComPortDevice::on_pbtnSend_clicked()
{

    QString data = lWriteData->text();
    if(!data.isEmpty())
    {
        serPort->write(data.toLocal8Bit());
        lWriteData->clear();
    }
}

