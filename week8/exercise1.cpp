#include <iostream>
#include <algorithm> // std::find
#include <vector>

using std::vector;
using std::string;

class Book {
    private:
        std::string title;
        int availableCopies;
        vector<string> namesOfBorrowers;
    
    public:
        Book();

        Book(string title, int availableCopies, vector<string> namesOfBorrowers) {
            this->title = title;
            this->availableCopies = availableCopies;
            this->namesOfBorrowers = namesOfBorrowers;
        }

        friend class User; // User can access private attributes of Book

        void addName(std::string name) {
            namesOfBorrowers.push_back(name);
        }

        void removeName(string name) {
            vector<string>::iterator it;

            // find the index of delete element
            it = std::find(namesOfBorrowers.begin(), namesOfBorrowers.end(), name);
            if (it == namesOfBorrowers.end()) {
                std::cerr << title << " is not borrowed by " << name << "!!!\n";
                return;
            }
        
            namesOfBorrowers.erase(it);
        }

        void showInfo() {
            std::cout << "Title: " << title
                      << ", Copies: " << availableCopies << "\n\n";
        }

        void showBorrowers() {
            std::cout << "List of borrowers of " << title << ":\n";

            if (namesOfBorrowers.size() == 0) {
                std::cout << "No one borrows " << title << "\n\n";
                return;
            }
        
            for (auto name : namesOfBorrowers) {
                std::cout << name << std::endl;
            }

            std::cout << "\n";
        }
};

class User{
    private:
        string name;
        vector<Book*> borrowedBooks;

    public:
        User();
        User(string name, vector<Book*>borrowedBooks) {
            this->name = name;
            this->borrowedBooks = borrowedBooks;
        }

        virtual bool doBorrow(Book &abook) {
            if (abook.availableCopies > 0) {
                borrowedBooks.push_back(&abook);
                abook.addName(this->name);
                abook.availableCopies--;
                std::cout << name << " has borrowed " << abook.title << "\n\n";
                return true;
            }
        
            std::cerr << name << " cannot borrow " << abook.title << "\n\n";
            return false;
        }

        void doReturn(Book &abook) {
            vector<Book*>::iterator it;
					
            // find the index of delete element
            it = std::find(borrowedBooks.begin(), borrowedBooks.end(), &abook);

            if (it == borrowedBooks.end()) {
                std::cerr << name << " cannot return " << abook.title << std::endl;
                std::cerr << name << " does not borrow book " << abook.title << "!!!\n\n";
                return;
            }

            abook.removeName(this->name);
					
            // delete element by index
            for (int i = 0; i < borrowedBooks.size(); i++) {
                if (borrowedBooks[i] == &abook) {
                    borrowedBooks.erase(borrowedBooks.begin() + i);
                }
            }

            abook.availableCopies++;
            std::cerr << name << " has returned " << abook.title << "\n\n";
        }

        void showInfo() {
            std::cout << "Name: " << name << std::endl;
            if (borrowedBooks.size() == 0) {
                std::cout << "No book borrowed\n";
            } else {
                std::cout << "Books have been borrowed: \n";
                for (auto* book : borrowedBooks) {
                     std::cout << book->title << std::endl;
                }
            }

            std::cout << std::endl;
        }
};

class SuperUser : public User {
    public:
        SuperUser(string name, vector<Book*> booksBorrowed) : User(name, booksBorrowed) {}

        bool doBorrow(Book &book1, Book &book2) {
            return User::doBorrow(book1) && User::doBorrow(book2);
        }
};

int main() {
    vector<Book*> books {
        new Book("Books1", 3, vector<string>()),
        new Book("Books2", 3, vector<string>()),
        new Book("Books3", 3, vector<string>())
    };

    User user1("User1", vector<Book*>()), user2("User2", vector<Book*>());
    user1.doBorrow(*books[0]);
    user2.doBorrow(*books[1]);

    books[0]->showInfo();
    books[1]->showInfo();
    books[2]->showInfo();

    SuperUser super("super", vector<Book*>());
    super.doBorrow(*books[0], *books[1]);
	super.showInfo();

    books[0]->showInfo();
    books[1]->showInfo();
    books[2]->showInfo();

    // free up memory at the end
    for (Book* abook : books) {
        delete abook;
    }
    return 0;
}