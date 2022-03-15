#include <iostream>

class Cat {
    public:
        std::string name;
        int age;
        Cat(){};
        Cat(std::string name_val, int age_val) {
            name = name_val;
            age = age_val;
        };

        void display() {
            std::cout << "Cat named: " << name << "\tAge: " << age << "\n"; 
        }
};

class person {
    public:
        Cat cat;
        std::string name;
        person(){};
        person(Cat cat_obj, std::string name_val) {
            cat = cat_obj;
            name = name_val;
        };

        void display() {
            std::cout << "Person named: " << name << "\n"; 
        }
};

int main() {
    Cat c1("hello kitty", 2);
    person p1(c1, "tuan");

    Cat c2("emma", 3);
    person p2(c2, "khatun");

    Cat c3("lily", 1);
    person p3(c3, "daotuan");

    person personArray[3] = {p1, p2, p3};
    person personWithOldestCat = personArray[0];

    for (int i = 0; i < 3; i++) {
        if (personArray[i].cat.age > personWithOldestCat.cat.age) {
            personWithOldestCat = personArray[i];
        }
    }

    personWithOldestCat.display();
    personWithOldestCat.cat.display();
    return 0;
}