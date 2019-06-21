#include "Node.h"

Node::Node(int data, Node* next)
{
    this->data = data;
    this->next = next;
}

Node::Node(Node& other)
{
    data = other.data;
    next = other.next;
}

