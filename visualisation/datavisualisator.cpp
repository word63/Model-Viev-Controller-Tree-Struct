#include "datavisualisator.h"

void DataVisualisator::setPolarChart()
{
    currentWidget->deleteLater();
    chart = new ChartWidget(this);
    currentWidget = chart;

}

void DataVisualisator::setLog()
{
    log = new LogWidget(this);
    currentWidget = log;


}

DataVisualisator::DataVisualisator(QWidget *parent, int type) : QWidget(parent)
{

    if(type == noVisualisation)
        setLog();
    else
        changeType(type);


}

void DataVisualisator::changeType(int type)
{
   if(type == polarChart)
       setPolarChart();
   else
       setLog();
}

void DataVisualisator::resizeEvent(QResizeEvent *event)
{
    if(currentWidget!=nullptr)
        currentWidget->setGeometry(this->rect());
}


void DataVisualisator::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(QPen(QBrush(Qt::red),5));
    p.drawRect(this->rect());
}
