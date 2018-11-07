#ifndef DATADISPATCHER_H
#define DATADISPATCHER_H

#include <QObject>

class DataDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit DataDispatcher(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DATADISPATCHER_H