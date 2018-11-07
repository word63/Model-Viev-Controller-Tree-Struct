#include "serverdevice.h"

ServerDevice::ServerDevice(QString description) : AbstractIODevice (description)
{
    Initialization();
    connect(pbtnSend, &QPushButton::clicked, this, &ServerDevice::on_pbtnSend_clicked);
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
    emit receiveData(lWriteData->text());
    lWriteData->clear();
}

void ServerDevice::updateOpenStatus(int count)
{
    lOpenStatus->setText(count>0?"Connected: "+ QString::number(count) :"isListening");
}
