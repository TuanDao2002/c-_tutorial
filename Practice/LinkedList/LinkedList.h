#include "node.h"
template <class X> class LinkedList{
    private:
        node<X>* head; // pointer of the head node

    public:
        LinkedList();    // Constructor with no arguments
        LinkedList(X newData); // Constructors with an initial Head node data value
        ~LinkedList();   // Destructor

        void headInsert(X newData); // Add a node to the head of a Linked List    
        void tailAppend(X newData); // Append a node to the end of a Linked List
        void insertNodeAfter(node<X>* afterMe, X newData); // Add a node in the middle of a Linked List, after the given node

        void removeNode(X val); // Remove a node with the given value (if it exists)    
        void clear(); // Delete all nodes in the Linked List
        bool findData(X val); // Search the Linked List for a node with a given value, return TRUE if found, FALSE if not found

        node<X>* findNode(X val); // Search the Linked List for a node with a given value, return address of node if found

        int size(); // Count the number of nodes in the Linked List
        void printList(); // Traverse the Linked List and print out the data value of each node 
};