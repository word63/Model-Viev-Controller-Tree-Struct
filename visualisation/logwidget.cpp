#include "logwidget.h"

LogWidget::LogWidget(QWidget *parent) : QWidget(parent)
{
    texter = new QTextEdit(this);
    texter->show();
    texter->setReadOnly(true);


}

void LogWidget::printLine(QString str)
{
    texter->append(str);
}


void LogWidget::resizeEvent(QResizeEvent *event)
{
    texter->setGeometry(this->rect());
}
