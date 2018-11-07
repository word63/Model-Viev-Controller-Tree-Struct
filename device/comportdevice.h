#ifndef COMPORTDEVICE_H
#define COMPORTDEVICE_H

#include "device/abstractiodevice.h"
#include <QDebug>
#include <QPushButton>
#include <QLineEdit>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class ComPortDevice : public AbstractIODevice
{
    Q_OBJECT
private:
    QPushButton *pbtnConnect;
    QLineEdit *comportStr;
    QLineEdit * baudStr;
    QSerialPort *serPort;

    bool isConnected = false;
public:
    explicit ComPortDevice(QString description);

protected:
//    void paintEvent(QPaintEvent *event);
private slots:
    void getData();
    void on_pbtnConnect_clicked();
    void setOpen();
    void on_pbtnSend_clicked();

signals:
    void setOpenProperty();
    void sendData(QString str);
};

#endif // COMPORTDEVICE_H
