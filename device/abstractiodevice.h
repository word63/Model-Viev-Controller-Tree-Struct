#ifndef ABSTRACTIODEVICE_H
#define ABSTRACTIODEVICE_H

#include <QWidget>
#include <QPushButton>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLabel>
#include <QLineEdit>

#include <QPainter>

class AbstractIODevice : public QWidget
{
    Q_OBJECT
    
    // устройства, на которые должны отправляться
    // данные при получении
    QList<AbstractIODevice*> bridgedDevices;

public:
    AbstractIODevice(QString description = "undefined", QWidget *parent = nullptr);

    void setDesription(const QString description);
    QString getDescription() const;

    // Отправка данных из одного виджета в другой
    void bridgeTo(AbstractIODevice *device);
    // Отвязка отправки данных в другой виджет
    void unbridgeFrom(AbstractIODevice *device);

    // количество линий виджетов (для расчета размера высоты виджета)
    int getWLineCount() const;

protected:
    // Первичная настройка внешнего вида виджета
    // Используйте эту функцию в своём конструкторе
    // Для наследования от этого класса
    void Initialization(); 
    
    // Создание линии с виджетами, добавление функционала
    void createLineWidget(QString labelStr, QWidget *widget= nullptr);
    void createLineWidget(QWidget *widget);

    void paintEvent(QPaintEvent *event) override;
    
    // При изменении статуса на открытый необходимо 
    // Поменять этот флаг чтобы проверка на валидность
    // устройства проходилась успешно
    bool status = false;
    
    // Описание устройства, используется для
    // создания первичного окна устройства
    QVBoxLayout *mainLayout = nullptr;

    QString description = nullptr;

    QLineEdit *lWriteData = nullptr;
    QLineEdit *lReadData = nullptr;
    QLineEdit *lOpenStatus = nullptr;

    QPushButton *pbtnSend = nullptr;
    QPushButton *pbtnClose = nullptr;

    // Количество строк виджета для установки размера
    int wLineCount = 0;

    // отправка данных
    void sendData(QString datas);
protected slots:
    // реализовать в каждом дочернем классе

    // слот обработки закрытия виджета
    virtual void on_pbtnClose_clicked();

    // слот обработки получения данных,
    // внутри необходимо использовать функцию sendToBridges
    // для отправки данных на подписанные устройства
    void receiveData(){}

    // Отправка пришедших данных по всем мостам
    void notificateBridges(QString datas);
signals:
    void transmitData(QString datas);
    void deviceDestroyed(AbstractIODevice *device);
};

#endif // ABSTRACTIODEVICE_H
