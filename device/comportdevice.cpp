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
    connect(pbtnSend, &QPushButton::clicked, this, &ComPortDevice::on_pbtnSend_clicked);

    connect(this ,&ComPortDevice::setOpenProperty,this, &ComPortDevice::setOpen);

    pbtnSend->setEnabled(false);

    comportStr->setText("COM3");
    baudStr->setText("9600");
}

void ComPortDevice::on_pbtnConnect_clicked()
{
    if(!isConnected)
    {
        QSerialPortInfo info = QSerialPortInfo(comportStr->text());

        serPort->setPort(info);
        serPort->setBaudRate(baudStr->text().toInt());

        if(serPort->open(QIODevice::ReadWrite))
        {
            isConnected = true;

            // может потичь бочек при принятии данных через
            // ком порт, если да то виноват этот коннект
            connect(serPort, &QSerialPort::readyRead, this, &ComPortDevice::receiveData);
        }
        else
            isConnected = false;
    }
    else
    {
        serPort->close();
        isConnected = false;
    }

    emit setOpenProperty();

}

void ComPortDevice::setOpen()
{
    QString str;

    if(isConnected)
    {
        str = "Open";
        pbtnConnect->setText("disconnect");
        pbtnSend->setEnabled(true);
    }
    else
    {
        str = "Closed";
        pbtnConnect->setText("connect");
        pbtnSend->setEnabled(false);
    }

    lOpenStatus->setText(str);
}

void ComPortDevice::on_pbtnSend_clicked()
{
    sendData(lWriteData->text());
}



void ComPortDevice::on_pbtnClose_clicked()
{
    emit deviceDestroyed(this);
    this->deleteLater();
}

void ComPortDevice::receiveData()
{
     QByteArray bytes = serPort->readAll();

     QString str = QString::fromLocal8Bit(bytes);

     lReadData->setText(str);

     emit transmitData(str);

}

void ComPortDevice::sendData(QString datas)
{
    if(!datas.isEmpty())
    {
        serPort->write(datas.toLocal8Bit());
        lWriteData->clear();
    }
}
