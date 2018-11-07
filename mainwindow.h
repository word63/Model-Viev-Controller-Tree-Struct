#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "models/simpletreemodel.h"
#include "device/comportdevice.h"
#include "device/serverdevice.h"
#include "device/socketdevice.h"
#include <QVBoxLayout>
#include <QSpacerItem>
#include "tcpserver.h"
#include "visualisation/datavisualisator.h"

#include "QSplitter"
#include "QMenuBar"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private Q_SLOTS:
    void tableUpbate();

private:
    SimpleTreeModel localModel;
    TcpServer *server;
    DataVisualisator *dataVis;

    QList<AbstractIODevice* > deviceList;

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setUpTreeView();
    void setUpDevices();
    void setUpChart();

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;
private slots:
    void getFromCom(QString str);
signals:
    void sizeChanged();

};

#endif // MAINWINDOW_H
