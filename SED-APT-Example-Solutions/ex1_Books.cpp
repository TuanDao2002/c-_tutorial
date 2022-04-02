#include <iostream>
#include <sstream>
#include <cstring>
#define NAMESIZE 100

class Book {
public:
    std::string *name;
    int price;

    //constructor
    Book(){ name = new std::string; }

    Book(std::string name_val, int price_val){
        //this->name = name_val;
        this->name = new (std::nothrow) std::string(name_val); //Qc
        if (this->name == NULL) {
            std::cerr << "Fail to allocate memory \n";
        }
        this->price = price_val;
    }

    //function to return info as a string
    std::string toString(){
        std::stringstream sstr; 
        sstr << "name: " << *name << ", price: " << price;
        return sstr.str(); //get and return string content from the stringstream
    }

    //Qc  Destructor
    ~Book(){
        delete name;
    }

};




int main() {
    //Qa
    //request dynamic memory allocation
    Book *book1 = new (std::nothrow) Book("Harry Potter", 100); 
    if (book1 == NULL) {
        std::cerr << "Fail to allocate heap memory for book1 \n";
        return -1;
    }

    //print out info
    std::cout << "A book's info: " << book1->toString() << "\n\n";
    delete book1; //free up allocated memory

    
    //Qb
    int n;
    std::cout << "Enter number of books: ";
    std::cin >> n;
    Book *books = new (std::nothrow) Book[n]; 

    char str_temp[NAMESIZE]; //declare a C-style string to use with getline

    std::cout << "Enter information for each book: \n";
    for (int i = 0; i < n; i++) {
        std::cout << "> Book " << i + 1 << "'s name: ";
        
        //read a line
        do {
            std::cin.getline(str_temp, sizeof(str_temp));
        } while (strlen(str_temp) == 0);
        *books[i].name = str_temp;

        std::cout << "price: ";
        std::cin >> books[i].price;
    }

    Book *most_exp = &books[0]; //assume first book is the most expensive
    for (int i = 1; i < n; i++) { //check with other books
        if (most_exp->price < books[i].price) {
            most_exp = &books[i];
        }
    }

    std::cout << "> Most expensive book: " << most_exp->toString();

    return 0;
}