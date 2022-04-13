#include <iostream> // include iostream to use NULL
#include "LinkedList.h"

LinkedList::LinkedList() {
    head = NULL;
};

LinkedList::LinkedList(int newData) {
    head = new node(newData, NULL);
}

LinkedList::~LinkedList(){
    clear();
}

void LinkedList::headInsert(int newData) {
    node* newHead = new node(newData);    
    newHead->setNext(head);
    head = newHead;
}

void LinkedList::tailAppend(int newData) {
    node* newNode = new node(newData);

    node* current = head;
    while (current->getNext() != NULL) {
        current = current->getNext();
    }

    current->setNext(newNode);
}

void LinkedList::insertNodeAfter(node* afterMe, int newData) {
    node* newNode = new node(newData);

    node* current = head;
    while (current != NULL) {
        if (current == afterMe) {
            newNode->setNext(current->getNext());
            current->setNext(newNode);
            break;
        }

        current = current->getNext();
    }
}

void LinkedList::removeNode(int val) {
    node* deleteNode = NULL;
	if (head->getData() == val) {
        deleteNode = head;
        head = deleteNode->getNext();
        delete deleteNode;
		return;
    }

    node* current = head;
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

void LinkedList::clear() {
    node* current = head;
    while (current != NULL) {
        head = head->getNext();
        delete current;
        current = head;
    }
}

bool LinkedList::findData(int val) {
    node* retrieveNode = findNode(val);
    if (retrieveNode == NULL) {
        return false;
    }

    return true;
}

node* LinkedList::findNode(int val) {
    node* current = head;
    while (current != NULL) {
        if (current->getData() == val) {
            return current;
        }

        current = current->getNext();
    }

    return NULL;
}

int LinkedList::size() {
    int count = 0;
    node* current = head;
    while (current != NULL) {
        count++;
        current = current->getNext();
    }

    return count;
}


void LinkedList::printList() {
    int index = 0;
    node* current = head;
    while (current != NULL) {
        std::cout << "Node " << index << ": " << current->getData() << std::endl;
        index++;
        current = current->getNext();
    }
}

