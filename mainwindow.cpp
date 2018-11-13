#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setMinimumWidth(800);

    //[1]! TREE VIEW
    ui->treeView->setModel(&localModel);

    QTreeView *temp = ui->treeView;

    connect(temp, &QTreeView::expanded , this, &MainWindow::tableUpbate);
    connect(temp, &QTreeView::collapsed, this, &MainWindow::tableUpbate);

    //[2]! DEVICES
    devicer = new DeviceDispatcher();

    leftScrollLay = new QVBoxLayout();
    QSpacerItem *spaser = new QSpacerItem(10,10,QSizePolicy::Minimum,QSizePolicy::Expanding);

    leftScrollLay->addSpacerItem(spaser);

    ui->scrollAreaWidgetContents->setLayout(leftScrollLay);
    ui->scrollArea_Left->setFixedWidth(200);

    //[3]!  VISUALISATION
    dataVis = new DataVisualisator(this, 1);

    QVBoxLayout *rightScrollLay = new QVBoxLayout();
    rightScrollLay->addWidget(dataVis);
    ui->scrollArea_Right->setLayout(rightScrollLay);

    dataVis->setGeometry(ui->scrollArea_Right->rect());

    QStringList list;
    list << "Log" << "Polar Chart";
    ui->comboBox_infoTypes->addItems(list);

    connect(devicer, &DeviceDispatcher::listDeviceChanged, this, &MainWindow::update_comboBox_widgets);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::tableUpbate()
{
    ui->treeView->resizeColumnToContents(0);
}



void MainWindow::resizeEvent(QResizeEvent *event)
{
    emit sizeChanged();
    dataVis->setGeometry(ui->scrollArea_Right->rect());
}

void MainWindow::on_actionCom_Device_triggered()
{
    leftScrollLay->addWidget(devicer->createComDevice("comport"));
}


void MainWindow::on_actionSocket_triggered()
{
    leftScrollLay->addWidget(devicer->createSocketDevice("socket"));
}

void MainWindow::on_actionServer_triggered()
{
    leftScrollLay->addWidget(devicer->createServerDevice("servachok!"));
}

void MainWindow::on_comboBox_infoTypes_currentIndexChanged(int index)
{
    dataVis->changeType(index);
}

void MainWindow::on_comboBox_widgets_currentIndexChanged(int index)
{

}

void MainWindow::update_comboBox_widgets()
{
    ui->comboBox_widgets->clear();
    ui->comboBox_widgets->addItems(devicer->getStringListDevices());
}
