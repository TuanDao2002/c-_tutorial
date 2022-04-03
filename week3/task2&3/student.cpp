#include <iostream>
#include <fstream>
#include <string.h>
#define MAX_SIZE 50
class Student {
    private:
        int score;
        std::string password;

    public:
        std::string name;
        Student(std::string name_val, int score_val) {
            name = name_val;
            score = score_val;
        }

        int get_score() {
            return score;
        }

        void display() {
            std::cout << "Name: " << name << "\tScore: " << get_score() << "\n";
        }

        void write_file(std::string val) {
            std::fstream myfile;
            myfile.open(name + ".dat", std::ios::out);

            if (!myfile) {
                std::cout << "Cannot open file" << "\n";
                return;
            }
            
            myfile << val << "\n";
            
            std::cout << "Password is saved!" << "\n"; 
            myfile.close();
        }

        std::string read_file(std::string datFilename) {
            char prev_password[MAX_SIZE];

            std::fstream myfile;
            myfile.open(datFilename + ".dat", std::ios::in);

            if (!myfile) {
                std::cerr << "Cannot open file" << "\n";
            }

            myfile.getline(prev_password, MAX_SIZE); // get a line from the file and store into prev_password

            myfile.close();

            return prev_password;
        }

        void change_pwd() {
            std::string password = read_file(name);
            if (password.empty()) {
                std::cout << "Enter a password: ";
                std::getline(std::cin, password); // only use cin.ignore when we use std::cin before std::getline

                write_file(password);
            } else {
                std::string new_password;
                std::string prev_password;
                std::cout << "Enter the previous password to check: ";
                std::getline(std::cin, prev_password);

                if (read_file(name) != prev_password) {
                    std::cout << "Wrong password" << "\n";
                    return;
                }

                std::cout << "Enter your new password: ";
                std::getline(std::cin, new_password);

                password = new_password;

                write_file(new_password);
            }
        }
};

int main() {
    Student s1("tuan", 80);
    Student s2("khatun", 81);

    s1.display();
    s2.display();

    Student studentArray[3] = {s1, s2, Student("Peter Pan", 85)};

    Student highestScoreStudent = studentArray[0];
    std::cout << "All students in the array:\n";
    for (int i = 0; i < 3; i++) {
        studentArray[i].display();
        if (studentArray[i].get_score() > highestScoreStudent.get_score()) {
            highestScoreStudent = studentArray[i];
        }
    }

    std::cout  << "\n";

    std::cout << "Student with the highest score: " << "\n";
    highestScoreStudent.display();

    highestScoreStudent.change_pwd();
    return 0;
}