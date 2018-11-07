#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setUpTreeView();

    setUpDevices();

    setUpChart();

    this->setMinimumWidth(800);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpTreeView()
{

    ui->treeView->setModel(&localModel);

    QTreeView *temp = ui->treeView;

    connect(temp, &QTreeView::expanded , this, &MainWindow::tableUpbate);
    connect(temp, &QTreeView::collapsed, this, &MainWindow::tableUpbate);

}

void MainWindow::setUpDevices()
{
    QVBoxLayout *scrollLay = new QVBoxLayout();
    ComPortDevice *dev = new ComPortDevice("Com_port_1");
    ServerDevice *dev3 = new ServerDevice("Server_Port_3");
    SocketDevice *dev4 = new SocketDevice("Socket_Port_4");

    scrollLay->addWidget(dev);
    scrollLay->addWidget(dev3);
    scrollLay->addWidget(dev4);

    deviceList << dev << dev3 << dev4;

    foreach(AbstractIODevice* device, deviceList)
    {
        device->setFixedHeight(device->getWidgetCount()*40);
    }

    QSpacerItem *spaser = new QSpacerItem(10,10,QSizePolicy::Minimum,QSizePolicy::Expanding);
    scrollLay->addSpacerItem(spaser);
    ui->scrollAreaWidgetContents->setLayout(scrollLay);
    ui->scrollArea_Left->setFixedWidth(200);
    server = new TcpServer(8080);

    connect(server, &TcpServer::deviceCountChanged, dev3, &ServerDevice::updateOpenStatus);
    connect(server, &TcpServer::requestedMessage, dev3, &ServerDevice::setRequestedData);
    connect(dev3, &ServerDevice::receiveData, server, &TcpServer::slotSendData);
    connect(dev, &ComPortDevice::sendData, this, &MainWindow::getFromCom);

}

void MainWindow::setUpChart()
{
    dataVis = new DataVisualisator(this, 1);

    QVBoxLayout *scrollLay = new QVBoxLayout();
    scrollLay->addWidget(dataVis);
    ui->scrollArea_Right->setLayout(scrollLay);

    dataVis->setGeometry(ui->scrollArea_Right->rect());

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

void MainWindow::getFromCom(QString str)
{
}
