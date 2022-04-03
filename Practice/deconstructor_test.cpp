#include <iostream>

class Data {
public:
    std::string name;
    int *arr;

    Data(){ // default constructor
        std::cout << "\n\nDefault Constructor of " << name << " is called \n";
        arr = new int[1000]; //dynamic memory allocation with the heap
    }

    Data(std::string name) { // Paramaterized constructor
        std::cout << "\n\nParamaterized Constructor of " << name << " is called \n";
        this->name = name;
        arr = new int[1000]; //dynamic memory allocation with the heap
    }; 

    Data(const Data& data) {
        this->name = data.name;
        this->arr = new int[1000];
    }

    ~Data() { // destructor
        std::cout << "Destructor of " << name  << " is called \n";
        delete[] arr; //comment out this one will cause Memory Leak (computer hang)
    }; 
};
 



//A function with local object to test
void myFunc(int i){
    std::string name = "dataX" + std::to_string(i);
    
    Data dataX(name);   //create a local object (use Paramaterized constructor)
    dataX.arr[1000] = 1000; //test the allocated arr attribute
    std::cout << "dataX.arr[1000]: " << dataX.arr[1000] << "\n";

    Data dataY = dataX; //use copy constructor
    /* Observed behavior: it is automatically allocate a coresponding memory space in heap (for dataY.arr) to
    copy a region from heap (from dataX.arr) */

    dataY.name[4] = 'Y';
    dataY.arr[1000] = 2000; //test the allocated arr attribute
    std::cout << "dataY.arr[1000]: " << dataY.arr[1000] << "\n";
}



int main() {

    /* Test: delete an unallocated pointer will hang the program */
    // char *arr;
    // delete[] arr;
    // std::cout << "End of the program !\n";

    //Call the function many times
    for (int i = 0; i < 5; i++) {
        myFunc(i); 
    }
    
    return 0;
}