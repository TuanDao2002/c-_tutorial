#include <iostream> // include iostream to use NULL
#include "LinkedList.h"

template <class X> 
LinkedList<X>::LinkedList() {
    head = NULL;
};

template <class X> 
LinkedList<X>::LinkedList(X newData) {
    head = new node<X>(newData, NULL);
}

template <class X> 
LinkedList<X>::~LinkedList(){
    clear();
}

template <class X> 
void LinkedList<X>::headInsert(X newData) {
    node<X>* newHead = new node<X>(newData);    
    newHead->setNext(head);
    head = newHead;
}

template <class X> 
void LinkedList<X>::tailAppend(X newData) {
    node<X>* newNode = new node<X>(newData);

    node<X>* current = head;
    while (current->getNext() != NULL) {
        current = current->getNext();
    }

    current->setNext(newNode);
}

template <class X> 
void LinkedList<X>::insertNodeAfter(node<X>* afterMe, X newData) {
    node<X>* newNode = new node<X>(newData);

    node<X>* current = head;
    while (current != NULL) {
        if (current == afterMe) {
            newNode->setNext(current->getNext());
            current->setNext(newNode);
            break;
        }

        current = current->getNext();
    }
}

template <class X> 
void LinkedList<X>::removeNode(X val) {
    node<X>* deleteNode = NULL;
	if (head->getData() == val) {
        deleteNode = head;
        head = deleteNode->getNext();
        delete deleteNode;
		return;
    }

    node<X>* current = head;
    while (current->getNext() != NULL) {
        if (current->getNext()->getData() == val) {
            deleteNode = current->getNext();
            current->setNext(deleteNode->getNext());
            delete deleteNode;
            break;
        }

        current = current->getNext();
    }
}

template <class X> 
void LinkedList<X>::clear() {
    node<X>* current = head;
    while (current != NULL) {
        head = head->getNext();
        delete current;
        current = head;
    }
}

template <class X> 
bool LinkedList<X>::findData(X val) {
    node<X>* retrieveNode = findNode(val);
    if (retrieveNode == NULL) {
        return false;
    }

    return true;
}

template <class X> 
node<X>* LinkedList<X>::findNode(X val) {
    node<X>* current = head;
    while (current != NULL) {
        if (current->getData() == val) {
            return current;
        }

        current = current->getNext();
    }

    return NULL;
}

template <class X> 
int LinkedList<X>::size() {
    int count = 0;
    node<X>* current = head;
    while (current != NULL) {
        count++;
        current = current->getNext();
    }

    return count;
}

template <class X> 
void LinkedList<X>::printList() {
    int index = 0;
    node<X>* current = head;
    while (current != NULL) {
        std::cout << "Node " << index << ": " << current->getData() << std::endl;
        index++;
        current = current->getNext();
    }
}

// explicitly institating all relevant templates
template class LinkedList<std::string>;
template class LinkedList<int>;