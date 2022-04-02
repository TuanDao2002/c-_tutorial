#include <iostream>
#include <cstring>

#define NAMESIZE 100

class Book {    
    public:
        std::string* name; // dynamic allocation for "name" attribute
        int* price;

        Book(){}

        Book(std::string name, int price) {
            this->name = new std::string(name);
            this->price = new int(price);
        }

        Book (const Book& book) {
            name = new std::string(*(book.name));
            price = new int(*(book.price));
        }

        void display() {
            // access pointer of "name" attribute
            std::cout << "Name: " << *name << "\tPrice: " << *price << std::endl;
        }

        ~Book() {
            delete price;
            delete name;
        }

        Book operator++ (int) {
            Book temp = *this;
            (*price)--;
            return temp;
        }
};

#if 1
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
    Book** books = new (std::nothrow) Book* [n];

    char str_temp[NAMESIZE]; //declare a C-style string to use with getline
    int price_temp;
    for (int i = 0; i < n; i++) {
        std::cout << "> Book " << i + 1 << "'s name: ";
        
        //read a line
        do {
            std::cin.getline(str_temp, sizeof(str_temp));
        } while (strlen(str_temp) == 0);

        std::cout << "price: ";
        std::cin >> price_temp;

        books[i] = new Book(str_temp, price_temp);
    }

    Book* most_expensive = books[0];
    for (int i = 0; i < n; i++) {
        // use arrow as each object is dynamic
        if (*books[i]->price > *most_expensive->price) {
            most_expensive = books[i];
        }
    
        books[i]->display();
    }

    std::cout << "The book with the highest price is: " << *most_expensive->name << std::endl;

    // delete all dynamic objects of the array
    for (int i = 0; i < n; i++) {
        delete books[i];
    }

    // delete dynamic array
    delete[] books;

    Book test = Book("test", 100);
    Book temp = test++;
    temp.display();
    test.display();
    return 0;
}
#endif
