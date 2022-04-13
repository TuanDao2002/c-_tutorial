#include "node.cpp"
class LinkedList{
    private:
        node* head; // pointer of the head node

    public:
        LinkedList();    // Constructor with no arguments
        LinkedList(int newData); // Constructors with an initial Head node data value
        ~LinkedList();   // Destructor

        void headInsert(int newData); // Add a node to the head of a Linked List    
        void tailAppend(int newData); // Append a node to the end of a Linked List
        void insertNodeAfter(node* afterMe, int newData); // Add a node in the middle of a Linked List, after the given node

        void removeNode(int val); // Remove a node with the given value (if it exists)    
        void clear(); // Delete all nodes in the Linked List
        bool findData(int val); // Search the Linked List for a node with a given value, return TRUE if found, FALSE if not found

        node* findNode(int val); // Search the Linked List for a node with a given value, return address of node if found

        int size(); // Count the number of nodes in the Linked List
        void printList(); // Traverse the Linked List and print out the data value of each node 
};