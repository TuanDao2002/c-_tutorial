class node {
    private:
        int data;
        node* next;
    
    public:
        node(int data); // Constructor to initialise node data
        node(int data, node* nextNode); // Constructor to initialise node data
        
        int getData(); // Data accessor function
        node* getNext(); // Data accessor function

        void setData(int newData); // Data setter function
        void setNext(node* newNode); // Data setter function
};