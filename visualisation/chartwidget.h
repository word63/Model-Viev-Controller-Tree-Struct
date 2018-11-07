#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <QPolarChart>
#include <QScatterSeries>

using namespace QtCharts;

class ChartWidget : public QWidget
{
private:

    QChartView *chartView;
    QScatterSeries *series;
    QLineSeries *lineSeries;
    QValueAxis *angularAxis;
    QValueAxis *radialAxis;


    QPolarChart *chart;
    Q_OBJECT
public:
    explicit ChartWidget(QWidget *parent = nullptr);


    void initSeries();

signals:

public slots:
    void updatePoint(qreal degree, qreal range);

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // CHARTWIDGET_H
