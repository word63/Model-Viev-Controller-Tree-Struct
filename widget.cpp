#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeView->setModel(&localModel);



    QTreeView *temp = ui->treeView;
    //ui->treeView->expanded()

    connect(temp, &QTreeView::expanded , this, &Widget::tableUpbate);

    //connect(temp,SIGNAL(expanded(QModelIndex())),this,SLOT(tableUpbate()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    localModel.insertRows(0,0, index);

    //ui->treeView->resizeColumnToContents(0);
    //ui->treeView->update(index);
}

void Widget::tableUpbate()
{
    ui->treeView->resizeColumnToContents(0);
}
