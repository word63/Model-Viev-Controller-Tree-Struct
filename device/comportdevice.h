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
    void sendData(QString datas);
private slots:

    void on_pbtnConnect_clicked();
    void setOpen();
    void on_pbtnSend_clicked();

signals:
    void setOpenProperty();


    // AbstractIODevice interface
protected slots:
    void on_pbtnClose_clicked() override;
    void receiveData() ;

};

#endif // COMPORTDEVICE_H
