#ifndef DEVICEDISPATCHER_H
#define DEVICEDISPATCHER_H

#include <QObject>
#include <device/abstractiodevice.h>
#include <device/comportdevice.h>
#include <device/serverdevice.h>
#include <device/socketdevice.h>
#include <QDebug>

class DeviceDispatcher : public QObject
{
    Q_OBJECT
    QList<AbstractIODevice* > listDevices;

public:
    explicit DeviceDispatcher(QObject *parent = nullptr);

    ComPortDevice *createComDevice(const QString descr = "comport");
    ServerDevice *createServerDevice(const QString descr = "server");
    SocketDevice *createSocketDevice(const QString descr = "socket");

    bool setBridge(AbstractIODevice* from, AbstractIODevice* to);

    QStringList getStringListDevices() const;

private slots:
    void deviceDestroyed(AbstractIODevice *device);
signals:
    void listDeviceChanged();
public slots:
};

#endif // DEVICEDISPATCHER_H
