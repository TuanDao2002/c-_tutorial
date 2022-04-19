#include <iostream>
#include <algorithm> // std::find
#include <vector>
class Book {
    private:
        std::string title;
        int availableCopies;
        std::vector<std::string> namesOfBorrowers;
    
    public:
        Book();

        Book(std::string title, int availableCopies) {
            this->title = title;
            this->availableCopies = availableCopies;
        }

        std::string getTitle() {
            return title;
        }

        void addName(std::string name) {
            namesOfBorrowers.push_back(name);
        }

        void removeName(std::string name) {
            std::vector<std::string>::iterator it;

            // find the index of delete element
            it = std::find(namesOfBorrowers.begin(), namesOfBorrowers.end(), name);
            if (it == namesOfBorrowers.end()) {
                std::cerr << title << " is not borrowed by " << name << "!!!\n";
                return;
            }
        
            namesOfBorrowers.erase(it);
        }

        bool minusCopy(){
            if (availableCopies == 0) {
                return false;
            }
					
            availableCopies--;
				return true;
        }

        void addCopy() {
            availableCopies++;
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
        std::string name;

    public:
        std::vector<Book*> borrowedBooks;

        User();
        User(std::string name) {
            this->name = name;
        }

        bool doBorrow(Book &abook) {
            if (abook.minusCopy()) {
                borrowedBooks.push_back(&abook);
                abook.addName(this->name);
                std::cout << name << " has borrowed " << abook.getTitle() << "\n\n";
                return true;
            }
        
            std::cerr << name << " cannot borrow " << abook.getTitle() << "\n\n";
            return false;
        }

				virtual bool doBorrow(Book &book1, Book &book2){
						return false;
				};

        void doReturn(Book &abook) {
            std::vector<Book*>::iterator it;
					
            // find the index of delete element
            it = std::find(borrowedBooks.begin(), borrowedBooks.end(), &abook);

            if (it == borrowedBooks.end()) {
                std::cerr << name << " cannot return " << abook.getTitle() << std::endl;
                std::cerr << name << " does not borrow book " << abook.getTitle() << "!!!\n\n";
                return;
            }

            abook.removeName(this->name);
					
            // delete element by index
            borrowedBooks.erase(it);

            abook.addCopy();
            std::cerr << name << " has returned " << abook.getTitle() << "\n\n";
        }

        void showInfo() {
            std::cout << "Name: " << name << std::endl;
            if (borrowedBooks.size() == 0) {
                std::cout << "No book borrowed\n";
            } else {
                std::cout << "Books have been borrowed: \n";
                for (auto* book : borrowedBooks) {
                     std::cout << book->getTitle() << std::endl;
                }
            }

            std::cout << std::endl;
        }

      	~User() {
         	// for (auto book : borrowedBooks) {
            //     delete book;
            // }
            borrowedBooks.clear();
        }
};

class SuperUser : public User {
    public:
        SuperUser(std::string name) : User(name) {}

        bool doBorrow(Book &book1, Book &book2) {
            return User::doBorrow(book1) && User::doBorrow(book2);
        }
};

int main() {
    std::vector<Book*> bookVector;
    bookVector.push_back(new Book("Harry Potter", 100));
    bookVector.push_back(new Book("Fantastic Beast", 1));
    bookVector.push_back(new Book("Game of thrones", 300));

    User user1("tuan"), user2("khatun");

    user1.doBorrow(*bookVector.at(1)); // vector contains pointers to Book object
    user1.showInfo();
    bookVector.at(1)->showBorrowers();

    user2.doBorrow(*bookVector.at(1));
    user2.showInfo();	
    bookVector.at(1)->showBorrowers();

    user2.doReturn(*bookVector.at(2));
    user2.showInfo();

    bookVector.at(2)->showInfo();

    user1.doReturn(*bookVector.at(1));
    user1.showInfo();
    bookVector.at(1)->showInfo();
    bookVector.at(1)->showBorrowers();

    user2.doBorrow(*bookVector.at(1));
    user2.doBorrow(*bookVector.at(2));
    user2.showInfo();

    bookVector.at(1)->showInfo();
    bookVector.at(2)->showInfo();
	
    SuperUser super("super");
    super.doBorrow(*bookVector.at(0), *bookVector.at(2));
    super.showInfo();

    for (auto pBook : bookVector) {
        delete pBook;
    }

    bookVector.clear();
    return 0;
}