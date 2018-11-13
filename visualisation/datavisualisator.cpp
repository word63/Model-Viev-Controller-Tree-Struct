#include "datavisualisator.h"

void DataVisualisator::setPolarChart()
{
   if(currentWidget != nullptr)
        currentWidget->hide();

    if(chart==nullptr)
        chart = new ChartWidget(this);

    currentWidget = chart;

    emit typeChanged();
}

void DataVisualisator::setLog()
{
    if(currentWidget != nullptr)
         currentWidget->hide();

    if(log==nullptr)
        log = new LogWidget(this);

    currentWidget = log;

    emit typeChanged();
}

DataVisualisator::DataVisualisator(QWidget *parent, int type) : QWidget(parent)
{
    connect(this, &DataVisualisator::typeChanged, this, &DataVisualisator::slotTypeChanged);

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

void DataVisualisator::slotTypeChanged()
{
        currentWidget->show();
        currentWidget->setGeometry(this->rect());
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
