#include "node.h"

Node::Node(DeviceDescription item, Node *parent):
    parent(parent), item(item)
{

}

DeviceDescription Node::getItem() const
{
    return item;
}

void Node::setItem(const DeviceDescription &value)
{
    item = value;
}

void Node::appendChild(Node *child)
{
    children.append(child);
}

Node *Node::child(int row) const
{
    return children.value(row);
}

int Node::childCount() const
{
    return children.length();
}

int Node::columnCount() const
{
    return 4;
}

int Node::row() const
{
    if(parent)
        return parent->children.indexOf(const_cast<Node *>(this));
    return 0;
}

QVariant Node::data(int column)
{
    switch (column) {
    case 0: return item.deviceOut;
    case 1: return item.type;
    case 2: return item.deviceIn;
    case 3: return item.value;
    }

    return QVariant();
}

Node *Node::getParent() const
{
    return parent;
}
