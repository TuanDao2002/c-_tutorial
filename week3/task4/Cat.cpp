#include <iostream>

class Cat {
    public:
        std::string name;
        int age;
        Cat(){}; // default constructor with no parameter (needed for person class)
        Cat(std::string name_val, int age_val) {
            name = name_val;
            age = age_val;
        };

        void display() {
            std::cout << "Cat named: " << name << "\tAge: " << age << "\n"; 
        }
};
    
class Person {
    public:
        Cat cat;
        std::string name;

        Person(Cat cat_obj, std::string name_val) {
            cat = cat_obj;
            name = name_val;
        };

        void display() {
            std::cout << "Person named: " << name << "\n"; 
        }
};

int main() {
    Cat c1("hello kitty", 2);
    Person p1(c1, "tuan");

    Cat c2("emma", 3);
    Person p2(c2, "khatun");

    Cat c3("lily", 1);
    Person p3(c3, "daotuan");

    Person personArray[3] = {p1, p2, p3};
    Person personWithOldestCat = personArray[0];

    for (int i = 0; i < 3; i++) {
        if (personArray[i].cat.age > personWithOldestCat.cat.age) {
            personWithOldestCat = personArray[i];
        }
    }

    personWithOldestCat.display();
    personWithOldestCat.cat.display();
    return 0;
}