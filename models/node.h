#ifndef NODE_H
#define NODE_H

#include "QString"
#include "QList"

struct DeviceDescription{
    QString deviceOut;
    QString type;
    QString deviceIn;
    int value;
};

class Node
{
public:
    Node(DeviceDescription item, Node *parent = nullptr);

    DeviceDescription getItem() const;
    void setItem(const DeviceDescription &value);

    void appendChild(Node *child);
    Node *child(int row) const;

    int childCount() const;
    int columnCount() const;

    int row() const;
    QVariant data(int column);

    Node *getParent() const;

private:
    Node *parent;
    DeviceDescription item;
    QList<Node *> children;

};

#endif // NODE_H
