#ifndef COMPORTDEVICE_H
#define COMPORTDEVICE_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>

#include <QStyleOption>
#include <QPainter>
#include <QStyle>
#include <QPen>
#include <QColor>

class ComPortDevice : public QWidget
{
    Q_OBJECT
public:
    explicit ComPortDevice(QWidget *parent = nullptr);

signals:

public slots:

private:
    QVBoxLayout *newLay;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);


};

#endif // COMPORTDEVICE_H
