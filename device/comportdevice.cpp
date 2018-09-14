#include "comportdevice.h"


ComPortDevice::ComPortDevice(QString description) : AbstractIODevice (description)
{
    Initialization();
}



//void ComPortDevice::paintEvent(QPaintEvent *event)
//{
//    QPainter p(this);

//    p.setRenderHint(QPainter::Antialiasing, true);
//    p.setPen(QPen(QColor(Qt::cyan)));
//    p.drawRoundedRect(1, 1, width() - 2, height() - 2,3,3, Qt::AbsoluteSize);

//}

