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

    lOpenStatus->setReadOnly(true);
    lReadData->setReadOnly(true);

    lOpenStatus->setText("Closed");

    createLineWidget(description);
    createLineWidget("Status: ", lOpenStatus);
    createLineWidget("Read: ", lReadData);
    createLineWidget("Write: ", lWriteData);


    pbtnSend = new QPushButton("Send data");
    mainLayout->addWidget(pbtnSend);
    this->setLayout(mainLayout);

}

void AbstractIODevice::createLineWidget(QString labelStr, QWidget *widget)
{
    widgetCount++;
    QHBoxLayout *hlayout = new QHBoxLayout();

    QLabel *label = new QLabel(labelStr);
    hlayout->addWidget(label);

    if(widget!=nullptr)
        hlayout->addWidget(widget);

    mainLayout->addLayout(hlayout);
}

void AbstractIODevice::createLineWidget(QWidget *widget)
{
    widgetCount++;
    if(widget != nullptr)
    {
        mainLayout->addWidget(widget);
    }
}



void AbstractIODevice::setDesription(QString description)
{
    this->description = description;
}

int AbstractIODevice::getWidgetCount() const
{
    return widgetCount;
}

void AbstractIODevice::bridgeTo(AbstractIODevice *from)
{
//    connect();
}

void AbstractIODevice::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(QColor(Qt::cyan)));
    p.setBrush(QBrush(Qt::white));
    p.drawRoundedRect(1, 1, width() - 2, height() - 2,3,3, Qt::AbsoluteSize);
}

