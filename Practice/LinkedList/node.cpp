#include <iostream>
#include "node.h"

template <class X> 
node<X>::node() {// constructor for class node<X>
}

template <class X> 
node<X>::node(X newData) {// constructor for class node<X>
    data = newData;
    next = NULL;
}

template <class X> 
node<X>::node(X newData, node* nextNode) { // constructor for class node<X>
    data = newData;
    next = nextNode;
}

template <class X> 
X node<X>::getData() { // return X data type object
    return data;
}

template <class X>
node<X>* node<X>::getNext() { // return node<X>*
    return next;
}

template <class X>
void node<X>::setData(X newData) { // void setter for class node<X>
    data = newData;
}

template <class X>
void node<X>::setNext(node* nextNode) {
    next = nextNode;
}

// explicitly institating all relevant templates
template class node<std::string>;
template class node<int>;
