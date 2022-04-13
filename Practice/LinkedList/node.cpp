#include <iostream>
#include "node.h"

node::node(int newData) {
    data = newData;
    next = NULL;
}

node::node(int newData, node* nextNode) {
    data = newData;
    next = nextNode;
}

int node::getData() {
    return data;
}

node* node::getNext() {
    return next;
}

void node::setData(int newData) {
    data = newData;
}

void node::setNext(node* nextNode) {
    next = nextNode;
}