#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "models/simpletreemodel.h"
#include <QVBoxLayout>
#include <QSpacerItem>

#include "device/devicedispatcher.h"
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

    void on_actionCom_Device_triggered();

    void on_actionSocket_triggered();

    void on_actionServer_triggered();

    void on_comboBox_infoTypes_currentIndexChanged(int index);

    void on_comboBox_widgets_currentIndexChanged(int index);
private slots:
    void update_comboBox_widgets();
private:

    DeviceDispatcher *devicer = nullptr;

    SimpleTreeModel localModel;
    DataVisualisator *dataVis;


private:
    Ui::MainWindow *ui;

    QVBoxLayout *leftScrollLay = nullptr;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;

signals:
    void sizeChanged();

};

#endif // MAINWINDOW_H
