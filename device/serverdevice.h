#ifndef SERVERDEVICE_H
#define SERVERDEVICE_H

#include "device/abstractiodevice.h"
#include "tcpserver.h"

#include <QDebug>

class ServerDevice : public AbstractIODevice
{
    Q_OBJECT

    // пользовательский сервер, создается при нажатии на
    // кнопку Start Server с указанным в QLineEdit портом
    TcpServer *server = nullptr;

    // Изменяемая строка порта для запуска сервера при помощи
    // кнопки запуска Start server
    QLineEdit *portStr = nullptr;

    QPushButton *pbtnServer = nullptr;
private slots:
    void on_pbtnServer_clicked();

    // установить кнопку pbtnServer Enabled если порт норм
    void checkPortStr();
public:
    ServerDevice(QString description);

public slots:
    void setRequestedData(QString str);

    // AbstractIODevice interface
    void on_pbtnSend_clicked();
    void updateOpenStatus(int count);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;

Q_SIGNALS:
    void receiveData(QString data) ;

    // AbstractIODevice interface
protected slots:
    void on_pbtnClose_clicked() override;

    // AbstractIODevice interface
protected:
    void sendData(QString datas);
};

#endif // SERVERDEVICE_H
