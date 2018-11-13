#include "devicedispatcher.h"

QStringList DeviceDispatcher::getStringListDevices() const
{
    QStringList strList;
    foreach (AbstractIODevice* device, listDevices) {
       strList.append(device->getDescription());
    }
    return strList;
}

void DeviceDispatcher::deviceDestroyed(AbstractIODevice *device)
{

    listDevices.removeOne(device);
    emit listDeviceChanged();

    qDebug() << "devices: " << listDevices.length();

}

DeviceDispatcher::DeviceDispatcher(QObject *parent) : QObject(parent)
{

}

ComPortDevice *DeviceDispatcher::createComDevice(const QString descr)
{
    if(!descr.isNull())
    {
        ComPortDevice *device = new ComPortDevice(descr);
        listDevices.append(device);
        emit listDeviceChanged();

        connect(device, &ComPortDevice::deviceDestroyed, this, &DeviceDispatcher::deviceDestroyed);

        return device;
    }

    return nullptr;
}

ServerDevice *DeviceDispatcher::createServerDevice(const QString descr)
{
    if(!descr.isNull())
    {
        ServerDevice *device = new ServerDevice(descr);
        listDevices.append(device);
        emit listDeviceChanged();

        connect(device, &ServerDevice::deviceDestroyed, this, &DeviceDispatcher::deviceDestroyed);

        return device;
    }
    return nullptr;
}

SocketDevice *DeviceDispatcher::createSocketDevice(const QString descr)
{
    if(!descr.isNull())
    {
        SocketDevice *device = new SocketDevice(descr);
        listDevices.append(device);
        emit listDeviceChanged();
connect(device, &SocketDevice::deviceDestroyed, this, &DeviceDispatcher::deviceDestroyed);
        return device;
    }
    return nullptr;
}

bool DeviceDispatcher::setBridge(AbstractIODevice *from, AbstractIODevice *to)
{
    from->bridgeTo(to);
    return true;
}
