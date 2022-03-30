#include <iostream>
#include <stdlib.h>
#include <time.h>

class Book {
    private:
        std::string* name; // dynamic allocation for "name" attribute
        int price;
    
    public:
        Book(){}

        Book(std::string name, int price) {
            this->name = new std::string(name);
            this->price = price;
        }

        std::string get_name() {
            return *name;
        }

        int get_price() {
            return this->price;
        }

        void display() {
            // access pointer of "name" attribute
            std::cout << "Name: " << *name << "\tPrice: " << price << std::endl;
        }

        ~Book() {
            std::cout << *name + " is deleted" << std::endl;
            delete name;
        }
};

int main() {
    // question a
    Book *book1 = new (std::nothrow) Book("History of time", 200); // ignore exception

    // log out error if dynamic memory allocation failed
    if (book1 == NULL) {
        std::cerr << "Dynamic memory allocation failed" << std::endl;
        return -1;
    }

    book1->display(); // (*book1).display() is the same

    delete book1;


    // question b
    int n;
    std::cout << "Enter a number n: ";
    std::cin >> n;

    // create a dynamic array of dynamic objects
    Book** book_arr = new (std::nothrow) Book* [n];

    srand(time(NULL)); // random generator
    int max_index = 0;
    
    for (int i = 0; i < n; i++) {
        int price = rand() % 100;

        // initialize dynamic object
        book_arr[i] = new Book("Book " + std::to_string(i + 1), price);
    }

    for (int i = 0; i < n; i++) {
        // use arrow as each object is dynamic
        if (book_arr[i]->get_price() > book_arr[max_index]->get_price()) {
            max_index = i;
        }
    
        book_arr[i]->display();
    }

    std::cout << "The book with the highest price is: " << book_arr[max_index]->get_name() << std::endl;

    // delete all dynamic objects of the array
    for (int i = 0; i < n; i++) {
        delete book_arr[i];
    }

    // delete dynamic array
    delete[] book_arr;
    return 0;
}