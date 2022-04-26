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

void swap(Node* &originNode, Node* first, Node* second) {
    if (first == originNode) {
        originNode = second;
    } else if (second == originNode) {
        originNode = first;
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

void sort(Node* &originNode) {
    Node* current = originNode;
    Node* nextNode = NULL;
    while (current != NULL) {
        if (current->next == originNode) {
            break;
        }
    
        nextNode = current->next;
        while (nextNode != NULL) {
            if (current->value > nextNode->value) {
                swap(originNode, current, nextNode);

                // swap again so current index will not be moved to the swapped node
                Node* temp = current;
                current = nextNode;
                nextNode = temp;

                // printForward(originNode);
                // std::cout << "\n";
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

    swap(originNode, &n1, &n4);
    std::cout << "\n\nAfter swap 8 and 6:" << std::endl;
    printForward(originNode);

    sort(originNode);
    std::cout << "\n\nAfter sorting:" << std::endl;
    printForward(originNode);
	
    return 0;
}