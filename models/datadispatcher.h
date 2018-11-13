#ifndef DATADISPATCHER_H
#define DATADISPATCHER_H

#include <QObject>
#include "simpletreemodel.h"

class DataDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit DataDispatcher(QObject *parent = nullptr);

    void addNode();
signals:

public slots:
};

#endif // DATADISPATCHER_H
