#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeView->setModel(&localModel);

    QTreeView *temp = ui->treeView;


    connect(temp, &QTreeView::expanded , this, &Widget::tableUpbate);
    connect(temp, &QTreeView::collapsed, this, &Widget::tableUpbate);

    QVBoxLayout *scrollLay = new QVBoxLayout();

    ComPortDevice *dev = new ComPortDevice("Com_port_1");
    ComPortDevice *dev2 = new ComPortDevice("Com_port_2");
    ServerDevice *dev3 = new ServerDevice("Server_Port_3");
    SocketDevice *dev4 = new SocketDevice("Socket_Port_4");

    scrollLay->addWidget(dev);
    scrollLay->addWidget(dev2);
    scrollLay->addWidget(dev3);
    scrollLay->addWidget(dev4);

    deviceList << dev << dev2 << dev3 << dev4;

    foreach(AbstractIODevice* device, deviceList)
    {
        device->setFixedHeight(device->getWidgetCount()*40);
//        qDebug() << device
    }



    QSpacerItem *spaser = new QSpacerItem(10,10,QSizePolicy::Minimum,QSizePolicy::Expanding);
    scrollLay->addSpacerItem(spaser);
    ui->scrollAreaWidgetContents->setLayout(scrollLay);
//    ui->scrollAreaWidgetContents->setStyleSheet("background-color: #98FB98");

    server = new TcpServer(8080);

    connect(server, &TcpServer::deviceCountChanged, dev3, &ServerDevice::updateOpenStatus);
    connect(server, &TcpServer::requestedMessage, dev3, &ServerDevice::setRequestedData);
    connect(dev3, &ServerDevice::receiveData, server, &TcpServer::slotSendData);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    localModel.insertRows(0,0, index);

}

void Widget::tableUpbate()
{
    ui->treeView->resizeColumnToContents(0);
}
