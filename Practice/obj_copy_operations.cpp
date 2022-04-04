#include <iostream>


class Juice {
public:
    std::string name;
    int *price;

public:
    // Default contructor
    Juice(){
        this->price = new int; //request memmory allocation
    }

    //Constructor
    Juice (std::string name_val, int price_val){
        this->name = name_val;
        this->price = new int(price_val); //request memmory allocation
        
        std::cout << "\n\nConstructor is called, name = " << name << ", price = " << *price << "\n";
    }



    /* COPY constructor */
    // Juice (const Juice &juice) {
    //     this->name = juice.name;
    //     this->price = new int(*juice.price); //allocate new memory location
    // }



    // Display method
    void display(){
        std::cout << "Juice: " << name << std::endl;
        std::cout << "Price: " << *price << std::endl;
        std::cout << std::endl;
    }


    // Overload operators --
    Juice operator -- (int){
        Juice temp = *this;   //Copy constructor:  price of temp got same address with current object !!!

        std::cout << "addr of this->price: " << (void *) this->price << "\n";
        std::cout << "addr of temp->price: " << (void *) temp.price << "\n";;
        
        temp.name = "TempJuice"; 
            
        *(this->price) -= 1;
        
        return temp;  //return previous value (before decreasing)
        /*  when we return, it will call destructor of temp and delete its price
            --> will make the price of current object fails to work
        */
    }






    // Destructor
    ~Juice(){
        std::cout << "Destructor is called, name = " << name << ", price = " << *price << "\n";
        delete price;
    }
};




int main(int argc, char *argv[]){

    // Question B
    Juice juice1("Juice1", 100);
    Juice juice2("Juice2", 200);

    //Test -- operator
    juice2 = juice1--;

    return 0;
}
