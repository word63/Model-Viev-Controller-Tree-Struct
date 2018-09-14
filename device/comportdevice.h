#ifndef COMPORTDEVICE_H
#define COMPORTDEVICE_H

#include "device/abstractiodevice.h"
#include <QDebug>

class ComPortDevice : public AbstractIODevice
{
    Q_OBJECT
public:
    explicit ComPortDevice(QString description);

protected:
//    void paintEvent(QPaintEvent *event);


};

#endif // COMPORTDEVICE_H
