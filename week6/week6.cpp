#include <iostream>
#include <vector>

#define DELETE_INDEX 1

class Person{
    protected:
        std::string name = "hello";
        int age = 22;

    public:
        ~Person() {
            // std::cout << "Person destroy" << std::endl;
        }
};

class Student : public Person{
    protected:
        int studentID = 1;
    
        // setters and getters of parent members should belong to one class only to prevent ambiguos in Tutor class
        void setName(std::string name) {
            this->name = name;
        }

        void setAge(int age) {
            this->age = age;
        }

        std::string getName() {
            return name;
        }

        int getAge() {
            return age;
        }
    
    public:
        ~Student() {
            // std::cout << "Student destroy" << std::endl;
        }
};

class Staff : public Person{
    protected:
        int staffID = 2;

    public:
        ~Staff() {
            // std::cout << "Staff destroy" << std::endl;
        }
};

class Tutor : Student, Staff{
    public:
        Tutor(){}

        Tutor(std::string name, int age, int studentID, int staffID){
            setName(name);
            setAge(age);
            this->studentID = studentID;
            this->staffID = staffID;
        }

        void consultation() {
            std::cout << "Name: " << getName() << std::endl
                      << "Age: " << getAge() << std::endl
                      << "Student ID = " << studentID << std::endl
                      << "Staff ID = " << staffID << std::endl;
        };

        // Tutor will be destroyed first, then Student and Staff, when Student or Staff is destroyed, Person will be destroyed also => Person will be destoryed for each Student or Staff
        ~Tutor() {
            // std::cout << "Tutor destroy" << std::endl;
        }
};

int main() {
    Tutor t;
    t.consultation();

    std::cout << "\n";

    Tutor t1("tuan", 20, 3877347, 384);
    Tutor t2("dao", 21, 3877341, 314);
    Tutor t3("kha", 22, 3877337, 334);

    std::vector<Tutor> tutorVector = {t1, t2, t3};

    for (Tutor t : tutorVector) {
        t.consultation();
        std::cout << "\n";
    }

    tutorVector.erase(tutorVector.begin() + DELETE_INDEX);

    std::cout << "Tutor vector after deleting second object: \n";
    for (Tutor t : tutorVector) {
        t.consultation();
        std::cout << "\n";
    }
    return 0;
}