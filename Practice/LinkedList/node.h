template <class X>
class node {
    private:
        X data;
        node* next;
    
    public:
				node();
        node(X data); // Constructor to initialise node data
        node(X data, node* nextNode); // Constructor to initialise node data
        
        X getData(); // Data accessor function
        node<X>* getNext(); // Data accessor function

        void setData(X newData); // Data setter function
        void setNext(node* newNode); // Data setter function
};

