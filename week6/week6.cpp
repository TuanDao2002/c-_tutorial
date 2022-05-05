#include <iostream>
#include <vector>

#define DELETE_INDEX 1

class Person{
    public:
        std::string name = "hello";
        int age = 22;

        Person() {
            // std::cout << "Constructor of Person is called" << std::endl;
        }

        ~Person() {
            // std::cout << "\nDestructor of Person is called" << std::endl;
        }
};

// use virtual base class to prevent multiple inheritance ambiguosity
class Student : virtual public Person{
    public:
        int studentID = 1;

        Student() {
            // std::cout << "Constructor of Student is called" << std::endl;
        }

        ~Student() {
            // std::cout << "\nDestructor of Student is called" << std::endl;
        }
};

class Staff : virtual public Person{
    public:
        int staffID = 2;

        Staff() {
            // std::cout << "Constructor of Staff is called" << std::endl;
        }

        ~Staff() {
            // std::cout << "\nDestructor of Staff is called" << std::endl;
        }
};

class Tutor : public Student, public Staff{
    public:
        void consultation() {
           std::cout << "Consultation!! " << std::endl;
        };

        Tutor() {
            // std::cout << "Constructor of Tutor is called" << std::endl;
        }

        Tutor(int studentID, int staffID, std::string name, int age) {
            this->studentID = studentID;
            this->staffID = staffID;
            this->name = name;
            this->age = age;
            // std::cout << "Constructor of Tutor is called" << std::endl;
        }

        ~Tutor() {
            // std::cout << "\nDestructor of Tutor is called" << std::endl;
        }

        void showInfo() {
            std::cout << "staffID = " << staffID << std::endl
                      << "studentID = " << studentID << std::endl
                      << "name = " << name << std::endl
                      << "age = " << age << "\n\n";
        }
};

int main() {
    // does not define the size
    std::vector<Tutor> tutors = {
        Tutor(123, 99999, "tuan", 20),
        Tutor(222, 93232, "khatun", 19),
        Tutor(212, 23434, "tun", 20),
    };

    for (Tutor eachTutor : tutors) {
        eachTutor.showInfo();
    }

    tutors.erase(tutors.begin() + DELETE_INDEX);

    std::cout << "Vector after deleting at index: " << DELETE_INDEX << std::endl;
    for (Tutor eachTutor : tutors) {
        eachTutor.showInfo();
    }
    return 0;
}