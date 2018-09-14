#ifndef SERVERDEVICE_H
#define SERVERDEVICE_H

#include "device/abstractiodevice.h"
#include <QDebug>

class ServerDevice : public AbstractIODevice
{
    Q_OBJECT
public:
    ServerDevice(QString description);

public slots:
    void setRequestedData(QString str);
    // AbstractIODevice interface
protected:

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;


    // AbstractIODevice interface
public slots:
    void on_pbtnSend_clicked();
    void updateOpenStatus(int count);

Q_SIGNALS:
    void receiveData(QString data);
};

#endif // SERVERDEVICE_H
