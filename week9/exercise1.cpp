#include <iostream>

#if 0
class Node{
    public:
        int value;
        Node* next = NULL;
        Node* prev = NULL;

        // constructors
        Node(){}
        Node(int value) {
            this->value = value;
        }

        // method to set connections to node
        void connectNode(Node* next, Node* prev) {
            this->next = next;
            this->prev = prev;
        }


};

void printForward(Node* originNode) {
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
}

void printBackward(Node* lastNode) {
    // print backward order
    Node* temp = lastNode;
    while (temp != NULL) {
        std::cout << temp->value << " --> ";

        // if the previous node is the last node, break the while loop
        if (temp->prev == lastNode) {
            break;
        }

        // Otherwise, move to the previous node
        temp = temp->prev;
    }
}

// pass by reference the pointer of head node so the head node can be changed
void insertNode(Node* &head, Node* priorNode, Node* newNode) {
    if (priorNode == NULL) {
        // new node points next to head node
        newNode->next = head;

        // new node points back to the previous node of head node (which is last node)
        newNode->prev = head->prev;

        // the previous node of head node (the last node) points next to new node;
        head->prev->next = newNode;

        // the head node points back to new node
        head->prev = newNode;

        // now the new node will become head node
        head = newNode;
    } else {
        // let new node points next to the next node of prior node
        newNode->next = priorNode->next;

        // new node points back to prior node
        newNode->prev = priorNode;  

        // the next node after prior node points back to new node
        priorNode->next->prev = newNode;

        // now prior node points next to new node
        priorNode->next = newNode;
    }
}

void deleteNode(Node* &head, Node* delNode) {
    // if the delete node is head
    if (delNode == head) {
        // delete node becomes head node
        delNode = head;

        // new head node will be the next node of the old head node
        head = delNode->next;

        // new head node points back to the previous node of the old head node
        head->prev = delNode->prev;

        // the previous node of the old head node (last node) points next to the new head node
        delNode->prev->next = head;

        // delete old head node
        // delete delNode;
        return;
    }

    // previous node of the delete node points next to its next node
    delNode->prev->next = delNode->next;

    // next node of the delete node points back to its previous node
    delNode->next->prev = delNode->prev;

    // delete delNode
    // delete delNode;
}

void swap(Node* &originNode, Node* &lastNode, Node* first, Node* second) {
    if (first == originNode) {
        originNode = second;
    } else if (second == originNode) {
        originNode = first;
    }

    if (first == lastNode) {
        lastNode = second;
    } else if (second == lastNode) {
        lastNode = first;
    }
	
    Node* temp = first->next;
    first->next = second->next;
	first->next->prev = first;
    second->next = temp;
	second->next->prev = second;

    temp = first->prev;
    first->prev = second->prev;
	first->prev->next = first;
    second->prev = temp;
	second->prev->next = second;
}

void sort(Node* &originNode, Node* &lastNode) {
    Node* current = originNode;
    Node* nextNode = NULL;
    while (current != NULL) {
        if (current->next == originNode) {
            break;
        }
    
        nextNode = current->next;
        while (nextNode != NULL) {
            if (current->value > nextNode->value) {
                swap(originNode, lastNode, current, nextNode);

                // swap again so pointer to current node will not be moved to the swapped node
                Node* temp = current;
                current = nextNode;
                nextNode = temp;
            }

            if (nextNode->next == originNode) {
                break;
            }

            nextNode = nextNode->next;
        }

        current = current->next;
    }
}


int main(){
    Node n1(8), n2(5), n3(3), n4(6);

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

    printForward(originNode);

    std::cout << std::endl;
    printBackward(lastNode);

    Node newNode = Node(100);
    // insert new node with value 100 at the head of the list
    insertNode(originNode, NULL, &newNode);
    std::cout << "\n\nAfter insert a new node with value 100 at the head of the list" << std::endl;
    // std::cout << "The head node now is: " << originNode->value << std::endl;
    printForward(originNode);
    std::cout << std::endl;
    printBackward(lastNode);

    Node newNode1 = Node(200);
    // insert new node after 3 and 6
    insertNode(originNode, &n3, &newNode1);
    std::cout << "\n\nAfter insert new node with value 200 after node with value 3" << std::endl;
    // std::cout << "The head node now is: " << originNode->value << std::endl;
    printForward(originNode);
    std::cout << std::endl;
    printBackward(lastNode);

    Node* delNode = &n2;
    deleteNode(originNode, delNode);
    std::cout << "\n\nAfter delete node with value 5" << std::endl;
    // std::cout << "The head node now is: " << originNode->value << std::endl;
    printForward(originNode);
    std::cout << std::endl;
    printBackward(lastNode);

    swap(originNode, lastNode, &newNode1, &n4);
    std::cout << "\n\nAfter swap 200 and 6:" << std::endl;
    printForward(originNode);
    std::cout << std::endl;
    printBackward(lastNode);

    sort(originNode, lastNode);
    std::cout << "\n\nAfter sorting:" << std::endl;
    printForward(originNode);
	
    return 0;
}
#endif

#if 1

class Node{
    private:
        int value;
        Node* next = NULL;
        Node* prev = NULL;

    public:
        // constructors
        Node(){}
        Node(int value) {
            this->value = value;
        }

        // method to set connections to node
        void connectNode(Node* prev, Node* next) {
            this->prev = prev;
            this->next = next;
        }

        void linkNextNode(Node* nextNode) {
            this->next = nextNode;

            if (nextNode != NULL) {
                nextNode->prev = this;
            }
        }

        void linkPrevNode(Node* prevNode) {
            this->prev = prevNode;

            if (prevNode != NULL) {
                prevNode->next = this;
            }
        }

        friend void showForwdLink(Node* head);
        friend void showBackwdLink(Node* tail);
        friend void insertNode(Node*& head, Node*& tail, Node* priorNode, Node* newNode);
        friend void deleteNode(Node*& head, Node*& tail, Node* delNode);
        friend void swap(Node*& head, Node*& tail, Node* node1, Node* node2);
        friend void sortAscend(Node*& head, Node*& tail);
};

void showForwdLink(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        std::cout << temp->value << " --> ";
        temp = temp->next;

        // for circular linkedlist
        // if (temp == head) {
        //     break;
        // }
    }

    std::cout << std::endl;
}

void showBackwdLink(Node* tail) {
    Node* temp = tail;

    while (temp != NULL) {
        std::cout << temp->value << " --> ";
        temp = temp->prev;

        // for circular linkedlist
        // if (temp == tail) {
        //     break;
        // }
    }

    std::cout << std::endl;
}

void insertNode(Node*& head, Node*& tail, Node* priorNode, Node* newNode) {
    if (priorNode != NULL) {
        newNode->linkNextNode(priorNode->next);
        priorNode->linkNextNode(newNode);

        if (priorNode == tail) {
            tail = newNode;
        }
    } else {
        newNode->linkNextNode(head);
        head = newNode;

        // for circular linkedlist
        // tail->linkNextNode(head);
    }
}

void deleteNode(Node*& head, Node*& tail, Node* delNode) {

    if (head == delNode) {
        head = delNode->next;
        head->linkPrevNode(delNode->prev);
        return;
    }

    Node* priorNode = head;

    while (priorNode != NULL) {
        if (priorNode->next == delNode) {
            priorNode->linkNextNode(delNode->next);

            if (tail == delNode) {
                tail = priorNode;
            }

            break;
        }

        priorNode = priorNode->next;
    }
}

void swap(Node*& head, Node*& tail, Node* node1, Node* node2) {
    Node temp = *node1;

    if (node1->next == node2) { // node1 before node2
        node1->linkNextNode(node2->next);
        node1->linkPrevNode(node2);
        node2->linkPrevNode(temp.prev);
    } else if (node1->prev == node2) { // node1 after node2
        node1->linkPrevNode(node2->prev);
        node1->linkNextNode(node2);
        node2->linkNextNode(temp.next);
    } else {
        node1->linkNextNode(node2->next);
        node1->linkPrevNode(node2->prev);
        node2->linkNextNode(temp.next);
        node2->linkPrevNode(temp.prev);
    }

    if (node1 == head) {
        head = node2;
    } else if (node2 == head) {
        head = node1;
    }

    if (node1 == tail) {
        tail = node2;
    } else if (node2 == tail) {
        tail = node1;
    }
}

void sortAscend(Node*& head, Node*& tail) {
    while (true) {
        bool hasSwap = false;

        for (Node* left = head; left != NULL && left != tail;) {
            if (left->value > left->next->value) {
                swap(head, tail, left, left->next);
                hasSwap = true;
            } else {
                left = left->next;
            }
        }

        if (!hasSwap) {
            break;
        }
    }
}


int main() {
    // create 4 nodes with values 8,5,3,6
    Node node1(8), node2(5), node3(3), node4(6);

    Node* head = &node1; 

    // non circular
    node1.connectNode(NULL, &node2);
    node2.connectNode(&node1, &node3);
    node3.connectNode(&node2, &node4);
    node4.connectNode(&node3, NULL);

    // circular
    /*
    node1.connectNode(&node4, &node2);
    node2.connectNode(&node1, &node3);
    node3.connectNode(&node2, &node4);
    node4.connectNode(&node3, &node1);
    */

    Node* tail = &node4;
    showForwdLink(head);

    Node newNode(100);
    insertNode(head, tail, NULL, &newNode);

    std::cout << "After insert 100 at head:" << std::endl;
    showForwdLink(head);

    Node newNode2(200);
    insertNode(head, tail, tail, &newNode2);

    std::cout << "After insert 200 after tail" << std::endl;
    showForwdLink(head);
    showBackwdLink(tail);

    deleteNode(head, tail, head);
    std::cout << "After deleting head: " << std::endl;
    showForwdLink(head);
    showBackwdLink(tail);

    deleteNode(head, tail, &newNode2);
    std::cout << "After deleting node 200:" << std::endl;
    showForwdLink(head);
    showBackwdLink(tail);

    swap(head, tail, &node1, &node4);
    std::cout << "After swapping head and tail:" << std::endl;
    showForwdLink(head);
    showBackwdLink(tail);

    sortAscend(head, tail);
    std::cout << "After sorting in ascending order:" << std::endl;
    showForwdLink(head);
    showBackwdLink(tail);
    return 0;
}

#endif