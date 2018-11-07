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
    
public:
    AbstractIODevice(QString description = "undefined", QWidget *parent = nullptr);
    void setDesription(QString description);

    int getWidgetCount() const;

    void bridgeTo(AbstractIODevice *from);

protected:
    int widgetCount = 0;

    void Initialization(); // call this func from your constructor
    
    void createLineWidget(QString labelStr, QWidget *widget= nullptr);
    void createLineWidget(QWidget *widget);

    void paintEvent(QPaintEvent *event) override;
    
    QString description;
    QVBoxLayout *mainLayout;

    QLineEdit *lWriteData;
    QLineEdit *lReadData;
    QLineEdit *lOpenStatus;

    QPushButton *pbtnSend;
    
protected slots:

signals:
    void dataReceived(QString datas);
};

#endif // ABSTRACTIODEVICE_H
