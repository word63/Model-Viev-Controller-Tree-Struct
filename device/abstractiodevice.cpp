#include "abstractiodevice.h"

AbstractIODevice::AbstractIODevice(QString description, QWidget *parent) : QWidget(parent)
{
    this->description = description;
    this->setStyleSheet("AbstractIODevice { background-color: yellow }");
}



void AbstractIODevice::Initialization()
{
    mainLayout = new QVBoxLayout();

    lOpenStatus = new QLineEdit();
    lReadData = new  QLineEdit();
    lWriteData = new  QLineEdit();

    pbtnSend = new QPushButton("Send data");
    pbtnClose = new QPushButton("delete device");

    pbtnClose->setStyleSheet("background-color: rgba(255,0,0,100)");

    lOpenStatus->setReadOnly(true);
    lReadData->setReadOnly(true);

    lOpenStatus->setText("Closed");

    createLineWidget(description, pbtnClose);
    createLineWidget("Status: ", lOpenStatus);
    createLineWidget("Read: ", lReadData);
    createLineWidget("Write: ", lWriteData);
    createLineWidget(pbtnSend);

    this->setLayout(mainLayout);

    connect(pbtnClose, &QPushButton::clicked, this, &AbstractIODevice::on_pbtnClose_clicked);
}

void AbstractIODevice::createLineWidget(QString labelStr, QWidget *widget)
{
    wLineCount++;
    QHBoxLayout *hlayout = new QHBoxLayout();

    QLabel *label = new QLabel(labelStr);
    hlayout->addWidget(label);

    if(widget!=nullptr)
        hlayout->addWidget(widget);

    mainLayout->addLayout(hlayout);
}

void AbstractIODevice::createLineWidget(QWidget *widget)
{
    wLineCount++;
    if(widget != nullptr)
    {
        mainLayout->addWidget(widget);
    }
}



void AbstractIODevice::setDesription(const QString description)
{
    if(!description.isNull())
        this->description = description;
}

void AbstractIODevice::bridgeTo(AbstractIODevice *device)
{
    bridgedDevices.append(device);
}

void AbstractIODevice::unbridgeFrom(AbstractIODevice *device)
{
   bridgedDevices.removeOne(device);
}

void AbstractIODevice::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(QColor(Qt::cyan)));
    p.setBrush(QBrush(Qt::white));
    p.drawRoundedRect(1, 1, width() - 2, height() - 2,3,3, Qt::AbsoluteSize);
}

void AbstractIODevice::sendData(QString datas)
{

}

void AbstractIODevice::on_pbtnClose_clicked()
{

}

void AbstractIODevice::notificateBridges(QString datas)
{
    foreach (AbstractIODevice* device, bridgedDevices) {
       device->sendData(datas);
    }
}


int AbstractIODevice::getWLineCount() const
{
    return wLineCount;
}

QString AbstractIODevice::getDescription() const
{
    return description;
}

