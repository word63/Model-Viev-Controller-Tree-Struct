#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTextEdit>

class LogWidget : public QWidget
{
    Q_OBJECT
    QTextEdit *texter;
public:
    explicit LogWidget(QWidget *parent = nullptr);

signals:

public slots:
    void printLine(QString str);


    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // LOGWIDGET_H
