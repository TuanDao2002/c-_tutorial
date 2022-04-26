#include <iostream>

class Node{
    public:
        int value;
        Node* next = NULL;
        Node* prev = NULL;

        Node(int value) {
            this->value = value;
        }
};

int main(){
    Node n1 = Node(8), n2 = Node(5), n3 = Node(3), n4 = Node(6);

    // doubly linkedlist
    Node* originNode = &n1;

    n1.next = &n2;
    n2.prev = &n1;

    n2.next = &n3;
    n3.prev = &n2;

    n3.next = &n4;
    n4.prev = &n3;

    n4.next = &n1;
    n1.prev = &n4;

    Node* lastNode = &n4;

    // print forward order
    Node* temp = originNode;
    while (temp != NULL) {
        std::cout << temp->value << " --> ";

        // if the next node is the original node, break the while loop
        if (temp->next == originNode) {
            break;
        }

        // Otherwise, move to the next node
        temp = temp->next;
    }

    std::cout << std::endl;
    // print backward order
    temp = lastNode;
    while (temp != NULL) {
        std::cout << temp->value << " --> ";

        // if the previous node is the last node, break the while loop
        if (temp->prev == lastNode) {
            break;
        }

        // Otherwise, move to the previous node
        temp = temp->prev;
    }

    return 0;
}