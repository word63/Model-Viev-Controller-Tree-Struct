#ifndef COMPORTDEVICE_H
#define COMPORTDEVICE_H

#include <QWidget>
#include <QPushButton>


#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLabel>
#include <QLineEdit>


#include <QPainter>


class ComPortDevice : public QWidget
{
    Q_OBJECT
public:
    explicit ComPortDevice(QWidget *parent = nullptr);

    void setDiscription(const QString &value);

signals:

public slots:

private:
    QLabel *desc;
    QString discription = "COM_Port_1";
    QVBoxLayout *newLay;

protected:
    void paintEvent(QPaintEvent *event);


};

#endif // COMPORTDEVICE_H
