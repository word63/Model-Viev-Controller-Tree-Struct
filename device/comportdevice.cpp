#include "comportdevice.h"

ComPortDevice::ComPortDevice(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(100,100);
    this->setMaximumHeight(100);


    QPushButton *pbtn = new QPushButton(this);

    newLay = new QVBoxLayout();
    newLay->addWidget(pbtn);

    this->setLayout(newLay);

}

void ComPortDevice::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QPen pen;

    pen.setWidth(1);
    pen.setColor(Qt::cyan);

    p.setRenderHint(QPainter::Antialiasing, true);

    p.setPen(pen);
    p.drawRoundedRect(1, 1, width() - 2, height() - 2,5,5, Qt::AbsoluteSize);

}

