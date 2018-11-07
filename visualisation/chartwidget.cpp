#include "chartwidget.h"
#include <QPointF>
#include <QtDebug>



void ChartWidget::initSeries()
{
//    for(int i = 0; i<=60; i++)
//        series->append(0,0);
}

void ChartWidget::updatePoint(qreal degree, qreal range)
{

    qDebug() << degree << range;
    series->append(degree, range);

//    int newIndex = degree/6;

//    series->remove(degree/6);
    series->append(degree,range);

//        qDebug() << "Out of range polar points";

}

ChartWidget::ChartWidget(QWidget *parent) : QWidget(parent)
{

    // Полярные координаты
    const qreal angularMin = 0;
    const qreal angularMax = 360;

    const qreal radialMin = 0;
    const qreal radialMax = 200;

    series = new QScatterSeries();
    series->setName("range");

    chart = new QPolarChart();
    chart->addSeries(series);
    chart->setMinimumSize(200,200);
    // Angular Axis для круговых осей
    // Изменение угла
    angularAxis = new QValueAxis();
    angularAxis->setTickCount(9); // First and last ticks are co-located on 0/360 angle.
    angularAxis->setLabelFormat("%.1f");
    angularAxis->setShadesVisible(true);
    angularAxis->setShadesBrush(QBrush(QColor(249, 249, 255)));
    chart->addAxis(angularAxis, QPolarChart::PolarOrientationAngular);

    // Radial axis для оси дальности
    // изменение длины
    radialAxis = new QValueAxis();
    radialAxis->setTickCount(9);
    radialAxis->setLabelFormat("%d");
    chart->addAxis(radialAxis, QPolarChart::PolarOrientationRadial);

    series->attachAxis(radialAxis);
    series->attachAxis(angularAxis);

    radialAxis->setRange(radialMin,radialMax);
    angularAxis->setRange(angularMin,angularMax);

    chartView = new QChartView(this);
    chartView->setChart(chart);

    chartView->setRenderHint(QPainter::Antialiasing);

        initSeries();
}


void ChartWidget::resizeEvent(QResizeEvent *event)
{
    chartView->setGeometry(this->rect());
}
