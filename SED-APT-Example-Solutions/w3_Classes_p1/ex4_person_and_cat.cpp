#include <iostream>

class Cat {
    public:
        std::string name;
        int age;

        /* We may have multile versions of constructor */ 
        //default constructor with no paramters (needed for Person constructor)  
        Cat(){}  
        
        //constructor with two arguments
        Cat (std::string name_val, int age_val) { 
            name = name_val; age = age_val;
        }
};


class Person {
    public:
        Cat cat;
        std::string name;

        Person (Cat mycat, std::string name_val) {
            cat = mycat; name = name_val;
        }
};


    
int main() {
    Person ps_arr[3] = { Person(Cat("Cat1", 3), "An"),
                         Person(Cat("Cat2", 5), "Tae-hee"),
                         Person(Cat("Cat1", 4), "Viet")};

    Person max_person = ps_arr[0]; //assume person0 is the one that has thet oldest cat
    for (int i = 1; i < 3; i++) { //compare the cat's age with that of other people's cats
        if (max_person.cat.age < ps_arr[i].cat.age) {
            max_person = ps_arr[i];
        }
    }

    std::cout   << "Person with oldest cat: \n"
                << "Person Name = " << max_person.name
                << ", Cat Name = " << max_person.cat.name
                << ", Cat Age = " << max_person.cat.age;

    return 0;
}