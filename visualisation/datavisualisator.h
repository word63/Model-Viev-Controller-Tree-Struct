#ifndef DATAVISUALISATOR_H
#define DATAVISUALISATOR_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QVBoxLayout>

#include "chartwidget.h"
#include "logwidget.h"

class DataVisualisator : public QWidget
{
    Q_OBJECT

    // Chart type = hex int value
    const int polarChart = 1;
    const int noVisualisation = 0;

    QWidget *currentWidget = nullptr;
    QVBoxLayout* vLay = nullptr;
    LogWidget * log;
    ChartWidget *chart;

    void setPolarChart();
    void setLog();

public:
    explicit DataVisualisator(QWidget *parent = nullptr, int type = 0);
    void changeType(int type);

signals:
    void typeChanged();
public slots:
    void slotTypeChanged();
    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // DATAVISUALISATOR_H
