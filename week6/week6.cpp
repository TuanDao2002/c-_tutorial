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

class Student : public Person{
    public:
        int studentID = 1;

        Student() {
            // std::cout << "Constructor of Student is called" << std::endl;
        }

        ~Student() {
            // std::cout << "\nDestructor of Student is called" << std::endl;
        }
};

class Staff : public Person{
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

        Tutor(int studentID, int staffID) {
            this->studentID = studentID;
            this->staffID = staffID;
            // std::cout << "Constructor of Tutor is called" << std::endl;
        }

        ~Tutor() {
            // std::cout << "\nDestructor of Tutor is called" << std::endl;
        }

        void showInfo() {
            std::cout << "staffID = " << staffID << std::endl
                      << "studentID = " << studentID << std::endl;
        }
};

int main() {
    Tutor t;

    // does not define the size
    std::vector<Tutor> tutors = {
        Tutor(123, 99999),
        Tutor(222, 93232),
        Tutor(212, 23434),
    };

    for (Tutor eachTutor : tutors) {
        eachTutor.showInfo();
    }
    return 0;
}